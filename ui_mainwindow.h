/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionOpen_motion_file;
    QAction *actionSave_motion_file_as;
    QAction *actionSave_motion_file;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QSlider *lae4_slider;
    QSpinBox *he1_spinBox;
    QLabel *label_29;
    QSpinBox *rae1_spinBox;
    QLabel *label_15;
    QSpinBox *lae2_spinBox;
    QSlider *he1_slider;
    QLabel *label_21;
    QSlider *he2_slider;
    QSpinBox *lae4_spinBox;
    QLabel *label_26;
    QSpinBox *lle6_spinBox;
    QSlider *lle7_slider;
    QSpinBox *rle1_spinBox;
    QSpinBox *he2_spinBox;
    QLabel *label_22;
    QSpinBox *lle1_spinBox;
    QLabel *label_16;
    QSlider *rle5_slider;
    QSpinBox *rle2_spinBox;
    QLabel *label_11;
    QSpinBox *lae3_spinBox;
    QSlider *lae1_slider;
    QSlider *rle7_slider;
    QSpinBox *lle5_spinBox;
    QSlider *lle4_slider;
    QSlider *rle2_slider;
    QSlider *rae1_slider;
    QLabel *label_12;
    QSpinBox *rae3_spinBox;
    QSpinBox *rle4_spinBox;
    QSlider *rle1_slider;
    QSlider *rle4_slider;
    QLabel *label_27;
    QSpinBox *lle2_spinBox;
    QSpinBox *rle3_spinBox;
    QLabel *label_10;
    QSlider *rle3_slider;
    QSpinBox *lle7_spinBox;
    QSpinBox *lle3_spinBox;
    QSlider *lae2_slider;
    QSpinBox *rle6_spinBox;
    QSpinBox *lle4_spinBox;
    QLabel *label_6;
    QSpinBox *rle5_spinBox;
    QSlider *lle3_slider;
    QSlider *rae2_slider;
    QLabel *label_20;
    QSpinBox *lae1_spinBox;
    QSlider *lle1_slider;
    QLabel *label_28;
    QSlider *lle5_slider;
    QSlider *rae3_slider;
    QLabel *label_9;
    QSpinBox *rae4_spinBox;
    QSlider *lle6_slider;
    QLabel *label_23;
    QLabel *label_14;
    QLabel *label_5;
    QLabel *label_13;
    QSlider *lle2_slider;
    QLabel *label_25;
    QSlider *lae3_slider;
    QSpinBox *rle7_spinBox;
    QLabel *label_18;
    QLabel *label_17;
    QLabel *label_4;
    QLabel *label_19;
    QLabel *label_8;
    QLabel *label_24;
    QSpinBox *rae2_spinBox;
    QSlider *rae4_slider;
    QSlider *rle6_slider;
    QLineEdit *keyframeTimeT;
    QListView *keyFramesListView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *agentBodyTypeCbx;
    QPushButton *setBodyTypeButt;
    QPushButton *addKeyFrameButt;
    QPushButton *deleteKeyFrameButt;
    QPushButton *moveKeyFrameUpButt;
    QPushButton *moveKeyFrameDownButt;
    QPushButton *Getup_butt;
    QPushButton *resetMonitorButt;
    QPushButton *playKeyframesButt;
    QCheckBox *autoFallRecoverChBx;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(591, 1013);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(9);
        MainWindow->setFont(font);
        MainWindow->setWindowTitle(QStringLiteral("aaa"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionOpen_motion_file = new QAction(MainWindow);
        actionOpen_motion_file->setObjectName(QStringLiteral("actionOpen_motion_file"));
        actionOpen_motion_file->setEnabled(false);
        actionSave_motion_file_as = new QAction(MainWindow);
        actionSave_motion_file_as->setObjectName(QStringLiteral("actionSave_motion_file_as"));
        actionSave_motion_file_as->setEnabled(false);
        actionSave_motion_file = new QAction(MainWindow);
        actionSave_motion_file->setObjectName(QStringLiteral("actionSave_motion_file"));
        actionSave_motion_file->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 70, 491, 867));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setHorizontalSpacing(4);
        gridLayout->setVerticalSpacing(6);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lae4_slider = new QSlider(layoutWidget);
        lae4_slider->setObjectName(QStringLiteral("lae4_slider"));
        lae4_slider->setEnabled(false);
        lae4_slider->setMinimum(-90);
        lae4_slider->setMaximum(1);
        lae4_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lae4_slider, 6, 2, 1, 1);

        he1_spinBox = new QSpinBox(layoutWidget);
        he1_spinBox->setObjectName(QStringLiteral("he1_spinBox"));
        he1_spinBox->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(he1_spinBox->sizePolicy().hasHeightForWidth());
        he1_spinBox->setSizePolicy(sizePolicy1);
        he1_spinBox->setMinimum(-120);
        he1_spinBox->setMaximum(120);

        gridLayout->addWidget(he1_spinBox, 1, 1, 1, 1);

        label_29 = new QLabel(layoutWidget);
        label_29->setObjectName(QStringLiteral("label_29"));

        gridLayout->addWidget(label_29, 17, 0, 1, 1);

        rae1_spinBox = new QSpinBox(layoutWidget);
        rae1_spinBox->setObjectName(QStringLiteral("rae1_spinBox"));
        rae1_spinBox->setEnabled(false);
        rae1_spinBox->setMinimum(-120);
        rae1_spinBox->setMaximum(120);

        gridLayout->addWidget(rae1_spinBox, 7, 1, 1, 1);

        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 10, 0, 1, 1);

        lae2_spinBox = new QSpinBox(layoutWidget);
        lae2_spinBox->setObjectName(QStringLiteral("lae2_spinBox"));
        lae2_spinBox->setEnabled(false);
        lae2_spinBox->setMinimum(-1);
        lae2_spinBox->setMaximum(95);

        gridLayout->addWidget(lae2_spinBox, 4, 1, 1, 1);

        he1_slider = new QSlider(layoutWidget);
        he1_slider->setObjectName(QStringLiteral("he1_slider"));
        he1_slider->setEnabled(false);
        he1_slider->setMinimum(-120);
        he1_slider->setMaximum(120);
        he1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(he1_slider, 1, 2, 1, 1);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout->addWidget(label_21, 16, 0, 1, 1);

        he2_slider = new QSlider(layoutWidget);
        he2_slider->setObjectName(QStringLiteral("he2_slider"));
        he2_slider->setEnabled(false);
        he2_slider->setMinimum(-45);
        he2_slider->setMaximum(45);
        he2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(he2_slider, 2, 2, 1, 1);

        lae4_spinBox = new QSpinBox(layoutWidget);
        lae4_spinBox->setObjectName(QStringLiteral("lae4_spinBox"));
        lae4_spinBox->setEnabled(false);
        lae4_spinBox->setMinimum(-90);
        lae4_spinBox->setMaximum(1);

        gridLayout->addWidget(lae4_spinBox, 6, 1, 1, 1);

        label_26 = new QLabel(layoutWidget);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout->addWidget(label_26, 23, 0, 1, 1);

        lle6_spinBox = new QSpinBox(layoutWidget);
        lle6_spinBox->setObjectName(QStringLiteral("lle6_spinBox"));
        lle6_spinBox->setEnabled(false);
        lle6_spinBox->setMinimum(-45);
        lle6_spinBox->setMaximum(25);

        gridLayout->addWidget(lle6_spinBox, 16, 1, 1, 1);

        lle7_slider = new QSlider(layoutWidget);
        lle7_slider->setObjectName(QStringLiteral("lle7_slider"));
        lle7_slider->setEnabled(false);
        lle7_slider->setMinimum(-1);
        lle7_slider->setMaximum(70);
        lle7_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle7_slider, 17, 2, 1, 1);

        rle1_spinBox = new QSpinBox(layoutWidget);
        rle1_spinBox->setObjectName(QStringLiteral("rle1_spinBox"));
        rle1_spinBox->setEnabled(false);
        rle1_spinBox->setMinimum(-90);
        rle1_spinBox->setMaximum(1);

        gridLayout->addWidget(rle1_spinBox, 18, 1, 1, 1);

        he2_spinBox = new QSpinBox(layoutWidget);
        he2_spinBox->setObjectName(QStringLiteral("he2_spinBox"));
        he2_spinBox->setEnabled(false);
        he2_spinBox->setMinimum(-45);
        he2_spinBox->setMaximum(45);

        gridLayout->addWidget(he2_spinBox, 2, 1, 1, 1);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout->addWidget(label_22, 18, 0, 1, 1);

        lle1_spinBox = new QSpinBox(layoutWidget);
        lle1_spinBox->setObjectName(QStringLiteral("lle1_spinBox"));
        lle1_spinBox->setEnabled(false);
        lle1_spinBox->setMinimum(-90);
        lle1_spinBox->setMaximum(1);

        gridLayout->addWidget(lle1_spinBox, 11, 1, 1, 1);

        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 11, 0, 1, 1);

        rle5_slider = new QSlider(layoutWidget);
        rle5_slider->setObjectName(QStringLiteral("rle5_slider"));
        rle5_slider->setEnabled(false);
        rle5_slider->setMinimum(-45);
        rle5_slider->setMaximum(75);
        rle5_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle5_slider, 22, 2, 1, 1);

        rle2_spinBox = new QSpinBox(layoutWidget);
        rle2_spinBox->setObjectName(QStringLiteral("rle2_spinBox"));
        rle2_spinBox->setEnabled(false);
        rle2_spinBox->setMinimum(-45);
        rle2_spinBox->setMaximum(25);

        gridLayout->addWidget(rle2_spinBox, 19, 1, 1, 1);

        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 6, 0, 1, 1);

        lae3_spinBox = new QSpinBox(layoutWidget);
        lae3_spinBox->setObjectName(QStringLiteral("lae3_spinBox"));
        lae3_spinBox->setEnabled(false);
        lae3_spinBox->setMinimum(-120);
        lae3_spinBox->setMaximum(120);

        gridLayout->addWidget(lae3_spinBox, 5, 1, 1, 1);

        lae1_slider = new QSlider(layoutWidget);
        lae1_slider->setObjectName(QStringLiteral("lae1_slider"));
        lae1_slider->setEnabled(false);
        lae1_slider->setMinimum(-120);
        lae1_slider->setMaximum(120);
        lae1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lae1_slider, 3, 2, 1, 1);

        rle7_slider = new QSlider(layoutWidget);
        rle7_slider->setObjectName(QStringLiteral("rle7_slider"));
        rle7_slider->setEnabled(false);
        rle7_slider->setMinimum(-1);
        rle7_slider->setMaximum(70);
        rle7_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle7_slider, 24, 2, 1, 1);

        lle5_spinBox = new QSpinBox(layoutWidget);
        lle5_spinBox->setObjectName(QStringLiteral("lle5_spinBox"));
        lle5_spinBox->setEnabled(false);
        lle5_spinBox->setMinimum(-45);
        lle5_spinBox->setMaximum(75);

        gridLayout->addWidget(lle5_spinBox, 15, 1, 1, 1);

        lle4_slider = new QSlider(layoutWidget);
        lle4_slider->setObjectName(QStringLiteral("lle4_slider"));
        lle4_slider->setEnabled(false);
        lle4_slider->setMinimum(-130);
        lle4_slider->setMaximum(1);
        lle4_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle4_slider, 14, 2, 1, 1);

        rle2_slider = new QSlider(layoutWidget);
        rle2_slider->setObjectName(QStringLiteral("rle2_slider"));
        rle2_slider->setEnabled(false);
        rle2_slider->setMinimum(-45);
        rle2_slider->setMaximum(25);
        rle2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle2_slider, 19, 2, 1, 1);

        rae1_slider = new QSlider(layoutWidget);
        rae1_slider->setObjectName(QStringLiteral("rae1_slider"));
        rae1_slider->setEnabled(false);
        rae1_slider->setMinimum(-120);
        rae1_slider->setMaximum(120);
        rae1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rae1_slider, 7, 2, 1, 1);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 7, 0, 1, 1);

        rae3_spinBox = new QSpinBox(layoutWidget);
        rae3_spinBox->setObjectName(QStringLiteral("rae3_spinBox"));
        rae3_spinBox->setEnabled(false);
        rae3_spinBox->setMinimum(-120);
        rae3_spinBox->setMaximum(120);

        gridLayout->addWidget(rae3_spinBox, 9, 1, 1, 1);

        rle4_spinBox = new QSpinBox(layoutWidget);
        rle4_spinBox->setObjectName(QStringLiteral("rle4_spinBox"));
        rle4_spinBox->setEnabled(false);
        rle4_spinBox->setMinimum(-130);
        rle4_spinBox->setMaximum(1);

        gridLayout->addWidget(rle4_spinBox, 21, 1, 1, 1);

        rle1_slider = new QSlider(layoutWidget);
        rle1_slider->setObjectName(QStringLiteral("rle1_slider"));
        rle1_slider->setEnabled(false);
        rle1_slider->setMinimum(-90);
        rle1_slider->setMaximum(1);
        rle1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle1_slider, 18, 2, 1, 1);

        rle4_slider = new QSlider(layoutWidget);
        rle4_slider->setObjectName(QStringLiteral("rle4_slider"));
        rle4_slider->setEnabled(false);
        rle4_slider->setMinimum(-130);
        rle4_slider->setMaximum(1);
        rle4_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle4_slider, 21, 2, 1, 1);

        label_27 = new QLabel(layoutWidget);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout->addWidget(label_27, 24, 0, 1, 1);

        lle2_spinBox = new QSpinBox(layoutWidget);
        lle2_spinBox->setObjectName(QStringLiteral("lle2_spinBox"));
        lle2_spinBox->setEnabled(false);
        lle2_spinBox->setMinimum(-25);
        lle2_spinBox->setMaximum(45);

        gridLayout->addWidget(lle2_spinBox, 12, 1, 1, 1);

        rle3_spinBox = new QSpinBox(layoutWidget);
        rle3_spinBox->setObjectName(QStringLiteral("rle3_spinBox"));
        rle3_spinBox->setEnabled(false);
        rle3_spinBox->setMinimum(-25);
        rle3_spinBox->setMaximum(100);

        gridLayout->addWidget(rle3_spinBox, 20, 1, 1, 1);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 5, 0, 1, 1);

        rle3_slider = new QSlider(layoutWidget);
        rle3_slider->setObjectName(QStringLiteral("rle3_slider"));
        rle3_slider->setMinimum(-25);
        rle3_slider->setMaximum(100);
        rle3_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle3_slider, 20, 2, 1, 1);

        lle7_spinBox = new QSpinBox(layoutWidget);
        lle7_spinBox->setObjectName(QStringLiteral("lle7_spinBox"));
        lle7_spinBox->setEnabled(false);
        lle7_spinBox->setMinimum(-1);
        lle7_spinBox->setMaximum(70);

        gridLayout->addWidget(lle7_spinBox, 17, 1, 1, 1);

        lle3_spinBox = new QSpinBox(layoutWidget);
        lle3_spinBox->setObjectName(QStringLiteral("lle3_spinBox"));
        lle3_spinBox->setEnabled(false);
        lle3_spinBox->setMinimum(-25);
        lle3_spinBox->setMaximum(100);

        gridLayout->addWidget(lle3_spinBox, 13, 1, 1, 1);

        lae2_slider = new QSlider(layoutWidget);
        lae2_slider->setObjectName(QStringLiteral("lae2_slider"));
        lae2_slider->setEnabled(false);
        lae2_slider->setMinimum(-1);
        lae2_slider->setMaximum(95);
        lae2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lae2_slider, 4, 2, 1, 1);

        rle6_spinBox = new QSpinBox(layoutWidget);
        rle6_spinBox->setObjectName(QStringLiteral("rle6_spinBox"));
        rle6_spinBox->setEnabled(false);
        rle6_spinBox->setMinimum(-25);
        rle6_spinBox->setMaximum(45);

        gridLayout->addWidget(rle6_spinBox, 23, 1, 1, 1);

        lle4_spinBox = new QSpinBox(layoutWidget);
        lle4_spinBox->setObjectName(QStringLiteral("lle4_spinBox"));
        lle4_spinBox->setEnabled(false);
        lle4_spinBox->setMinimum(-130);
        lle4_spinBox->setMaximum(1);

        gridLayout->addWidget(lle4_spinBox, 14, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        rle5_spinBox = new QSpinBox(layoutWidget);
        rle5_spinBox->setObjectName(QStringLiteral("rle5_spinBox"));
        rle5_spinBox->setEnabled(false);
        rle5_spinBox->setMinimum(-45);
        rle5_spinBox->setMaximum(75);

        gridLayout->addWidget(rle5_spinBox, 22, 1, 1, 1);

        lle3_slider = new QSlider(layoutWidget);
        lle3_slider->setObjectName(QStringLiteral("lle3_slider"));
        lle3_slider->setEnabled(false);
        lle3_slider->setMinimum(-25);
        lle3_slider->setMaximum(100);
        lle3_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle3_slider, 13, 2, 1, 1);

        rae2_slider = new QSlider(layoutWidget);
        rae2_slider->setObjectName(QStringLiteral("rae2_slider"));
        rae2_slider->setEnabled(false);
        rae2_slider->setMinimum(-95);
        rae2_slider->setMaximum(1);
        rae2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rae2_slider, 8, 2, 1, 1);

        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout->addWidget(label_20, 15, 0, 1, 1);

        lae1_spinBox = new QSpinBox(layoutWidget);
        lae1_spinBox->setObjectName(QStringLiteral("lae1_spinBox"));
        lae1_spinBox->setEnabled(false);
        lae1_spinBox->setMinimum(-120);
        lae1_spinBox->setMaximum(120);

        gridLayout->addWidget(lae1_spinBox, 3, 1, 1, 1);

        lle1_slider = new QSlider(layoutWidget);
        lle1_slider->setObjectName(QStringLiteral("lle1_slider"));
        lle1_slider->setEnabled(false);
        lle1_slider->setMinimum(-90);
        lle1_slider->setMaximum(1);
        lle1_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle1_slider, 11, 2, 1, 1);

        label_28 = new QLabel(layoutWidget);
        label_28->setObjectName(QStringLiteral("label_28"));

        gridLayout->addWidget(label_28, 22, 0, 1, 1);

        lle5_slider = new QSlider(layoutWidget);
        lle5_slider->setObjectName(QStringLiteral("lle5_slider"));
        lle5_slider->setEnabled(false);
        lle5_slider->setMinimum(-45);
        lle5_slider->setMaximum(75);
        lle5_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle5_slider, 15, 2, 1, 1);

        rae3_slider = new QSlider(layoutWidget);
        rae3_slider->setObjectName(QStringLiteral("rae3_slider"));
        rae3_slider->setEnabled(false);
        rae3_slider->setMinimum(-120);
        rae3_slider->setMaximum(120);
        rae3_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rae3_slider, 9, 2, 1, 1);

        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        rae4_spinBox = new QSpinBox(layoutWidget);
        rae4_spinBox->setObjectName(QStringLiteral("rae4_spinBox"));
        rae4_spinBox->setEnabled(false);
        rae4_spinBox->setMinimum(-1);
        rae4_spinBox->setMaximum(90);

        gridLayout->addWidget(rae4_spinBox, 10, 1, 1, 1);

        lle6_slider = new QSlider(layoutWidget);
        lle6_slider->setObjectName(QStringLiteral("lle6_slider"));
        lle6_slider->setEnabled(false);
        lle6_slider->setMinimum(-45);
        lle6_slider->setMaximum(25);
        lle6_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle6_slider, 16, 2, 1, 1);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout->addWidget(label_23, 19, 0, 1, 1);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 9, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 8, 0, 1, 1);

        lle2_slider = new QSlider(layoutWidget);
        lle2_slider->setObjectName(QStringLiteral("lle2_slider"));
        lle2_slider->setEnabled(false);
        lle2_slider->setMinimum(-25);
        lle2_slider->setMaximum(45);
        lle2_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lle2_slider, 12, 2, 1, 1);

        label_25 = new QLabel(layoutWidget);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout->addWidget(label_25, 21, 0, 1, 1);

        lae3_slider = new QSlider(layoutWidget);
        lae3_slider->setObjectName(QStringLiteral("lae3_slider"));
        lae3_slider->setEnabled(false);
        lae3_slider->setMinimum(-120);
        lae3_slider->setMaximum(120);
        lae3_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(lae3_slider, 5, 2, 1, 1);

        rle7_spinBox = new QSpinBox(layoutWidget);
        rle7_spinBox->setObjectName(QStringLiteral("rle7_spinBox"));
        rle7_spinBox->setEnabled(false);
        rle7_spinBox->setMinimum(-1);
        rle7_spinBox->setMaximum(70);

        gridLayout->addWidget(rle7_spinBox, 24, 1, 1, 1);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout->addWidget(label_18, 13, 0, 1, 1);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 12, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout->addWidget(label_19, 14, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_24 = new QLabel(layoutWidget);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout->addWidget(label_24, 20, 0, 1, 1);

        rae2_spinBox = new QSpinBox(layoutWidget);
        rae2_spinBox->setObjectName(QStringLiteral("rae2_spinBox"));
        rae2_spinBox->setEnabled(false);
        rae2_spinBox->setMinimum(-95);
        rae2_spinBox->setMaximum(1);

        gridLayout->addWidget(rae2_spinBox, 8, 1, 1, 1);

        rae4_slider = new QSlider(layoutWidget);
        rae4_slider->setObjectName(QStringLiteral("rae4_slider"));
        rae4_slider->setEnabled(false);
        rae4_slider->setMinimum(-1);
        rae4_slider->setMaximum(90);
        rae4_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rae4_slider, 10, 2, 1, 1);

        rle6_slider = new QSlider(layoutWidget);
        rle6_slider->setObjectName(QStringLiteral("rle6_slider"));
        rle6_slider->setEnabled(false);
        rle6_slider->setMinimum(-25);
        rle6_slider->setMaximum(45);
        rle6_slider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(rle6_slider, 23, 2, 1, 1);

        keyframeTimeT = new QLineEdit(layoutWidget);
        keyframeTimeT->setObjectName(QStringLiteral("keyframeTimeT"));
        keyframeTimeT->setEnabled(false);
        sizePolicy1.setHeightForWidth(keyframeTimeT->sizePolicy().hasHeightForWidth());
        keyframeTimeT->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(keyframeTimeT, 0, 1, 1, 1);

        keyFramesListView = new QListView(centralWidget);
        keyFramesListView->setObjectName(QStringLiteral("keyFramesListView"));
        keyFramesListView->setGeometry(QRect(10, 70, 71, 631));
        keyFramesListView->setSelectionMode(QAbstractItemView::SingleSelection);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, -2, 271, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        agentBodyTypeCbx = new QComboBox(layoutWidget1);
        agentBodyTypeCbx->setObjectName(QStringLiteral("agentBodyTypeCbx"));

        horizontalLayout->addWidget(agentBodyTypeCbx);

        setBodyTypeButt = new QPushButton(layoutWidget1);
        setBodyTypeButt->setObjectName(QStringLiteral("setBodyTypeButt"));

        horizontalLayout->addWidget(setBodyTypeButt);

        addKeyFrameButt = new QPushButton(centralWidget);
        addKeyFrameButt->setObjectName(QStringLiteral("addKeyFrameButt"));
        addKeyFrameButt->setEnabled(false);
        addKeyFrameButt->setGeometry(QRect(10, 50, 20, 20));
        QIcon icon;
        icon.addFile(QStringLiteral("icon32x32/add-icon32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        addKeyFrameButt->setIcon(icon);
        deleteKeyFrameButt = new QPushButton(centralWidget);
        deleteKeyFrameButt->setObjectName(QStringLiteral("deleteKeyFrameButt"));
        deleteKeyFrameButt->setEnabled(false);
        deleteKeyFrameButt->setGeometry(QRect(30, 50, 20, 20));
        QIcon icon1;
        icon1.addFile(QStringLiteral("icon32x32/Close-2-icon32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteKeyFrameButt->setIcon(icon1);
        moveKeyFrameUpButt = new QPushButton(centralWidget);
        moveKeyFrameUpButt->setObjectName(QStringLiteral("moveKeyFrameUpButt"));
        moveKeyFrameUpButt->setEnabled(false);
        moveKeyFrameUpButt->setGeometry(QRect(50, 50, 20, 20));
        QIcon icon2;
        icon2.addFile(QStringLiteral("icon32x32/Arrows-Up-icon32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveKeyFrameUpButt->setIcon(icon2);
        moveKeyFrameDownButt = new QPushButton(centralWidget);
        moveKeyFrameDownButt->setObjectName(QStringLiteral("moveKeyFrameDownButt"));
        moveKeyFrameDownButt->setEnabled(false);
        moveKeyFrameDownButt->setGeometry(QRect(70, 50, 20, 20));
        QIcon icon3;
        icon3.addFile(QStringLiteral("icon32x32/Arrows-Down-icon32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        moveKeyFrameDownButt->setIcon(icon3);
        Getup_butt = new QPushButton(centralWidget);
        Getup_butt->setObjectName(QStringLiteral("Getup_butt"));
        Getup_butt->setEnabled(false);
        Getup_butt->setGeometry(QRect(70, 26, 20, 25));
        QIcon icon4;
        icon4.addFile(QStringLiteral("icon32x32/getup512x512.png"), QSize(), QIcon::Normal, QIcon::Off);
        Getup_butt->setIcon(icon4);
        resetMonitorButt = new QPushButton(centralWidget);
        resetMonitorButt->setObjectName(QStringLiteral("resetMonitorButt"));
        resetMonitorButt->setEnabled(false);
        resetMonitorButt->setGeometry(QRect(10, 26, 40, 25));
        QIcon icon5;
        icon5.addFile(QStringLiteral("icon32x32/reset-icon32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        resetMonitorButt->setIcon(icon5);
        playKeyframesButt = new QPushButton(centralWidget);
        playKeyframesButt->setObjectName(QStringLiteral("playKeyframesButt"));
        playKeyframesButt->setEnabled(false);
        playKeyframesButt->setGeometry(QRect(50, 26, 20, 25));
        QIcon icon6;
        icon6.addFile(QStringLiteral("icon32x32/play-icon-32x32.png"), QSize(), QIcon::Normal, QIcon::Off);
        playKeyframesButt->setIcon(icon6);
        playKeyframesButt->setIconSize(QSize(16, 16));
        autoFallRecoverChBx = new QCheckBox(centralWidget);
        autoFallRecoverChBx->setObjectName(QStringLiteral("autoFallRecoverChBx"));
        autoFallRecoverChBx->setEnabled(false);
        autoFallRecoverChBx->setGeometry(QRect(90, 30, 160, 23));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());

        // Thanks to my good friend Daruish Hasanpoor for the nice hint...
        // The following line is added so that the motion editor menu items will
        // be displayed correctly on machines with no Qt IDE installed.
        menuBar->setNativeMenuBar(false);
        // ...............................................................

        menuFile->addAction(actionOpen_motion_file);
        menuFile->addAction(actionSave_motion_file);
        menuFile->addAction(actionSave_motion_file_as);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionOpen_motion_file->setText(QApplication::translate("MainWindow", "Open motion file", 0));
        actionOpen_motion_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0));
        actionSave_motion_file_as->setText(QApplication::translate("MainWindow", "Save motion file as", 0));
        actionSave_motion_file->setText(QApplication::translate("MainWindow", "Save motion file", 0));
        actionSave_motion_file->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        label_29->setText(QApplication::translate("MainWindow", "Left Toe", 0));
        label_15->setText(QApplication::translate("MainWindow", "Right Elbow Roll", 0));
        label_21->setText(QApplication::translate("MainWindow", "Left Ankle Roll", 0));
        label_26->setText(QApplication::translate("MainWindow", "Right Ankle Roll", 0));
        label_22->setText(QApplication::translate("MainWindow", "Right Hip Yaw-Pitch", 0));
        label_16->setText(QApplication::translate("MainWindow", "Left Hip Yaw-Pitch", 0));
        label_11->setText(QApplication::translate("MainWindow", "Left Elbow Roll", 0));
        label_12->setText(QApplication::translate("MainWindow", "Right Shoulder Pitch", 0));
        label_27->setText(QApplication::translate("MainWindow", "Right Toe", 0));
        label_10->setText(QApplication::translate("MainWindow", "Left Elbow Yaw", 0));
        label_6->setText(QApplication::translate("MainWindow", "Head Pitch", 0));
        label_20->setText(QApplication::translate("MainWindow", "Left Ankle Pitch", 0));
        label_28->setText(QApplication::translate("MainWindow", "Right Ankle Pitch", 0));
        label_9->setText(QApplication::translate("MainWindow", "Left Shoulder Roll", 0));
        label_23->setText(QApplication::translate("MainWindow", "Right Hip Roll", 0));
        label_14->setText(QApplication::translate("MainWindow", "Right Elbow Yaw", 0));
        label_5->setText(QApplication::translate("MainWindow", "Keyframe Time (sec)", 0));
        label_13->setText(QApplication::translate("MainWindow", "Right Shoulder Roll", 0));
        label_25->setText(QApplication::translate("MainWindow", "Right Knee Pitch", 0));
        label_18->setText(QApplication::translate("MainWindow", "Left Hip Pitch", 0));
        label_17->setText(QApplication::translate("MainWindow", "Left Hip Roll", 0));
        label_4->setText(QApplication::translate("MainWindow", "Head Yaw", 0));
        label_19->setText(QApplication::translate("MainWindow", "Left Knee Pitch", 0));
        label_8->setText(QApplication::translate("MainWindow", "Left Shoulder Pitch", 0));
        label_24->setText(QApplication::translate("MainWindow", "Right Hip Pitch", 0));
        keyframeTimeT->setText(QApplication::translate("MainWindow", "0.5", 0));
        label->setText(QApplication::translate("MainWindow", "Agent body type", 0));
        agentBodyTypeCbx->clear();
        agentBodyTypeCbx->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0)
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
        );
        setBodyTypeButt->setText(QApplication::translate("MainWindow", "Set Body Type", 0));
#ifndef QT_NO_TOOLTIP
        addKeyFrameButt->setToolTip(QApplication::translate("MainWindow", "Add a new keyframe", 0));
#endif // QT_NO_TOOLTIP
        addKeyFrameButt->setText(QString());
#ifndef QT_NO_TOOLTIP
        deleteKeyFrameButt->setToolTip(QApplication::translate("MainWindow", "Delete a keyframe", 0));
#endif // QT_NO_TOOLTIP
        deleteKeyFrameButt->setText(QString());
        moveKeyFrameUpButt->setText(QString());
        moveKeyFrameDownButt->setText(QString());
#ifndef QT_NO_TOOLTIP
        Getup_butt->setToolTip(QApplication::translate("MainWindow", "Get up", 0));
#endif // QT_NO_TOOLTIP
        Getup_butt->setText(QString());
#ifndef QT_NO_TOOLTIP
        resetMonitorButt->setToolTip(QApplication::translate("MainWindow", "Reset monitor", 0));
#endif // QT_NO_TOOLTIP
        resetMonitorButt->setText(QString());
#ifndef QT_NO_TOOLTIP
        playKeyframesButt->setToolTip(QApplication::translate("MainWindow", "Play all keyframes in order", 0));
#endif // QT_NO_TOOLTIP
        playKeyframesButt->setText(QString());
        autoFallRecoverChBx->setText(QApplication::translate("MainWindow", "Auto Fall Recovery", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
