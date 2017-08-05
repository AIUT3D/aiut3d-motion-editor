#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    /*
     * To change the default font of the MainWindow:------------------------------------------
     * Link: http://stackoverflow.com/questions/27257442/qt-apply-a-font-change-on-an-entire-form
     */
    QFont font = QFont("Fira Mono", 10, 1);
    QApplication::setFont(font);
    QString styleSheet = QString("font-size:%1px;").arg(QApplication::font().pointSize());
    this->setStyleSheet(styleSheet);
    //----------------------------------------------------------------------------------------

    ui->setupUi(this);



    //Initially, set the name of the motion file to an empty string
    motionFileName = "";

    //related to menu items
    connect(ui->actionAbout, SIGNAL(triggered()),
            SLOT(About()));

    connect(ui->actionOpen_motion_file, SIGNAL(triggered()),
            SLOT(OpenFile()));

    connect(ui->actionSave_motion_file_as, SIGNAL(triggered()),
            SLOT(SaveFileAs()));

    connect(ui->actionSave_motion_file, SIGNAL(triggered()),
            SLOT(SaveFile()));

    //related to keyframe list view
    ui->keyFramesListView->setModel(new QStringListModel(keyFrameStrList));
    connect(ui->keyFramesListView, SIGNAL(clicked(QModelIndex)),
            SLOT(keyFrameListViewItemClicked(QModelIndex)));

    //get up button
    connect(ui->Getup_butt, SIGNAL(clicked()),
            SLOT(getupButtClicked()));

    //auto fall recovery checkbox
    connect(ui->autoFallRecoverChBx, SIGNAL(stateChanged(int)),
            SLOT(autoFallRecoverChBxStateChanged(int)));

    //set body type button
    connect(ui->setBodyTypeButt, SIGNAL(clicked()),
            SLOT(setBodyTypeButtClicked()));

    //reset monitor button
    connect(ui->resetMonitorButt, SIGNAL(clicked()),
            SLOT(resetMonitorButtClicked()));

    //play keyframe button
    connect(ui->playKeyframesButt, SIGNAL(clicked()),
            SLOT(playKeyframeButtClicked()));

    //add keyframe button
    connect(ui->addKeyFrameButt, SIGNAL(clicked()),
            SLOT(addKeyFrameButtClicked()));

    //delete keyframe button
    connect(ui->deleteKeyFrameButt, SIGNAL(clicked()),
            SLOT(deleteKeyFrameButtClicked()));

    //connect keyframeTimeT signal to event handler
    connect(ui->keyframeTimeT, SIGNAL(textChanged(QString)),
            SLOT(KeyframeTimeTextChanged(QString)));

    //connect slider signal to event handler
    connect(ui->he1_slider, SIGNAL(valueChanged(int)),
            SLOT(He1ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->he1_slider, SIGNAL(valueChanged(int)),
            ui->he1_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->he1_spinBox, SIGNAL(valueChanged(int)),
            SLOT(He1ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->he1_spinBox, SIGNAL(valueChanged(int)),
            ui->he1_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->he2_slider, SIGNAL(valueChanged(int)),
            SLOT(He2ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->he2_slider, SIGNAL(valueChanged(int)),
            ui->he2_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->he2_spinBox, SIGNAL(valueChanged(int)),
            SLOT(He2ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->he2_spinBox, SIGNAL(valueChanged(int)),
            ui->he2_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lae1_slider, SIGNAL(valueChanged(int)),
            SLOT(Lae1ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lae1_slider, SIGNAL(valueChanged(int)),
            ui->lae1_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lae1_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lae1ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lae1_spinBox, SIGNAL(valueChanged(int)),
            ui->lae1_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lae2_slider, SIGNAL(valueChanged(int)),
            SLOT(Lae2ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lae2_slider, SIGNAL(valueChanged(int)),
            ui->lae2_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lae2_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lae2ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lae2_spinBox, SIGNAL(valueChanged(int)),
            ui->lae2_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lae3_slider, SIGNAL(valueChanged(int)),
            SLOT(Lae3ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lae3_slider, SIGNAL(valueChanged(int)),
            ui->lae3_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lae3_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lae3ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lae3_spinBox, SIGNAL(valueChanged(int)),
            ui->lae3_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lae4_slider, SIGNAL(valueChanged(int)),
            SLOT(Lae4ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lae4_slider, SIGNAL(valueChanged(int)),
            ui->lae4_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lae4_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lae4ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lae4_spinBox, SIGNAL(valueChanged(int)),
            ui->lae4_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rae1_slider, SIGNAL(valueChanged(int)),
            SLOT(Rae1ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rae1_slider, SIGNAL(valueChanged(int)),
            ui->rae1_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rae1_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rae1ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rae1_spinBox, SIGNAL(valueChanged(int)),
            ui->rae1_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rae2_slider, SIGNAL(valueChanged(int)),
            SLOT(Rae2ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rae2_slider, SIGNAL(valueChanged(int)),
            ui->rae2_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rae2_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rae2ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rae2_spinBox, SIGNAL(valueChanged(int)),
            ui->rae2_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rae3_slider, SIGNAL(valueChanged(int)),
            SLOT(Rae3ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rae3_slider, SIGNAL(valueChanged(int)),
            ui->rae3_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rae3_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rae3ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rae3_spinBox, SIGNAL(valueChanged(int)),
            ui->rae3_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rae4_slider, SIGNAL(valueChanged(int)),
            SLOT(Rae4ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rae4_slider, SIGNAL(valueChanged(int)),
            ui->rae4_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rae4_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rae4ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rae4_spinBox, SIGNAL(valueChanged(int)),
            ui->rae4_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle1_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle1ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle1_slider, SIGNAL(valueChanged(int)),
            ui->lle1_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle1_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle1ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle1_spinBox, SIGNAL(valueChanged(int)),
            ui->lle1_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle2_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle2ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle2_slider, SIGNAL(valueChanged(int)),
            ui->lle2_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle2_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle2ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle2_spinBox, SIGNAL(valueChanged(int)),
            ui->lle2_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle3_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle3ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle3_slider, SIGNAL(valueChanged(int)),
            ui->lle3_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle3_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle3ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle3_spinBox, SIGNAL(valueChanged(int)),
            ui->lle3_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle4_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle4ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle4_slider, SIGNAL(valueChanged(int)),
            ui->lle4_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle4_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle4ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle4_spinBox, SIGNAL(valueChanged(int)),
            ui->lle4_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle5_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle5ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle5_slider, SIGNAL(valueChanged(int)),
            ui->lle5_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle5_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle5ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle5_spinBox, SIGNAL(valueChanged(int)),
            ui->lle5_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle6_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle6ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle6_slider, SIGNAL(valueChanged(int)),
            ui->lle6_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle6_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle6ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle6_spinBox, SIGNAL(valueChanged(int)),
            ui->lle6_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->lle7_slider, SIGNAL(valueChanged(int)),
            SLOT(Lle7ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->lle7_slider, SIGNAL(valueChanged(int)),
            ui->lle7_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->lle7_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Lle7ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->lle7_spinBox, SIGNAL(valueChanged(int)),
            ui->lle7_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle1_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle1ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle1_slider, SIGNAL(valueChanged(int)),
            ui->rle1_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle1_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle1ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle1_spinBox, SIGNAL(valueChanged(int)),
            ui->rle1_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle2_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle2ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle2_slider, SIGNAL(valueChanged(int)),
            ui->rle2_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle2_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle2ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle2_spinBox, SIGNAL(valueChanged(int)),
            ui->rle2_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle3_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle3ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle3_slider, SIGNAL(valueChanged(int)),
            ui->rle3_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle3_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle3ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle3_spinBox, SIGNAL(valueChanged(int)),
            ui->rle3_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle4_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle4ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle4_slider, SIGNAL(valueChanged(int)),
            ui->rle4_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle4_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle4ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle4_spinBox, SIGNAL(valueChanged(int)),
            ui->rle4_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle5_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle5ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle5_slider, SIGNAL(valueChanged(int)),
            ui->rle5_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle5_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle5ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle5_spinBox, SIGNAL(valueChanged(int)),
            ui->rle5_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle6_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle6ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle6_slider, SIGNAL(valueChanged(int)),
            ui->rle6_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle6_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle6ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle6_spinBox, SIGNAL(valueChanged(int)),
            ui->rle6_slider, SLOT(setValue(int)));



    //connect slider signal to event handler
    connect(ui->rle7_slider, SIGNAL(valueChanged(int)),
            SLOT(Rle7ValChanged(int)));
    //connect slider signal to corresponding spinbox slot
    connect(ui->rle7_slider, SIGNAL(valueChanged(int)),
            ui->rle7_spinBox, SLOT(setValue(int)));
    //connect spinbox signal to event handler
    connect(ui->rle7_spinBox, SIGNAL(valueChanged(int)),
            SLOT(Rle7ValChanged(int)));
    //connect spinbox signal to corresponding slider slot
    connect(ui->rle7_spinBox, SIGNAL(valueChanged(int)),
            ui->rle7_slider, SLOT(setValue(int)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getupButtClicked()
{
    sts->getBehavior()->setBGetup(true);
}

void MainWindow::autoFallRecoverChBxStateChanged(int state)
{
    if(state == Qt::Checked)
        sts->getBehavior()->setBAutoGetup(true);
    else
        sts->getBehavior()->setBAutoGetup(false);
}

void MainWindow::SetJointsActivationState(bool state)
{
    ui->keyframeTimeT->setEnabled(state);
    ui->he1_slider->setEnabled(false);  // (state);
    ui->he1_spinBox->setEnabled(false); // (state);
    ui->he2_slider->setEnabled(false);  // (state);
    ui->he2_spinBox->setEnabled(false); // (state);
    ui->lae1_slider->setEnabled(state);
    ui->lae1_spinBox->setEnabled(state);
    ui->lae2_slider->setEnabled(state);
    ui->lae2_spinBox->setEnabled(state);
    ui->lae3_slider->setEnabled(state);
    ui->lae3_spinBox->setEnabled(state);
    ui->lae4_slider->setEnabled(state);
    ui->lae4_spinBox->setEnabled(state);
    ui->rae1_slider->setEnabled(state);
    ui->rae1_spinBox->setEnabled(state);
    ui->rae2_slider->setEnabled(state);
    ui->rae2_spinBox->setEnabled(state);
    ui->rae3_slider->setEnabled(state);
    ui->rae3_spinBox->setEnabled(state);
    ui->rae4_slider->setEnabled(state);
    ui->rae4_spinBox->setEnabled(state);
    ui->lle1_slider->setEnabled(state);
    ui->lle1_spinBox->setEnabled(state);
    ui->lle2_slider->setEnabled(state);
    ui->lle2_spinBox->setEnabled(state);
    ui->lle2_slider->setEnabled(state);
    ui->lle2_spinBox->setEnabled(state);
    ui->lle3_slider->setEnabled(state);
    ui->lle3_spinBox->setEnabled(state);
    ui->lle4_slider->setEnabled(state);
    ui->lle4_spinBox->setEnabled(state);
    ui->lle5_slider->setEnabled(state);
    ui->lle5_spinBox->setEnabled(state);
    ui->lle6_slider->setEnabled(state);
    ui->lle6_spinBox->setEnabled(state);    
    ui->rle1_slider->setEnabled(state);
    ui->rle1_spinBox->setEnabled(state);
    ui->rle2_slider->setEnabled(state);
    ui->rle2_spinBox->setEnabled(state);
    ui->rle3_slider->setEnabled(state);
    ui->rle3_spinBox->setEnabled(state);
    ui->rle4_slider->setEnabled(state);
    ui->rle4_spinBox->setEnabled(state);
    ui->rle5_slider->setEnabled(state);
    ui->rle5_spinBox->setEnabled(state);
    ui->rle6_slider->setEnabled(state);
    ui->rle6_spinBox->setEnabled(state);


    // Only type 4 agent has toes, so enable toe controls only if the agent is of type 4
    if( state == false ||
       (state == true && sts->getAgentBodyType() == 4) )
    {
        ui->lle7_slider->setEnabled(state);
        ui->lle7_spinBox->setEnabled(state);

        ui->rle7_slider->setEnabled(state);
        ui->rle7_spinBox->setEnabled(state);
    }
}

void MainWindow::setBodyTypeButtClicked()
{    
    int agentBodyType = ui->agentBodyTypeCbx->currentText().toInt();

    ui->addKeyFrameButt->setEnabled(true);
    ui->deleteKeyFrameButt->setEnabled(true);
    ui->moveKeyFrameDownButt->setEnabled(true);
    ui->moveKeyFrameUpButt->setEnabled(true);
    ui->autoFallRecoverChBx->setEnabled(true);
    ui->actionOpen_motion_file->setEnabled(true);
    ui->actionSave_motion_file->setEnabled(true);
    ui->actionSave_motion_file_as->setEnabled(true);
    ui->resetMonitorButt->setEnabled(true);
    ui->Getup_butt->setEnabled(true);
    ui->playKeyframesButt->setEnabled(true);

    //disable agent body type selection after the user has selected it once
    ui->agentBodyTypeCbx->setEnabled(false);
    ui->setBodyTypeButt->setEnabled(false);

    //allocate sender to server object
    sts = new SenderToServer(agentBodyType);
    sts->start();
}

void MainWindow::resetMonitorButtClicked()
{    
    bResetMonitor = true;
}

void MainWindow::playKeyframeButtClicked()
{
    // Set the keyframes to negative so that all keyframes will executed in order
    sts->lockMutex();
    sts->getBehavior()->resetSkill(SKILL_MOTION_EDITOR);
    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, -1);
    sts->unlockMutex();
}

shared_ptr<KeyFrame> MainWindow::createKeyframe(JointSet &js)
{    
    shared_ptr<KeyFrame> keyframe = shared_ptr<KeyFrame>(new KeyFrame());

    keyframe->setWaitTime(js.keyframeTime);    
    vector<int> effIndices;
    effIndices.push_back(_he1);
    effIndices.push_back(_he2);
    effIndices.push_back(_lae1);
    effIndices.push_back(_lae2);
    effIndices.push_back(_lae3);
    effIndices.push_back(_lae4);
    effIndices.push_back(_rae1);
    effIndices.push_back(_rae2);
    effIndices.push_back(_rae3);
    effIndices.push_back(_rae4);
    effIndices.push_back(_lle1);
    effIndices.push_back(_lle2);
    effIndices.push_back(_lle3);
    effIndices.push_back(_lle4);
    effIndices.push_back(_lle5);
    effIndices.push_back(_lle6);
    effIndices.push_back(_lle7);
    effIndices.push_back(_rle1);
    effIndices.push_back(_rle2);
    effIndices.push_back(_rle3);
    effIndices.push_back(_rle4);
    effIndices.push_back(_rle5);
    effIndices.push_back(_rle6);
    effIndices.push_back(_rle7);

    vector<double> effValues;
    effValues.push_back(js.joints[_he1]);
    effValues.push_back(js.joints[_he2]);
    effValues.push_back(js.joints[_lae1]);
    effValues.push_back(js.joints[_lae2]);
    effValues.push_back(js.joints[_lae3]);
    effValues.push_back(js.joints[_lae4]);
    effValues.push_back(js.joints[_rae1]);
    effValues.push_back(js.joints[_rae2]);
    effValues.push_back(js.joints[_rae3]);
    effValues.push_back(js.joints[_rae4]);
    effValues.push_back(js.joints[_lle1]);
    effValues.push_back(js.joints[_lle2]);
    effValues.push_back(js.joints[_lle3]);
    effValues.push_back(js.joints[_lle4]);
    effValues.push_back(js.joints[_lle5]);
    effValues.push_back(js.joints[_lle6]);
    effValues.push_back(js.joints[_lle7]);
    effValues.push_back(js.joints[_rle1]);
    effValues.push_back(js.joints[_rle2]);
    effValues.push_back(js.joints[_rle3]);
    effValues.push_back(js.joints[_rle4]);
    effValues.push_back(js.joints[_rle5]);
    effValues.push_back(js.joints[_rle6]);
    effValues.push_back(js.joints[_rle7]);
    shared_ptr< Macro > setTarMacro( new SetTar( effIndices, effValues ) );
    keyframe->appendMacro(setTarMacro);
    return keyframe;
}

void MainWindow::addKeyFrameButtClicked()
{
    JointSet js;
    if (!ui->keyframeTimeT->text().isEmpty())
    {
        js.keyframeTime = ui->keyframeTimeT->text().toDouble();
    }
    else
    {
        QMessageBox Msgbox;
        Msgbox.setText("Keyframe time can't be empty!");
        Msgbox.exec();
        return;
    }

    //now insert the new keyframe into the list:
    stringstream ss;
    ss << "Keyframe " << keyFrameStrList.size();

    // The following two lines will add an item to the list view in the motion editor UI window
    keyFrameStrList.append( ss.str().c_str() );
    ((QStringListModel*) ui->keyFramesListView->model())->setStringList(keyFrameStrList);


    //add an item to keyframe sequence list    
    js.keyframeIndex = keyFrameStrList.size()-1;    
    js.joints[_he1] = ui->he1_slider->value();
    js.joints[_he2] = ui->he2_slider->value();
    js.joints[_lae1] = ui->lae1_slider->value();
    js.joints[_lae2] = ui->lae2_slider->value();
    js.joints[_lae3] = ui->lae3_slider->value();
    js.joints[_lae4] = ui->lae4_slider->value();
    js.joints[_rae1] = ui->rae1_slider->value();
    js.joints[_rae2] = ui->rae2_slider->value();
    js.joints[_rae3] = ui->rae3_slider->value();
    js.joints[_rae4] = ui->rae4_slider->value();
    js.joints[_lle1] = ui->lle1_slider->value();
    js.joints[_lle2] = ui->lle2_slider->value();
    js.joints[_lle3] = ui->lle3_slider->value();
    js.joints[_lle4] = ui->lle4_slider->value();
    js.joints[_lle5] = ui->lle5_slider->value();
    js.joints[_lle6] = ui->lle6_slider->value();
    js.joints[_lle7] = ui->lle7_slider->value();
    js.joints[_rle1] = ui->rle1_slider->value();
    js.joints[_rle2] = ui->rle2_slider->value();
    js.joints[_rle3] = ui->rle3_slider->value();
    js.joints[_rle4] = ui->rle4_slider->value();
    js.joints[_rle5] = ui->rle5_slider->value();
    js.joints[_rle6] = ui->rle6_slider->value();
    js.joints[_rle7] = ui->rle7_slider->value();
    keyFrameSequence.push_back(js);

    shared_ptr<KeyFrame> keyframe = createKeyframe(js);

    sts->lockMutex();

    sts->getBehavior()->addKeyframeToSkill(SKILL_MOTION_EDITOR, keyframe);

    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, keyFrameStrList.length()-1);

    keyframe.reset();   // This is done according to comment in skill::editkeyframe

    sts->unlockMutex();
}

void MainWindow::deleteKeyFrameButtClicked()
{
    //link: http://stackoverflow.com/questions/12551889/how-to-remove-an-item-from-a-list-view

    list<int> deletedKeyFramesIndices;

    QModelIndexList selected = ui->keyFramesListView->selectionModel()->selectedIndexes();
    if (selected.isEmpty())
        return;

    sts->lockMutex();

    qSort(selected);
    for (int i = 0; i < selected.count(); i++)
    {
        //save the index of the key frame in deletedKeyFramesIndices list before actually deleting it
        deletedKeyFramesIndices.push_back( selected.at(i).row()-i );

        keyFrameStrList.removeAt(selected.at(i).row()-i);        
    }

    ((QStringListModel*) ui->keyFramesListView->model())->setStringList(keyFrameStrList);

    //delete the items from keyframe sequence list that correspond to the deleted keyframes from keyFrameStrList    
    list<int>::iterator indexIter;
    list<JointSet>::iterator iter;
    for(indexIter = deletedKeyFramesIndices.begin(); indexIter != deletedKeyFramesIndices.end(); indexIter++)
    {
        int keyframeInd = 0;
        for(iter = keyFrameSequence.begin(); iter != keyFrameSequence.end(); iter++, keyframeInd++)
        {
            if(keyframeInd == *indexIter)
            {
                // The keyframe to be deleted has been found so delete it from keyFrameSequence list
                keyFrameSequence.erase(iter);

                // Also delete the corresponding keyframe from SKILL_MOTION_EDITOR
                //QString deletedKeyframeInd(strIter->c_str());
                sts->getBehavior()->deleteKeyframeFromSkill(SKILL_MOTION_EDITOR, keyframeInd);

                break;
            }
        }
    }

    // Disable all the joint controls and tell the motion editor skill to execute all of its
    // keyframes in order, Any better Option?---------------
    SetJointsActivationState(false);
    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, 0);
    //------------------------------------------------------

    sts->unlockMutex();    
}

void MainWindow::moveKeyFrameUpButtClicked()
{}

void MainWindow::moveKeyFrameDownButtClicked()
{}

void MainWindow::keyFrameListViewItemClicked(QModelIndex qmIndex)
{
    //when an item in the keyframe list view is clicked, we must set the joint controls
    //according to the values dictated by the clicked item:

    // Instead of content of the clicked item (string keyframeName( qmIndex.data().toString().toStdString() );)
    // we will use the index of the clicked item:
    int clickedKeyframeIndex = qmIndex.row();


    list<JointSet>::iterator iter;
    int keyframeIndex = 0;
    for(iter = keyFrameSequence.begin(); iter != keyFrameSequence.end(); iter++, keyframeIndex++)
    {
        if(keyframeIndex == clickedKeyframeIndex)
        {
            //the keyframe has been found
            stringstream ss;
            ss << iter->keyframeTime;
            QString timeStr(ss.str().c_str());
            ui->keyframeTimeT->setText(timeStr);
            ui->he1_slider->setValue(iter->joints[_he1]);
            ui->he2_slider->setValue(iter->joints[_he2]);
            ui->lae1_slider->setValue(iter->joints[_lae1]);
            ui->lae2_slider->setValue(iter->joints[_lae2]);
            ui->lae3_slider->setValue(iter->joints[_lae3]);
            ui->lae4_slider->setValue(iter->joints[_lae4]);
            ui->rae1_slider->setValue(iter->joints[_rae1]);
            ui->rae2_slider->setValue(iter->joints[_rae2]);
            ui->rae3_slider->setValue(iter->joints[_rae3]);
            ui->rae4_slider->setValue(iter->joints[_rae4]);
            ui->lle1_slider->setValue(iter->joints[_lle1]);
            ui->lle2_slider->setValue(iter->joints[_lle2]);
            ui->lle3_slider->setValue(iter->joints[_lle3]);
            ui->lle4_slider->setValue(iter->joints[_lle4]);
            ui->lle5_slider->setValue(iter->joints[_lle5]);
            ui->lle6_slider->setValue(iter->joints[_lle6]);
            ui->lle7_slider->setValue(iter->joints[_lle7]);
            ui->rle1_slider->setValue(iter->joints[_rle1]);
            ui->rle2_slider->setValue(iter->joints[_rle2]);
            ui->rle3_slider->setValue(iter->joints[_rle3]);
            ui->rle4_slider->setValue(iter->joints[_rle4]);
            ui->rle5_slider->setValue(iter->joints[_rle5]);
            ui->rle6_slider->setValue(iter->joints[_rle6]);
            ui->rle7_slider->setValue(iter->joints[_rle7]);
            break;
        }
    }

    //enable the joint controls so that the user can edit the keyframe
    SetJointsActivationState(true);

    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, keyframeIndex);
}

void MainWindow::UpdateKeyFrameSequenceEntry(joints jointIndex, double jointVal)
{
    //extract the currently selected keyframe name from the QListView:
    QModelIndex qmInd = ui->keyFramesListView->currentIndex();
    int selectedKeyframeInd = qmInd.row();

    //find the corresponding item in keyframe sequence list and update the appropriate joint value
    list<JointSet>::iterator iter;
    int keyframeIndex = 0;
    for(iter = keyFrameSequence.begin(); iter != keyFrameSequence.end(); iter++, keyframeIndex++)
    {
        if(keyframeIndex == selectedKeyframeInd)
        {
            //the corresponding item has been found
            iter->joints[jointIndex] = jointVal;
            break;
        }
    }   

    shared_ptr<KeyFrame> modifiedKeyframe = createKeyframe(*iter);
    sts->getBehavior()->editSkill(SKILL_MOTION_EDITOR, keyframeIndex, modifiedKeyframe);    


    modifiedKeyframe.reset();   // This is done according to comment in skill::editkeyframe

    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, keyframeIndex);    
}

void MainWindow::UpdateKeyFrameSequenceEntry(double time)
{
    //extract the currently selected keyframe name from the QListView:
    QModelIndex qmInd = ui->keyFramesListView->currentIndex();
    int selectedKeyframeInd = qmInd.row();

    //find the corresponding item in keyframe sequence list and update the time value
    list<JointSet>::iterator iter;
    int keyframeIndex = 0;
    for(iter = keyFrameSequence.begin(); iter != keyFrameSequence.end(); iter++, keyframeIndex++)
    {
        if(keyframeIndex == selectedKeyframeInd)
        {
            //the corresponding item has been found
            iter->keyframeTime = time;
            break;
        }
    }

    shared_ptr<KeyFrame> modifiedKeyframe = createKeyframe(*iter);
    sts->getBehavior()->editSkill(SKILL_MOTION_EDITOR, keyframeIndex, modifiedKeyframe);


    modifiedKeyframe.reset();   // This is done according to comment in skill::editkeyframe

    sts->getBehavior()->setKeyframeToExecuteIndex(SKILL_MOTION_EDITOR, keyframeIndex);
}

void MainWindow::KeyframeTimeTextChanged(QString val)
{
    //update the keyframe time
    double v = 0.001;
    if(val.toDouble() > 0.001)
        v = val.toDouble();

    UpdateKeyFrameSequenceEntry(v);
}
void MainWindow::He1ValChanged(int val)
{    
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_he1, val);
}
void MainWindow::He2ValChanged(int val)
{    
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_he2, val);
}
void MainWindow::Lae1ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lae1, val);
}
void MainWindow::Lae2ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lae2, val);
}
void MainWindow::Lae3ValChanged(int val)
{    
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lae3, val);
}
void MainWindow::Lae4ValChanged(int val)
{    
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lae4, val);
}
void MainWindow::Rae1ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rae1, val);
}
void MainWindow::Rae2ValChanged(int val)
{ 
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rae2, val);
}
void MainWindow::Rae3ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rae3, val);
}
void MainWindow::Rae4ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rae4, val);
}
void MainWindow::Lle1ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle1, val);
}
void MainWindow::Lle2ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle2, val);
}
void MainWindow::Lle3ValChanged(int val)
{ 
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle3, val);
}
void MainWindow::Lle4ValChanged(int val)
{ 
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle4, val);
}
void MainWindow::Lle5ValChanged(int val)
{ 
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle5, val);
}
void MainWindow::Lle6ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle6, val);
}
void MainWindow::Lle7ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_lle7, val);
}
void MainWindow::Rle1ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle1, val);
}
void MainWindow::Rle2ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle2, val);
}
void MainWindow::Rle3ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle3, val);
}
void MainWindow::Rle4ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle4, val);
}
void MainWindow::Rle5ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle5, val);
}
void MainWindow::Rle6ValChanged(int val)
{
    //update the appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle6, val);
}
void MainWindow::Rle7ValChanged(int val)
{
    //update teh appropriate item in keyframe sequence list as well
    UpdateKeyFrameSequenceEntry(_rle7, val);
}

void MainWindow::SaveFileRoboNewbieFormat(string fileName)
{
    stringstream ss;
    ofstream motionFile;
    motionFile.open(fileName.c_str(), ios::trunc | ios::out);
    if(!motionFile)
    {
        ss << "Could not save file " << fileName;
        QString mbtext(ss.str().c_str());
        QMessageBox qmb;
        qmb.setText(mbtext);
        qmb.show();
    }

    list<JointSet>::iterator iter;
    for(iter = keyFrameSequence.begin(); iter != keyFrameSequence.end(); iter++)
    {
        ss.str(""); ss.clear();
        ss << iter->keyframeTime * 1000 << " ";  // save time in miliseconds
        ss << iter->joints[_he1] << " "
           << iter->joints[_he2] << " "
           << iter->joints[_lae1] << " "
           << iter->joints[_lae2] << " "
           << iter->joints[_lae3] << " "
           << iter->joints[_lae4] << " "
           << iter->joints[_lle1] << " "
           << iter->joints[_lle2] << " "
           << iter->joints[_lle3] << " "
           << iter->joints[_lle4] << " "
           << iter->joints[_lle5] << " "
           << iter->joints[_lle6] << " "
           << iter->joints[_rle1] << " "
           << iter->joints[_rle2] << " "
           << iter->joints[_rle3] << " "
           << iter->joints[_rle4] << " "
           << iter->joints[_rle5] << " "
           << iter->joints[_rle6] << " "
           << iter->joints[_rae1] << " "
           << iter->joints[_rae2] << " "
           << iter->joints[_rae3] << " "
           << iter->joints[_rae4] << " "
           << iter->joints[_lle7] << " "        // --| These two lines are not part of RoboNewbie original file format
           << iter->joints[_rle7] << endl;      //---| I've added this so that it will be consistent with UTAustinVilla code
        motionFile << ss.str();
    }
    motionFile.close();
}

joints_robonewbie MainWindow::ServerMsgJntOrderToRbNwBieJntOrder(joints j)
{
    switch(j)
    {
    case _he1:
        return _he1_r;
    case _he2:
        return _he2_r;
    case _lae1:
        return _lae1_r;
    case _lae2:
        return _lae2_r;
    case _lae3:
        return _lae3_r;
    case _lae4:
        return _lae4_r;
    case _lle1:
        return _lle1_r;
    case _lle2:
        return _lle2_r;
    case _lle3:
        return _lle3_r;
    case _lle4:
        return _lle4_r;
    case _lle5:
        return _lle5_r;
    case _lle6:
        return _lle6_r;    
    case _rle1:
        return _rle1_r;
    case _rle2:
        return _rle2_r;
    case _rle3:
        return _rle3_r;
    case _rle4:
        return _rle4_r;
    case _rle5:
        return _rle5_r;
    case _rle6:
        return _rle6_r;
    case _rae1:
        return _rae1_r;
    case _rae2:
        return _rae2_r;
    case _rae3:
        return _rae3_r;
    case _rae4:
        return _rae4_r;
    case _lle7:
        return _lle7_r;
    case _rle7:
        return _rle7_r;
    case JOINT_NUM:
        return _JOINT_NUM_R;
    }
    return (joints_robonewbie) -1;
}

joints MainWindow::RbNwBieJntOrderToServerMsgJntOrder(joints_robonewbie jrb)
{
    switch(jrb)
    {
    case _he1_r:
        return _he1;
    case _he2_r:
        return _he2;
    case _lae1_r:
        return _lae1;
    case _lae2_r:
        return _lae2;
    case _lae3_r:
        return _lae3;
    case _lae4_r:
        return _lae4;
    case _lle1_r:
        return _lle1;
    case _lle2_r:
        return _lle2;
    case _lle3_r:
        return _lle3;
    case _lle4_r:
        return _lle4;
    case _lle5_r:
        return _lle5;
    case _lle6_r:
        return _lle6;
    case _rle1_r:
        return _rle1;
    case _rle2_r:
        return _rle2;
    case _rle3_r:
        return _rle3;
    case _rle4_r:
        return _rle4;
    case _rle5_r:
        return _rle5;
    case _rle6_r:
        return _rle6;
    case _rae1_r:
        return _rae1;
    case _rae2_r:
        return _rae2;
    case _rae3_r:
        return _rae3;
    case _rae4_r:
        return _rae4;
    case _lle7_r:
        return _lle7;
    case _rle7_r:
        return _rle7;
    case _JOINT_NUM_R:
        return JOINT_NUM;
    }
    return (joints) -1;
}

void MainWindow::OpenFileRoboNewbieFormat(string fileName)
{
    ifstream motionFile;
    motionFile.open(fileName.c_str(), ios::in);
    if(!motionFile)
    {
        stringstream ss;
        ss << "Could not open file " << fileName;
        QString mbtext(ss.str().c_str());
        QMessageBox qmb;
        qmb.setText(mbtext);
        qmb.show();
    }

    // Request a lock since we're about to edit skills[SKILL_MOTION_EDITOR] which is used by the other thread
    // running UTAustinVilla NaoBehavior class in sendtoserver.cpp
    sts->lockMutex();

    // Clear the current keyframe list before populating it again from opened file
    keyFrameSequence.clear();
    keyFrameStrList.clear();
    ((QStringListModel*) ui->keyFramesListView->model())->setStringList(keyFrameStrList);

    // Also clear the keyframes of the skill named SKILL_MOTION_EDITOR
    sts->getBehavior()->deleteAllKeyframesFromSkill(SKILL_MOTION_EDITOR);

    //populate the keyframe list using opened file:
    stringstream curSS;
    string curFrameStr;

    int keyframeIndex = 0;
    while(!motionFile.eof())
    {
        getline(motionFile, curFrameStr);
        if(curFrameStr.length() < 22)       //minimal sanity check
            break;
        curSS.str(""); curSS.clear();
        curSS << curFrameStr;

        JointSet js;

        //set keyframe index
        js.keyframeIndex = keyframeIndex++;

        stringstream keyframeName;
        keyframeName.str("");
        keyframeName.clear();
        keyframeName << "Keyframe " << js.keyframeIndex;
        keyFrameStrList.append( keyframeName.str().c_str() );

        //parse current keyframe time
        string timeStr;
        getline(curSS, timeStr, ' ');
        js.keyframeTime = atof(timeStr.c_str()) / 1000.0;     // Convert time from miliseconds to seconds

        //parse the joint values
        string jointStr;
        for(int i = 0; i < _JOINT_NUM_R; i++)
        {
            getline(curSS, jointStr, ' ');
            js.joints[ RbNwBieJntOrderToServerMsgJntOrder( (joints_robonewbie) i) ] = atof( jointStr.c_str() );
        }

        keyFrameSequence.push_back(js);

        // Add the read keyframe to SKILL_MOTION_EDITOR
        shared_ptr<KeyFrame> keyframe = createKeyframe(js);

        sts->getBehavior()->addKeyframeToSkill(SKILL_MOTION_EDITOR, keyframe);        

        keyframe.reset();   // This is done according to comment in skill::editkeyframe        
    }


    // Update keyframe listview as well
    ((QStringListModel*) ui->keyFramesListView->model())->setStringList(keyFrameStrList);

    // Set the first keyframe as the selected one
    QModelIndex currentIndex = ui->keyFramesListView->model()->index(0, 0);
    ui->keyFramesListView->setCurrentIndex(currentIndex);

    // Reset SKILL_MOTION_EDITOR
    sts->getBehavior()->resetSkill(SKILL_MOTION_EDITOR);    

    // Unlock the mutex
    sts->unlockMutex();
}

void MainWindow::OpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"./createdKicks",tr("All Files (*)"));
    //qDebug() << "Opened file: " << fileName;

    if(fileName.length() > 0)       //minimal sanity check
    {
        //set the motionFileName to the one opened by the user so that it could be used later
        //for saving using Ctrl+s shortcut key.
        motionFileName = fileName.toStdString();


        //actually open the specified file
        OpenFileRoboNewbieFormat(motionFileName);
    }
}

void MainWindow::SaveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File As"), "", tr("All Files (*)"));
    if(fileName.length() > 0)
    {
        //overwrite the previous motion file name
        motionFileName = fileName.toStdString();

        //actually save the keyframes in a file with the specified name
        SaveFileRoboNewbieFormat(motionFileName);
    }
}

void MainWindow::SaveFile()
{
    //save the keyframes in a file with the last specified name
    SaveFileRoboNewbieFormat(motionFileName);
}

void MainWindow::About()
{
    //qDebug() << "About pressed";
    CreditWindow *cWindow = new CreditWindow();
    cWindow->setAttribute(Qt::WA_DeleteOnClose);    //delete the credit window as soon as it's closed by the user.
    cWindow->show();
}

