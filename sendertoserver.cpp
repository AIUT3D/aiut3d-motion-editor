#include "sendertoserver.h"
#include <QDebug>

SenderToServer::SenderToServer(int _agentBodyType)
{
    gHost = "127.0.0.1";
    gPort = 3100;
    mPort = 3200;

    teamName = "AIUT3D";
    uNum = 2;
    outputFile = "out.txt"; // For optimization

    if( !Init() )
        qDebug() << "Init failed!";
    else
        qDebug() << "Init OK.";    

    agentBodyType = _agentBodyType;

    stringstream ss;
    ss << agentBodyType;
    rsg = "rsg/agent/nao/nao_hetero.rsg " + ss.str();

    qDebug() << "Agent body type: " << agentBodyType;

    LoadParams("paramfiles/defaultParams.txt");
    LoadParams("paramfiles/defaultParams_t" + ss.str() + ".txt");

    behavior = new NaoBehavior(teamName, uNum, namedParams, rsg);
}

SenderToServer::~SenderToServer()
{
    gSocket.close();
    mSocket.close();
    delete behavior;
}

void SenderToServer::LaunchMsgLoop()
{
    PutMessage(behavior->Init()+"(syn)");

    string msg;
    if (mPort != -1)
    {
        msg = "(playMode PlayOn)";
        behavior->setMonMessage(msg);
        PutMonMessage(behavior->getMonMessage());
    }

    msg = "";
    long i = 0;
    while (true)
    {                
        GetMessage(msg);


        lockMutex();
        string msgToServer = behavior->Think(msg);        
        unlockMutex();


        // To support agent sync mode
        msgToServer.append("(syn)");
        PutMessage(msgToServer);

        static double start=-1;
        msg ="";
        if (mPort != -1)
        {
            if(bResetMonitor)
            {                
                if(behavior->getWorldModel()->getPlayMode() != PM_BEFORE_KICK_OFF)
                {
                    msg += "(playMode BeforeKickOff)";
                    if(start < 0)
                        start = behavior->getWorldModel()->getTime();
                }
                else if(behavior->getWorldModel()->getPlayMode() == PM_BEFORE_KICK_OFF &&
                        behavior->getWorldModel()->getTime() - start > 0.5)
                {                    
                    msg += "(playMode PlayOn)";

                    bResetMonitor = false;
                    start = -1;
                }
            }            

            behavior->setMonMessage(msg);
            PutMonMessage(behavior->getMonMessage());
        }
    }
}

void SenderToServer::LoadParams(const string& inputsFile)
{
    istream *input;
    ifstream infile;
    istringstream inString;

    infile.open(inputsFile.c_str(), ifstream::in);

    if(!infile)
    {
        cerr << "Could not open parameter file " << inputsFile << endl;
        exit(1);
    }

    input = &(infile);

    string name;
    bool fBlockComment = false;
    while(!input->eof())
    {

        // Skip comments and empty lines
        std::string str;
        std::getline(*input, str);
        if (str.length() >= 2 && str.substr(0,2) == "/*")
        {
            fBlockComment = true;
        }
        else if (str == "*/")
        {
            fBlockComment = false;
        }
        if(fBlockComment || str == "" || str[0] == '#' )
        {
            continue;
        }

        // otherwise parse strings
        stringstream s(str);
        std::string key;
        std::string value;
        std::getline(s, key, '\t');      //read thru tab
        std::getline(s, value);          //read thru newline
        if(value.empty()) {
            continue;
        }
        namedParams[key] = value;
    }

    infile.close();
}

bool SenderToServer::Init()
{
    QString qstr;
    stringstream ss;
    ss << "connecting to TCP " << gHost << ":" << gPort;
    qstr= ss.str().c_str();    

    try
    {
        Addr local(INADDR_ANY,INADDR_ANY);
        gSocket.bind(local);
    }
    catch (BindErr &error)						//AI lab 95-4-5 hoseini: excetion catching was done by value but it's recommended that catching is done by reference so atch (BindErr error) is changed to atch (BindErr &error).
    {
        ss.str(""); ss.clear();
        ss << "failed to bind socket with '" << error.what() << "'" << endl;
        qstr = ss.str().c_str();        

        gSocket.close();
        return false;
    }

    try
    {
        Addr server(gPort,gHost);
        gSocket.connect(server);
    }
    catch (ConnectErr &error)					//AI lab 95-4-5 hoseini: catch exception by reference
    {
        ss.str(""); ss.clear();
        ss << "connection failed with: '" << error.what() << "'" << endl;
        qstr = ss.str().c_str();        
        gSocket.close();
        return false;
    }

    // Connect to the monitor port so that we can use the training command parser
    if (mPort != -1)
    {
        try
        {
            Addr local(INADDR_ANY,INADDR_ANY);
            mSocket.bind(local);
        }
        catch (BindErr &error)					//AI lab 95-4-5 hoseini: catch exception by reference
        {
            ss.str(""); ss.clear();
            ss << "failed to bind socket with '" << error.what() << "'" << endl;
            qstr = ss.str().c_str();            
            mSocket.close();
            return false;
        }

        try
        {
            Addr server(mPort,gHost);
            mSocket.connect(server);
        }
        catch (ConnectErr &error)				//AI lab 95-4-5 hoseini: catch exception by reference
        {
            ss.str(""); ss.clear();
            ss << "connection failed with: '" << error.what() << "'" << endl;
            qstr = ss.str().c_str();            
            mSocket.close();
            return false;
        }
    }
    return true;
}

void SenderToServer::Done()
{
    gSocket.close();

    QString qstr;
    stringstream ss;
    ss << "closed connection to " << gHost << ":" << gPort << endl;
    qstr = ss.str().c_str();    
    if (mPort != -1)
    {
        mSocket.close();
    }
}

bool SenderToServer::SelectInput()
{
    fd_set readfds;
    struct timeval tv = {60,0};
    FD_ZERO(&readfds);
    FD_SET(gSocket.getFD(),&readfds);

    while(1)
    {
        QString qstr;
        stringstream ss;
        switch(select(gSocket.getFD()+1,&readfds, 0, 0, &tv))
        {
        case 1:
            return 1;
        case 0:
            ss.str(""); ss.clear();
            ss << "(SelectInput) select failed " << strerror(errno) << endl;
            qstr = ss.str().c_str();            
            abort();
            return 0;
        default:
            if(errno == EINTR)
                continue;
            ss.str(""); ss.clear();
            ss << "(SelectInput) select failed " << strerror(errno) << endl;
            qstr = ss.str().c_str();            
            abort();
            return 0;
        }
    }
}

void SenderToServer::PutMessage(const string& msg)
{
    if (msg.empty())
    {
        return;
    }

    // prefix the message with it's payload length
    unsigned int len = htonl(msg.size());
    string prefix((const char*)&len,sizeof(unsigned int));
    string str = prefix + msg;
    if ( static_cast<ssize_t>(str.size()) != write(gSocket.getFD(), str.data(), str.size()))
    {
        QString qstr;
        string str;
        str = "could not put entire message: ";
        str += msg;
        qstr = str.c_str();        
    }
}

void SenderToServer::PutMonMessage(const string& msg)
{
    if (msg.empty())
    {
        return;
    }

    // prefix the message with it's payload length
    unsigned int len = htonl(msg.size());
    string prefix((const char*)&len,sizeof(unsigned int));
    string str = prefix + msg;
    if ( static_cast<ssize_t>(str.size()) != write(mSocket.getFD(), str.data(), str.size()))
    {
        QString qstr;
        string str("could not put entire monitor message: ");
        str += msg;
        qstr = str.c_str();        
    }
}

bool SenderToServer::GetMessage(string& msg)
{
    QString qstr;
    stringstream ss;

    static char buffer[16 * 1024];

    unsigned int bytesRead = 0;
    while(bytesRead < sizeof(unsigned int))
    {
        SelectInput();
        int readResult = read(gSocket.getFD(), buffer + bytesRead, sizeof(unsigned int) - bytesRead);
        if(readResult < 0)
            continue;
        if (readResult == 0)
        {
            // [patmac] Kill ourselves if we disconnect from the server
            // for instance when the server is killed.  This helps to
            // prevent runaway agents.
            ss.str(""); ss.clear();
            ss << "Lost connection to server" << endl;
            qstr = ss.str().c_str();            
            Done();
            exit(1);
        }
        bytesRead += readResult;
    }

    // msg is prefixed with it's total length
    union int_char_t
    {
        char *c;
        unsigned int *i;
    };
    int_char_t size;
    size.c = buffer;
    unsigned int msgLen = ntohl(*(size.i));

    if(sizeof(unsigned int) + msgLen > sizeof(buffer))
    {
        ss.str(""); ss.clear();
        ss << "too long message; aborting" << endl;
        qstr = ss.str().c_str();        
        abort();
    }

    // read remaining message segments
    unsigned int msgRead = bytesRead - sizeof(unsigned int);

    char *offset = buffer + bytesRead;

    while (msgRead < msgLen)
    {
        if (! SelectInput())
        {
            return false;
        }

        unsigned readLen = sizeof(buffer) - msgRead;
        if(readLen > msgLen - msgRead)
            readLen = msgLen - msgRead;

        int readResult = read(gSocket.getFD(), offset, readLen);
        if(readResult < 0)
            continue;
        msgRead += readResult;
        offset += readResult;        
    }

    // zero terminate received data
    (*offset) = 0;

    msg = string(buffer+sizeof(unsigned int));

    static string lastMsg = "";
    if (msg.compare(lastMsg) == 0)
    {
        ss.str(""); ss.clear();
        ss << "Duplicate message received from server -- has the server killed us?\n";
        qstr = ss.str().c_str();        
        Done();
        exit(1);
    }
    lastMsg = msg;

    return true;
}

void SenderToServer::run()
{    
    LaunchMsgLoop();    
    Done();
}

