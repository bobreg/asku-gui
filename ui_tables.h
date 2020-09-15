/********************************************************************************
** Form generated from reading UI file 'tables.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLES_H
#define UI_TABLES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DlgDASDTables
{
public:
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tabSwitch;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboSwitch;
    QSpacerItem *spacerSwitch;
    QVBoxLayout *verticalLayoutSwitch;
    QSpacerItem *verticalSpacerSwitch1;
    QPushButton *pushSwitchAdd;
    QPushButton *pushSwitchUp;
    QPushButton *pushSwitchDown;
    QPushButton *pushSwitchDelete;
    QSpacerItem *verticalSpacerSwitch2;
    QTableWidget *tableSwitch;
    QWidget *tabMode;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *comboMode;
    QSpacerItem *spacerMode;
    QTableWidget *tableMode;
    QVBoxLayout *verticalLayoutMode;
    QSpacerItem *verticalSpacerMode1;
    QPushButton *pushModeAdd;
    QPushButton *pushModeUp;
    QPushButton *pushModeDown;
    QPushButton *pushModeDelete;
    QSpacerItem *verticalSpacerMode2;
    QWidget *tabImpulse;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboRipch;
    QSpacerItem *spacerRipch;
    QTableWidget *tableRipch;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacerRipch1;
    QPushButton *pushRipchAdd;
    QPushButton *pushRipchUp;
    QPushButton *pushRipchDown;
    QPushButton *pushRipchDelete;
    QSpacerItem *verticalSpacerRipch2;
    QWidget *tabDisable;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QTableWidget *tableDisable;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacerDisable1;
    QPushButton *pushDisableAdd;
    QPushButton *pushDisableUp;
    QPushButton *pushDisableDown;
    QPushButton *pushDisableDelete;
    QSpacerItem *verticalSpacerDisable2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushRefresh;
    QPushButton *pushRefreshFiles;
    QPushButton *pushSaveFiles;
    QPushButton *pushSaveModule;
    QSpacerItem *spacerButtons;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgDASDTables)
    {
        if (DlgDASDTables->objectName().isEmpty())
            DlgDASDTables->setObjectName(QString::fromUtf8("DlgDASDTables"));
        DlgDASDTables->resize(832, 600);
        verticalLayout_2 = new QVBoxLayout(DlgDASDTables);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(DlgDASDTables);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(150, 0));
        tabSwitch = new QWidget();
        tabSwitch->setObjectName(QString::fromUtf8("tabSwitch"));
        verticalLayout_3 = new QVBoxLayout(tabSwitch);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboSwitch = new QComboBox(tabSwitch);
        comboSwitch->setObjectName(QString::fromUtf8("comboSwitch"));
        comboSwitch->setMinimumSize(QSize(150, 0));
        comboSwitch->setMaxVisibleItems(16);

        horizontalLayout_5->addWidget(comboSwitch);

        spacerSwitch = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(spacerSwitch);


        gridLayout->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        verticalLayoutSwitch = new QVBoxLayout();
        verticalLayoutSwitch->setObjectName(QString::fromUtf8("verticalLayoutSwitch"));
        verticalSpacerSwitch1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutSwitch->addItem(verticalSpacerSwitch1);

        pushSwitchAdd = new QPushButton(tabSwitch);
        pushSwitchAdd->setObjectName(QString::fromUtf8("pushSwitchAdd"));

        verticalLayoutSwitch->addWidget(pushSwitchAdd);

        pushSwitchUp = new QPushButton(tabSwitch);
        pushSwitchUp->setObjectName(QString::fromUtf8("pushSwitchUp"));

        verticalLayoutSwitch->addWidget(pushSwitchUp);

        pushSwitchDown = new QPushButton(tabSwitch);
        pushSwitchDown->setObjectName(QString::fromUtf8("pushSwitchDown"));

        verticalLayoutSwitch->addWidget(pushSwitchDown);

        pushSwitchDelete = new QPushButton(tabSwitch);
        pushSwitchDelete->setObjectName(QString::fromUtf8("pushSwitchDelete"));

        verticalLayoutSwitch->addWidget(pushSwitchDelete);

        verticalSpacerSwitch2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutSwitch->addItem(verticalSpacerSwitch2);


        gridLayout->addLayout(verticalLayoutSwitch, 0, 1, 2, 1);

        tableSwitch = new QTableWidget(tabSwitch);
        tableSwitch->setObjectName(QString::fromUtf8("tableSwitch"));
        tableSwitch->setAlternatingRowColors(true);
        tableSwitch->setSelectionMode(QAbstractItemView::SingleSelection);
        tableSwitch->setCornerButtonEnabled(false);
        tableSwitch->horizontalHeader()->setDefaultSectionSize(166);
        tableSwitch->horizontalHeader()->setMinimumSectionSize(18);
        tableSwitch->verticalHeader()->setDefaultSectionSize(18);

        gridLayout->addWidget(tableSwitch, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        tabWidget->addTab(tabSwitch, QString());
        tabMode = new QWidget();
        tabMode->setObjectName(QString::fromUtf8("tabMode"));
        verticalLayout_4 = new QVBoxLayout(tabMode);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        comboMode = new QComboBox(tabMode);
        comboMode->setObjectName(QString::fromUtf8("comboMode"));
        comboMode->setMinimumSize(QSize(150, 0));
        comboMode->setMaxVisibleItems(16);

        horizontalLayout_3->addWidget(comboMode);

        spacerMode = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(spacerMode);


        gridLayout_2->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        tableMode = new QTableWidget(tabMode);
        tableMode->setObjectName(QString::fromUtf8("tableMode"));
        tableMode->setAlternatingRowColors(true);
        tableMode->setSelectionMode(QAbstractItemView::SingleSelection);
        tableMode->setCornerButtonEnabled(false);
        tableMode->horizontalHeader()->setDefaultSectionSize(150);
        tableMode->verticalHeader()->setDefaultSectionSize(18);

        gridLayout_2->addWidget(tableMode, 1, 0, 1, 1);

        verticalLayoutMode = new QVBoxLayout();
        verticalLayoutMode->setObjectName(QString::fromUtf8("verticalLayoutMode"));
        verticalSpacerMode1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutMode->addItem(verticalSpacerMode1);

        pushModeAdd = new QPushButton(tabMode);
        pushModeAdd->setObjectName(QString::fromUtf8("pushModeAdd"));

        verticalLayoutMode->addWidget(pushModeAdd);

        pushModeUp = new QPushButton(tabMode);
        pushModeUp->setObjectName(QString::fromUtf8("pushModeUp"));

        verticalLayoutMode->addWidget(pushModeUp);

        pushModeDown = new QPushButton(tabMode);
        pushModeDown->setObjectName(QString::fromUtf8("pushModeDown"));

        verticalLayoutMode->addWidget(pushModeDown);

        pushModeDelete = new QPushButton(tabMode);
        pushModeDelete->setObjectName(QString::fromUtf8("pushModeDelete"));

        verticalLayoutMode->addWidget(pushModeDelete);

        verticalSpacerMode2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutMode->addItem(verticalSpacerMode2);


        gridLayout_2->addLayout(verticalLayoutMode, 0, 1, 2, 1);


        verticalLayout_4->addLayout(gridLayout_2);

        tabWidget->addTab(tabMode, QString());
        tabImpulse = new QWidget();
        tabImpulse->setObjectName(QString::fromUtf8("tabImpulse"));
        verticalLayout_5 = new QVBoxLayout(tabImpulse);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboRipch = new QComboBox(tabImpulse);
        comboRipch->setObjectName(QString::fromUtf8("comboRipch"));
        comboRipch->setMinimumSize(QSize(150, 0));
        comboRipch->setMaxVisibleItems(16);

        horizontalLayout_4->addWidget(comboRipch);

        spacerRipch = new QSpacerItem(128, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(spacerRipch);


        gridLayout_3->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        tableRipch = new QTableWidget(tabImpulse);
        tableRipch->setObjectName(QString::fromUtf8("tableRipch"));
        tableRipch->setAlternatingRowColors(true);
        tableRipch->setSelectionMode(QAbstractItemView::SingleSelection);
        tableRipch->setCornerButtonEnabled(false);
        tableRipch->horizontalHeader()->setDefaultSectionSize(85);
        tableRipch->verticalHeader()->setDefaultSectionSize(18);

        gridLayout_3->addWidget(tableRipch, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacerRipch1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacerRipch1);

        pushRipchAdd = new QPushButton(tabImpulse);
        pushRipchAdd->setObjectName(QString::fromUtf8("pushRipchAdd"));

        verticalLayout->addWidget(pushRipchAdd);

        pushRipchUp = new QPushButton(tabImpulse);
        pushRipchUp->setObjectName(QString::fromUtf8("pushRipchUp"));

        verticalLayout->addWidget(pushRipchUp);

        pushRipchDown = new QPushButton(tabImpulse);
        pushRipchDown->setObjectName(QString::fromUtf8("pushRipchDown"));

        verticalLayout->addWidget(pushRipchDown);

        pushRipchDelete = new QPushButton(tabImpulse);
        pushRipchDelete->setObjectName(QString::fromUtf8("pushRipchDelete"));

        verticalLayout->addWidget(pushRipchDelete);

        verticalSpacerRipch2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacerRipch2);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 2, 1);


        verticalLayout_5->addLayout(gridLayout_3);

        tabWidget->addTab(tabImpulse, QString());
        tabDisable = new QWidget();
        tabDisable->setObjectName(QString::fromUtf8("tabDisable"));
        gridLayout_5 = new QGridLayout(tabDisable);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        tableDisable = new QTableWidget(tabDisable);
        tableDisable->setObjectName(QString::fromUtf8("tableDisable"));
        tableDisable->setAlternatingRowColors(true);
        tableDisable->setSelectionMode(QAbstractItemView::SingleSelection);
        tableDisable->setCornerButtonEnabled(false);
        tableDisable->horizontalHeader()->setDefaultSectionSize(85);
        tableDisable->verticalHeader()->setDefaultSectionSize(18);

        gridLayout_4->addWidget(tableDisable, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacerDisable1 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacerDisable1);

        pushDisableAdd = new QPushButton(tabDisable);
        pushDisableAdd->setObjectName(QString::fromUtf8("pushDisableAdd"));

        verticalLayout_6->addWidget(pushDisableAdd);

        pushDisableUp = new QPushButton(tabDisable);
        pushDisableUp->setObjectName(QString::fromUtf8("pushDisableUp"));

        verticalLayout_6->addWidget(pushDisableUp);

        pushDisableDown = new QPushButton(tabDisable);
        pushDisableDown->setObjectName(QString::fromUtf8("pushDisableDown"));

        verticalLayout_6->addWidget(pushDisableDown);

        pushDisableDelete = new QPushButton(tabDisable);
        pushDisableDelete->setObjectName(QString::fromUtf8("pushDisableDelete"));

        verticalLayout_6->addWidget(pushDisableDelete);

        verticalSpacerDisable2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacerDisable2);


        gridLayout_4->addLayout(verticalLayout_6, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tabDisable, QString());

        verticalLayout_2->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushRefresh = new QPushButton(DlgDASDTables);
        pushRefresh->setObjectName(QString::fromUtf8("pushRefresh"));

        horizontalLayout->addWidget(pushRefresh);

        pushRefreshFiles = new QPushButton(DlgDASDTables);
        pushRefreshFiles->setObjectName(QString::fromUtf8("pushRefreshFiles"));

        horizontalLayout->addWidget(pushRefreshFiles);

        pushSaveFiles = new QPushButton(DlgDASDTables);
        pushSaveFiles->setObjectName(QString::fromUtf8("pushSaveFiles"));

        horizontalLayout->addWidget(pushSaveFiles);

        pushSaveModule = new QPushButton(DlgDASDTables);
        pushSaveModule->setObjectName(QString::fromUtf8("pushSaveModule"));

        horizontalLayout->addWidget(pushSaveModule);

        spacerButtons = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(spacerButtons);

        pushClose = new QPushButton(DlgDASDTables);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);


        verticalLayout_2->addLayout(horizontalLayout);

        QWidget::setTabOrder(tabWidget, comboSwitch);
        QWidget::setTabOrder(comboSwitch, tableSwitch);
        QWidget::setTabOrder(tableSwitch, pushSwitchAdd);
        QWidget::setTabOrder(pushSwitchAdd, pushSwitchUp);
        QWidget::setTabOrder(pushSwitchUp, pushSwitchDown);
        QWidget::setTabOrder(pushSwitchDown, pushSwitchDelete);
        QWidget::setTabOrder(pushSwitchDelete, comboMode);
        QWidget::setTabOrder(comboMode, tableMode);
        QWidget::setTabOrder(tableMode, pushModeAdd);
        QWidget::setTabOrder(pushModeAdd, pushModeUp);
        QWidget::setTabOrder(pushModeUp, pushModeDown);
        QWidget::setTabOrder(pushModeDown, pushModeDelete);
        QWidget::setTabOrder(pushModeDelete, comboRipch);
        QWidget::setTabOrder(comboRipch, tableRipch);
        QWidget::setTabOrder(tableRipch, pushRipchAdd);
        QWidget::setTabOrder(pushRipchAdd, pushRipchUp);
        QWidget::setTabOrder(pushRipchUp, pushRipchDown);
        QWidget::setTabOrder(pushRipchDown, pushRipchDelete);
        QWidget::setTabOrder(pushRipchDelete, tableDisable);
        QWidget::setTabOrder(tableDisable, pushDisableAdd);
        QWidget::setTabOrder(pushDisableAdd, pushDisableUp);
        QWidget::setTabOrder(pushDisableUp, pushDisableDown);
        QWidget::setTabOrder(pushDisableDown, pushDisableDelete);
        QWidget::setTabOrder(pushDisableDelete, pushRefresh);
        QWidget::setTabOrder(pushRefresh, pushRefreshFiles);
        QWidget::setTabOrder(pushRefreshFiles, pushSaveFiles);
        QWidget::setTabOrder(pushSaveFiles, pushSaveModule);
        QWidget::setTabOrder(pushSaveModule, pushClose);

        retranslateUi(DlgDASDTables);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DlgDASDTables);
    } // setupUi

    void retranslateUi(QDialog *DlgDASDTables)
    {
        DlgDASDTables->setWindowTitle(QApplication::translate("DlgDASDTables", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \321\200\320\265\320\266\320\270\320\274\320\276\320\262 \320\276\320\261\320\267\320\276\321\200\320\260 \320\270 \320\267\320\276\320\275\320\264\320\270\321\200\321\203\321\216\321\211\320\270\321\205 \320\270\320\274\320\277\321\203\320\273\321\214\321\201\320\276\320\262 \320\264\320\273\321\217 \320\272\320\276\320\274\320\274\321\203\320\275\320\270\320\272\320\260\321\206\320\270\320\276\320\275\320\275\320\276\320\263\320\276 \320\274\320\276\320\264\321\203\320\273\321\217 \320\2242\320\222\320\232028", 0, QApplication::UnicodeUTF8));
        pushSwitchAdd->setText(QApplication::translate("DlgDASDTables", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushSwitchUp->setText(QApplication::translate("DlgDASDTables", "\320\222\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        pushSwitchDown->setText(QApplication::translate("DlgDASDTables", "\320\222\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
        pushSwitchDelete->setText(QApplication::translate("DlgDASDTables", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabSwitch), QApplication::translate("DlgDASDTables", "\320\237\320\265\321\200\320\265\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217 \321\200\320\265\320\266\320\270\320\274\320\276\320\262 \320\276\320\261\320\267\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        pushModeAdd->setText(QApplication::translate("DlgDASDTables", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushModeUp->setText(QApplication::translate("DlgDASDTables", "\320\222\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        pushModeDown->setText(QApplication::translate("DlgDASDTables", "\320\222\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
        pushModeDelete->setText(QApplication::translate("DlgDASDTables", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabMode), QApplication::translate("DlgDASDTables", "\320\240\320\265\320\266\320\270\320\274\321\213 \320\276\320\261\320\267\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        pushRipchAdd->setText(QApplication::translate("DlgDASDTables", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushRipchUp->setText(QApplication::translate("DlgDASDTables", "\320\222\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        pushRipchDown->setText(QApplication::translate("DlgDASDTables", "\320\222\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
        pushRipchDelete->setText(QApplication::translate("DlgDASDTables", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabImpulse), QApplication::translate("DlgDASDTables", "\320\227\320\276\320\275\320\264\320\270\321\200\321\203\321\216\321\211\320\270\320\265 \320\270\320\274\320\277\321\203\320\273\321\214\321\201\321\213", 0, QApplication::UnicodeUTF8));
        pushDisableAdd->setText(QApplication::translate("DlgDASDTables", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushDisableUp->setText(QApplication::translate("DlgDASDTables", "\320\222\320\262\320\265\321\200\321\205", 0, QApplication::UnicodeUTF8));
        pushDisableDown->setText(QApplication::translate("DlgDASDTables", "\320\222\320\275\320\270\320\267", 0, QApplication::UnicodeUTF8));
        pushDisableDelete->setText(QApplication::translate("DlgDASDTables", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tabDisable), QApplication::translate("DlgDASDTables", "\320\241\320\265\320\272\321\202\320\276\321\200\320\260 \320\267\320\260\320\277\321\200\320\265\321\202\320\260", 0, QApplication::UnicodeUTF8));
        pushRefresh->setText(QApplication::translate("DlgDASDTables", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \321\202\320\265\320\272\321\203\321\211\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushRefreshFiles->setText(QApplication::translate("DlgDASDTables", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        pushSaveFiles->setText(QApplication::translate("DlgDASDTables", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \321\204\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        pushSaveModule->setText(QApplication::translate("DlgDASDTables", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \320\274\320\276\320\264\321\203\320\273\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgDASDTables", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgDASDTables: public Ui_DlgDASDTables {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLES_H
