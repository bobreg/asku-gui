/********************************************************************************
** Form generated from reading UI file 'powermeter.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERMETER_H
#define UI_POWERMETER_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
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

class Ui_DlgPowerMeter
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupState;
    QGridLayout *gridLayout;
    QLineEdit *Name;
    QGroupBox *groupService;
    QFormLayout *formLayout;
    QLabel *textLink;
    QLineEdit *Link;
    QLabel *textVersion;
    QLineEdit *Version;
    QLabel *textStatus;
    QLineEdit *Status;
    QGroupBox *groupMeasure;
    QHBoxLayout *_2;
    QSpacerItem *spacerReset1;
    QPushButton *pushMeasure;
    QPushButton *pushReset;
    QSpacerItem *spacerReset2;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *Value;
    QGroupBox *groupKoeff;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Koeff;
    QGroupBox *groupPower;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *Power;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerClose1;
    QPushButton *pushClose;
    QSpacerItem *spacerClose2;

    void setupUi(QDialog *DlgPowerMeter)
    {
        if (DlgPowerMeter->objectName().isEmpty())
            DlgPowerMeter->setObjectName(QString::fromUtf8("DlgPowerMeter"));
        DlgPowerMeter->resize(694, 333);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgPowerMeter->sizePolicy().hasHeightForWidth());
        DlgPowerMeter->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(DlgPowerMeter);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupState = new QGroupBox(DlgPowerMeter);
        groupState->setObjectName(QString::fromUtf8("groupState"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupState->sizePolicy().hasHeightForWidth());
        groupState->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(groupState);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Name = new QLineEdit(groupState);
        Name->setObjectName(QString::fromUtf8("Name"));
        Name->setEnabled(true);
        Name->setMinimumSize(QSize(400, 0));
        Name->setAlignment(Qt::AlignCenter);
        Name->setReadOnly(true);

        gridLayout->addWidget(Name, 0, 0, 1, 1);


        verticalLayout_2->addWidget(groupState);

        groupService = new QGroupBox(DlgPowerMeter);
        groupService->setObjectName(QString::fromUtf8("groupService"));
        formLayout = new QFormLayout(groupService);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        textLink = new QLabel(groupService);
        textLink->setObjectName(QString::fromUtf8("textLink"));
        textLink->setWordWrap(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, textLink);

        Link = new QLineEdit(groupService);
        Link->setObjectName(QString::fromUtf8("Link"));
        Link->setEnabled(true);
        Link->setAlignment(Qt::AlignCenter);
        Link->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, Link);

        textVersion = new QLabel(groupService);
        textVersion->setObjectName(QString::fromUtf8("textVersion"));
        textVersion->setWordWrap(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, textVersion);

        Version = new QLineEdit(groupService);
        Version->setObjectName(QString::fromUtf8("Version"));
        Version->setEnabled(true);
        Version->setAlignment(Qt::AlignCenter);
        Version->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, Version);

        textStatus = new QLabel(groupService);
        textStatus->setObjectName(QString::fromUtf8("textStatus"));
        textStatus->setWordWrap(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, textStatus);

        Status = new QLineEdit(groupService);
        Status->setObjectName(QString::fromUtf8("Status"));
        Status->setEnabled(true);
        Status->setAlignment(Qt::AlignCenter);
        Status->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, Status);


        verticalLayout_2->addWidget(groupService);

        groupMeasure = new QGroupBox(DlgPowerMeter);
        groupMeasure->setObjectName(QString::fromUtf8("groupMeasure"));
        _2 = new QHBoxLayout(groupMeasure);
        _2->setSpacing(6);
        _2->setContentsMargins(11, 11, 11, 11);
        _2->setObjectName(QString::fromUtf8("_2"));
        spacerReset1 = new QSpacerItem(20, 16, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerReset1);

        pushMeasure = new QPushButton(groupMeasure);
        pushMeasure->setObjectName(QString::fromUtf8("pushMeasure"));
        pushMeasure->setMaximumSize(QSize(80, 32767));

        _2->addWidget(pushMeasure);

        pushReset = new QPushButton(groupMeasure);
        pushReset->setObjectName(QString::fromUtf8("pushReset"));
        pushReset->setMaximumSize(QSize(80, 32767));

        _2->addWidget(pushReset);

        spacerReset2 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        _2->addItem(spacerReset2);


        verticalLayout_2->addWidget(groupMeasure);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(DlgPowerMeter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Value = new QLineEdit(groupBox);
        Value->setObjectName(QString::fromUtf8("Value"));
        Value->setEnabled(true);
        Value->setAlignment(Qt::AlignCenter);
        Value->setReadOnly(true);

        horizontalLayout_2->addWidget(Value);


        verticalLayout->addWidget(groupBox);

        groupKoeff = new QGroupBox(DlgPowerMeter);
        groupKoeff->setObjectName(QString::fromUtf8("groupKoeff"));
        horizontalLayout_3 = new QHBoxLayout(groupKoeff);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Koeff = new QLineEdit(groupKoeff);
        Koeff->setObjectName(QString::fromUtf8("Koeff"));
        Koeff->setEnabled(true);
        Koeff->setAlignment(Qt::AlignCenter);
        Koeff->setReadOnly(true);

        horizontalLayout_3->addWidget(Koeff);


        verticalLayout->addWidget(groupKoeff);

        groupPower = new QGroupBox(DlgPowerMeter);
        groupPower->setObjectName(QString::fromUtf8("groupPower"));
        horizontalLayout_4 = new QHBoxLayout(groupPower);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        Power = new QLineEdit(groupPower);
        Power->setObjectName(QString::fromUtf8("Power"));
        Power->setEnabled(true);
        Power->setAlignment(Qt::AlignCenter);
        Power->setReadOnly(true);

        horizontalLayout_4->addWidget(Power);


        verticalLayout->addWidget(groupPower);


        horizontalLayout_5->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerClose1 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose1);

        pushClose = new QPushButton(DlgPowerMeter);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        spacerClose2 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(DlgPowerMeter);

        QMetaObject::connectSlotsByName(DlgPowerMeter);
    } // setupUi

    void retranslateUi(QDialog *DlgPowerMeter)
    {
        DlgPowerMeter->setWindowTitle(QApplication::translate("DlgPowerMeter", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\270\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\217 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\320\270", 0, QApplication::UnicodeUTF8));
        groupState->setTitle(QApplication::translate("DlgPowerMeter", "\320\230\320\267\320\274\320\265\321\200\320\270\321\202\320\265\320\273\321\214", 0, QApplication::UnicodeUTF8));
        groupService->setTitle(QApplication::translate("DlgPowerMeter", "\320\241\320\265\321\200\320\262\320\270\321\201", 0, QApplication::UnicodeUTF8));
        textLink->setText(QApplication::translate("DlgPowerMeter", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textVersion->setText(QApplication::translate("DlgPowerMeter", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        textStatus->setText(QApplication::translate("DlgPowerMeter", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        groupMeasure->setTitle(QApplication::translate("DlgPowerMeter", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushMeasure->setText(QApplication::translate("DlgPowerMeter", "\320\230\320\267\320\274\320\265\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushReset->setText(QApplication::translate("DlgPowerMeter", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgPowerMeter", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265, \320\274\320\222\321\202", 0, QApplication::UnicodeUTF8));
        groupKoeff->setTitle(QApplication::translate("DlgPowerMeter", "\320\227\320\260\321\202\321\203\321\205\320\260\320\275\320\270\320\265 \320\235\320\236, \320\264\320\221", 0, QApplication::UnicodeUTF8));
        groupPower->setTitle(QApplication::translate("DlgPowerMeter", "\320\234\320\276\321\211\320\275\320\276\321\201\321\202\321\214, \320\222\321\202", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgPowerMeter", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgPowerMeter: public Ui_DlgPowerMeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERMETER_H
