/********************************************************************************
** Form generated from reading UI file 'ctrlelk.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLELK_H
#define UI_CTRLELK_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgCtrlElk
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupControl;
    QGridLayout *gridLayout;
    QGroupBox *groupControlOsvPerim;
    QHBoxLayout *hboxLayout;
    QPushButton *pushOsvPerimOn;
    QPushButton *pushOsvPerimOff;
    QGroupBox *groupControlCond;
    QHBoxLayout *hboxLayout1;
    QPushButton *pushCondOn;
    QPushButton *pushCondOff;
    QGroupBox *groupControlReset;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerReset1;
    QPushButton *pushReset;
    QSpacerItem *spacerReset2;
    QGroupBox *groupControlFire;
    QHBoxLayout *hboxLayout3;
    QPushButton *pushFireOn;
    QPushButton *pushFireOff;
    QGroupBox *groupControlGuard;
    QHBoxLayout *hboxLayout4;
    QPushButton *pushGuardOn;
    QPushButton *pushGuardOff;
    QGroupBox *groupControlHowl;
    QHBoxLayout *_2;
    QSpacerItem *spacerHowl1;
    QPushButton *pushTestHowl;
    QSpacerItem *spacerHowl2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerClose1;
    QPushButton *pushClose;
    QSpacerItem *spacerClose2;

    void setupUi(QDialog *DlgCtrlElk)
    {
        if (DlgCtrlElk->objectName().isEmpty())
            DlgCtrlElk->setObjectName(QString::fromUtf8("DlgCtrlElk"));
        DlgCtrlElk->resize(557, 229);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgCtrlElk->sizePolicy().hasHeightForWidth());
        DlgCtrlElk->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(DlgCtrlElk);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupControl = new QGroupBox(DlgCtrlElk);
        groupControl->setObjectName(QString::fromUtf8("groupControl"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupControl->sizePolicy().hasHeightForWidth());
        groupControl->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupControl);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupControlOsvPerim = new QGroupBox(groupControl);
        groupControlOsvPerim->setObjectName(QString::fromUtf8("groupControlOsvPerim"));
        hboxLayout = new QHBoxLayout(groupControlOsvPerim);
        hboxLayout->setSpacing(6);
        hboxLayout->setContentsMargins(11, 11, 11, 11);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        pushOsvPerimOn = new QPushButton(groupControlOsvPerim);
        pushOsvPerimOn->setObjectName(QString::fromUtf8("pushOsvPerimOn"));
        pushOsvPerimOn->setMaximumSize(QSize(60, 32767));
        pushOsvPerimOn->setCheckable(true);

        hboxLayout->addWidget(pushOsvPerimOn);

        pushOsvPerimOff = new QPushButton(groupControlOsvPerim);
        pushOsvPerimOff->setObjectName(QString::fromUtf8("pushOsvPerimOff"));
        pushOsvPerimOff->setMaximumSize(QSize(60, 32767));
        pushOsvPerimOff->setCheckable(true);

        hboxLayout->addWidget(pushOsvPerimOff);


        gridLayout->addWidget(groupControlOsvPerim, 0, 0, 1, 1);

        groupControlCond = new QGroupBox(groupControl);
        groupControlCond->setObjectName(QString::fromUtf8("groupControlCond"));
        hboxLayout1 = new QHBoxLayout(groupControlCond);
        hboxLayout1->setSpacing(6);
        hboxLayout1->setContentsMargins(11, 11, 11, 11);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        pushCondOn = new QPushButton(groupControlCond);
        pushCondOn->setObjectName(QString::fromUtf8("pushCondOn"));
        pushCondOn->setMaximumSize(QSize(60, 32767));
        pushCondOn->setCheckable(true);

        hboxLayout1->addWidget(pushCondOn);

        pushCondOff = new QPushButton(groupControlCond);
        pushCondOff->setObjectName(QString::fromUtf8("pushCondOff"));
        pushCondOff->setMaximumSize(QSize(60, 32767));
        pushCondOff->setCheckable(true);

        hboxLayout1->addWidget(pushCondOff);


        gridLayout->addWidget(groupControlCond, 0, 1, 1, 1);

        groupControlReset = new QGroupBox(groupControl);
        groupControlReset->setObjectName(QString::fromUtf8("groupControlReset"));
        hboxLayout2 = new QHBoxLayout(groupControlReset);
        hboxLayout2->setSpacing(6);
        hboxLayout2->setContentsMargins(11, 11, 11, 11);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        spacerReset1 = new QSpacerItem(20, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerReset1);

        pushReset = new QPushButton(groupControlReset);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));
        pushReset->setMaximumSize(QSize(60, 32767));

        hboxLayout2->addWidget(pushReset);

        spacerReset2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout2->addItem(spacerReset2);


        gridLayout->addWidget(groupControlReset, 0, 2, 1, 1);

        groupControlFire = new QGroupBox(groupControl);
        groupControlFire->setObjectName(QString::fromUtf8("groupControlFire"));
        hboxLayout3 = new QHBoxLayout(groupControlFire);
        hboxLayout3->setSpacing(6);
        hboxLayout3->setContentsMargins(11, 11, 11, 11);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        pushFireOn = new QPushButton(groupControlFire);
        pushFireOn->setObjectName(QString::fromUtf8("pushFireOn"));
        pushFireOn->setMaximumSize(QSize(60, 32767));
        pushFireOn->setCheckable(true);

        hboxLayout3->addWidget(pushFireOn);

        pushFireOff = new QPushButton(groupControlFire);
        pushFireOff->setObjectName(QString::fromUtf8("pushFireOff"));
        pushFireOff->setMaximumSize(QSize(60, 32767));
        pushFireOff->setCheckable(true);

        hboxLayout3->addWidget(pushFireOff);


        gridLayout->addWidget(groupControlFire, 1, 0, 1, 1);

        groupControlGuard = new QGroupBox(groupControl);
        groupControlGuard->setObjectName(QString::fromUtf8("groupControlGuard"));
        hboxLayout4 = new QHBoxLayout(groupControlGuard);
        hboxLayout4->setSpacing(6);
        hboxLayout4->setContentsMargins(11, 11, 11, 11);
        hboxLayout4->setObjectName(QString::fromUtf8("hboxLayout4"));
        pushGuardOn = new QPushButton(groupControlGuard);
        pushGuardOn->setObjectName(QString::fromUtf8("pushGuardOn"));
        pushGuardOn->setMaximumSize(QSize(60, 32767));
        pushGuardOn->setCheckable(true);

        hboxLayout4->addWidget(pushGuardOn);

        pushGuardOff = new QPushButton(groupControlGuard);
        pushGuardOff->setObjectName(QString::fromUtf8("pushGuardOff"));
        pushGuardOff->setMaximumSize(QSize(60, 32767));
        pushGuardOff->setCheckable(true);

        hboxLayout4->addWidget(pushGuardOff);


        gridLayout->addWidget(groupControlGuard, 1, 1, 1, 1);

        groupControlHowl = new QGroupBox(groupControl);
        groupControlHowl->setObjectName(QString::fromUtf8("groupControlHowl"));
        _2 = new QHBoxLayout(groupControlHowl);
        _2->setSpacing(6);
        _2->setContentsMargins(11, 11, 11, 11);
        _2->setObjectName(QString::fromUtf8("_2"));
        spacerHowl1 = new QSpacerItem(20, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerHowl1);

        pushTestHowl = new QPushButton(groupControlHowl);
        pushTestHowl->setObjectName(QString::fromUtf8("pushTestHowl"));
        pushTestHowl->setMaximumSize(QSize(80, 32767));

        _2->addWidget(pushTestHowl);

        spacerHowl2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerHowl2);


        gridLayout->addWidget(groupControlHowl, 1, 2, 1, 1);


        verticalLayout->addWidget(groupControl);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerClose1 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose1);

        pushClose = new QPushButton(DlgCtrlElk);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        spacerClose2 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(pushOsvPerimOn, pushOsvPerimOff);
        QWidget::setTabOrder(pushOsvPerimOff, pushFireOn);
        QWidget::setTabOrder(pushFireOn, pushFireOff);
        QWidget::setTabOrder(pushFireOff, pushGuardOn);
        QWidget::setTabOrder(pushGuardOn, pushGuardOff);
        QWidget::setTabOrder(pushGuardOff, pushCondOn);
        QWidget::setTabOrder(pushCondOn, pushCondOff);
        QWidget::setTabOrder(pushCondOff, pushReset);
        QWidget::setTabOrder(pushReset, pushClose);

        retranslateUi(DlgCtrlElk);

        QMetaObject::connectSlotsByName(DlgCtrlElk);
    } // setupUi

    void retranslateUi(QDialog *DlgCtrlElk)
    {
        DlgCtrlElk->setWindowTitle(QApplication::translate("DlgCtrlElk", "\320\237\320\260\320\275\320\265\320\273\321\214 \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\255\320\233\320\232", 0, QApplication::UnicodeUTF8));
        groupControl->setTitle(QApplication::translate("DlgCtrlElk", "\320\243\320\237\320\240\320\220\320\222\320\233\320\225\320\235\320\230\320\225", 0, QApplication::UnicodeUTF8));
        groupControlOsvPerim->setTitle(QApplication::translate("DlgCtrlElk", "\320\236\320\241\320\222\320\225\320\251 \320\237\320\225\320\240\320\230\320\234", 0, QApplication::UnicodeUTF8));
        pushOsvPerimOn->setText(QApplication::translate("DlgCtrlElk", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushOsvPerimOff->setText(QApplication::translate("DlgCtrlElk", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlCond->setTitle(QApplication::translate("DlgCtrlElk", "\320\227\320\220\320\237\320\240\320\225\320\242 \320\232\320\236\320\235\320\224\320\230\320\246", 0, QApplication::UnicodeUTF8));
        pushCondOn->setText(QApplication::translate("DlgCtrlElk", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushCondOff->setText(QApplication::translate("DlgCtrlElk", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlReset->setTitle(QApplication::translate("DlgCtrlElk", "\320\241\320\261\321\200\320\276\321\201 \320\260\320\262\320\260\321\200\320\270\320\270", 0, QApplication::UnicodeUTF8));
        pushReset->setText(QApplication::translate("DlgCtrlElk", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupControlFire->setTitle(QApplication::translate("DlgCtrlElk", "\320\237\320\236\320\226\320\220\320\240 (\320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\260)", 0, QApplication::UnicodeUTF8));
        pushFireOn->setText(QApplication::translate("DlgCtrlElk", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushFireOff->setText(QApplication::translate("DlgCtrlElk", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlGuard->setTitle(QApplication::translate("DlgCtrlElk", "\320\236\320\245\320\240\320\220\320\235\320\220 (\320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\260)", 0, QApplication::UnicodeUTF8));
        pushGuardOn->setText(QApplication::translate("DlgCtrlElk", "\320\222\320\232\320\233", 0, QApplication::UnicodeUTF8));
        pushGuardOff->setText(QApplication::translate("DlgCtrlElk", "\320\236\320\242\320\232\320\233", 0, QApplication::UnicodeUTF8));
        groupControlHowl->setTitle(QApplication::translate("DlgCtrlElk", "\320\241\320\230\320\240\320\225\320\235\320\220 \320\236\320\237\320\243 (\320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\260)", 0, QApplication::UnicodeUTF8));
        pushTestHowl->setText(QApplication::translate("DlgCtrlElk", "\320\237\321\200\320\276\320\262\320\265\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgCtrlElk", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgCtrlElk: public Ui_DlgCtrlElk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLELK_H
