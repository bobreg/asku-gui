/********************************************************************************
** Form generated from reading UI file 'upses.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPSES_H
#define UI_UPSES_H

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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgUpses
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
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
    QGroupBox *groupUps1;
    QGridLayout *gridLayout_3;
    QLabel *textWork1;
    QLineEdit *upsWork1;
    QLabel *textRegime1;
    QLineEdit *upsRegime1;
    QGroupBox *groupUps2;
    QGridLayout *gridLayout_4;
    QLabel *textWork2;
    QLineEdit *upsWork2;
    QLabel *textRegime2;
    QLineEdit *upsRegime2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgUpses)
    {
        if (DlgUpses->objectName().isEmpty())
            DlgUpses->setObjectName(QString::fromUtf8("DlgUpses"));
        DlgUpses->resize(403, 257);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgUpses->sizePolicy().hasHeightForWidth());
        DlgUpses->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(DlgUpses);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 384, 238));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        groupPorts = new QGroupBox(layoutWidget);
        groupPorts->setObjectName(QString::fromUtf8("groupPorts"));
        gridLayout = new QGridLayout(groupPorts);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
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


        gridLayout_2->addWidget(groupPorts, 0, 0, 2, 1);

        groupUps1 = new QGroupBox(layoutWidget);
        groupUps1->setObjectName(QString::fromUtf8("groupUps1"));
        gridLayout_3 = new QGridLayout(groupUps1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        textWork1 = new QLabel(groupUps1);
        textWork1->setObjectName(QString::fromUtf8("textWork1"));
        textWork1->setWordWrap(false);

        gridLayout_3->addWidget(textWork1, 0, 0, 1, 1);

        upsWork1 = new QLineEdit(groupUps1);
        upsWork1->setObjectName(QString::fromUtf8("upsWork1"));
        upsWork1->setEnabled(true);
        upsWork1->setAlignment(Qt::AlignCenter);
        upsWork1->setReadOnly(true);

        gridLayout_3->addWidget(upsWork1, 0, 1, 1, 1);

        textRegime1 = new QLabel(groupUps1);
        textRegime1->setObjectName(QString::fromUtf8("textRegime1"));
        textRegime1->setWordWrap(false);

        gridLayout_3->addWidget(textRegime1, 1, 0, 1, 1);

        upsRegime1 = new QLineEdit(groupUps1);
        upsRegime1->setObjectName(QString::fromUtf8("upsRegime1"));
        upsRegime1->setEnabled(true);
        upsRegime1->setAlignment(Qt::AlignCenter);
        upsRegime1->setReadOnly(true);

        gridLayout_3->addWidget(upsRegime1, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupUps1, 0, 1, 1, 1);

        groupUps2 = new QGroupBox(layoutWidget);
        groupUps2->setObjectName(QString::fromUtf8("groupUps2"));
        gridLayout_4 = new QGridLayout(groupUps2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        textWork2 = new QLabel(groupUps2);
        textWork2->setObjectName(QString::fromUtf8("textWork2"));
        textWork2->setWordWrap(false);

        gridLayout_4->addWidget(textWork2, 0, 0, 1, 1);

        upsWork2 = new QLineEdit(groupUps2);
        upsWork2->setObjectName(QString::fromUtf8("upsWork2"));
        upsWork2->setEnabled(true);
        upsWork2->setAlignment(Qt::AlignCenter);
        upsWork2->setReadOnly(true);

        gridLayout_4->addWidget(upsWork2, 0, 1, 1, 1);

        textRegime2 = new QLabel(groupUps2);
        textRegime2->setObjectName(QString::fromUtf8("textRegime2"));
        textRegime2->setWordWrap(false);

        gridLayout_4->addWidget(textRegime2, 1, 0, 1, 1);

        upsRegime2 = new QLineEdit(groupUps2);
        upsRegime2->setObjectName(QString::fromUtf8("upsRegime2"));
        upsRegime2->setEnabled(true);
        upsRegime2->setAlignment(Qt::AlignCenter);
        upsRegime2->setReadOnly(true);

        gridLayout_4->addWidget(upsRegime2, 1, 1, 1, 1);


        gridLayout_2->addWidget(groupUps2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushClose = new QPushButton(layoutWidget);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        horizontalLayout->addWidget(pushClose);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 2);


        retranslateUi(DlgUpses);

        QMetaObject::connectSlotsByName(DlgUpses);
    } // setupUi

    void retranslateUi(QDialog *DlgUpses)
    {
        DlgUpses->setWindowTitle(QApplication::translate("DlgUpses", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\276\321\202 \320\230\320\221\320\237", 0, QApplication::UnicodeUTF8));
        groupPorts->setTitle(QApplication::translate("DlgUpses", "\320\232\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\202\320\276\321\200\321\213", 0, QApplication::UnicodeUTF8));
        textLabelPort->setText(QApplication::translate("DlgUpses", "\320\237\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        textLabelPort1->setText(QApplication::translate("DlgUpses", "1", 0, QApplication::UnicodeUTF8));
        textLabelPort2->setText(QApplication::translate("DlgUpses", "2", 0, QApplication::UnicodeUTF8));
        textPortOpen->setText(QApplication::translate("DlgUpses", "\320\236\321\202\320\272\321\200\321\213\321\202", 0, QApplication::UnicodeUTF8));
        textPortActive->setText(QApplication::translate("DlgUpses", "\320\220\320\272\321\202\320\270\320\262\320\265\320\275", 0, QApplication::UnicodeUTF8));
        textPortFail->setText(QApplication::translate("DlgUpses", "\320\241\320\261\320\276\320\271", 0, QApplication::UnicodeUTF8));
        textPortNoData->setText(QApplication::translate("DlgUpses", "\320\235/\320\224", 0, QApplication::UnicodeUTF8));
        textPortBadData->setText(QApplication::translate("DlgUpses", "\320\241/\320\224", 0, QApplication::UnicodeUTF8));
        groupUps1->setTitle(QApplication::translate("DlgUpses", "\320\230\320\221\320\237 1", 0, QApplication::UnicodeUTF8));
        textWork1->setText(QApplication::translate("DlgUpses", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textRegime1->setText(QApplication::translate("DlgUpses", "\320\240\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        groupUps2->setTitle(QApplication::translate("DlgUpses", "\320\230\320\221\320\237 2", 0, QApplication::UnicodeUTF8));
        textWork2->setText(QApplication::translate("DlgUpses", "\320\241\320\262\321\217\320\267\321\214", 0, QApplication::UnicodeUTF8));
        textRegime2->setText(QApplication::translate("DlgUpses", "\320\240\320\265\320\266\320\270\320\274", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgUpses", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgUpses: public Ui_DlgUpses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPSES_H
