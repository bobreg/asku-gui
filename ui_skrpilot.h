/********************************************************************************
** Form generated from reading UI file 'skrpilot.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKRPILOT_H
#define UI_SKRPILOT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgSkrPilot
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QSpinBox *spinPS;
    QLabel *labelSKR;
    QLabel *labelPS;
    QLabel *labelPeriod;
    QSpinBox *spinPeriod;
    QSpinBox *spinSKR;
    QLabel *labelHint;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushApply;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushClose;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DlgSkrPilot)
    {
        if (DlgSkrPilot->objectName().isEmpty())
            DlgSkrPilot->setObjectName(QString::fromUtf8("DlgSkrPilot"));
        DlgSkrPilot->resize(238, 211);
        verticalLayout = new QVBoxLayout(DlgSkrPilot);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DlgSkrPilot);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        spinPS = new QSpinBox(groupBox);
        spinPS->setObjectName(QString::fromUtf8("spinPS"));
        spinPS->setMaximum(255);

        gridLayout->addWidget(spinPS, 1, 1, 1, 1);

        labelSKR = new QLabel(groupBox);
        labelSKR->setObjectName(QString::fromUtf8("labelSKR"));

        gridLayout->addWidget(labelSKR, 0, 0, 1, 1);

        labelPS = new QLabel(groupBox);
        labelPS->setObjectName(QString::fromUtf8("labelPS"));

        gridLayout->addWidget(labelPS, 1, 0, 1, 1);

        labelPeriod = new QLabel(groupBox);
        labelPeriod->setObjectName(QString::fromUtf8("labelPeriod"));

        gridLayout->addWidget(labelPeriod, 2, 0, 1, 1);

        spinPeriod = new QSpinBox(groupBox);
        spinPeriod->setObjectName(QString::fromUtf8("spinPeriod"));
        spinPeriod->setMaximum(31);

        gridLayout->addWidget(spinPeriod, 2, 1, 1, 1);

        spinSKR = new QSpinBox(groupBox);
        spinSKR->setObjectName(QString::fromUtf8("spinSKR"));
        spinSKR->setMaximum(255);

        gridLayout->addWidget(spinSKR, 0, 1, 1, 1);

        labelHint = new QLabel(groupBox);
        labelHint->setObjectName(QString::fromUtf8("labelHint"));
        labelHint->setWordWrap(true);

        gridLayout->addWidget(labelHint, 3, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushApply = new QPushButton(DlgSkrPilot);
        pushApply->setObjectName(QString::fromUtf8("pushApply"));

        horizontalLayout->addWidget(pushApply);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushClose = new QPushButton(DlgSkrPilot);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        horizontalLayout->addWidget(pushClose);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DlgSkrPilot);
        QObject::connect(pushClose, SIGNAL(clicked()), DlgSkrPilot, SLOT(hide()));

        QMetaObject::connectSlotsByName(DlgSkrPilot);
    } // setupUi

    void retranslateUi(QDialog *DlgSkrPilot)
    {
        DlgSkrPilot->setWindowTitle(QApplication::translate("DlgSkrPilot", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\241\320\232\320\240 \320\270 \320\237\320\241", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        labelSKR->setText(QApplication::translate("DlgSkrPilot", "\320\220\320\267\320\270\320\274\321\203\321\202 \320\241\320\232\320\240", 0, QApplication::UnicodeUTF8));
        labelPS->setText(QApplication::translate("DlgSkrPilot", "\320\220\320\267\320\270\320\274\321\203\321\202 \320\237\320\241", 0, QApplication::UnicodeUTF8));
        labelPeriod->setText(QApplication::translate("DlgSkrPilot", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214*", 0, QApplication::UnicodeUTF8));
        labelHint->setText(QApplication::translate("DlgSkrPilot", "* 0 - \320\276\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\241\320\232\320\240 \320\270 \320\237\320\241", 0, QApplication::UnicodeUTF8));
        pushApply->setText(QApplication::translate("DlgSkrPilot", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgSkrPilot", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgSkrPilot: public Ui_DlgSkrPilot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKRPILOT_H
