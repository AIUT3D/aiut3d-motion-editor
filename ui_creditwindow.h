/********************************************************************************
** Form generated from reading UI file 'creditwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREDITWINDOW_H
#define UI_CREDITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreditWindow
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *UTAustinVilla_URL_label;
    QLabel *label_2;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CreditWindow)
    {
        if (CreditWindow->objectName().isEmpty())
            CreditWindow->setObjectName(QStringLiteral("CreditWindow"));
        CreditWindow->resize(400, 300);
        verticalLayout = new QVBoxLayout(CreditWindow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_3 = new QLabel(CreditWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(150, 150));
        label_3->setPixmap(QPixmap(QString::fromUtf8("credit-logo/IUT.png")));
        label_3->setScaledContents(true);

        verticalLayout_4->addWidget(label_3, 0, Qt::AlignHCenter);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        label = new QLabel(CreditWindow);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_4->addWidget(label, 0, Qt::AlignHCenter);

        label_4 = new QLabel(CreditWindow);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4, 0, Qt::AlignHCenter);

        UTAustinVilla_URL_label = new QLabel(CreditWindow);
        UTAustinVilla_URL_label->setObjectName(QStringLiteral("UTAustinVilla_URL_label"));
        UTAustinVilla_URL_label->setTextFormat(Qt::PlainText);

        verticalLayout_4->addWidget(UTAustinVilla_URL_label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(CreditWindow);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_4->addWidget(label_2, 0, Qt::AlignHCenter);

        label_5 = new QLabel(CreditWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));

        verticalLayout_4->addWidget(label_5, 0, Qt::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout->addLayout(verticalLayout_4);


        retranslateUi(CreditWindow);

        QMetaObject::connectSlotsByName(CreditWindow);
    } // setupUi

    void retranslateUi(QWidget *CreditWindow)
    {
        CreditWindow->setWindowTitle(QApplication::translate("CreditWindow", "AIUT3D Motion Editor Credit", 0));
        label_3->setText(QString());
        label->setText(QApplication::translate("CreditWindow", "AIUT3D Motion Editor", 0));
        label_4->setText(QApplication::translate("CreditWindow", "Based on UTAustinVilla base code release:", 0));
        UTAustinVilla_URL_label->setText(QApplication::translate("CreditWindow", "http://www.cs.utexas.edu/~AustinVilla/sim/3dsimulation/", 0));
        label_2->setText(QApplication::translate("CreditWindow", "Developer: Navid Hoseini Izadi", 0));
        label_5->setText(QApplication::translate("CreditWindow", "Contact: hhnavid@yahoo.com", 0));
    } // retranslateUi

};

namespace Ui {
    class CreditWindow: public Ui_CreditWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREDITWINDOW_H
