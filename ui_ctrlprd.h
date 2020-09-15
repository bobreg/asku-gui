/********************************************************************************
** Form generated from reading UI file 'ctrlprd.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLPRD_H
#define UI_CTRLPRD_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgCtrlPrd
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupSelect;
    QHBoxLayout *hboxLayout;
    QLabel *textSelectPrd;
    QComboBox *comboSelectPrd;
    QLabel *textSelectModule;
    QComboBox *comboSelectModule;
    QSpacerItem *spacerSelect;
    QGroupBox *groupControl;
    QGridLayout *gridLayout;
    QGroupBox *groupControlModule;
    QHBoxLayout *hboxLayout1;
    QPushButton *pushModuleOn;
    QPushButton *pushModuleOff;
    QGroupBox *groupControlModule380;
    QHBoxLayout *hboxLayout2;
    QPushButton *pushModule380On;
    QPushButton *pushModule380Off;
    QGroupBox *groupControlPumi;
    QHBoxLayout *hboxLayout3;
    QPushButton *pushPumi1;
    QPushButton *pushPumi2;
    QGroupBox *groupControlReset;
    QHBoxLayout *hboxLayout4;
    QSpacerItem *spacerReset1;
    QPushButton *pushReset;
    QSpacerItem *spacerReset2;
    QGroupBox *groupControlPower;
    QHBoxLayout *hboxLayout5;
    QPushButton *pushPowerOn;
    QPushButton *pushPowerOff;
    QGroupBox *groupControlHotRes;
    QHBoxLayout *hboxLayout6;
    QPushButton *pushHotResOn;
    QPushButton *pushHotResOff;
    QGroupBox *groupControlSVCh;
    QHBoxLayout *hboxLayout7;
    QPushButton *pushSVChOn;
    QPushButton *pushSVChOff;
    QSpacerItem *spacerLine2;
    QSpacerItem *spacerLine3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerClose1;
    QPushButton *pushClose;
    QSpacerItem *spacerClose2;

    void setupUi(QDialog *DlgCtrlPrd)
    {
        if (DlgCtrlPrd->objectName().isEmpty())
            DlgCtrlPrd->setObjectName(QString::fromUtf8("DlgCtrlPrd"));
        DlgCtrlPrd->resize(528, 370);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgCtrlPrd->sizePolicy().hasHeightForWidth());
        DlgCtrlPrd->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DlgCtrlPrd);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupSelect = new QGroupBox(DlgCtrlPrd);
        groupSelect->setObjectName(QString::fromUtf8("groupSelect"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupSelect->sizePolicy().hasHeightForWidth());
        groupSelect->setSizePolicy(sizePolicy1);
        hboxLayout = new QHBoxLayout(groupSelect);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textSelectPrd = new QLabel(groupSelect);
        textSelectPrd->setObjectName(QString::fromUtf8("textSelectPrd"));
        textSelectPrd->setWordWrap(false);

        hboxLayout->addWidget(textSelectPrd);

        comboSelectPrd = new QComboBox(groupSelect);
        comboSelectPrd->setObjectName(QString::fromUtf8("comboSelectPrd"));
        comboSelectPrd->setMinimumSize(QSize(80, 0));
        comboSelectPrd->setMaxVisibleItems(16);

        hboxLayout->addWidget(comboSelectPrd);

        textSelectModule = new QLabel(groupSelect);
        textSelectModule->setObjectName(QString::fromUtf8("textSelectModule"));
        textSelectModule->setWordWrap(false);

        hboxLayout->addWidget(textSelectModule);

        comboSelectModule = new QComboBox(groupSelect);
        comboSelectModule->setObjectName(QString::fromUtf8("comboSelectModule"));
        comboSelectModule->setMinimumSize(QSize(100, 0));
        comboSelectModule->setMaxVisibleItems(16);

        hboxLayout->addWidget(comboSelectModule);

        spacerSelect = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerSelect);


        verticalLayout->addWidget(groupSelect);

        groupControl = new QGroupBox(DlgCtrlPrd);
        groupControl->setObjectName(QString::fromUtf8("groupControl"));
        sizePolicy1.setHeightForWidth(groupControl->sizePolicy().hasHeightForWidth());
        groupControl->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupControl);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupControlModule = new QGroupBox(groupControl);
        groupControlModule->setObjectName(QString::fromUtf8("groupControlModule"));
        hboxLayout1 = new QHBoxLayout(groupControlModule);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        pushModuleOn = new QPushButton(groupControlModule);
        pushModuleOn->setObjectName(QString::fromUtf8("pushModuleOn"));
        pushModuleOn->setMaximumSize(QSize(60, 32767));
        pushModuleOn->setCheckable(true);

        hboxLayout1->addWidget(pushModuleOn);

        pushModuleOff = new QPushButton(groupControlModule);
        pushModuleOff->setObjectName(QString::fromUtf8("pushModuleOff"));
        pushModuleOff->setMaximumSize(QSize(60, 32767));
        pushModuleOff->setCheckable(true);

        hboxLayout1->addWidget(pushModuleOff);


        gridLayout->addWidget(groupControlModule, 1, 1, 1, 1);

        groupControlModule380 = new QGroupBox(groupControl);
        groupControlModule380->setObjectName(QString::fromUtf8("groupControlModule380"));
        hboxLayout2 = new QHBoxLayout(groupControlModule380);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        pushModule380On = new QPushButton(groupControlModule380);
        pushModule380On->setObjectName(QString::fromUtf8("pushModule380On"));
        pushModule380On->setMaximumSize(QSize(60, 32767));
        pushModule380On->setCheckable(true);

        hboxLayout2->addWidget(pushModule380On);

        pushModule380Off = new QPushButton(groupControlModule380);
        pushModule380Off->setObjectName(QString::fromUtf8("pushModule380Off"));
        pushModule380Off->setMaximumSize(QSize(60, 32767));
        pushModule380Off->setCheckable(true);

        hboxLayout2->addWidget(pushModule380Off);


        gridLayout->addWidget(groupControlModule380, 1, 0, 1, 1);

        groupControlPumi = new QGroupBox(groupControl);
        groupControlPumi->setObjectName(QString::fromUtf8("groupControlPumi"));
        hboxLayout3 = new QHBoxLayout(groupControlPumi);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        pushPumi1 = new QPushButton(groupControlPumi);
        pushPumi1->setObjectName(QString::fromUtf8("pushPumi1"));
        pushPumi1->setMaximumSize(QSize(60, 32767));
        pushPumi1->setCheckable(true);

        hboxLayout3->addWidget(pushPumi1);

        pushPumi2 = new QPushButton(groupControlPumi);
        pushPumi2->setObjectName(QString::fromUtf8("pushPumi2"));
        pushPumi2->setMaximumSize(QSize(60, 32767));
        pushPumi2->setCheckable(true);

        hboxLayout3->addWidget(pushPumi2);


        gridLayout->addWidget(groupControlPumi, 0, 1, 1, 1);

        groupControlReset = new QGroupBox(groupControl);
        groupControlReset->setObjectName(QString::fromUtf8("groupControlReset"));
        hboxLayout4 = new QHBoxLayout(groupControlReset);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(11, 11, 11, 11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        spacerReset1 = new QSpacerItem(20, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerReset1);

        pushReset = new QPushButton(groupControlReset);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));
        pushReset->setMaximumSize(QSize(60, 32767));

        hboxLayout4->addWidget(pushReset);

        spacerReset2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout4->addItem(spacerReset2);


        gridLayout->addWidget(groupControlReset, 2, 1, 1, 1);

        groupControlPower = new QGroupBox(groupControl);
        groupControlPower->setObjectName(QString::fromUtf8("groupControlPower"));
        hboxLayout5 = new QHBoxLayout(groupControlPower);
        hboxLayout5->setSpacing(6);
        hboxLayout5->setContentsMargins(11, 11, 11, 11);
        hboxLayout5->setObjectName(QString::fromUtf8("hboxLayout5"));
        pushPowerOn = new QPushButton(groupControlPower);
        pushPowerOn->setObjectName(QString::fromUtf8("pushPowerOn"));
        pushPowerOn->setMaximumSize(QSize(60, 32767));
        pushPowerOn->setCheckable(true);

        hboxLayout5->addWidget(pushPowerOn);

        pushPowerOff = new QPushButton(groupControlPower);
        pushPowerOff->setObjectName(QString::fromUtf8("pushPowerOff"));
        pushPowerOff->setMaximumSize(QSize(60, 32767));
        pushPowerOff->setCheckable(true);

        hboxLayout5->addWidget(pushPowerOff);


        gridLayout->addWidget(groupControlPower, 0, 0, 1, 1);

        groupControlHotRes = new QGroupBox(groupControl);
        groupControlHotRes->setObjectName(QString::fromUtf8("groupControlHotRes"));
        hboxLayout6 = new QHBoxLayout(groupControlHotRes);
        hboxLayout6->setSpacing(6);
        hboxLayout6->setContentsMargins(11, 11, 11, 11);
        hboxLayout6->setObjectName(QString::fromUtf8("hboxLayout6"));
        pushHotResOn = new QPushButton(groupControlHotRes);
        pushHotResOn->setObjectName(QString::fromUtf8("pushHotResOn"));
        pushHotResOn->setMaximumSize(QSize(60, 32767));
        pushHotResOn->setCheckable(true);

        hboxLayout6->addWidget(pushHotResOn);

        pushHotResOff = new QPushButton(groupControlHotRes);
        pushHotResOff->setObjectName(QString::fromUtf8("pushHotResOff"));
        pushHotResOff->setMaximumSize(QSize(60, 32767));
        pushHotResOff->setCheckable(true);

        hboxLayout6->addWidget(pushHotResOff);


        gridLayout->addWidget(groupControlHotRes, 0, 2, 1, 1);

        groupControlSVCh = new QGroupBox(groupControl);
        groupControlSVCh->setObjectName(QString::fromUtf8("groupControlSVCh"));
        hboxLayout7 = new QHBoxLayout(groupControlSVCh);
        hboxLayout7->setSpacing(6);
        hboxLayout7->setContentsMargins(11, 11, 11, 11);
        hboxLayout7->setObjectName(QString::fromUtf8("hboxLayout7"));
        pushSVChOn = new QPushButton(groupControlSVCh);
        pushSVChOn->setObjectName(QString::fromUtf8("pushSVChOn"));
        pushSVChOn->setMaximumSize(QSize(60, 32767));
        pushSVChOn->setCheckable(true);

        hboxLayout7->addWidget(pushSVChOn);

        pushSVChOff = new QPushButton(groupControlSVCh);
        pushSVChOff->setObjectName(QString::fromUtf8("pushSVChOff"));
        pushSVChOff->setMaximumSize(QSize(60, 32767));
        pushSVChOff->setCheckable(true);

        hboxLayout7->addWidget(pushSVChOff);


        gridLayout->addWidget(groupControlSVCh, 2, 0, 1, 1);

        spacerLine2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerLine2, 1, 2, 1, 1);

        spacerLine3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(spacerLine3, 2, 2, 1, 1);


        verticalLayout->addWidget(groupControl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerClose1 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose1);

        pushClose = new QPushButton(DlgCtrlPrd);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        spacerClose2 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(comboSelectPrd, comboSelectModule);
        QWidget::setTabOrder(comboSelectModule, pushPowerOn);
        QWidget::setTabOrder(pushPowerOn, pushPowerOff);
        QWidget::setTabOrder(pushPowerOff, pushPumi1);
        QWidget::setTabOrder(pushPumi1, pushPumi2);
        QWidget::setTabOrder(pushPumi2, pushHotResOn);
        QWidget::setTabOrder(pushHotResOn, pushHotResOff);
        QWidget::setTabOrder(pushHotResOff, pushModule380On);
        QWidget::setTabOrder(pushModule380On, pushModule380Off);
        QWidget::setTabOrder(pushModule380Off, pushModuleOn);
        QWidget::setTabOrder(pushModuleOn, pushModuleOff);
        QWidget::setTabOrder(pushModuleOff, pushSVChOn);
        QWidget::setTabOrder(pushSVChOn, pushSVChOff);
        QWidget::setTabOrder(pushSVChOff, pushReset);
        QWidget::setTabOrder(pushReset, pushClose);

        retranslateUi(DlgCtrlPrd);

        QMetaObject::connectSlotsByName(DlgCtrlPrd);
    } // setupUi

    void retranslateUi(QDialog *DlgCtrlPrd)
    {
        DlgCtrlPrd->setWindowTitle(QApplication::translate("DlgCtrlPrd", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\237\320\240\320\224", 0, QApplication::UnicodeUTF8));
        groupSelect->setTitle(QApplication::translate("DlgCtrlPrd", "\320\222\320\253\320\221\320\236\320\240", 0, QApplication::UnicodeUTF8));
        textSelectPrd->setText(QApplication::translate("DlgCtrlPrd", "\320\237\320\240\320\224", 0, QApplication::UnicodeUTF8));
        comboSelectPrd->clear();
        comboSelectPrd->insertItems(0, QStringList()
         << QApplication::translate("DlgCtrlPrd", "\320\222\320\241\320\225", 0, QApplication::UnicodeUTF8)
        );
        textSelectModule->setText(QApplication::translate("DlgCtrlPrd", "\320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        comboSelectModule->clear();
        comboSelectModule->insertItems(0, QStringList()
         << QApplication::translate("DlgCtrlPrd", "\320\222\320\241\320\225", 0, QApplication::UnicodeUTF8)
        );
        groupControl->setTitle(QApplication::translate("DlgCtrlPrd", "\320\243\320\237\320\240\320\220\320\222\320\233\320\225\320\235\320\230\320\225", 0, QApplication::UnicodeUTF8));
        groupControlModule->setTitle(QApplication::translate("DlgCtrlPrd", "\320\230\320\237 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        pushModuleOn->setText(QApplication::translate("DlgCtrlPrd", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushModuleOff->setText(QApplication::translate("DlgCtrlPrd", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlModule380->setTitle(QApplication::translate("DlgCtrlPrd", "380\320\222 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        pushModule380On->setText(QApplication::translate("DlgCtrlPrd", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushModule380Off->setText(QApplication::translate("DlgCtrlPrd", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlPumi->setTitle(QApplication::translate("DlgCtrlPrd", "\320\237\320\243\320\234", 0, QApplication::UnicodeUTF8));
        pushPumi1->setText(QApplication::translate("DlgCtrlPrd", "I", 0, QApplication::UnicodeUTF8));
        pushPumi2->setText(QApplication::translate("DlgCtrlPrd", "II", 0, QApplication::UnicodeUTF8));
        groupControlReset->setTitle(QApplication::translate("DlgCtrlPrd", "\320\241\320\261\321\200\320\276\321\201 \320\260\320\262\320\260\321\200\320\270\320\270", 0, QApplication::UnicodeUTF8));
        pushReset->setText(QApplication::translate("DlgCtrlPrd", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupControlPower->setTitle(QApplication::translate("DlgCtrlPrd", "\320\237\320\230\320\242 \320\237\320\240\320\224", 0, QApplication::UnicodeUTF8));
        pushPowerOn->setText(QApplication::translate("DlgCtrlPrd", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushPowerOff->setText(QApplication::translate("DlgCtrlPrd", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlHotRes->setTitle(QApplication::translate("DlgCtrlPrd", "\320\223\320\276\321\200\321\217\321\207\320\270\320\271 \321\200\320\265\320\267\320\265\321\200\320\262 \320\237\320\243\320\234", 0, QApplication::UnicodeUTF8));
        pushHotResOn->setText(QApplication::translate("DlgCtrlPrd", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushHotResOff->setText(QApplication::translate("DlgCtrlPrd", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlSVCh->setTitle(QApplication::translate("DlgCtrlPrd", "\320\241\320\222\320\247 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        pushSVChOn->setText(QApplication::translate("DlgCtrlPrd", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushSVChOff->setText(QApplication::translate("DlgCtrlPrd", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgCtrlPrd", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgCtrlPrd: public Ui_DlgCtrlPrd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLPRD_H
