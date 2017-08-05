#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QStringList>          //used to add item to QListView
#include <QStringListModel>     //used to add item to QListView
#include <QDebug>
#include <QFileDialog>
#include <QFontDatabase>
#include <QCloseEvent>
#include <QScrollArea>

#include <sstream>
#include <list>
#include <fstream>

#include "creditwindow.h"
#include "sendertoserver.h"

using namespace std;

extern bool bResetMonitor;

// UTAustinVilla joint order
enum joints
{
    _he1,
    _he2,
    _lae1,
    _lae2,
    _lae3,
    _lae4,
    _rae1,
    _rae2,
    _rae3,
    _rae4,
    _lle1,
    _lle2,
    _lle3,
    _lle4,
    _lle5,
    _lle6,
    _lle7,
    _rle1,
    _rle2,
    _rle3,
    _rle4,
    _rle5,
    _rle6,    
    _rle7,
    JOINT_NUM
};

// The following is just an enum like the one above but only with different joint order. the
// joint order is according to the order specified by RoboNewbie team motion files.
enum joints_robonewbie
{
    _he1_r,
    _he2_r,
    _lae1_r,
    _lae2_r,
    _lae3_r,
    _lae4_r,
    _lle1_r,
    _lle2_r,
    _lle3_r,
    _lle4_r,
    _lle5_r,
    _lle6_r,    
    _rle1_r,
    _rle2_r,
    _rle3_r,
    _rle4_r,
    _rle5_r,
    _rle6_r,
    _rae1_r,
    _rae2_r,
    _rae3_r,
    _rae4_r,
    _lle7_r,    // This is not considered by RoboNewbie team, I've added this to make it consistent with UTAustinvilla (95-10-7)
    _rle7_r,    // This is not considered by RoboNewbie team, I've added this to make it consistent with UTAustinvilla (95-10-7)
    _JOINT_NUM_R
};

typedef struct _JointSet
{
    int    keyframeIndex;
    double joints[JOINT_NUM];
    double keyframeTime; //in seconds
} JointSet;

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent=0);
    ~MainWindow();
    shared_ptr<KeyFrame> createKeyframe(JointSet &js);

public slots:
    void getupButtClicked();    
    void autoFallRecoverChBxStateChanged(int state);
    void setBodyTypeButtClicked();
    void resetMonitorButtClicked();
    void playKeyframeButtClicked();

    void SetJointsActivationState(bool state);

    void addKeyFrameButtClicked();
    void deleteKeyFrameButtClicked();
    void moveKeyFrameUpButtClicked();
    void moveKeyFrameDownButtClicked();

    void keyFrameListViewItemClicked(QModelIndex qmIndex);

    void UpdateKeyFrameSequenceEntry(joints jointIndex, double jointVal);
    void UpdateKeyFrameSequenceEntry(double time);

    void KeyframeTimeTextChanged(QString val);
    void He1ValChanged(int val);
    void He2ValChanged(int val);
    void Lae1ValChanged(int val);
    void Lae2ValChanged(int val);
    void Lae3ValChanged(int val);
    void Lae4ValChanged(int val);
    void Rae1ValChanged(int val);
    void Rae2ValChanged(int val);
    void Rae3ValChanged(int val);
    void Rae4ValChanged(int val);
    void Lle1ValChanged(int val);
    void Lle2ValChanged(int val);
    void Lle3ValChanged(int val);
    void Lle4ValChanged(int val);
    void Lle5ValChanged(int val);
    void Lle6ValChanged(int val);
    void Lle7ValChanged(int val);
    void Rle1ValChanged(int val);
    void Rle2ValChanged(int val);
    void Rle3ValChanged(int val);
    void Rle4ValChanged(int val);
    void Rle5ValChanged(int val);
    void Rle6ValChanged(int val);
    void Rle7ValChanged(int val);

    //menu event handlers
    void OpenFile();
    void OpenFileRoboNewbieFormat(string fileName);

    void SaveFileAs();
    void SaveFile();
    void SaveFileRoboNewbieFormat(string fileName);

    joints_robonewbie ServerMsgJntOrderToRbNwBieJntOrder(joints j);
    joints RbNwBieJntOrderToServerMsgJntOrder(joints_robonewbie jrb);

    void About();

private:
    Ui::MainWindow *ui;
    QStringList keyFrameStrList;       //each item of this list contains the name of one of the keyframes.
    list<JointSet> keyFrameSequence;   //each item of this list contains the set of joint commands for one keyframe
    SenderToServer *sts;    //an instance of SendToServer object used to communicate with rcssserver3d in parallel with
                            //the motion editor gui.

    string motionFileName;  //the name of the motion file opened/created by the user
};

#endif // MAINWINDOW_H
