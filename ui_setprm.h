/********************************************************************************
** Form generated from reading UI file 'setprm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPRM_H
#define UI_SETPRM_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgSetPrm
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupStrobe;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkGsh;
    QCheckBox *checkZu;
    QCheckBox *checkPilot;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelCh1;
    QSpinBox *spinCh1;
    QLabel *labelCh2;
    QSpinBox *spinCh2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkAllow;
    QCheckBox *checkBlock;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgSetPrm)
    {
        if (DlgSetPrm->objectName().isEmpty())
            DlgSetPrm->setObjectName(QString::fromUtf8("DlgSetPrm"));
        DlgSetPrm->resize(323, 162);
        gridLayout_2 = new QGridLayout(DlgSetPrm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupStrobe = new QGroupBox(DlgSetPrm);
        groupStrobe->setObjectName(QString::fromUtf8("groupStrobe"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupStrobe->sizePolicy().hasHeightForWidth());
        groupStrobe->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupStrobe);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkGsh = new QCheckBox(groupStrobe);
        checkGsh->setObjectName(QString::fromUtf8("checkGsh"));

        verticalLayout->addWidget(checkGsh);

        checkZu = new QCheckBox(groupStrobe);
        checkZu->setObjectName(QString::fromUtf8("checkZu"));

        verticalLayout->addWidget(checkZu);

        checkPilot = new QCheckBox(groupStrobe);
        checkPilot->setObjectName(QString::fromUtf8("checkPilot"));

        verticalLayout->addWidget(checkPilot);


        gridLayout_2->addWidget(groupStrobe, 0, 0, 1, 1);

        groupBox = new QGroupBox(DlgSetPrm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelCh1 = new QLabel(groupBox);
        labelCh1->setObjectName(QString::fromUtf8("labelCh1"));

        gridLayout->addWidget(labelCh1, 0, 0, 1, 1);

        spinCh1 = new QSpinBox(groupBox);
        spinCh1->setObjectName(QString::fromUtf8("spinCh1"));
        spinCh1->setMaximum(31);

        gridLayout->addWidget(spinCh1, 0, 1, 1, 1);

        labelCh2 = new QLabel(groupBox);
        labelCh2->setObjectName(QString::fromUtf8("labelCh2"));

        gridLayout->addWidget(labelCh2, 1, 0, 1, 1);

        spinCh2 = new QSpinBox(groupBox);
        spinCh2->setObjectName(QString::fromUtf8("spinCh2"));
        spinCh2->setMaximum(31);

        gridLayout->addWidget(spinCh2, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkAllow = new QCheckBox(DlgSetPrm);
        checkAllow->setObjectName(QString::fromUtf8("checkAllow"));

        horizontalLayout->addWidget(checkAllow);

        checkBlock = new QCheckBox(DlgSetPrm);
        checkBlock->setObjectName(QString::fromUtf8("checkBlock"));

        horizontalLayout->addWidget(checkBlock);

        pushClose = new QPushButton(DlgSetPrm);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        horizontalLayout->addWidget(pushClose);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);

        QWidget::setTabOrder(checkBlock, checkGsh);
        QWidget::setTabOrder(checkGsh, checkZu);
        QWidget::setTabOrder(checkZu, checkPilot);
        QWidget::setTabOrder(checkPilot, spinCh1);
        QWidget::setTabOrder(spinCh1, spinCh2);
        QWidget::setTabOrder(spinCh2, pushClose);

        retranslateUi(DlgSetPrm);

        QMetaObject::connectSlotsByName(DlgSetPrm);
    } // setupUi

    void retranslateUi(QDialog *DlgSetPrm)
    {
        DlgSetPrm->setWindowTitle(QApplication::translate("DlgSetPrm", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\277\321\200\320\270\321\221\320\274\320\275\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        groupStrobe->setTitle(QApplication::translate("DlgSetPrm", "\320\241\321\202\321\200\320\276\320\261\321\213", 0, QApplication::UnicodeUTF8));
        checkGsh->setText(QApplication::translate("DlgSetPrm", "\320\223\320\250", 0, QApplication::UnicodeUTF8));
        checkZu->setText(QApplication::translate("DlgSetPrm", "\320\227\320\243", 0, QApplication::UnicodeUTF8));
        checkPilot->setText(QApplication::translate("DlgSetPrm", "\320\237\320\241", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgSetPrm", "\320\232\320\276\320\264 \320\250\320\220\320\240\320\243", 0, QApplication::UnicodeUTF8));
        labelCh1->setText(QApplication::translate("DlgSetPrm", "\320\232\320\260\320\275\320\260\320\273 \320\241\320\243\320\234\320\234", 0, QApplication::UnicodeUTF8));
        labelCh2->setText(QApplication::translate("DlgSetPrm", "\320\232\320\260\320\275\320\260\320\273 \320\240\320\220\320\227\320\235", 0, QApplication::UnicodeUTF8));
        checkAllow->setText(QApplication::translate("DlgSetPrm", "\320\240\320\260\320\267\321\200\320\265\321\210\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkBlock->setText(QApplication::translate("DlgSetPrm", "\320\221\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgSetPrm", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgSetPrm: public Ui_DlgSetPrm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPRM_H
