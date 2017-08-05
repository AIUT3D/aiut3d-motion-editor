#include "mainwindow.h"
#include "sendertoserver.h"
#include <QApplication>
#include <QScrollArea>

//monitor port
string    mHost = "127.0.0.1";

bool bResetMonitor = false;

int agentBodyType;
map<string, string> namedParams;
string teamName;
int uNum;
string outputFile; // For optimization
string agentType;
string rsg;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    ///
    /// the link to how to add scroll bar to the application form:
    /// http://www.informit.com/articles/article.aspx?p=1405543&seqNum=4
    ///
    QScrollArea scrollArea;
    scrollArea.setWidget(&w);
    scrollArea.setWindowTitle(QObject::tr("AIUT 3D Motion Editor"));
    scrollArea.show();
    w.show();
    return a.exec();
}
