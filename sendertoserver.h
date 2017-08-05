#ifndef SENDERTOSERVER_H
#define SENDERTOSERVER_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <QMessageBox>
#include <QMutex>
#include <QtCore>

#include <string>
#include <errno.h>
#include <signal.h>
#include <string>
#include <iostream>
#include <sstream>
#include <rcssnet/tcpsocket.hpp>
#include <rcssnet/exception.hpp>
#include <netinet/in.h>

#include <behaviors/behavior.h>
#include <behaviors/naobehavior.h>

using namespace rcss::net;
using namespace std;

extern int agentBodyType;

extern bool bResetMonitor;

extern string    mHost;
extern map<string, string> namedParams;
extern string teamName;
extern int uNum;
extern string outputFile; // For optimization
extern string rsg;

class SenderToServer:public QThread
{
    Q_OBJECT
public:
    SenderToServer(int _agentBodyType);
    ~SenderToServer();
    void LaunchMsgLoop();
    bool Init();
    void LoadParams(const string& inputsFile);
    void Done();
    bool SelectInput();
    void PutMessage(const string& msg);
    void PutMonMessage(const string& msg);
    bool GetMessage(string& msg);

    inline NaoBehavior* getBehavior()
    {
        return behavior;
    }
    inline int getAgentBodyType()
    {
        return agentBodyType;
    }

    inline void lockMutex()
    {
        mutex.lock();
    }
    inline void unlockMutex()
    {
        mutex.unlock();
    }
private:
    void run();

    QMutex mutex;

    // Variables for connecting to the server port
    TCPSocket gSocket;
    string gHost;
    int    gPort;

    // Variables for connecting to the monitor port
    TCPSocket mSocket;    
    int    mPort;

    NaoBehavior *behavior;
//    int agentBodyType;
};

#endif // SENDERTOSERVER_H
