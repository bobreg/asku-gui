/********************************************************************************
** Form generated from reading UI file 'coolers.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOLERS_H
#define UI_COOLERS_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <fstream>

QT_BEGIN_NAMESPACE

class Ui_DlgCoolers
{
public:
    QGridLayout *gridLayout_5;
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
    QSpacerItem *verticalSpacer;
    QGroupBox *groupPrd2;
    QGridLayout *gridLayout_4;
    QLabel *textLabelVersper2;
    QLabel *textLabelVesper21;
    QLabel *textLabelVesper22;
    QLabel *textVesperActive2;
    QLineEdit *vesper21Active;
    QLineEdit *vesper22Active;
    QLabel *textVesperFail2;
    QLineEdit *vesper21Fail;
    QLineEdit *vesper22Fail;
    QLabel *textVesperStart2;
    QLineEdit *vesper21Start;
    QLineEdit *vesper22Start;
    QLabel *textVesperFreq2;
    QLineEdit *vesper21Freq;
    QLineEdit *vesper22Freq;
    QLabel *textVesperError2;
    QLineEdit *vesper21Error;
    QLineEdit *vesper22Error;
    QHBoxLayout *HorizontalSliderBox_2;
    QSlider *vesperSlider2;
    QLabel *vesperFreq2;
    QLabel *textLabelHz2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushOn2;
    QPushButton *pushOff2;
    QGroupBox *groupPrd1;
    QGridLayout *gridLayout_3;
    QLabel *textLabelVersper1;
    QLabel *textLabelVesper11;
    QLabel *textLabelVesper12;
    QLabel *textVesperActive1;
    QLineEdit *vesper11Active;
    QLineEdit *vesper12Active;
    QLabel *textVesperFail1;
    QLineEdit *vesper11Fail;
    QLineEdit *vesper12Fail;
    QLabel *textVesperStart1;
    QLineEdit *vesper11Start;
    QLineEdit *vesper12Start;
    QLabel *textVesperFreq1;
    QLineEdit *vesper11Freq;
    QLineEdit *vesper12Freq;
    QLabel *textVesperError1;
    QLineEdit *vesper11Error;
    QLineEdit *vesper12Error;
    QHBoxLayout *HorizontalSliderBox;
    QSlider *vesperSlider1;
    QLabel *vesperFreq1;
    QLabel *textLabelHz1;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushOn1;
    QPushButton *pushOff1;
    QGroupBox *groupTemp;
    QGridLayout *gridLayout_2;
    QLabel *textTempEnv;
    QLineEdit *tenv;
    QLabel *textTempPrd1;
    QLineEdit *tprd1;
    QLabel *textTempPrd2;
    QLineEdit *tprd2;
    QLabel *textOnPrd1;
    QLineEdit *onprd1;
    QLabel *textOnPrd2;
    QLineEdit *onprd2;
    QSpacerItem *verticalSpacerTemp;
    QVBoxLayout *verticalLayoutButtons;
    QSpacerItem *verticalSpacerBtn;
    QCheckBox *manualCheckBox;
    QPushButton *pushSetFreq;
    QPushButton *pushReset;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgCoolers)
    {
        if (DlgCoolers->objectName().isEmpty())
            DlgCoolers->setObjectName(QString::fromUtf8("DlgCoolers"));
        DlgCoolers->resize(582, 459);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgCoolers->sizePolicy().hasHeightForWidth());
        DlgCoolers->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(DlgCoolers);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupPorts = new QGroupBox(DlgCoolers);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);


        gridLayout_5->addWidget(groupPorts, 0, 0, 1, 1);

        groupPrd2 = new QGroupBox(DlgCoolers);
        groupPrd2->setObjectName(QString::fromUtf8("groupPrd2"));
        gridLayout_4 = new QGridLayout(groupPrd2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textLabelVersper2 = new QLabel(groupPrd2);
        textLabelVersper2->setObjectName(QString::fromUtf8("textLabelVersper2"));
        textLabelVersper2->setWordWrap(false);

        gridLayout_4->addWidget(textLabelVersper2, 0, 0, 1, 1);

        textLabelVesper21 = new QLabel(groupPrd2);
        textLabelVesper21->setObjectName(QString::fromUtf8("textLabelVesper21"));
        textLabelVesper21->setAlignment(Qt::AlignCenter);
        textLabelVesper21->setWordWrap(false);

        gridLayout_4->addWidget(textLabelVesper21, 0, 1, 1, 1);

        textLabelVesper22 = new QLabel(groupPrd2);
        textLabelVesper22->setObjectName(QString::fromUtf8("textLabelVesper22"));
        textLabelVesper22->setAlignment(Qt::AlignCenter);
        textLabelVesper22->setWordWrap(false);

        gridLayout_4->addWidget(textLabelVesper22, 0, 2, 1, 1);

        textVesperActive2 = new QLabel(groupPrd2);
        textVesperActive2->setObjectName(QString::fromUtf8("textVesperActive2"));
        textVesperActive2->setWordWrap(false);

        gridLayout_4->addWidget(textVesperActive2, 1, 0, 1, 1);

        vesper21Active = new QLineEdit(groupPrd2);
        vesper21Active->setObjectName(QString::fromUtf8("vesper21Active"));
        vesper21Active->setEnabled(true);
        vesper21Active->setMinimumSize(QSize(40, 0));
        vesper21Active->setMaximumSize(QSize(40, 32767));
        vesper21Active->setAlignment(Qt::AlignCenter);
        vesper21Active->setReadOnly(true);

        gridLayout_4->addWidget(vesper21Active, 1, 1, 1, 1);

        vesper22Active = new QLineEdit(groupPrd2);
        vesper22Active->setObjectName(QString::fromUtf8("vesper22Active"));
        vesper22Active->setEnabled(true);
        vesper22Active->setMinimumSize(QSize(40, 0));
        vesper22Active->setMaximumSize(QSize(40, 32767));
        vesper22Active->setAlignment(Qt::AlignCenter);
        vesper22Active->setReadOnly(true);

        gridLayout_4->addWidget(vesper22Active, 1, 2, 1, 1);

        textVesperFail2 = new QLabel(groupPrd2);
        textVesperFail2->setObjectName(QString::fromUtf8("textVesperFail2"));
        textVesperFail2->setWordWrap(false);

        gridLayout_4->addWidget(textVesperFail2, 2, 0, 1, 1);

        vesper21Fail = new QLineEdit(groupPrd2);
        vesper21Fail->setObjectName(QString::fromUtf8("vesper21Fail"));
        vesper21Fail->setEnabled(true);
        vesper21Fail->setMinimumSize(QSize(40, 0));
        vesper21Fail->setMaximumSize(QSize(40, 32767));
        vesper21Fail->setAlignment(Qt::AlignCenter);
        vesper21Fail->setReadOnly(true);

        gridLayout_4->addWidget(vesper21Fail, 2, 1, 1, 1);

        vesper22Fail = new QLineEdit(groupPrd2);
        vesper22Fail->setObjectName(QString::fromUtf8("vesper22Fail"));
        vesper22Fail->setEnabled(true);
        vesper22Fail->setMinimumSize(QSize(40, 0));
        vesper22Fail->setMaximumSize(QSize(40, 32767));
        vesper22Fail->setAlignment(Qt::AlignCenter);
        vesper22Fail->setReadOnly(true);

        gridLayout_4->addWidget(vesper22Fail, 2, 2, 1, 1);

        textVesperStart2 = new QLabel(groupPrd2);
        textVesperStart2->setObjectName(QString::fromUtf8("textVesperStart2"));
        textVesperStart2->setWordWrap(false);

        gridLayout_4->addWidget(textVesperStart2, 3, 0, 1, 1);

        vesper21Start = new QLineEdit(groupPrd2);
        vesper21Start->setObjectName(QString::fromUtf8("vesper21Start"));
        vesper21Start->setEnabled(true);
        vesper21Start->setMinimumSize(QSize(40, 0));
        vesper21Start->setMaximumSize(QSize(40, 32767));
        vesper21Start->setAlignment(Qt::AlignCenter);
        vesper21Start->setReadOnly(true);

        gridLayout_4->addWidget(vesper21Start, 3, 1, 1, 1);

        vesper22Start = new QLineEdit(groupPrd2);
        vesper22Start->setObjectName(QString::fromUtf8("vesper22Start"));
        vesper22Start->setEnabled(true);
        vesper22Start->setMinimumSize(QSize(40, 0));
        vesper22Start->setMaximumSize(QSize(40, 32767));
        vesper22Start->setAlignment(Qt::AlignCenter);
        vesper22Start->setReadOnly(true);

        gridLayout_4->addWidget(vesper22Start, 3, 2, 1, 1);

        textVesperFreq2 = new QLabel(groupPrd2);
        textVesperFreq2->setObjectName(QString::fromUtf8("textVesperFreq2"));
        textVesperFreq2->setWordWrap(false);

        gridLayout_4->addWidget(textVesperFreq2, 4, 0, 1, 1);

        vesper21Freq = new QLineEdit(groupPrd2);
        vesper21Freq->setObjectName(QString::fromUtf8("vesper21Freq"));
        vesper21Freq->setEnabled(true);
        vesper21Freq->setMinimumSize(QSize(40, 0));
        vesper21Freq->setMaximumSize(QSize(40, 32767));
        vesper21Freq->setAlignment(Qt::AlignCenter);
        vesper21Freq->setReadOnly(true);

        gridLayout_4->addWidget(vesper21Freq, 4, 1, 1, 1);

        vesper22Freq = new QLineEdit(groupPrd2);
        vesper22Freq->setObjectName(QString::fromUtf8("vesper22Freq"));
        vesper22Freq->setEnabled(true);
        vesper22Freq->setMinimumSize(QSize(40, 0));
        vesper22Freq->setMaximumSize(QSize(40, 32767));
        vesper22Freq->setAlignment(Qt::AlignCenter);
        vesper22Freq->setReadOnly(true);

        gridLayout_4->addWidget(vesper22Freq, 4, 2, 1, 1);

        textVesperError2 = new QLabel(groupPrd2);
        textVesperError2->setObjectName(QString::fromUtf8("textVesperError2"));
        textVesperError2->setWordWrap(false);

        gridLayout_4->addWidget(textVesperError2, 5, 0, 1, 1);

        vesper21Error = new QLineEdit(groupPrd2);
        vesper21Error->setObjectName(QString::fromUtf8("vesper21Error"));
        vesper21Error->setEnabled(true);
        vesper21Error->setMinimumSize(QSize(40, 0));
        vesper21Error->setMaximumSize(QSize(40, 32767));
        vesper21Error->setAlignment(Qt::AlignCenter);
        vesper21Error->setReadOnly(true);

        gridLayout_4->addWidget(vesper21Error, 5, 1, 1, 1);

        vesper22Error = new QLineEdit(groupPrd2);
        vesper22Error->setObjectName(QString::fromUtf8("vesper22Error"));
        vesper22Error->setEnabled(true);
        vesper22Error->setMinimumSize(QSize(40, 0));
        vesper22Error->setMaximumSize(QSize(40, 32767));
        vesper22Error->setAlignment(Qt::AlignCenter);
        vesper22Error->setReadOnly(true);

        gridLayout_4->addWidget(vesper22Error, 5, 2, 1, 1);

        HorizontalSliderBox_2 = new QHBoxLayout();
        HorizontalSliderBox_2->setSpacing(6);
        HorizontalSliderBox_2->setObjectName(QString::fromUtf8("HorizontalSliderBox_2"));
        vesperSlider2 = new QSlider(groupPrd2);
        vesperSlider2->setObjectName(QString::fromUtf8("vesperSlider2"));
        vesperSlider2->setEnabled(false);
        vesperSlider2->setMinimumSize(QSize(80, 0));
        vesperSlider2->setMaximum(50);
        vesperSlider2->setSingleStep(5);
        vesperSlider2->setPageStep(5);
        vesperSlider2->setOrientation(Qt::Horizontal);

        HorizontalSliderBox_2->addWidget(vesperSlider2);

        vesperFreq2 = new QLabel(groupPrd2);
        vesperFreq2->setObjectName(QString::fromUtf8("vesperFreq2"));
        vesperFreq2->setMinimumSize(QSize(30, 0));
        vesperFreq2->setMaximumSize(QSize(30, 32767));
        vesperFreq2->setTextFormat(Qt::PlainText);
        vesperFreq2->setAlignment(Qt::AlignCenter);
        vesperFreq2->setWordWrap(false);

        HorizontalSliderBox_2->addWidget(vesperFreq2);

        textLabelHz2 = new QLabel(groupPrd2);
        textLabelHz2->setObjectName(QString::fromUtf8("textLabelHz2"));
        textLabelHz2->setWordWrap(false);

        HorizontalSliderBox_2->addWidget(textLabelHz2);


        gridLayout_4->addLayout(HorizontalSliderBox_2, 6, 0, 1, 3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushOn2 = new QPushButton(groupPrd2);
        pushOn2->setObjectName(QString::fromUtf8("pushOn2"));
        pushOn2->setCheckable(true);

        horizontalLayout_2->addWidget(pushOn2);

        pushOff2 = new QPushButton(groupPrd2);
        pushOff2->setObjectName(QString::fromUtf8("pushOff2"));
        pushOff2->setCheckable(true);

        horizontalLayout_2->addWidget(pushOff2);


        gridLayout_4->addLayout(horizontalLayout_2, 7, 0, 1, 3);


        gridLayout_5->addWidget(groupPrd2, 0, 2, 1, 1);

        groupPrd1 = new QGroupBox(DlgCoolers);
        groupPrd1->setObjectName(QString::fromUtf8("groupPrd1"));
        gridLayout_3 = new QGridLayout(groupPrd1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textLabelVersper1 = new QLabel(groupPrd1);
        textLabelVersper1->setObjectName(QString::fromUtf8("textLabelVersper1"));
        textLabelVersper1->setWordWrap(false);

        gridLayout_3->addWidget(textLabelVersper1, 0, 0, 1, 1);

        textLabelVesper11 = new QLabel(groupPrd1);
        textLabelVesper11->setObjectName(QString::fromUtf8("textLabelVesper11"));
        textLabelVesper11->setAlignment(Qt::AlignCenter);
        textLabelVesper11->setWordWrap(false);

        gridLayout_3->addWidget(textLabelVesper11, 0, 1, 1, 1);

        textLabelVesper12 = new QLabel(groupPrd1);
        textLabelVesper12->setObjectName(QString::fromUtf8("textLabelVesper12"));
        textLabelVesper12->setAlignment(Qt::AlignCenter);
        textLabelVesper12->setWordWrap(false);

        gridLayout_3->addWidget(textLabelVesper12, 0, 2, 1, 1);

        textVesperActive1 = new QLabel(groupPrd1);
        textVesperActive1->setObjectName(QString::fromUtf8("textVesperActive1"));
        textVesperActive1->setWordWrap(false);

        gridLayout_3->addWidget(textVesperActive1, 1, 0, 1, 1);

        vesper11Active = new QLineEdit(groupPrd1);
        vesper11Active->setObjectName(QString::fromUtf8("vesper11Active"));
        vesper11Active->setEnabled(true);
        vesper11Active->setMinimumSize(QSize(40, 0));
        vesper11Active->setMaximumSize(QSize(40, 32767));
        vesper11Active->setAlignment(Qt::AlignCenter);
        vesper11Active->setReadOnly(true);

        gridLayout_3->addWidget(vesper11Active, 1, 1, 1, 1);

        vesper12Active = new QLineEdit(groupPrd1);
        vesper12Active->setObjectName(QString::fromUtf8("vesper12Active"));
        vesper12Active->setEnabled(true);
        vesper12Active->setMinimumSize(QSize(40, 0));
        vesper12Active->setMaximumSize(QSize(40, 32767));
        vesper12Active->setAlignment(Qt::AlignCenter);
        vesper12Active->setReadOnly(true);

        gridLayout_3->addWidget(vesper12Active, 1, 2, 1, 1);

        textVesperFail1 = new QLabel(groupPrd1);
        textVesperFail1->setObjectName(QString::fromUtf8("textVesperFail1"));
        textVesperFail1->setWordWrap(false);

        gridLayout_3->addWidget(textVesperFail1, 2, 0, 1, 1);

        vesper11Fail = new QLineEdit(groupPrd1);
        vesper11Fail->setObjectName(QString::fromUtf8("vesper11Fail"));
        vesper11Fail->setEnabled(true);
        vesper11Fail->setMinimumSize(QSize(40, 0));
        vesper11Fail->setMaximumSize(QSize(40, 32767));
        vesper11Fail->setAlignment(Qt::AlignCenter);
        vesper11Fail->setReadOnly(true);

        gridLayout_3->addWidget(vesper11Fail, 2, 1, 1, 1);

        vesper12Fail = new QLineEdit(groupPrd1);
        vesper12Fail->setObjectName(QString::fromUtf8("vesper12Fail"));
        vesper12Fail->setEnabled(true);
        vesper12Fail->setMinimumSize(QSize(40, 0));
        vesper12Fail->setMaximumSize(QSize(40, 32767));
        vesper12Fail->setAlignment(Qt::AlignCenter);
        vesper12Fail->setReadOnly(true);

        gridLayout_3->addWidget(vesper12Fail, 2, 2, 1, 1);

        textVesperStart1 = new QLabel(groupPrd1);
        textVesperStart1->setObjectName(QString::fromUtf8("textVesperStart1"));
        textVesperStart1->setWordWrap(false);

        gridLayout_3->addWidget(textVesperStart1, 3, 0, 1, 1);

        vesper11Start = new QLineEdit(groupPrd1);
        vesper11Start->setObjectName(QString::fromUtf8("vesper11Start"));
        vesper11Start->setEnabled(true);
        vesper11Start->setMinimumSize(QSize(40, 0));
        vesper11Start->setMaximumSize(QSize(40, 32767));
        vesper11Start->setAlignment(Qt::AlignCenter);
        vesper11Start->setReadOnly(true);

        gridLayout_3->addWidget(vesper11Start, 3, 1, 1, 1);

        vesper12Start = new QLineEdit(groupPrd1);
        vesper12Start->setObjectName(QString::fromUtf8("vesper12Start"));
        vesper12Start->setEnabled(true);
        vesper12Start->setMinimumSize(QSize(40, 0));
        vesper12Start->setMaximumSize(QSize(40, 32767));
        vesper12Start->setAlignment(Qt::AlignCenter);
        vesper12Start->setReadOnly(true);

        gridLayout_3->addWidget(vesper12Start, 3, 2, 1, 1);

        textVesperFreq1 = new QLabel(groupPrd1);
        textVesperFreq1->setObjectName(QString::fromUtf8("textVesperFreq1"));
        textVesperFreq1->setWordWrap(false);

        gridLayout_3->addWidget(textVesperFreq1, 4, 0, 1, 1);

        vesper11Freq = new QLineEdit(groupPrd1);
        vesper11Freq->setObjectName(QString::fromUtf8("vesper11Freq"));
        vesper11Freq->setEnabled(true);
        vesper11Freq->setMinimumSize(QSize(40, 0));
        vesper11Freq->setMaximumSize(QSize(40, 32767));
        vesper11Freq->setAlignment(Qt::AlignCenter);
        vesper11Freq->setReadOnly(true);

        gridLayout_3->addWidget(vesper11Freq, 4, 1, 1, 1);

        vesper12Freq = new QLineEdit(groupPrd1);
        vesper12Freq->setObjectName(QString::fromUtf8("vesper12Freq"));
        vesper12Freq->setEnabled(true);
        vesper12Freq->setMinimumSize(QSize(40, 0));
        vesper12Freq->setMaximumSize(QSize(40, 32767));
        vesper12Freq->setAlignment(Qt::AlignCenter);
        vesper12Freq->setReadOnly(true);

        gridLayout_3->addWidget(vesper12Freq, 4, 2, 1, 1);

        textVesperError1 = new QLabel(groupPrd1);
        textVesperError1->setObjectName(QString::fromUtf8("textVesperError1"));

        gridLayout_3->addWidget(textVesperError1, 5, 0, 1, 1);

        vesper11Error = new QLineEdit(groupPrd1);
        vesper11Error->setObjectName(QString::fromUtf8("vesper11Error"));
        vesper11Error->setEnabled(true);
        vesper11Error->setMinimumSize(QSize(40, 0));
        vesper11Error->setMaximumSize(QSize(40, 32767));
        vesper11Error->setAlignment(Qt::AlignCenter);
        vesper11Error->setReadOnly(true);

        gridLayout_3->addWidget(vesper11Error, 5, 1, 1, 1);

        vesper12Error = new QLineEdit(groupPrd1);
        vesper12Error->setObjectName(QString::fromUtf8("vesper12Error"));
        vesper12Error->setEnabled(true);
        vesper12Error->setMinimumSize(QSize(40, 0));
        vesper12Error->setMaximumSize(QSize(40, 32767));
        vesper12Error->setAlignment(Qt::AlignCenter);
        vesper12Error->setReadOnly(true);

        gridLayout_3->addWidget(vesper12Error, 5, 2, 1, 1);

        HorizontalSliderBox = new QHBoxLayout();
        HorizontalSliderBox->setSpacing(6);
        HorizontalSliderBox->setObjectName(QString::fromUtf8("HorizontalSliderBox"));
        vesperSlider1 = new QSlider(groupPrd1);
        vesperSlider1->setObjectName(QString::fromUtf8("vesperSlider1"));
        vesperSlider1->setEnabled(false);
        vesperSlider1->setMinimumSize(QSize(80, 0));
        vesperSlider1->setMaximum(50);
        vesperSlider1->setSingleStep(5);
        vesperSlider1->setPageStep(5);
        vesperSlider1->setOrientation(Qt::Horizontal);

        HorizontalSliderBox->addWidget(vesperSlider1);

        vesperFreq1 = new QLabel(groupPrd1);
        vesperFreq1->setObjectName(QString::fromUtf8("vesperFreq1"));
        vesperFreq1->setMinimumSize(QSize(30, 0));
        vesperFreq1->setMaximumSize(QSize(30, 32767));
        vesperFreq1->setTextFormat(Qt::PlainText);
        vesperFreq1->setAlignment(Qt::AlignCenter);
        vesperFreq1->setWordWrap(false);

        HorizontalSliderBox->addWidget(vesperFreq1);

        textLabelHz1 = new QLabel(groupPrd1);
        textLabelHz1->setObjectName(QString::fromUtf8("textLabelHz1"));
        textLabelHz1->setWordWrap(false);

        HorizontalSliderBox->addWidget(textLabelHz1);


        gridLayout_3->addLayout(HorizontalSliderBox, 6, 0, 1, 3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushOn1 = new QPushButton(groupPrd1);
        pushOn1->setObjectName(QString::fromUtf8("pushOn1"));
        pushOn1->setCheckable(true);

        horizontalLayout->addWidget(pushOn1);

        pushOff1 = new QPushButton(groupPrd1);
        pushOff1->setObjectName(QString::fromUtf8("pushOff1"));
        pushOff1->setCheckable(true);

        horizontalLayout->addWidget(pushOff1);


        gridLayout_3->addLayout(horizontalLayout, 7, 0, 1, 3);


        gridLayout_5->addWidget(groupPrd1, 0, 1, 1, 1);

        groupTemp = new QGroupBox(DlgCoolers);
        groupTemp->setObjectName(QString::fromUtf8("groupTemp"));
        gridLayout_2 = new QGridLayout(groupTemp);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textTempEnv = new QLabel(groupTemp);
        textTempEnv->setObjectName(QString::fromUtf8("textTempEnv"));
        textTempEnv->setWordWrap(false);

        gridLayout_2->addWidget(textTempEnv, 0, 0, 1, 1);

        tenv = new QLineEdit(groupTemp);
        tenv->setObjectName(QString::fromUtf8("tenv"));
        tenv->setEnabled(true);
        tenv->setMinimumSize(QSize(50, 0));
        tenv->setMaximumSize(QSize(50, 32767));
        tenv->setAlignment(Qt::AlignCenter);
        tenv->setReadOnly(true);

        gridLayout_2->addWidget(tenv, 0, 1, 1, 1);

        textTempPrd1 = new QLabel(groupTemp);
        textTempPrd1->setObjectName(QString::fromUtf8("textTempPrd1"));
        textTempPrd1->setWordWrap(false);

        gridLayout_2->addWidget(textTempPrd1, 1, 0, 1, 1);

        tprd1 = new QLineEdit(groupTemp);
        tprd1->setObjectName(QString::fromUtf8("tprd1"));
        tprd1->setEnabled(true);
        tprd1->setMinimumSize(QSize(50, 0));
        tprd1->setMaximumSize(QSize(50, 32767));
        tprd1->setAlignment(Qt::AlignCenter);
        tprd1->setReadOnly(true);

        gridLayout_2->addWidget(tprd1, 1, 1, 1, 1);

        textTempPrd2 = new QLabel(groupTemp);
        textTempPrd2->setObjectName(QString::fromUtf8("textTempPrd2"));
        textTempPrd2->setWordWrap(false);

        gridLayout_2->addWidget(textTempPrd2, 2, 0, 1, 1);

        tprd2 = new QLineEdit(groupTemp);
        tprd2->setObjectName(QString::fromUtf8("tprd2"));
        tprd2->setEnabled(true);
        tprd2->setMinimumSize(QSize(50, 0));
        tprd2->setMaximumSize(QSize(50, 32767));
        tprd2->setAlignment(Qt::AlignCenter);
        tprd2->setReadOnly(true);

        gridLayout_2->addWidget(tprd2, 2, 1, 1, 1);

        textOnPrd1 = new QLabel(groupTemp);
        textOnPrd1->setObjectName(QString::fromUtf8("textOnPrd1"));
        textOnPrd1->setWordWrap(false);

        gridLayout_2->addWidget(textOnPrd1, 3, 0, 1, 1);

        onprd1 = new QLineEdit(groupTemp);
        onprd1->setObjectName(QString::fromUtf8("onprd1"));
        onprd1->setEnabled(true);
        onprd1->setMinimumSize(QSize(50, 0));
        onprd1->setMaximumSize(QSize(50, 32767));
        onprd1->setAlignment(Qt::AlignCenter);
        onprd1->setReadOnly(true);

        gridLayout_2->addWidget(onprd1, 3, 1, 1, 1);

        textOnPrd2 = new QLabel(groupTemp);
        textOnPrd2->setObjectName(QString::fromUtf8("textOnPrd2"));
        textOnPrd2->setWordWrap(false);

        gridLayout_2->addWidget(textOnPrd2, 4, 0, 1, 1);

        onprd2 = new QLineEdit(groupTemp);
        onprd2->setObjectName(QString::fromUtf8("onprd2"));
        onprd2->setEnabled(true);
        onprd2->setMinimumSize(QSize(50, 0));
        onprd2->setMaximumSize(QSize(50, 32767));
        onprd2->setAlignment(Qt::AlignCenter);
        onprd2->setReadOnly(true);

        gridLayout_2->addWidget(onprd2, 4, 1, 1, 1);

        verticalSpacerTemp = new QSpacerItem(178, 12, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacerTemp, 5, 0, 1, 2);


        gridLayout_5->addWidget(groupTemp, 1, 0, 1, 1);

        verticalLayoutButtons = new QVBoxLayout();
        verticalLayoutButtons->setSpacing(6);
        verticalLayoutButtons->setObjectName(QString::fromUtf8("verticalLayoutButtons"));
        verticalSpacerBtn = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutButtons->addItem(verticalSpacerBtn);

        manualCheckBox = new QCheckBox(DlgCoolers);
        manualCheckBox->setObjectName(QString::fromUtf8("manualCheckBox"));

        verticalLayoutButtons->addWidget(manualCheckBox);

        pushSetFreq = new QPushButton(DlgCoolers);
        pushSetFreq->setObjectName(QString::fromUtf8("pushSetFreq"));

        verticalLayoutButtons->addWidget(pushSetFreq);

        pushReset = new QPushButton(DlgCoolers);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));

        verticalLayoutButtons->addWidget(pushReset);

        pushClose = new QPushButton(DlgCoolers);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        verticalLayoutButtons->addWidget(pushClose);


        gridLayout_5->addLayout(verticalLayoutButtons, 1, 2, 1, 1);

        QWidget::setTabOrder(vesperSlider1, port1Opened);
        QWidget::setTabOrder(port1Opened, port2Opened);
        QWidget::setTabOrder(port2Opened, port1Active);
        QWidget::setTabOrder(port1Active, port2Active);
        QWidget::setTabOrder(port2Active, port1Fail);
        QWidget::setTabOrder(port1Fail, port2Fail);
        QWidget::setTabOrder(port2Fail, port1NoData);
        QWidget::setTabOrder(port1NoData, port2NoData);
        QWidget::setTabOrder(port2NoData, port1BadData);
        QWidget::setTabOrder(port1BadData, port2BadData);
        QWidget::setTabOrder(port2BadData, vesper11Active);
        QWidget::setTabOrder(vesper11Active, vesper12Active);
        QWidget::setTabOrder(vesper12Active, vesper11Fail);
        QWidget::setTabOrder(vesper11Fail, vesper12Fail);
        QWidget::setTabOrder(vesper12Fail, vesper11Start);
        QWidget::setTabOrder(vesper11Start, vesper12Start);
        QWidget::setTabOrder(vesper12Start, vesper11Freq);
        QWidget::setTabOrder(vesper11Freq, vesper12Freq);
        QWidget::setTabOrder(vesper12Freq, tenv);
        QWidget::setTabOrder(tenv, tprd1);
        QWidget::setTabOrder(tprd1, manualCheckBox);
        QWidget::setTabOrder(manualCheckBox, pushReset);
        QWidget::setTabOrder(pushReset, pushClose);

        retranslateUi(DlgCoolers);

        QMetaObject::connectSlotsByName(DlgCoolers);
    } // setupUi

    void retranslateUi(QDialog *DlgCoolers)
    {
        DlgCoolers->setWindowTitle(QApplication::translate("DlgCoolers", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\241\320\222\320\236 \320\237\320\240\320\224", 0, QApplication::UnicodeUTF8));
        groupPorts->setTitle(QApplication::translate("DlgCoolers", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        textLabelPort->setText(QApplication::translate("DlgCoolers", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textLabelPort1->setText(QApplication::translate("DlgCoolers", "1", 0, QApplication::UnicodeUTF8));
        textLabelPort2->setText(QApplication::translate("DlgCoolers", "2", 0, QApplication::UnicodeUTF8));
        textPortOpen->setText(QApplication::translate("DlgCoolers", "\320\236\321\202\320\272\321\200\321\213\321\202", 0, QApplication::UnicodeUTF8));
        textPortActive->setText(QApplication::translate("DlgCoolers", "\320\220\320\272\321\202\320\270\320\262\320\265\320\275", 0, QApplication::UnicodeUTF8));
        textPortFail->setText(QApplication::translate("DlgCoolers", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textPortNoData->setText(QApplication::translate("DlgCoolers", "\320\235/\320\224", 0, QApplication::UnicodeUTF8));
        textPortBadData->setText(QApplication::translate("DlgCoolers", "\320\241/\320\224", 0, QApplication::UnicodeUTF8));
        groupPrd2->setTitle(QApplication::translate("DlgCoolers", "\320\237\320\225\320\240\320\225\320\224\320\220\320\242\320\247\320\230\320\232 2", 0, QApplication::UnicodeUTF8));
        textLabelVersper2->setText(QApplication::translate("DlgCoolers", "\320\247\320\237", 0, QApplication::UnicodeUTF8));
        textLabelVesper21->setText(QApplication::translate("DlgCoolers", "1", 0, QApplication::UnicodeUTF8));
        textLabelVesper22->setText(QApplication::translate("DlgCoolers", "2", 0, QApplication::UnicodeUTF8));
        textVesperActive2->setText(QApplication::translate("DlgCoolers", "\320\223\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        textVesperFail2->setText(QApplication::translate("DlgCoolers", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textVesperStart2->setText(QApplication::translate("DlgCoolers", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textVesperFreq2->setText(QApplication::translate("DlgCoolers", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        textVesperError2->setText(QApplication::translate("DlgCoolers", "\320\236\321\210\320\270\320\261\320\272\320\260", 0, QApplication::UnicodeUTF8));
        vesperFreq2->setText(QApplication::translate("DlgCoolers", "0", 0, QApplication::UnicodeUTF8));
        textLabelHz2->setText(QApplication::translate("DlgCoolers", "\320\223\321\206", 0, QApplication::UnicodeUTF8));
        pushOn2->setText(QApplication::translate("DlgCoolers", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOff2->setText(QApplication::translate("DlgCoolers", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupPrd1->setTitle(QApplication::translate("DlgCoolers", "\320\237\320\225\320\240\320\225\320\224\320\220\320\242\320\247\320\230\320\232 1", 0, QApplication::UnicodeUTF8));
        textLabelVersper1->setText(QApplication::translate("DlgCoolers", "\320\247\320\237", 0, QApplication::UnicodeUTF8));
        textLabelVesper11->setText(QApplication::translate("DlgCoolers", "1", 0, QApplication::UnicodeUTF8));
        textLabelVesper12->setText(QApplication::translate("DlgCoolers", "2", 0, QApplication::UnicodeUTF8));
        textVesperActive1->setText(QApplication::translate("DlgCoolers", "\320\223\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        textVesperFail1->setText(QApplication::translate("DlgCoolers", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textVesperStart1->setText(QApplication::translate("DlgCoolers", "\320\241\321\202\320\260\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textVesperFreq1->setText(QApplication::translate("DlgCoolers", "\320\247\320\260\321\201\321\202\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        textVesperError1->setText(QApplication::translate("DlgCoolers", "\320\236\321\210\320\270\320\261\320\272\320\260", 0, QApplication::UnicodeUTF8));
        vesperFreq1->setText(QApplication::translate("DlgCoolers", "0", 0, QApplication::UnicodeUTF8));
        textLabelHz1->setText(QApplication::translate("DlgCoolers", "\320\223\321\206", 0, QApplication::UnicodeUTF8));
        pushOn1->setText(QApplication::translate("DlgCoolers", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOff1->setText(QApplication::translate("DlgCoolers", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupTemp->setTitle(QApplication::translate("DlgCoolers", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260", 0, QApplication::UnicodeUTF8));
        textTempEnv->setText(QApplication::translate("DlgCoolers", "\320\222\320\275\320\265\321\210\320\275., C", 0, QApplication::UnicodeUTF8));
        textTempPrd1->setText(QApplication::translate("DlgCoolers", "\320\237\320\240\320\224 1, C", 0, QApplication::UnicodeUTF8));
        textTempPrd2->setText(QApplication::translate("DlgCoolers", "\320\237\320\240\320\224 2, C", 0, QApplication::UnicodeUTF8));
        textOnPrd1->setText(QApplication::translate("DlgCoolers", "\320\237\320\240\320\224 1 \320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        onprd1->setText(QString());
        textOnPrd2->setText(QApplication::translate("DlgCoolers", "\320\237\320\240\320\224 2 \320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        onprd2->setText(QString());
        manualCheckBox->setText(QApplication::translate("DlgCoolers", "\320\240\321\203\321\207\320\275\320\276\320\265 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushSetFreq->setText(QApplication::translate("DlgCoolers", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\207\320\260\321\201\321\202\320\276\321\202\321\203", 0, QApplication::UnicodeUTF8));
        pushReset->setText(QApplication::translate("DlgCoolers", "\320\241\320\261\321\200\320\276\321\201 \320\220\320\262\320\260\321\200\320\270\320\270", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgCoolers", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgCoolers: public Ui_DlgCoolers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOLERS_H
