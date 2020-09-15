/********************************************************************************
** Form generated from reading UI file 'avtomatica.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVTOMATICA_H
#define UI_AVTOMATICA_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgAvtomatica
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupB3_2;
    QFormLayout *formLayout_5;
    QLabel *textDeviceType;
    QLineEdit *DeviceType;
    QLabel *textKeyActual;
    QLineEdit *KeyActual;
    QLabel *textKeyNext;
    QLineEdit *KeyNext;
    QLabel *textCatUnexpended;
    QLineEdit *CatUnexpended;
    QLabel *textCatUnexpended_2;
    QLineEdit *CatExpended;
    QGroupBox *groupService;
    QFormLayout *formLayout;
    QLabel *textLink;
    QLineEdit *Link;
    QLabel *textVersion;
    QLineEdit *Version;
    QLabel *textStatus;
    QLineEdit *Status;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupB1;
    QFormLayout *formLayout_2;
    QLabel *textB1state;
    QLineEdit *B1state;
    QLabel *textB1pult;
    QLineEdit *B1pult;
    QLabel *textB1linkB2;
    QLineEdit *B1linkB2;
    QGroupBox *groupB2;
    QFormLayout *formLayout_3;
    QLabel *textB2state;
    QLineEdit *B2state;
    QLabel *textB2uvk;
    QLineEdit *B2uvk;
    QLabel *textB2linkB3;
    QLineEdit *B2linkB3;
    QGroupBox *groupB3;
    QFormLayout *formLayout_4;
    QLabel *textB3state;
    QLineEdit *B3state;
    QLabel *textB3gsch;
    QLineEdit *B3gsch;
    QLabel *textB3link;
    QLineEdit *B3link;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *spacerClose1;
    QPushButton *pushClose;
    QSpacerItem *spacerClose2;

    void setupUi(QDialog *DlgAvtomatica)
    {
        if (DlgAvtomatica->objectName().isEmpty())
            DlgAvtomatica->setObjectName(QString::fromUtf8("DlgAvtomatica"));
        DlgAvtomatica->resize(635, 435);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgAvtomatica->sizePolicy().hasHeightForWidth());
        DlgAvtomatica->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(DlgAvtomatica);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupB3_2 = new QGroupBox(DlgAvtomatica);
        groupB3_2->setObjectName(QString::fromUtf8("groupB3_2"));
        formLayout_5 = new QFormLayout(groupB3_2);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        textDeviceType = new QLabel(groupB3_2);
        textDeviceType->setObjectName(QString::fromUtf8("textDeviceType"));
        textDeviceType->setMinimumSize(QSize(110, 0));
        textDeviceType->setWordWrap(false);

        formLayout_5->setWidget(0, QFormLayout::LabelRole, textDeviceType);

        DeviceType = new QLineEdit(groupB3_2);
        DeviceType->setObjectName(QString::fromUtf8("DeviceType"));
        DeviceType->setEnabled(true);
        DeviceType->setAlignment(Qt::AlignCenter);
        DeviceType->setReadOnly(true);

        formLayout_5->setWidget(0, QFormLayout::FieldRole, DeviceType);

        textKeyActual = new QLabel(groupB3_2);
        textKeyActual->setObjectName(QString::fromUtf8("textKeyActual"));
        textKeyActual->setMinimumSize(QSize(110, 0));
        textKeyActual->setWordWrap(false);

        formLayout_5->setWidget(1, QFormLayout::LabelRole, textKeyActual);

        KeyActual = new QLineEdit(groupB3_2);
        KeyActual->setObjectName(QString::fromUtf8("KeyActual"));
        KeyActual->setEnabled(true);
        KeyActual->setAlignment(Qt::AlignCenter);
        KeyActual->setReadOnly(true);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, KeyActual);

        textKeyNext = new QLabel(groupB3_2);
        textKeyNext->setObjectName(QString::fromUtf8("textKeyNext"));
        textKeyNext->setMinimumSize(QSize(110, 0));
        textKeyNext->setWordWrap(false);

        formLayout_5->setWidget(2, QFormLayout::LabelRole, textKeyNext);

        KeyNext = new QLineEdit(groupB3_2);
        KeyNext->setObjectName(QString::fromUtf8("KeyNext"));
        KeyNext->setEnabled(true);
        KeyNext->setAlignment(Qt::AlignCenter);
        KeyNext->setReadOnly(true);

        formLayout_5->setWidget(2, QFormLayout::FieldRole, KeyNext);

        textCatUnexpended = new QLabel(groupB3_2);
        textCatUnexpended->setObjectName(QString::fromUtf8("textCatUnexpended"));
        textCatUnexpended->setMinimumSize(QSize(110, 0));
        textCatUnexpended->setWordWrap(false);

        formLayout_5->setWidget(3, QFormLayout::LabelRole, textCatUnexpended);

        CatUnexpended = new QLineEdit(groupB3_2);
        CatUnexpended->setObjectName(QString::fromUtf8("CatUnexpended"));
        CatUnexpended->setEnabled(true);
        CatUnexpended->setAlignment(Qt::AlignCenter);
        CatUnexpended->setReadOnly(true);

        formLayout_5->setWidget(3, QFormLayout::FieldRole, CatUnexpended);

        textCatUnexpended_2 = new QLabel(groupB3_2);
        textCatUnexpended_2->setObjectName(QString::fromUtf8("textCatUnexpended_2"));
        textCatUnexpended_2->setMinimumSize(QSize(110, 0));
        textCatUnexpended_2->setWordWrap(false);

        formLayout_5->setWidget(4, QFormLayout::LabelRole, textCatUnexpended_2);

        CatExpended = new QLineEdit(groupB3_2);
        CatExpended->setObjectName(QString::fromUtf8("CatExpended"));
        CatExpended->setEnabled(true);
        CatExpended->setAlignment(Qt::AlignCenter);
        CatExpended->setReadOnly(true);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, CatExpended);


        verticalLayout_2->addWidget(groupB3_2);

        groupService = new QGroupBox(DlgAvtomatica);
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

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupB1 = new QGroupBox(DlgAvtomatica);
        groupB1->setObjectName(QString::fromUtf8("groupB1"));
        formLayout_2 = new QFormLayout(groupB1);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        textB1state = new QLabel(groupB1);
        textB1state->setObjectName(QString::fromUtf8("textB1state"));
        textB1state->setMinimumSize(QSize(110, 0));
        textB1state->setWordWrap(false);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, textB1state);

        B1state = new QLineEdit(groupB1);
        B1state->setObjectName(QString::fromUtf8("B1state"));
        B1state->setEnabled(true);
        B1state->setAlignment(Qt::AlignCenter);
        B1state->setReadOnly(true);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, B1state);

        textB1pult = new QLabel(groupB1);
        textB1pult->setObjectName(QString::fromUtf8("textB1pult"));
        textB1pult->setMinimumSize(QSize(110, 0));
        textB1pult->setWordWrap(false);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, textB1pult);

        B1pult = new QLineEdit(groupB1);
        B1pult->setObjectName(QString::fromUtf8("B1pult"));
        B1pult->setEnabled(true);
        B1pult->setAlignment(Qt::AlignCenter);
        B1pult->setReadOnly(true);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, B1pult);

        textB1linkB2 = new QLabel(groupB1);
        textB1linkB2->setObjectName(QString::fromUtf8("textB1linkB2"));
        textB1linkB2->setMinimumSize(QSize(110, 0));
        textB1linkB2->setWordWrap(false);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, textB1linkB2);

        B1linkB2 = new QLineEdit(groupB1);
        B1linkB2->setObjectName(QString::fromUtf8("B1linkB2"));
        B1linkB2->setEnabled(true);
        B1linkB2->setAlignment(Qt::AlignCenter);
        B1linkB2->setReadOnly(true);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, B1linkB2);


        verticalLayout->addWidget(groupB1);

        groupB2 = new QGroupBox(DlgAvtomatica);
        groupB2->setObjectName(QString::fromUtf8("groupB2"));
        formLayout_3 = new QFormLayout(groupB2);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        textB2state = new QLabel(groupB2);
        textB2state->setObjectName(QString::fromUtf8("textB2state"));
        textB2state->setMinimumSize(QSize(110, 0));
        textB2state->setWordWrap(false);

        formLayout_3->setWidget(0, QFormLayout::LabelRole, textB2state);

        B2state = new QLineEdit(groupB2);
        B2state->setObjectName(QString::fromUtf8("B2state"));
        B2state->setEnabled(true);
        B2state->setAlignment(Qt::AlignCenter);
        B2state->setReadOnly(true);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, B2state);

        textB2uvk = new QLabel(groupB2);
        textB2uvk->setObjectName(QString::fromUtf8("textB2uvk"));
        textB2uvk->setMinimumSize(QSize(110, 0));
        textB2uvk->setWordWrap(false);

        formLayout_3->setWidget(1, QFormLayout::LabelRole, textB2uvk);

        B2uvk = new QLineEdit(groupB2);
        B2uvk->setObjectName(QString::fromUtf8("B2uvk"));
        B2uvk->setEnabled(true);
        B2uvk->setAlignment(Qt::AlignCenter);
        B2uvk->setReadOnly(true);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, B2uvk);

        textB2linkB3 = new QLabel(groupB2);
        textB2linkB3->setObjectName(QString::fromUtf8("textB2linkB3"));
        textB2linkB3->setMinimumSize(QSize(110, 0));
        textB2linkB3->setWordWrap(false);

        formLayout_3->setWidget(2, QFormLayout::LabelRole, textB2linkB3);

        B2linkB3 = new QLineEdit(groupB2);
        B2linkB3->setObjectName(QString::fromUtf8("B2linkB3"));
        B2linkB3->setEnabled(true);
        B2linkB3->setAlignment(Qt::AlignCenter);
        B2linkB3->setReadOnly(true);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, B2linkB3);


        verticalLayout->addWidget(groupB2);

        groupB3 = new QGroupBox(DlgAvtomatica);
        groupB3->setObjectName(QString::fromUtf8("groupB3"));
        formLayout_4 = new QFormLayout(groupB3);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        textB3state = new QLabel(groupB3);
        textB3state->setObjectName(QString::fromUtf8("textB3state"));
        textB3state->setMinimumSize(QSize(110, 0));
        textB3state->setWordWrap(false);

        formLayout_4->setWidget(0, QFormLayout::LabelRole, textB3state);

        B3state = new QLineEdit(groupB3);
        B3state->setObjectName(QString::fromUtf8("B3state"));
        B3state->setEnabled(true);
        B3state->setAlignment(Qt::AlignCenter);
        B3state->setReadOnly(true);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, B3state);

        textB3gsch = new QLabel(groupB3);
        textB3gsch->setObjectName(QString::fromUtf8("textB3gsch"));
        textB3gsch->setMinimumSize(QSize(110, 0));
        textB3gsch->setWordWrap(false);

        formLayout_4->setWidget(1, QFormLayout::LabelRole, textB3gsch);

        B3gsch = new QLineEdit(groupB3);
        B3gsch->setObjectName(QString::fromUtf8("B3gsch"));
        B3gsch->setEnabled(true);
        B3gsch->setAlignment(Qt::AlignCenter);
        B3gsch->setReadOnly(true);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, B3gsch);

        textB3link = new QLabel(groupB3);
        textB3link->setObjectName(QString::fromUtf8("textB3link"));
        textB3link->setMinimumSize(QSize(110, 0));
        textB3link->setWordWrap(false);

        formLayout_4->setWidget(2, QFormLayout::LabelRole, textB3link);

        B3link = new QLineEdit(groupB3);
        B3link->setObjectName(QString::fromUtf8("B3link"));
        B3link->setEnabled(true);
        B3link->setAlignment(Qt::AlignCenter);
        B3link->setReadOnly(true);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, B3link);


        verticalLayout->addWidget(groupB3);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spacerClose1 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose1);

        pushClose = new QPushButton(DlgAvtomatica);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        spacerClose2 = new QSpacerItem(190, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerClose2);


        verticalLayout_3->addLayout(horizontalLayout);


        retranslateUi(DlgAvtomatica);

        QMetaObject::connectSlotsByName(DlgAvtomatica);
    } // setupUi

    void retranslateUi(QDialog *DlgAvtomatica)
    {
        DlgAvtomatica->setWindowTitle(QApplication::translate("DlgAvtomatica", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\227\320\220\320\236", 0, QApplication::UnicodeUTF8));
        groupB3_2->setTitle(QApplication::translate("DlgAvtomatica", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        textDeviceType->setText(QApplication::translate("DlgAvtomatica", "\320\242\320\270\320\277/\342\204\226 \320\260\320\277\320\277\320\260\321\200\320\260\321\202\320\260", 0, QApplication::UnicodeUTF8));
        textKeyActual->setText(QApplication::translate("DlgAvtomatica", "\320\224\320\265\320\271\321\201\321\202\320\262. \320\272\320\273\321\216\321\207", 0, QApplication::UnicodeUTF8));
        textKeyNext->setText(QApplication::translate("DlgAvtomatica", "\320\232\320\273\321\216\321\207 \320\275\320\260 \321\201\320\274\320\265\320\275\321\203", 0, QApplication::UnicodeUTF8));
        textCatUnexpended->setText(QApplication::translate("DlgAvtomatica", "\320\235\320\265\320\270\320\267\321\200\320\260\321\201\321\205\320\276\320\264. \320\272\320\260\321\202.", 0, QApplication::UnicodeUTF8));
        textCatUnexpended_2->setText(QApplication::translate("DlgAvtomatica", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\276 \320\272\320\260\321\202.", 0, QApplication::UnicodeUTF8));
        groupService->setTitle(QApplication::translate("DlgAvtomatica", "\320\241\320\265\321\200\320\262\320\270\321\201", 0, QApplication::UnicodeUTF8));
        textLink->setText(QApplication::translate("DlgAvtomatica", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textVersion->setText(QApplication::translate("DlgAvtomatica", "\320\222\320\265\321\200\321\201\320\270\321\217", 0, QApplication::UnicodeUTF8));
        textStatus->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\320\260\321\202\321\203\321\201", 0, QApplication::UnicodeUTF8));
        groupB1->setTitle(QApplication::translate("DlgAvtomatica", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\321\214 \320\2221", 0, QApplication::UnicodeUTF8));
        textB1state->setText(QApplication::translate("DlgAvtomatica", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        textB1pult->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\321\213\320\272 \321\201 \320\277\321\203\320\273\321\214\321\202\320\276\320\274", 0, QApplication::UnicodeUTF8));
        textB1linkB2->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\321\213\320\272 \321\201 \320\2222", 0, QApplication::UnicodeUTF8));
        groupB2->setTitle(QApplication::translate("DlgAvtomatica", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\321\214 \320\2222", 0, QApplication::UnicodeUTF8));
        textB2state->setText(QApplication::translate("DlgAvtomatica", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        textB2uvk->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\321\213\320\272 \321\201 \320\243\320\222\320\232", 0, QApplication::UnicodeUTF8));
        textB2linkB3->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\321\213\320\272 \321\201 \320\2223", 0, QApplication::UnicodeUTF8));
        groupB3->setTitle(QApplication::translate("DlgAvtomatica", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\320\265\320\273\321\214 \320\2223", 0, QApplication::UnicodeUTF8));
        textB3state->setText(QApplication::translate("DlgAvtomatica", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        textB3gsch->setText(QApplication::translate("DlgAvtomatica", "\320\223\320\241\320\247", 0, QApplication::UnicodeUTF8));
        textB3link->setText(QApplication::translate("DlgAvtomatica", "\320\241\321\202\321\213\320\272 \321\201 \320\227\320\260\320\277\321\200.", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgAvtomatica", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgAvtomatica: public Ui_DlgAvtomatica {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVTOMATICA_H
