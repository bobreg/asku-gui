/********************************************************************************
** Form generated from reading UI file 'listrgdv.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTRGDV_H
#define UI_LISTRGDV_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgListRGDV
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelState;
    QTableWidget *tableRgdv;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer1;
    QPushButton *pushClose;
    QSpacerItem *horizontalSpacer2;

    void setupUi(QDialog *DlgListRGDV)
    {
        if (DlgListRGDV->objectName().isEmpty())
            DlgListRGDV->setObjectName(QString::fromUtf8("DlgListRGDV"));
        DlgListRGDV->resize(500, 750);
        DlgListRGDV->setMinimumSize(QSize(400, 600));
        verticalLayout = new QVBoxLayout(DlgListRGDV);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelState = new QLabel(DlgListRGDV);
        labelState->setObjectName(QString::fromUtf8("labelState"));
        labelState->setMinimumSize(QSize(0, 25));
        labelState->setAutoFillBackground(true);
        labelState->setFrameShape(QFrame::Panel);
        labelState->setFrameShadow(QFrame::Raised);
        labelState->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelState);

        tableRgdv = new QTableWidget(DlgListRGDV);
        if (tableRgdv->columnCount() < 3)
            tableRgdv->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableRgdv->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableRgdv->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableRgdv->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableRgdv->setObjectName(QString::fromUtf8("tableRgdv"));
        tableRgdv->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableRgdv->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableRgdv->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableRgdv->setSelectionMode(QAbstractItemView::NoSelection);
        tableRgdv->setShowGrid(false);
        tableRgdv->setGridStyle(Qt::NoPen);
        tableRgdv->setWordWrap(false);
        tableRgdv->setCornerButtonEnabled(false);
        tableRgdv->horizontalHeader()->setDefaultSectionSize(120);
        tableRgdv->horizontalHeader()->setStretchLastSection(true);
        tableRgdv->verticalHeader()->setVisible(false);
        tableRgdv->verticalHeader()->setDefaultSectionSize(18);
        tableRgdv->verticalHeader()->setMinimumSectionSize(18);

        verticalLayout->addWidget(tableRgdv);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer1);

        pushClose = new QPushButton(DlgListRGDV);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DlgListRGDV);

        QMetaObject::connectSlotsByName(DlgListRGDV);
    } // setupUi

    void retranslateUi(QDialog *DlgListRGDV)
    {
        DlgListRGDV->setWindowTitle(QApplication::translate("DlgListRGDV", "\320\240\320\223\320\224\320\222", 0, QApplication::UnicodeUTF8));
        labelState->setText(QApplication::translate("DlgListRGDV", "\320\235\320\236\320\240\320\234\320\220 \320\240\320\223\320\224\320\222", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableRgdv->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DlgListRGDV", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableRgdv->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DlgListRGDV", "\320\250\320\272\320\260\321\204 (\320\261\320\273\320\276\320\272)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableRgdv->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DlgListRGDV", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgListRGDV", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgListRGDV: public Ui_DlgListRGDV {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTRGDV_H
