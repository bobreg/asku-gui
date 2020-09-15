/********************************************************************************
** Form generated from reading UI file 'deses.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESES_H
#define UI_DESES_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgDeses
{
public:
    QGridLayout *gridLayout_7;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupPorts;
    QGridLayout *gridLayout;
    QLineEdit *port1BadData;
    QLabel *textLabelPort;
    QLabel *textLabelPort1;
    QLabel *textLabelPort2;
    QLabel *textPortOpen;
    QLineEdit *port1Opened;
    QLineEdit *port2Opened;
    QLabel *textPortActive;
    QLineEdit *port1Active;
    QLineEdit *port2Active;
    QLabel *textPortFail;
    QLineEdit *port1Fail;
    QLineEdit *port2Fail;
    QLabel *textPortNoData;
    QLineEdit *port1NoData;
    QLineEdit *port2NoData;
    QLabel *textPortBadData;
    QLineEdit *port2BadData;
    QGroupBox *groupRegime;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkRegime1;
    QCheckBox *checkRegime2;
    QCheckBox *checkRegime3;
    QCheckBox *checkRegime4;
    QCheckBox *checkRegime5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutMains1;
    QGroupBox *groupMains;
    QGridLayout *gridLayout_5;
    QLabel *textWorkMn1;
    QLineEdit *mnWork1;
    QLabel *textRegimeMn1;
    QLineEdit *mnRegime1;
    QSpacerItem *horizontalSpacerMains1;
    QGroupBox *groupMainsMB;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushOffMB1;
    QPushButton *pushOnMB1;
    QGroupBox *groupMainsReset;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushResetMns1;
    QFrame *line;
    QGridLayout *gridLayoutDg1;
    QGroupBox *groupDg1Run;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushOffEngine1;
    QPushButton *pushOnEngine1;
    QGroupBox *groupDg1;
    QGridLayout *gridLayout_3;
    QLabel *textWorkDg1;
    QLineEdit *dgWork1;
    QLabel *textRegimeDg1;
    QLineEdit *dgRegime1;
    QGroupBox *groupDg1Reset;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushResetDgs1;
    QGroupBox *groupDg1GB;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushOffGB1;
    QPushButton *pushOnGB1;
    QFrame *line_2;
    QGridLayout *gridLayoutDg2;
    QGroupBox *groupDg2Reset;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushResetDgs2;
    QGroupBox *groupDg2Run;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushOffEngine2;
    QPushButton *pushOnEngine2;
    QGroupBox *groupDg2;
    QGridLayout *gridLayout_4;
    QLabel *textWorkDg2;
    QLineEdit *dgWork2;
    QLabel *textRegimeDg2;
    QLineEdit *dgRegime2;
    QGroupBox *groupDg2GB;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushOffGB2;
    QPushButton *pushOnGB2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgDeses)
    {
        if (DlgDeses->objectName().isEmpty())
            DlgDeses->setObjectName(QString::fromUtf8("DlgDeses"));
        DlgDeses->resize(923, 379);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgDeses->sizePolicy().hasHeightForWidth());
        DlgDeses->setSizePolicy(sizePolicy);
        gridLayout_7 = new QGridLayout(DlgDeses);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupPorts = new QGroupBox(DlgDeses);
        groupPorts->setObjectName(QString::fromUtf8("groupPorts"));
        gridLayout = new QGridLayout(groupPorts);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        port1BadData = new QLineEdit(groupPorts);
        port1BadData->setObjectName(QString::fromUtf8("port1BadData"));
        port1BadData->setEnabled(true);
        port1BadData->setMinimumSize(QSize(40, 0));
        port1BadData->setMaximumSize(QSize(40, 32767));
        port1BadData->setAlignment(Qt::AlignCenter);
        port1BadData->setReadOnly(true);

        gridLayout->addWidget(port1BadData, 5, 1, 1, 1);

        textLabelPort = new QLabel(groupPorts);
        textLabelPort->setObjectName(QString::fromUtf8("textLabelPort"));
        textLabelPort->setWordWrap(false);

        gridLayout->addWidget(textLabelPort, 0, 0, 1, 1);

        textLabelPort1 = new QLabel(groupPorts);
        textLabelPort1->setObjectName(QString::fromUtf8("textLabelPort1"));
        textLabelPort1->setAlignment(Qt::AlignCenter);
        textLabelPort1->setWordWrap(false);

        gridLayout->addWidget(textLabelPort1, 0, 1, 1, 1);

        textLabelPort2 = new QLabel(groupPorts);
        textLabelPort2->setObjectName(QString::fromUtf8("textLabelPort2"));
        textLabelPort2->setAlignment(Qt::AlignCenter);
        textLabelPort2->setWordWrap(false);

        gridLayout->addWidget(textLabelPort2, 0, 2, 1, 1);

        textPortOpen = new QLabel(groupPorts);
        textPortOpen->setObjectName(QString::fromUtf8("textPortOpen"));
        textPortOpen->setWordWrap(false);

        gridLayout->addWidget(textPortOpen, 1, 0, 1, 1);

        port1Opened = new QLineEdit(groupPorts);
        port1Opened->setObjectName(QString::fromUtf8("port1Opened"));
        port1Opened->setEnabled(true);
        port1Opened->setMinimumSize(QSize(40, 0));
        port1Opened->setMaximumSize(QSize(40, 32767));
        port1Opened->setAlignment(Qt::AlignCenter);
        port1Opened->setReadOnly(true);

        gridLayout->addWidget(port1Opened, 1, 1, 1, 1);

        port2Opened = new QLineEdit(groupPorts);
        port2Opened->setObjectName(QString::fromUtf8("port2Opened"));
        port2Opened->setEnabled(true);
        port2Opened->setMinimumSize(QSize(40, 0));
        port2Opened->setMaximumSize(QSize(40, 32767));
        port2Opened->setAlignment(Qt::AlignCenter);
        port2Opened->setReadOnly(true);

        gridLayout->addWidget(port2Opened, 1, 2, 1, 1);

        textPortActive = new QLabel(groupPorts);
        textPortActive->setObjectName(QString::fromUtf8("textPortActive"));
        textPortActive->setWordWrap(false);

        gridLayout->addWidget(textPortActive, 2, 0, 1, 1);

        port1Active = new QLineEdit(groupPorts);
        port1Active->setObjectName(QString::fromUtf8("port1Active"));
        port1Active->setEnabled(true);
        port1Active->setMinimumSize(QSize(40, 0));
        port1Active->setMaximumSize(QSize(40, 32767));
        port1Active->setAlignment(Qt::AlignCenter);
        port1Active->setReadOnly(true);

        gridLayout->addWidget(port1Active, 2, 1, 1, 1);

        port2Active = new QLineEdit(groupPorts);
        port2Active->setObjectName(QString::fromUtf8("port2Active"));
        port2Active->setEnabled(true);
        port2Active->setMinimumSize(QSize(40, 0));
        port2Active->setMaximumSize(QSize(40, 32767));
        port2Active->setAlignment(Qt::AlignCenter);
        port2Active->setReadOnly(true);

        gridLayout->addWidget(port2Active, 2, 2, 1, 1);

        textPortFail = new QLabel(groupPorts);
        textPortFail->setObjectName(QString::fromUtf8("textPortFail"));
        textPortFail->setWordWrap(false);

        gridLayout->addWidget(textPortFail, 3, 0, 1, 1);

        port1Fail = new QLineEdit(groupPorts);
        port1Fail->setObjectName(QString::fromUtf8("port1Fail"));
        port1Fail->setEnabled(true);
        port1Fail->setMinimumSize(QSize(40, 0));
        port1Fail->setMaximumSize(QSize(40, 32767));
        port1Fail->setAlignment(Qt::AlignCenter);
        port1Fail->setReadOnly(true);

        gridLayout->addWidget(port1Fail, 3, 1, 1, 1);

        port2Fail = new QLineEdit(groupPorts);
        port2Fail->setObjectName(QString::fromUtf8("port2Fail"));
        port2Fail->setEnabled(true);
        port2Fail->setMinimumSize(QSize(40, 0));
        port2Fail->setMaximumSize(QSize(40, 32767));
        port2Fail->setAlignment(Qt::AlignCenter);
        port2Fail->setReadOnly(true);

        gridLayout->addWidget(port2Fail, 3, 2, 1, 1);

        textPortNoData = new QLabel(groupPorts);
        textPortNoData->setObjectName(QString::fromUtf8("textPortNoData"));
        textPortNoData->setWordWrap(false);

        gridLayout->addWidget(textPortNoData, 4, 0, 1, 1);

        port1NoData = new QLineEdit(groupPorts);
        port1NoData->setObjectName(QString::fromUtf8("port1NoData"));
        port1NoData->setEnabled(true);
        port1NoData->setMinimumSize(QSize(40, 0));
        port1NoData->setMaximumSize(QSize(40, 32767));
        port1NoData->setAlignment(Qt::AlignCenter);
        port1NoData->setReadOnly(true);

        gridLayout->addWidget(port1NoData, 4, 1, 1, 1);

        port2NoData = new QLineEdit(groupPorts);
        port2NoData->setObjectName(QString::fromUtf8("port2NoData"));
        port2NoData->setEnabled(true);
        port2NoData->setMinimumSize(QSize(40, 0));
        port2NoData->setMaximumSize(QSize(40, 32767));
        port2NoData->setAlignment(Qt::AlignCenter);
        port2NoData->setReadOnly(true);

        gridLayout->addWidget(port2NoData, 4, 2, 1, 1);

        textPortBadData = new QLabel(groupPorts);
        textPortBadData->setObjectName(QString::fromUtf8("textPortBadData"));
        textPortBadData->setWordWrap(false);

        gridLayout->addWidget(textPortBadData, 5, 0, 1, 1);

        port2BadData = new QLineEdit(groupPorts);
        port2BadData->setObjectName(QString::fromUtf8("port2BadData"));
        port2BadData->setEnabled(true);
        port2BadData->setMinimumSize(QSize(40, 0));
        port2BadData->setMaximumSize(QSize(40, 32767));
        port2BadData->setAlignment(Qt::AlignCenter);
        port2BadData->setReadOnly(true);

        gridLayout->addWidget(port2BadData, 5, 2, 1, 1);


        verticalLayout_3->addWidget(groupPorts);

        groupRegime = new QGroupBox(DlgDeses);
        groupRegime->setObjectName(QString::fromUtf8("groupRegime"));
        verticalLayout_2 = new QVBoxLayout(groupRegime);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkRegime1 = new QCheckBox(groupRegime);
        checkRegime1->setObjectName(QString::fromUtf8("checkRegime1"));

        verticalLayout_2->addWidget(checkRegime1);

        checkRegime2 = new QCheckBox(groupRegime);
        checkRegime2->setObjectName(QString::fromUtf8("checkRegime2"));

        verticalLayout_2->addWidget(checkRegime2);

        checkRegime3 = new QCheckBox(groupRegime);
        checkRegime3->setObjectName(QString::fromUtf8("checkRegime3"));

        verticalLayout_2->addWidget(checkRegime3);

        checkRegime4 = new QCheckBox(groupRegime);
        checkRegime4->setObjectName(QString::fromUtf8("checkRegime4"));

        verticalLayout_2->addWidget(checkRegime4);

        checkRegime5 = new QCheckBox(groupRegime);
        checkRegime5->setObjectName(QString::fromUtf8("checkRegime5"));

        verticalLayout_2->addWidget(checkRegime5);


        verticalLayout_3->addWidget(groupRegime);


        gridLayout_7->addLayout(verticalLayout_3, 0, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayoutMains1 = new QHBoxLayout();
        horizontalLayoutMains1->setSpacing(6);
        horizontalLayoutMains1->setObjectName(QString::fromUtf8("horizontalLayoutMains1"));
        groupMains = new QGroupBox(DlgDeses);
        groupMains->setObjectName(QString::fromUtf8("groupMains"));
        gridLayout_5 = new QGridLayout(groupMains);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        textWorkMn1 = new QLabel(groupMains);
        textWorkMn1->setObjectName(QString::fromUtf8("textWorkMn1"));
        textWorkMn1->setWordWrap(false);

        gridLayout_5->addWidget(textWorkMn1, 0, 0, 1, 1);

        mnWork1 = new QLineEdit(groupMains);
        mnWork1->setObjectName(QString::fromUtf8("mnWork1"));
        mnWork1->setEnabled(true);
        mnWork1->setAlignment(Qt::AlignCenter);
        mnWork1->setReadOnly(true);

        gridLayout_5->addWidget(mnWork1, 0, 1, 1, 1);

        textRegimeMn1 = new QLabel(groupMains);
        textRegimeMn1->setObjectName(QString::fromUtf8("textRegimeMn1"));
        textRegimeMn1->setWordWrap(false);

        gridLayout_5->addWidget(textRegimeMn1, 1, 0, 1, 1);

        mnRegime1 = new QLineEdit(groupMains);
        mnRegime1->setObjectName(QString::fromUtf8("mnRegime1"));
        mnRegime1->setEnabled(true);
        mnRegime1->setAlignment(Qt::AlignCenter);
        mnRegime1->setReadOnly(true);

        gridLayout_5->addWidget(mnRegime1, 1, 1, 1, 1);


        horizontalLayoutMains1->addWidget(groupMains);

        horizontalSpacerMains1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayoutMains1->addItem(horizontalSpacerMains1);

        groupMainsMB = new QGroupBox(DlgDeses);
        groupMainsMB->setObjectName(QString::fromUtf8("groupMainsMB"));
        horizontalLayout_4 = new QHBoxLayout(groupMainsMB);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushOffMB1 = new QPushButton(groupMainsMB);
        pushOffMB1->setObjectName(QString::fromUtf8("pushOffMB1"));
        pushOffMB1->setCheckable(true);

        horizontalLayout_4->addWidget(pushOffMB1);

        pushOnMB1 = new QPushButton(groupMainsMB);
        pushOnMB1->setObjectName(QString::fromUtf8("pushOnMB1"));
        pushOnMB1->setCheckable(true);

        horizontalLayout_4->addWidget(pushOnMB1);


        horizontalLayoutMains1->addWidget(groupMainsMB);

        groupMainsReset = new QGroupBox(DlgDeses);
        groupMainsReset->setObjectName(QString::fromUtf8("groupMainsReset"));
        horizontalLayout_2 = new QHBoxLayout(groupMainsReset);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushResetMns1 = new QPushButton(groupMainsReset);
        pushResetMns1->setObjectName(QString::fromUtf8("pushResetMns1"));

        horizontalLayout_2->addWidget(pushResetMns1);


        horizontalLayoutMains1->addWidget(groupMainsReset);


        verticalLayout->addLayout(horizontalLayoutMains1);

        line = new QFrame(DlgDeses);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        gridLayoutDg1 = new QGridLayout();
        gridLayoutDg1->setSpacing(6);
        gridLayoutDg1->setObjectName(QString::fromUtf8("gridLayoutDg1"));
        groupDg1Run = new QGroupBox(DlgDeses);
        groupDg1Run->setObjectName(QString::fromUtf8("groupDg1Run"));
        horizontalLayout_11 = new QHBoxLayout(groupDg1Run);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushOffEngine1 = new QPushButton(groupDg1Run);
        pushOffEngine1->setObjectName(QString::fromUtf8("pushOffEngine1"));
        pushOffEngine1->setCheckable(true);

        horizontalLayout_11->addWidget(pushOffEngine1);

        pushOnEngine1 = new QPushButton(groupDg1Run);
        pushOnEngine1->setObjectName(QString::fromUtf8("pushOnEngine1"));
        pushOnEngine1->setCheckable(true);

        horizontalLayout_11->addWidget(pushOnEngine1);


        gridLayoutDg1->addWidget(groupDg1Run, 0, 2, 1, 1);

        groupDg1 = new QGroupBox(DlgDeses);
        groupDg1->setObjectName(QString::fromUtf8("groupDg1"));
        gridLayout_3 = new QGridLayout(groupDg1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textWorkDg1 = new QLabel(groupDg1);
        textWorkDg1->setObjectName(QString::fromUtf8("textWorkDg1"));
        textWorkDg1->setWordWrap(false);

        gridLayout_3->addWidget(textWorkDg1, 1, 0, 1, 1);

        dgWork1 = new QLineEdit(groupDg1);
        dgWork1->setObjectName(QString::fromUtf8("dgWork1"));
        dgWork1->setEnabled(true);
        dgWork1->setAlignment(Qt::AlignCenter);
        dgWork1->setReadOnly(true);

        gridLayout_3->addWidget(dgWork1, 1, 1, 1, 1);

        textRegimeDg1 = new QLabel(groupDg1);
        textRegimeDg1->setObjectName(QString::fromUtf8("textRegimeDg1"));
        textRegimeDg1->setWordWrap(false);

        gridLayout_3->addWidget(textRegimeDg1, 2, 0, 1, 1);

        dgRegime1 = new QLineEdit(groupDg1);
        dgRegime1->setObjectName(QString::fromUtf8("dgRegime1"));
        dgRegime1->setEnabled(true);
        dgRegime1->setAlignment(Qt::AlignCenter);
        dgRegime1->setReadOnly(true);

        gridLayout_3->addWidget(dgRegime1, 2, 1, 1, 1);


        gridLayoutDg1->addWidget(groupDg1, 0, 0, 1, 1);

        groupDg1Reset = new QGroupBox(DlgDeses);
        groupDg1Reset->setObjectName(QString::fromUtf8("groupDg1Reset"));
        horizontalLayout_6 = new QHBoxLayout(groupDg1Reset);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushResetDgs1 = new QPushButton(groupDg1Reset);
        pushResetDgs1->setObjectName(QString::fromUtf8("pushResetDgs1"));

        horizontalLayout_6->addWidget(pushResetDgs1);


        gridLayoutDg1->addWidget(groupDg1Reset, 0, 4, 1, 1);

        groupDg1GB = new QGroupBox(DlgDeses);
        groupDg1GB->setObjectName(QString::fromUtf8("groupDg1GB"));
        horizontalLayout_5 = new QHBoxLayout(groupDg1GB);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushOffGB1 = new QPushButton(groupDg1GB);
        pushOffGB1->setObjectName(QString::fromUtf8("pushOffGB1"));
        pushOffGB1->setCheckable(true);

        horizontalLayout_5->addWidget(pushOffGB1);

        pushOnGB1 = new QPushButton(groupDg1GB);
        pushOnGB1->setObjectName(QString::fromUtf8("pushOnGB1"));
        pushOnGB1->setCheckable(true);

        horizontalLayout_5->addWidget(pushOnGB1);


        gridLayoutDg1->addWidget(groupDg1GB, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayoutDg1);

        line_2 = new QFrame(DlgDeses);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        gridLayoutDg2 = new QGridLayout();
        gridLayoutDg2->setSpacing(6);
        gridLayoutDg2->setObjectName(QString::fromUtf8("gridLayoutDg2"));
        groupDg2Reset = new QGroupBox(DlgDeses);
        groupDg2Reset->setObjectName(QString::fromUtf8("groupDg2Reset"));
        horizontalLayout_9 = new QHBoxLayout(groupDg2Reset);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        pushResetDgs2 = new QPushButton(groupDg2Reset);
        pushResetDgs2->setObjectName(QString::fromUtf8("pushResetDgs2"));

        horizontalLayout_9->addWidget(pushResetDgs2);


        gridLayoutDg2->addWidget(groupDg2Reset, 0, 4, 1, 1);

        groupDg2Run = new QGroupBox(DlgDeses);
        groupDg2Run->setObjectName(QString::fromUtf8("groupDg2Run"));
        horizontalLayout_12 = new QHBoxLayout(groupDg2Run);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pushOffEngine2 = new QPushButton(groupDg2Run);
        pushOffEngine2->setObjectName(QString::fromUtf8("pushOffEngine2"));
        pushOffEngine2->setCheckable(true);

        horizontalLayout_12->addWidget(pushOffEngine2);

        pushOnEngine2 = new QPushButton(groupDg2Run);
        pushOnEngine2->setObjectName(QString::fromUtf8("pushOnEngine2"));
        pushOnEngine2->setCheckable(true);

        horizontalLayout_12->addWidget(pushOnEngine2);


        gridLayoutDg2->addWidget(groupDg2Run, 0, 2, 1, 1);

        groupDg2 = new QGroupBox(DlgDeses);
        groupDg2->setObjectName(QString::fromUtf8("groupDg2"));
        gridLayout_4 = new QGridLayout(groupDg2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textWorkDg2 = new QLabel(groupDg2);
        textWorkDg2->setObjectName(QString::fromUtf8("textWorkDg2"));
        textWorkDg2->setWordWrap(false);

        gridLayout_4->addWidget(textWorkDg2, 0, 0, 1, 1);

        dgWork2 = new QLineEdit(groupDg2);
        dgWork2->setObjectName(QString::fromUtf8("dgWork2"));
        dgWork2->setEnabled(true);
        dgWork2->setAlignment(Qt::AlignCenter);
        dgWork2->setReadOnly(true);

        gridLayout_4->addWidget(dgWork2, 0, 1, 1, 1);

        textRegimeDg2 = new QLabel(groupDg2);
        textRegimeDg2->setObjectName(QString::fromUtf8("textRegimeDg2"));
        textRegimeDg2->setWordWrap(false);

        gridLayout_4->addWidget(textRegimeDg2, 1, 0, 1, 1);

        dgRegime2 = new QLineEdit(groupDg2);
        dgRegime2->setObjectName(QString::fromUtf8("dgRegime2"));
        dgRegime2->setEnabled(true);
        dgRegime2->setAlignment(Qt::AlignCenter);
        dgRegime2->setReadOnly(true);

        gridLayout_4->addWidget(dgRegime2, 1, 1, 1, 1);


        gridLayoutDg2->addWidget(groupDg2, 0, 0, 1, 1);

        groupDg2GB = new QGroupBox(DlgDeses);
        groupDg2GB->setObjectName(QString::fromUtf8("groupDg2GB"));
        horizontalLayout_8 = new QHBoxLayout(groupDg2GB);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushOffGB2 = new QPushButton(groupDg2GB);
        pushOffGB2->setObjectName(QString::fromUtf8("pushOffGB2"));
        pushOffGB2->setCheckable(true);

        horizontalLayout_8->addWidget(pushOffGB2);

        pushOnGB2 = new QPushButton(groupDg2GB);
        pushOnGB2->setObjectName(QString::fromUtf8("pushOnGB2"));
        pushOnGB2->setCheckable(true);

        horizontalLayout_8->addWidget(pushOnGB2);


        gridLayoutDg2->addWidget(groupDg2GB, 0, 3, 1, 1);


        verticalLayout->addLayout(gridLayoutDg2);


        gridLayout_7->addLayout(verticalLayout, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushClose = new QPushButton(DlgDeses);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        horizontalLayout->addWidget(pushClose);


        gridLayout_7->addLayout(horizontalLayout, 1, 1, 1, 1);


        retranslateUi(DlgDeses);

        QMetaObject::connectSlotsByName(DlgDeses);
    } // setupUi

    void retranslateUi(QDialog *DlgDeses)
    {
        DlgDeses->setWindowTitle(QApplication::translate("DlgDeses", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\224\320\255\320\241", 0, QApplication::UnicodeUTF8));
        groupPorts->setTitle(QApplication::translate("DlgDeses", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        textLabelPort->setText(QApplication::translate("DlgDeses", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textLabelPort1->setText(QApplication::translate("DlgDeses", "1", 0, QApplication::UnicodeUTF8));
        textLabelPort2->setText(QApplication::translate("DlgDeses", "2", 0, QApplication::UnicodeUTF8));
        textPortOpen->setText(QApplication::translate("DlgDeses", "\320\236\321\202\320\272\321\200\321\213\321\202", 0, QApplication::UnicodeUTF8));
        textPortActive->setText(QApplication::translate("DlgDeses", "\320\220\320\272\321\202\320\270\320\262\320\265\320\275", 0, QApplication::UnicodeUTF8));
        textPortFail->setText(QApplication::translate("DlgDeses", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textPortNoData->setText(QApplication::translate("DlgDeses", "\320\235/\320\224", 0, QApplication::UnicodeUTF8));
        textPortBadData->setText(QApplication::translate("DlgDeses", "\320\241/\320\224", 0, QApplication::UnicodeUTF8));
        groupRegime->setTitle(QApplication::translate("DlgDeses", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213", 0, QApplication::UnicodeUTF8));
        checkRegime1->setText(QApplication::translate("DlgDeses", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8));
        checkRegime2->setText(QApplication::translate("DlgDeses", "\320\237\320\276\320\273\321\203\320\260\320\262\321\202\320\276\320\274\320\260\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271", 0, QApplication::UnicodeUTF8));
        checkRegime3->setText(QApplication::translate("DlgDeses", "\320\242\320\265\321\201\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkRegime4->setText(QApplication::translate("DlgDeses", "\320\240\321\203\321\207\320\275\320\276\320\271", 0, QApplication::UnicodeUTF8));
        checkRegime5->setText(QApplication::translate("DlgDeses", "\320\221\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        groupMains->setTitle(QApplication::translate("DlgDeses", "\320\241\320\225\320\242\320\254 1", 0, QApplication::UnicodeUTF8));
        textWorkMn1->setText(QApplication::translate("DlgDeses", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textRegimeMn1->setText(QApplication::translate("DlgDeses", "\320\240\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        groupMainsMB->setTitle(QApplication::translate("DlgDeses", "\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \320\262\321\213\320\272\320\273\321\216\321\207\320\260\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushOffMB1->setText(QApplication::translate("DlgDeses", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOnMB1->setText(QApplication::translate("DlgDeses", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupMainsReset->setTitle(QApplication::translate("DlgDeses", "\320\236\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushResetMns1->setText(QApplication::translate("DlgDeses", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupDg1Run->setTitle(QApplication::translate("DlgDeses", "\320\224\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushOffEngine1->setText(QApplication::translate("DlgDeses", "\320\241\320\242\320\236\320\237", 0, QApplication::UnicodeUTF8));
        pushOnEngine1->setText(QApplication::translate("DlgDeses", "\320\237\320\243\320\241\320\232", 0, QApplication::UnicodeUTF8));
        groupDg1->setTitle(QApplication::translate("DlgDeses", "\320\224\320\223 1", 0, QApplication::UnicodeUTF8));
        textWorkDg1->setText(QApplication::translate("DlgDeses", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textRegimeDg1->setText(QApplication::translate("DlgDeses", "\320\240\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        groupDg1Reset->setTitle(QApplication::translate("DlgDeses", "\320\236\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushResetDgs1->setText(QApplication::translate("DlgDeses", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupDg1GB->setTitle(QApplication::translate("DlgDeses", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202. \320\262\321\213\320\272\320\273\321\216\321\207\320\260\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushOffGB1->setText(QApplication::translate("DlgDeses", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOnGB1->setText(QApplication::translate("DlgDeses", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupDg2Reset->setTitle(QApplication::translate("DlgDeses", "\320\236\320\277\320\276\320\262\320\265\321\211\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushResetDgs2->setText(QApplication::translate("DlgDeses", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupDg2Run->setTitle(QApplication::translate("DlgDeses", "\320\224\320\262\320\270\320\263\320\260\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushOffEngine2->setText(QApplication::translate("DlgDeses", "\320\241\320\242\320\236\320\237", 0, QApplication::UnicodeUTF8));
        pushOnEngine2->setText(QApplication::translate("DlgDeses", "\320\237\320\243\320\241\320\232", 0, QApplication::UnicodeUTF8));
        groupDg2->setTitle(QApplication::translate("DlgDeses", "\320\224\320\223 2", 0, QApplication::UnicodeUTF8));
        textWorkDg2->setText(QApplication::translate("DlgDeses", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textRegimeDg2->setText(QApplication::translate("DlgDeses", "\320\240\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        groupDg2GB->setTitle(QApplication::translate("DlgDeses", "\320\223\320\265\320\275\320\265\321\200\320\260\321\202. \320\262\321\213\320\272\320\273\321\216\321\207\320\260\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushOffGB2->setText(QApplication::translate("DlgDeses", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOnGB2->setText(QApplication::translate("DlgDeses", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgDeses", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgDeses: public Ui_DlgDeses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESES_H
