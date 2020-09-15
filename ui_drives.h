/********************************************************************************
** Form generated from reading UI file 'drives.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRIVES_H
#define UI_DRIVES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgDrives
{
public:
    QGroupBox *groupDrive1;
    QLabel *labelVersion1;
    QLineEdit *editVersion1;
    QLineEdit *editSerial1;
    QLabel *labelSerial1;
    QLineEdit *editTime1;
    QLabel *labelTime1;
    QLabel *labelConfig1;
    QLineEdit *editConfig1;
    QLineEdit *editBan1;
    QLabel *labelBan1;
    QLineEdit *editDist1;
    QLineEdit *editAlarm1;
    QLabel *labelDist1;
    QLineEdit *editInvertor1;
    QLineEdit *editWork1;
    QLabel *labelWarn1;
    QLabel *labelReady1;
    QLabel *labelWork1;
    QLabel *labelInvertor1;
    QLabel *labelAlarm1;
    QLineEdit *editWarn1;
    QLineEdit *editReady1;
    QLabel *labelHeat1;
    QLineEdit *editHeat1;
    QLineEdit *editSensor1;
    QLabel *labelSensor1;
    QLineEdit *editPwrReady1;
    QLabel *labelPwrReady1;
    QLineEdit *editAzimuth1;
    QLabel *labelAzimuth1;
    QLineEdit *editMain1;
    QLabel *labelMain1;
    QLineEdit *editSpeed1;
    QLabel *labelSpeed1;
    QLineEdit *editCurrent1;
    QLineEdit *editVoltage1;
    QLabel *labelCurrent1;
    QLabel *labelVoltage1;
    QLineEdit *editMoment1;
    QLabel *labelMoment1;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupPorts;
    QGridLayout *gridLayout;
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
    QLineEdit *port1BadData;
    QLineEdit *port2BadData;
    QSpacerItem *verticalSpacer_3;
    QGroupBox *ctrlGBox;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkManual;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushOn;
    QPushButton *pushOff;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushSet1;
    QPushButton *pushSet2;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QLabel *setVelLbl;
    QDoubleSpinBox *spinSpeed;
    QPushButton *pushSetSpeed;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *pushReset;
    QPushButton *pushClose;
    QGroupBox *groupDrive2;
    QLabel *labelVersion2;
    QLineEdit *editVersion2;
    QLineEdit *editSerial2;
    QLabel *labelSerial2;
    QLineEdit *editTime2;
    QLabel *labelTime2;
    QLabel *labelConfig2;
    QLineEdit *editConfig2;
    QLineEdit *editBan2;
    QLabel *labelBan2;
    QLineEdit *editDist2;
    QLineEdit *editAlarm2;
    QLabel *labelDist2;
    QLineEdit *editInvertor2;
    QLineEdit *editWork2;
    QLabel *labelWarn2;
    QLabel *labelReady2;
    QLabel *labelWork2;
    QLabel *labelInvertor2;
    QLabel *labelAlarm2;
    QLineEdit *editWarn2;
    QLineEdit *editReady2;
    QLabel *labelHeat2;
    QLineEdit *editHeat2;
    QLineEdit *editSensor2;
    QLabel *labelSensor2;
    QLineEdit *editPwrReady2;
    QLabel *labelPwrReady2;
    QLineEdit *editAzimuth2;
    QLabel *labelAzimuth2;
    QLineEdit *editMain2;
    QLabel *labelMain2;
    QLineEdit *editSpeed2;
    QLabel *labelSpeed2;
    QLineEdit *editCurrent2;
    QLineEdit *editVoltage2;
    QLabel *labelCurrent2;
    QLabel *labelVoltage2;
    QLineEdit *editMoment2;
    QLabel *labelMoment2;

    void setupUi(QDialog *DlgDrives)
    {
        if (DlgDrives->objectName().isEmpty())
            DlgDrives->setObjectName(QString::fromUtf8("DlgDrives"));
        DlgDrives->resize(591, 495);
        DlgDrives->setBaseSize(QSize(460, 380));
        groupDrive1 = new QGroupBox(DlgDrives);
        groupDrive1->setObjectName(QString::fromUtf8("groupDrive1"));
        groupDrive1->setGeometry(QRect(10, 10, 281, 261));
        labelVersion1 = new QLabel(groupDrive1);
        labelVersion1->setObjectName(QString::fromUtf8("labelVersion1"));
        labelVersion1->setGeometry(QRect(10, 20, 61, 16));
        editVersion1 = new QLineEdit(groupDrive1);
        editVersion1->setObjectName(QString::fromUtf8("editVersion1"));
        editVersion1->setGeometry(QRect(80, 20, 111, 16));
        editVersion1->setAlignment(Qt::AlignCenter);
        editVersion1->setReadOnly(true);
        editSerial1 = new QLineEdit(groupDrive1);
        editSerial1->setObjectName(QString::fromUtf8("editSerial1"));
        editSerial1->setGeometry(QRect(80, 40, 61, 16));
        editSerial1->setAlignment(Qt::AlignCenter);
        editSerial1->setReadOnly(true);
        labelSerial1 = new QLabel(groupDrive1);
        labelSerial1->setObjectName(QString::fromUtf8("labelSerial1"));
        labelSerial1->setGeometry(QRect(10, 40, 61, 16));
        editTime1 = new QLineEdit(groupDrive1);
        editTime1->setObjectName(QString::fromUtf8("editTime1"));
        editTime1->setGeometry(QRect(80, 60, 61, 16));
        editTime1->setAlignment(Qt::AlignCenter);
        editTime1->setReadOnly(true);
        labelTime1 = new QLabel(groupDrive1);
        labelTime1->setObjectName(QString::fromUtf8("labelTime1"));
        labelTime1->setGeometry(QRect(10, 60, 61, 16));
        labelConfig1 = new QLabel(groupDrive1);
        labelConfig1->setObjectName(QString::fromUtf8("labelConfig1"));
        labelConfig1->setGeometry(QRect(10, 80, 61, 16));
        editConfig1 = new QLineEdit(groupDrive1);
        editConfig1->setObjectName(QString::fromUtf8("editConfig1"));
        editConfig1->setGeometry(QRect(80, 80, 31, 16));
        editConfig1->setAlignment(Qt::AlignCenter);
        editConfig1->setReadOnly(true);
        editBan1 = new QLineEdit(groupDrive1);
        editBan1->setObjectName(QString::fromUtf8("editBan1"));
        editBan1->setGeometry(QRect(250, 230, 21, 20));
        editBan1->setAlignment(Qt::AlignCenter);
        editBan1->setReadOnly(true);
        labelBan1 = new QLabel(groupDrive1);
        labelBan1->setObjectName(QString::fromUtf8("labelBan1"));
        labelBan1->setGeometry(QRect(140, 230, 101, 16));
        editDist1 = new QLineEdit(groupDrive1);
        editDist1->setObjectName(QString::fromUtf8("editDist1"));
        editDist1->setGeometry(QRect(100, 230, 21, 20));
        editDist1->setAlignment(Qt::AlignCenter);
        editDist1->setReadOnly(true);
        editAlarm1 = new QLineEdit(groupDrive1);
        editAlarm1->setObjectName(QString::fromUtf8("editAlarm1"));
        editAlarm1->setGeometry(QRect(100, 130, 21, 20));
        editAlarm1->setAlignment(Qt::AlignCenter);
        editAlarm1->setReadOnly(true);
        labelDist1 = new QLabel(groupDrive1);
        labelDist1->setObjectName(QString::fromUtf8("labelDist1"));
        labelDist1->setGeometry(QRect(20, 230, 81, 16));
        editInvertor1 = new QLineEdit(groupDrive1);
        editInvertor1->setObjectName(QString::fromUtf8("editInvertor1"));
        editInvertor1->setGeometry(QRect(100, 210, 21, 20));
        editInvertor1->setAlignment(Qt::AlignCenter);
        editInvertor1->setReadOnly(true);
        editWork1 = new QLineEdit(groupDrive1);
        editWork1->setObjectName(QString::fromUtf8("editWork1"));
        editWork1->setGeometry(QRect(100, 170, 21, 20));
        editWork1->setAlignment(Qt::AlignCenter);
        editWork1->setReadOnly(true);
        labelWarn1 = new QLabel(groupDrive1);
        labelWarn1->setObjectName(QString::fromUtf8("labelWarn1"));
        labelWarn1->setGeometry(QRect(20, 110, 81, 16));
        labelReady1 = new QLabel(groupDrive1);
        labelReady1->setObjectName(QString::fromUtf8("labelReady1"));
        labelReady1->setGeometry(QRect(20, 150, 81, 16));
        labelWork1 = new QLabel(groupDrive1);
        labelWork1->setObjectName(QString::fromUtf8("labelWork1"));
        labelWork1->setGeometry(QRect(20, 170, 81, 16));
        labelInvertor1 = new QLabel(groupDrive1);
        labelInvertor1->setObjectName(QString::fromUtf8("labelInvertor1"));
        labelInvertor1->setGeometry(QRect(20, 210, 81, 16));
        labelAlarm1 = new QLabel(groupDrive1);
        labelAlarm1->setObjectName(QString::fromUtf8("labelAlarm1"));
        labelAlarm1->setGeometry(QRect(20, 130, 81, 16));
        editWarn1 = new QLineEdit(groupDrive1);
        editWarn1->setObjectName(QString::fromUtf8("editWarn1"));
        editWarn1->setGeometry(QRect(100, 110, 21, 20));
        editWarn1->setAlignment(Qt::AlignCenter);
        editWarn1->setReadOnly(true);
        editReady1 = new QLineEdit(groupDrive1);
        editReady1->setObjectName(QString::fromUtf8("editReady1"));
        editReady1->setGeometry(QRect(100, 150, 21, 20));
        editReady1->setAlignment(Qt::AlignCenter);
        editReady1->setReadOnly(true);
        labelHeat1 = new QLabel(groupDrive1);
        labelHeat1->setObjectName(QString::fromUtf8("labelHeat1"));
        labelHeat1->setGeometry(QRect(20, 190, 81, 16));
        editHeat1 = new QLineEdit(groupDrive1);
        editHeat1->setObjectName(QString::fromUtf8("editHeat1"));
        editHeat1->setGeometry(QRect(100, 190, 21, 20));
        editHeat1->setAlignment(Qt::AlignCenter);
        editHeat1->setReadOnly(true);
        editSensor1 = new QLineEdit(groupDrive1);
        editSensor1->setObjectName(QString::fromUtf8("editSensor1"));
        editSensor1->setGeometry(QRect(250, 190, 21, 20));
        editSensor1->setAlignment(Qt::AlignCenter);
        editSensor1->setReadOnly(true);
        labelSensor1 = new QLabel(groupDrive1);
        labelSensor1->setObjectName(QString::fromUtf8("labelSensor1"));
        labelSensor1->setGeometry(QRect(140, 190, 111, 16));
        editPwrReady1 = new QLineEdit(groupDrive1);
        editPwrReady1->setObjectName(QString::fromUtf8("editPwrReady1"));
        editPwrReady1->setGeometry(QRect(250, 210, 21, 20));
        editPwrReady1->setAlignment(Qt::AlignCenter);
        editPwrReady1->setReadOnly(true);
        labelPwrReady1 = new QLabel(groupDrive1);
        labelPwrReady1->setObjectName(QString::fromUtf8("labelPwrReady1"));
        labelPwrReady1->setGeometry(QRect(140, 210, 111, 16));
        editAzimuth1 = new QLineEdit(groupDrive1);
        editAzimuth1->setObjectName(QString::fromUtf8("editAzimuth1"));
        editAzimuth1->setGeometry(QRect(210, 50, 61, 16));
        editAzimuth1->setAlignment(Qt::AlignCenter);
        editAzimuth1->setReadOnly(true);
        labelAzimuth1 = new QLabel(groupDrive1);
        labelAzimuth1->setObjectName(QString::fromUtf8("labelAzimuth1"));
        labelAzimuth1->setGeometry(QRect(160, 50, 51, 16));
        editMain1 = new QLineEdit(groupDrive1);
        editMain1->setObjectName(QString::fromUtf8("editMain1"));
        editMain1->setGeometry(QRect(250, 170, 21, 20));
        editMain1->setMinimumSize(QSize(0, 20));
        editMain1->setAlignment(Qt::AlignCenter);
        editMain1->setReadOnly(true);
        labelMain1 = new QLabel(groupDrive1);
        labelMain1->setObjectName(QString::fromUtf8("labelMain1"));
        labelMain1->setGeometry(QRect(140, 170, 111, 16));
        editSpeed1 = new QLineEdit(groupDrive1);
        editSpeed1->setObjectName(QString::fromUtf8("editSpeed1"));
        editSpeed1->setGeometry(QRect(220, 90, 51, 16));
        editSpeed1->setAlignment(Qt::AlignCenter);
        editSpeed1->setReadOnly(true);
        labelSpeed1 = new QLabel(groupDrive1);
        labelSpeed1->setObjectName(QString::fromUtf8("labelSpeed1"));
        labelSpeed1->setGeometry(QRect(140, 90, 81, 16));
        editCurrent1 = new QLineEdit(groupDrive1);
        editCurrent1->setObjectName(QString::fromUtf8("editCurrent1"));
        editCurrent1->setGeometry(QRect(220, 130, 51, 16));
        editCurrent1->setAlignment(Qt::AlignCenter);
        editCurrent1->setReadOnly(true);
        editVoltage1 = new QLineEdit(groupDrive1);
        editVoltage1->setObjectName(QString::fromUtf8("editVoltage1"));
        editVoltage1->setGeometry(QRect(220, 150, 51, 16));
        editVoltage1->setAlignment(Qt::AlignCenter);
        editVoltage1->setReadOnly(true);
        labelCurrent1 = new QLabel(groupDrive1);
        labelCurrent1->setObjectName(QString::fromUtf8("labelCurrent1"));
        labelCurrent1->setGeometry(QRect(140, 130, 81, 16));
        labelVoltage1 = new QLabel(groupDrive1);
        labelVoltage1->setObjectName(QString::fromUtf8("labelVoltage1"));
        labelVoltage1->setGeometry(QRect(140, 150, 81, 16));
        editMoment1 = new QLineEdit(groupDrive1);
        editMoment1->setObjectName(QString::fromUtf8("editMoment1"));
        editMoment1->setGeometry(QRect(220, 110, 51, 16));
        editMoment1->setAlignment(Qt::AlignCenter);
        editMoment1->setReadOnly(true);
        labelMoment1 = new QLabel(groupDrive1);
        labelMoment1->setObjectName(QString::fromUtf8("labelMoment1"));
        labelMoment1->setGeometry(QRect(140, 110, 81, 16));
        layoutWidget = new QWidget(DlgDrives);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 280, 567, 214));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        groupPorts = new QGroupBox(layoutWidget);
        groupPorts->setObjectName(QString::fromUtf8("groupPorts"));
        gridLayout = new QGridLayout(groupPorts);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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

        port1BadData = new QLineEdit(groupPorts);
        port1BadData->setObjectName(QString::fromUtf8("port1BadData"));
        port1BadData->setEnabled(true);
        port1BadData->setMinimumSize(QSize(40, 0));
        port1BadData->setMaximumSize(QSize(40, 32767));
        port1BadData->setAlignment(Qt::AlignCenter);
        port1BadData->setReadOnly(true);

        gridLayout->addWidget(port1BadData, 5, 1, 1, 1);

        port2BadData = new QLineEdit(groupPorts);
        port2BadData->setObjectName(QString::fromUtf8("port2BadData"));
        port2BadData->setEnabled(true);
        port2BadData->setMinimumSize(QSize(40, 0));
        port2BadData->setMaximumSize(QSize(40, 32767));
        port2BadData->setAlignment(Qt::AlignCenter);
        port2BadData->setReadOnly(true);

        gridLayout->addWidget(port2BadData, 5, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 0, 1, 1);


        horizontalLayout_2->addWidget(groupPorts);

        ctrlGBox = new QGroupBox(layoutWidget);
        ctrlGBox->setObjectName(QString::fromUtf8("ctrlGBox"));
        verticalLayout_2 = new QVBoxLayout(ctrlGBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkManual = new QCheckBox(ctrlGBox);
        checkManual->setObjectName(QString::fromUtf8("checkManual"));

        verticalLayout_2->addWidget(checkManual);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushOn = new QPushButton(ctrlGBox);
        pushOn->setObjectName(QString::fromUtf8("pushOn"));
        pushOn->setCheckable(true);

        horizontalLayout_3->addWidget(pushOn);

        pushOff = new QPushButton(ctrlGBox);
        pushOff->setObjectName(QString::fromUtf8("pushOff"));
        pushOff->setCheckable(true);

        horizontalLayout_3->addWidget(pushOff);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushSet1 = new QPushButton(ctrlGBox);
        pushSet1->setObjectName(QString::fromUtf8("pushSet1"));
        pushSet1->setCheckable(true);

        horizontalLayout_4->addWidget(pushSet1);

        pushSet2 = new QPushButton(ctrlGBox);
        pushSet2->setObjectName(QString::fromUtf8("pushSet2"));
        pushSet2->setCheckable(true);

        horizontalLayout_4->addWidget(pushSet2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        setVelLbl = new QLabel(ctrlGBox);
        setVelLbl->setObjectName(QString::fromUtf8("setVelLbl"));

        horizontalLayout->addWidget(setVelLbl);

        spinSpeed = new QDoubleSpinBox(ctrlGBox);
        spinSpeed->setObjectName(QString::fromUtf8("spinSpeed"));
        spinSpeed->setDecimals(3);
        spinSpeed->setMinimum(-100);
        spinSpeed->setMaximum(100);

        horizontalLayout->addWidget(spinSpeed);


        verticalLayout_2->addLayout(horizontalLayout);

        pushSetSpeed = new QPushButton(ctrlGBox);
        pushSetSpeed->setObjectName(QString::fromUtf8("pushSetSpeed"));

        verticalLayout_2->addWidget(pushSetSpeed);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout_2->addWidget(ctrlGBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushReset = new QPushButton(layoutWidget);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));

        verticalLayout->addWidget(pushReset);

        pushClose = new QPushButton(layoutWidget);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        verticalLayout->addWidget(pushClose);


        horizontalLayout_2->addLayout(verticalLayout);

        groupDrive2 = new QGroupBox(DlgDrives);
        groupDrive2->setObjectName(QString::fromUtf8("groupDrive2"));
        groupDrive2->setGeometry(QRect(300, 10, 281, 261));
        labelVersion2 = new QLabel(groupDrive2);
        labelVersion2->setObjectName(QString::fromUtf8("labelVersion2"));
        labelVersion2->setGeometry(QRect(10, 20, 61, 16));
        editVersion2 = new QLineEdit(groupDrive2);
        editVersion2->setObjectName(QString::fromUtf8("editVersion2"));
        editVersion2->setGeometry(QRect(80, 20, 111, 16));
        editVersion2->setAlignment(Qt::AlignCenter);
        editVersion2->setReadOnly(true);
        editSerial2 = new QLineEdit(groupDrive2);
        editSerial2->setObjectName(QString::fromUtf8("editSerial2"));
        editSerial2->setGeometry(QRect(80, 40, 61, 16));
        editSerial2->setAlignment(Qt::AlignCenter);
        editSerial2->setReadOnly(true);
        labelSerial2 = new QLabel(groupDrive2);
        labelSerial2->setObjectName(QString::fromUtf8("labelSerial2"));
        labelSerial2->setGeometry(QRect(10, 40, 61, 16));
        editTime2 = new QLineEdit(groupDrive2);
        editTime2->setObjectName(QString::fromUtf8("editTime2"));
        editTime2->setGeometry(QRect(80, 60, 61, 16));
        editTime2->setAlignment(Qt::AlignCenter);
        editTime2->setReadOnly(true);
        labelTime2 = new QLabel(groupDrive2);
        labelTime2->setObjectName(QString::fromUtf8("labelTime2"));
        labelTime2->setGeometry(QRect(10, 60, 61, 16));
        labelConfig2 = new QLabel(groupDrive2);
        labelConfig2->setObjectName(QString::fromUtf8("labelConfig2"));
        labelConfig2->setGeometry(QRect(10, 80, 61, 16));
        editConfig2 = new QLineEdit(groupDrive2);
        editConfig2->setObjectName(QString::fromUtf8("editConfig2"));
        editConfig2->setGeometry(QRect(80, 80, 31, 16));
        editConfig2->setAlignment(Qt::AlignCenter);
        editConfig2->setReadOnly(true);
        editBan2 = new QLineEdit(groupDrive2);
        editBan2->setObjectName(QString::fromUtf8("editBan2"));
        editBan2->setGeometry(QRect(250, 230, 21, 20));
        editBan2->setAlignment(Qt::AlignCenter);
        editBan2->setReadOnly(true);
        labelBan2 = new QLabel(groupDrive2);
        labelBan2->setObjectName(QString::fromUtf8("labelBan2"));
        labelBan2->setGeometry(QRect(140, 230, 101, 16));
        editDist2 = new QLineEdit(groupDrive2);
        editDist2->setObjectName(QString::fromUtf8("editDist2"));
        editDist2->setGeometry(QRect(100, 230, 21, 20));
        editDist2->setAlignment(Qt::AlignCenter);
        editDist2->setReadOnly(true);
        editAlarm2 = new QLineEdit(groupDrive2);
        editAlarm2->setObjectName(QString::fromUtf8("editAlarm2"));
        editAlarm2->setGeometry(QRect(100, 130, 21, 20));
        editAlarm2->setAlignment(Qt::AlignCenter);
        editAlarm2->setReadOnly(true);
        labelDist2 = new QLabel(groupDrive2);
        labelDist2->setObjectName(QString::fromUtf8("labelDist2"));
        labelDist2->setGeometry(QRect(20, 230, 81, 16));
        editInvertor2 = new QLineEdit(groupDrive2);
        editInvertor2->setObjectName(QString::fromUtf8("editInvertor2"));
        editInvertor2->setGeometry(QRect(100, 210, 21, 20));
        editInvertor2->setAlignment(Qt::AlignCenter);
        editInvertor2->setReadOnly(true);
        editWork2 = new QLineEdit(groupDrive2);
        editWork2->setObjectName(QString::fromUtf8("editWork2"));
        editWork2->setGeometry(QRect(100, 170, 21, 20));
        editWork2->setAlignment(Qt::AlignCenter);
        editWork2->setReadOnly(true);
        labelWarn2 = new QLabel(groupDrive2);
        labelWarn2->setObjectName(QString::fromUtf8("labelWarn2"));
        labelWarn2->setGeometry(QRect(20, 110, 81, 16));
        labelReady2 = new QLabel(groupDrive2);
        labelReady2->setObjectName(QString::fromUtf8("labelReady2"));
        labelReady2->setGeometry(QRect(20, 150, 81, 16));
        labelWork2 = new QLabel(groupDrive2);
        labelWork2->setObjectName(QString::fromUtf8("labelWork2"));
        labelWork2->setGeometry(QRect(20, 170, 81, 16));
        labelInvertor2 = new QLabel(groupDrive2);
        labelInvertor2->setObjectName(QString::fromUtf8("labelInvertor2"));
        labelInvertor2->setGeometry(QRect(20, 210, 81, 16));
        labelAlarm2 = new QLabel(groupDrive2);
        labelAlarm2->setObjectName(QString::fromUtf8("labelAlarm2"));
        labelAlarm2->setGeometry(QRect(20, 130, 81, 16));
        editWarn2 = new QLineEdit(groupDrive2);
        editWarn2->setObjectName(QString::fromUtf8("editWarn2"));
        editWarn2->setGeometry(QRect(100, 110, 21, 20));
        editWarn2->setAlignment(Qt::AlignCenter);
        editWarn2->setReadOnly(true);
        editReady2 = new QLineEdit(groupDrive2);
        editReady2->setObjectName(QString::fromUtf8("editReady2"));
        editReady2->setGeometry(QRect(100, 150, 21, 20));
        editReady2->setAlignment(Qt::AlignCenter);
        editReady2->setReadOnly(true);
        labelHeat2 = new QLabel(groupDrive2);
        labelHeat2->setObjectName(QString::fromUtf8("labelHeat2"));
        labelHeat2->setGeometry(QRect(20, 190, 81, 16));
        editHeat2 = new QLineEdit(groupDrive2);
        editHeat2->setObjectName(QString::fromUtf8("editHeat2"));
        editHeat2->setGeometry(QRect(100, 190, 21, 20));
        editHeat2->setAlignment(Qt::AlignCenter);
        editHeat2->setReadOnly(true);
        editSensor2 = new QLineEdit(groupDrive2);
        editSensor2->setObjectName(QString::fromUtf8("editSensor2"));
        editSensor2->setGeometry(QRect(250, 190, 21, 20));
        editSensor2->setAlignment(Qt::AlignCenter);
        editSensor2->setReadOnly(true);
        labelSensor2 = new QLabel(groupDrive2);
        labelSensor2->setObjectName(QString::fromUtf8("labelSensor2"));
        labelSensor2->setGeometry(QRect(140, 190, 111, 16));
        editPwrReady2 = new QLineEdit(groupDrive2);
        editPwrReady2->setObjectName(QString::fromUtf8("editPwrReady2"));
        editPwrReady2->setGeometry(QRect(250, 210, 21, 20));
        editPwrReady2->setAlignment(Qt::AlignCenter);
        editPwrReady2->setReadOnly(true);
        labelPwrReady2 = new QLabel(groupDrive2);
        labelPwrReady2->setObjectName(QString::fromUtf8("labelPwrReady2"));
        labelPwrReady2->setGeometry(QRect(140, 210, 111, 16));
        editAzimuth2 = new QLineEdit(groupDrive2);
        editAzimuth2->setObjectName(QString::fromUtf8("editAzimuth2"));
        editAzimuth2->setGeometry(QRect(210, 50, 61, 16));
        editAzimuth2->setAlignment(Qt::AlignCenter);
        editAzimuth2->setReadOnly(true);
        labelAzimuth2 = new QLabel(groupDrive2);
        labelAzimuth2->setObjectName(QString::fromUtf8("labelAzimuth2"));
        labelAzimuth2->setGeometry(QRect(160, 50, 51, 16));
        editMain2 = new QLineEdit(groupDrive2);
        editMain2->setObjectName(QString::fromUtf8("editMain2"));
        editMain2->setGeometry(QRect(250, 170, 21, 20));
        editMain2->setMinimumSize(QSize(0, 20));
        editMain2->setAlignment(Qt::AlignCenter);
        editMain2->setReadOnly(true);
        labelMain2 = new QLabel(groupDrive2);
        labelMain2->setObjectName(QString::fromUtf8("labelMain2"));
        labelMain2->setGeometry(QRect(140, 170, 111, 16));
        editSpeed2 = new QLineEdit(groupDrive2);
        editSpeed2->setObjectName(QString::fromUtf8("editSpeed2"));
        editSpeed2->setGeometry(QRect(220, 90, 51, 16));
        editSpeed2->setAlignment(Qt::AlignCenter);
        editSpeed2->setReadOnly(true);
        labelSpeed2 = new QLabel(groupDrive2);
        labelSpeed2->setObjectName(QString::fromUtf8("labelSpeed2"));
        labelSpeed2->setGeometry(QRect(140, 90, 81, 16));
        editCurrent2 = new QLineEdit(groupDrive2);
        editCurrent2->setObjectName(QString::fromUtf8("editCurrent2"));
        editCurrent2->setGeometry(QRect(220, 130, 51, 16));
        editCurrent2->setAlignment(Qt::AlignCenter);
        editCurrent2->setReadOnly(true);
        editVoltage2 = new QLineEdit(groupDrive2);
        editVoltage2->setObjectName(QString::fromUtf8("editVoltage2"));
        editVoltage2->setGeometry(QRect(220, 150, 51, 16));
        editVoltage2->setAlignment(Qt::AlignCenter);
        editVoltage2->setReadOnly(true);
        labelCurrent2 = new QLabel(groupDrive2);
        labelCurrent2->setObjectName(QString::fromUtf8("labelCurrent2"));
        labelCurrent2->setGeometry(QRect(140, 130, 81, 16));
        labelVoltage2 = new QLabel(groupDrive2);
        labelVoltage2->setObjectName(QString::fromUtf8("labelVoltage2"));
        labelVoltage2->setGeometry(QRect(140, 150, 81, 16));
        editMoment2 = new QLineEdit(groupDrive2);
        editMoment2->setObjectName(QString::fromUtf8("editMoment2"));
        editMoment2->setGeometry(QRect(220, 110, 51, 16));
        editMoment2->setAlignment(Qt::AlignCenter);
        editMoment2->setReadOnly(true);
        labelMoment2 = new QLabel(groupDrive2);
        labelMoment2->setObjectName(QString::fromUtf8("labelMoment2"));
        labelMoment2->setGeometry(QRect(140, 110, 81, 16));
        layoutWidget->raise();
        groupDrive1->raise();
        groupDrive2->raise();
        QWidget::setTabOrder(editAzimuth1, editSpeed1);
        QWidget::setTabOrder(editSpeed1, editWarn1);
        QWidget::setTabOrder(editWarn1, editAlarm1);
        QWidget::setTabOrder(editAlarm1, editReady1);
        QWidget::setTabOrder(editReady1, editHeat1);
        QWidget::setTabOrder(editHeat1, editSensor1);
        QWidget::setTabOrder(editSensor1, editPwrReady1);
        QWidget::setTabOrder(editPwrReady1, checkManual);
        QWidget::setTabOrder(checkManual, spinSpeed);
        QWidget::setTabOrder(spinSpeed, pushClose);

        retranslateUi(DlgDrives);
        QObject::connect(pushClose, SIGNAL(clicked()), DlgDrives, SLOT(hide()));

        QMetaObject::connectSlotsByName(DlgDrives);
    } // setupUi

    void retranslateUi(QDialog *DlgDrives)
    {
        DlgDrives->setWindowTitle(QApplication::translate("DlgDrives", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\221\320\255\320\237", 0, QApplication::UnicodeUTF8));
        groupDrive1->setTitle(QApplication::translate("DlgDrives", "\320\237\321\200\320\270\320\262\320\276\320\264 1", 0, QApplication::UnicodeUTF8));
        labelVersion1->setText(QApplication::translate("DlgDrives", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        editVersion1->setText(QString());
        labelSerial1->setText(QApplication::translate("DlgDrives", "C\320\265\321\200. \342\204\226", 0, QApplication::UnicodeUTF8));
        labelTime1->setText(QApplication::translate("DlgDrives", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        labelConfig1->setText(QApplication::translate("DlgDrives", "\320\232\320\276\320\275\321\204\320\270\320\263.", 0, QApplication::UnicodeUTF8));
        editBan1->setText(QString());
        labelBan1->setText(QApplication::translate("DlgDrives", "\320\267\320\260\320\277\321\200\320\265\321\202 \321\200\320\260\320\261\320\276\321\202\321\213", 0, QApplication::UnicodeUTF8));
        labelDist1->setText(QApplication::translate("DlgDrives", "\320\264\320\270\321\201\321\202 \321\203\320\277\321\200", 0, QApplication::UnicodeUTF8));
        labelWarn1->setText(QApplication::translate("DlgDrives", "\320\262\320\275\320\270\320\274\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelReady1->setText(QApplication::translate("DlgDrives", "\320\263\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        labelWork1->setText(QApplication::translate("DlgDrives", "\321\200\320\260\320\261\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        labelInvertor1->setText(QApplication::translate("DlgDrives", "\320\270\320\275\320\262 \320\262\320\272\320\273", 0, QApplication::UnicodeUTF8));
        labelAlarm1->setText(QApplication::translate("DlgDrives", "\320\260\320\262\320\260\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelHeat1->setText(QApplication::translate("DlgDrives", "\320\277\320\265\321\200\320\265\320\263\321\200\320\265\320\262", 0, QApplication::UnicodeUTF8));
        labelSensor1->setText(QApplication::translate("DlgDrives", "\320\260\320\262\320\260\321\200 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        labelPwrReady1->setText(QApplication::translate("DlgDrives", "\320\263\320\276\321\202.\321\201\320\270\320\273.\320\261\320\273\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
        labelAzimuth1->setText(QApplication::translate("DlgDrives", "\320\220\320\267\320\270\320\274\321\203\321\202", 0, QApplication::UnicodeUTF8));
        labelMain1->setText(QApplication::translate("DlgDrives", "\320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\271", 0, QApplication::UnicodeUTF8));
        labelSpeed1->setText(QApplication::translate("DlgDrives", "\321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelCurrent1->setText(QApplication::translate("DlgDrives", "\321\202\320\276\320\272 \320\262\321\213\321\205", 0, QApplication::UnicodeUTF8));
        labelVoltage1->setText(QApplication::translate("DlgDrives", "\320\275\320\260\320\277\321\200\321\217\320\266", 0, QApplication::UnicodeUTF8));
        labelMoment1->setText(QApplication::translate("DlgDrives", "\320\274\320\276\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        groupPorts->setTitle(QApplication::translate("DlgDrives", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        textLabelPort->setText(QApplication::translate("DlgDrives", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textLabelPort1->setText(QApplication::translate("DlgDrives", "1", 0, QApplication::UnicodeUTF8));
        textLabelPort2->setText(QApplication::translate("DlgDrives", "2", 0, QApplication::UnicodeUTF8));
        textPortOpen->setText(QApplication::translate("DlgDrives", "\320\236\321\202\320\272\321\200\321\213\321\202", 0, QApplication::UnicodeUTF8));
        textPortActive->setText(QApplication::translate("DlgDrives", "\320\220\320\272\321\202\320\270\320\262\320\265\320\275", 0, QApplication::UnicodeUTF8));
        textPortFail->setText(QApplication::translate("DlgDrives", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textPortNoData->setText(QApplication::translate("DlgDrives", "\320\235/\320\224", 0, QApplication::UnicodeUTF8));
        textPortBadData->setText(QApplication::translate("DlgDrives", "\320\241/\320\224", 0, QApplication::UnicodeUTF8));
        ctrlGBox->setTitle(QApplication::translate("DlgDrives", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkManual->setText(QApplication::translate("DlgDrives", "\320\240\321\203\321\207\320\275\320\276\320\265 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushOn->setText(QApplication::translate("DlgDrives", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOff->setText(QApplication::translate("DlgDrives", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushSet1->setText(QApplication::translate("DlgDrives", "I", 0, QApplication::UnicodeUTF8));
        pushSet2->setText(QApplication::translate("DlgDrives", "II", 0, QApplication::UnicodeUTF8));
        setVelLbl->setText(QApplication::translate("DlgDrives", " \320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214, \320\263\321\200\320\260\320\264/\321\201\320\265\320\272 ", 0, QApplication::UnicodeUTF8));
        pushSetSpeed->setText(QApplication::translate("DlgDrives", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushReset->setText(QApplication::translate("DlgDrives", "\320\241\320\261\321\200\320\276\321\201 \320\260\320\262\320\260\321\200\320\270\320\270", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgDrives", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupDrive2->setTitle(QApplication::translate("DlgDrives", "\320\237\321\200\320\270\320\262\320\276\320\264 2", 0, QApplication::UnicodeUTF8));
        labelVersion2->setText(QApplication::translate("DlgDrives", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        editVersion2->setText(QString());
        labelSerial2->setText(QApplication::translate("DlgDrives", "C\320\265\321\200. \342\204\226", 0, QApplication::UnicodeUTF8));
        labelTime2->setText(QApplication::translate("DlgDrives", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        labelConfig2->setText(QApplication::translate("DlgDrives", "\320\232\320\276\320\275\321\204\320\270\320\263.", 0, QApplication::UnicodeUTF8));
        editBan2->setText(QString());
        labelBan2->setText(QApplication::translate("DlgDrives", "\320\267\320\260\320\277\321\200\320\265\321\202 \321\200\320\260\320\261\320\276\321\202\321\213", 0, QApplication::UnicodeUTF8));
        labelDist2->setText(QApplication::translate("DlgDrives", "\320\264\320\270\321\201\321\202 \321\203\320\277\321\200", 0, QApplication::UnicodeUTF8));
        labelWarn2->setText(QApplication::translate("DlgDrives", "\320\262\320\275\320\270\320\274\320\260\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelReady2->setText(QApplication::translate("DlgDrives", "\320\263\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        labelWork2->setText(QApplication::translate("DlgDrives", "\321\200\320\260\320\261\320\276\321\202\320\260", 0, QApplication::UnicodeUTF8));
        labelInvertor2->setText(QApplication::translate("DlgDrives", "\320\270\320\275\320\262 \320\262\320\272\320\273", 0, QApplication::UnicodeUTF8));
        labelAlarm2->setText(QApplication::translate("DlgDrives", "\320\260\320\262\320\260\321\200\320\270\321\217", 0, QApplication::UnicodeUTF8));
        labelHeat2->setText(QApplication::translate("DlgDrives", "\320\277\320\265\321\200\320\265\320\263\321\200\320\265\320\262", 0, QApplication::UnicodeUTF8));
        labelSensor2->setText(QApplication::translate("DlgDrives", "\320\260\320\262\320\260\321\200 \320\264\320\260\321\202\321\207\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        labelPwrReady2->setText(QApplication::translate("DlgDrives", "\320\263\320\276\321\202.\321\201\320\270\320\273.\320\261\320\273\320\276\320\272\320\260", 0, QApplication::UnicodeUTF8));
        labelAzimuth2->setText(QApplication::translate("DlgDrives", "\320\220\320\267\320\270\320\274\321\203\321\202", 0, QApplication::UnicodeUTF8));
        labelMain2->setText(QApplication::translate("DlgDrives", "\320\276\321\201\320\275\320\276\320\262\320\275\320\276\320\271", 0, QApplication::UnicodeUTF8));
        labelSpeed2->setText(QApplication::translate("DlgDrives", "\321\201\320\272\320\276\321\200\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        labelCurrent2->setText(QApplication::translate("DlgDrives", "\321\202\320\276\320\272 \320\262\321\213\321\205", 0, QApplication::UnicodeUTF8));
        labelVoltage2->setText(QApplication::translate("DlgDrives", "\320\275\320\260\320\277\321\200\321\217\320\266", 0, QApplication::UnicodeUTF8));
        labelMoment2->setText(QApplication::translate("DlgDrives", "\320\274\320\276\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgDrives: public Ui_DlgDrives {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRIVES_H
