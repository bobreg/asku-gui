/********************************************************************************
** Form generated from reading UI file 'channel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANNEL_H
#define UI_CHANNEL_H

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

class Ui_DlgChannel
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *labelCommand;
    QTableWidget *tableCommand;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelCommand1;
    QTableWidget *tableCommand1;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelTest1;
    QTableWidget *tableTest1;
    QVBoxLayout *verticalLayout;
    QLabel *labelTest2;
    QTableWidget *tableTest2;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelDC;
    QTableWidget *tableDC;
    QVBoxLayout *verticalLayout_6;
    QLabel *labelState;
    QTableWidget *tableState;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer1;
    QPushButton *pushClose;
    QSpacerItem *horizontalSpacer2;

    void setupUi(QDialog *DlgChannel)
    {
        if (DlgChannel->objectName().isEmpty())
            DlgChannel->setObjectName(QString::fromUtf8("DlgChannel"));
        DlgChannel->resize(730, 386);
        verticalLayout_7 = new QVBoxLayout(DlgChannel);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        labelCommand = new QLabel(DlgChannel);
        labelCommand->setObjectName(QString::fromUtf8("labelCommand"));

        verticalLayout_4->addWidget(labelCommand);

        tableCommand = new QTableWidget(DlgChannel);
        if (tableCommand->columnCount() < 3)
            tableCommand->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCommand->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCommand->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCommand->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tableCommand->rowCount() < 3)
            tableCommand->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCommand->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableCommand->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableCommand->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(0, 0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(0, 1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(0, 2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(1, 0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(1, 1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(1, 2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(2, 0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(2, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand->setItem(2, 2, __qtablewidgetitem14);
        tableCommand->setObjectName(QString::fromUtf8("tableCommand"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableCommand->sizePolicy().hasHeightForWidth());
        tableCommand->setSizePolicy(sizePolicy);
        tableCommand->setMinimumSize(QSize(155, 95));
        tableCommand->setMaximumSize(QSize(155, 95));
        tableCommand->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableCommand->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableCommand->setAutoScroll(false);
        tableCommand->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableCommand->setSelectionMode(QAbstractItemView::NoSelection);
        tableCommand->setCornerButtonEnabled(false);
        tableCommand->horizontalHeader()->setDefaultSectionSize(25);
        tableCommand->horizontalHeader()->setHighlightSections(false);
        tableCommand->horizontalHeader()->setMinimumSectionSize(25);
        tableCommand->verticalHeader()->setDefaultSectionSize(20);
        tableCommand->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_4->addWidget(tableCommand);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        labelCommand1 = new QLabel(DlgChannel);
        labelCommand1->setObjectName(QString::fromUtf8("labelCommand1"));

        verticalLayout_3->addWidget(labelCommand1);

        tableCommand1 = new QTableWidget(DlgChannel);
        if (tableCommand1->columnCount() < 1)
            tableCommand1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableCommand1->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        if (tableCommand1->rowCount() < 3)
            tableCommand1->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableCommand1->setVerticalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableCommand1->setVerticalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableCommand1->setVerticalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand1->setItem(0, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand1->setItem(1, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableCommand1->setItem(2, 0, __qtablewidgetitem21);
        tableCommand1->setObjectName(QString::fromUtf8("tableCommand1"));
        sizePolicy.setHeightForWidth(tableCommand1->sizePolicy().hasHeightForWidth());
        tableCommand1->setSizePolicy(sizePolicy);
        tableCommand1->setMinimumSize(QSize(45, 95));
        tableCommand1->setMaximumSize(QSize(45, 95));
        tableCommand1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableCommand1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableCommand1->setAutoScroll(false);
        tableCommand1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableCommand1->setSelectionMode(QAbstractItemView::NoSelection);
        tableCommand1->setCornerButtonEnabled(false);
        tableCommand1->horizontalHeader()->setDefaultSectionSize(25);
        tableCommand1->horizontalHeader()->setMinimumSectionSize(25);
        tableCommand1->verticalHeader()->setVisible(false);
        tableCommand1->verticalHeader()->setDefaultSectionSize(20);
        tableCommand1->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_3->addWidget(tableCommand1);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        labelTest1 = new QLabel(DlgChannel);
        labelTest1->setObjectName(QString::fromUtf8("labelTest1"));

        verticalLayout_2->addWidget(labelTest1);

        tableTest1 = new QTableWidget(DlgChannel);
        if (tableTest1->columnCount() < 1)
            tableTest1->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableTest1->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        if (tableTest1->rowCount() < 3)
            tableTest1->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableTest1->setVerticalHeaderItem(0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableTest1->setVerticalHeaderItem(1, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableTest1->setVerticalHeaderItem(2, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        __qtablewidgetitem26->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest1->setItem(0, 0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        __qtablewidgetitem27->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest1->setItem(1, 0, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        __qtablewidgetitem28->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest1->setItem(2, 0, __qtablewidgetitem28);
        tableTest1->setObjectName(QString::fromUtf8("tableTest1"));
        sizePolicy.setHeightForWidth(tableTest1->sizePolicy().hasHeightForWidth());
        tableTest1->setSizePolicy(sizePolicy);
        tableTest1->setMinimumSize(QSize(105, 95));
        tableTest1->setMaximumSize(QSize(105, 95));
        tableTest1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableTest1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableTest1->setAutoScroll(false);
        tableTest1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableTest1->setSelectionMode(QAbstractItemView::NoSelection);
        tableTest1->setCornerButtonEnabled(false);
        tableTest1->horizontalHeader()->setDefaultSectionSize(25);
        tableTest1->horizontalHeader()->setMinimumSectionSize(25);
        tableTest1->verticalHeader()->setDefaultSectionSize(20);
        tableTest1->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_2->addWidget(tableTest1);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTest2 = new QLabel(DlgChannel);
        labelTest2->setObjectName(QString::fromUtf8("labelTest2"));

        verticalLayout->addWidget(labelTest2);

        tableTest2 = new QTableWidget(DlgChannel);
        if (tableTest2->columnCount() < 3)
            tableTest2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableTest2->setHorizontalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableTest2->setHorizontalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableTest2->setHorizontalHeaderItem(2, __qtablewidgetitem31);
        if (tableTest2->rowCount() < 3)
            tableTest2->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableTest2->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableTest2->setVerticalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableTest2->setVerticalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(0, 0, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(0, 1, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(0, 2, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(1, 1, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(1, 2, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(2, 0, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        __qtablewidgetitem42->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(2, 1, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        __qtablewidgetitem43->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableTest2->setItem(2, 2, __qtablewidgetitem43);
        tableTest2->setObjectName(QString::fromUtf8("tableTest2"));
        sizePolicy.setHeightForWidth(tableTest2->sizePolicy().hasHeightForWidth());
        tableTest2->setSizePolicy(sizePolicy);
        tableTest2->setMinimumSize(QSize(155, 95));
        tableTest2->setMaximumSize(QSize(155, 95));
        tableTest2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableTest2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableTest2->setAutoScroll(false);
        tableTest2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableTest2->setSelectionMode(QAbstractItemView::NoSelection);
        tableTest2->setCornerButtonEnabled(false);
        tableTest2->horizontalHeader()->setDefaultSectionSize(25);
        tableTest2->horizontalHeader()->setMinimumSectionSize(25);
        tableTest2->verticalHeader()->setDefaultSectionSize(20);
        tableTest2->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout->addWidget(tableTest2);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_7->addLayout(horizontalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        labelDC = new QLabel(DlgChannel);
        labelDC->setObjectName(QString::fromUtf8("labelDC"));

        verticalLayout_5->addWidget(labelDC);

        tableDC = new QTableWidget(DlgChannel);
        if (tableDC->columnCount() < 32)
            tableDC->setColumnCount(32);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(0, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(1, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(2, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(3, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(4, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(5, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(6, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(7, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(8, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(9, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(10, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(11, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(12, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(13, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(14, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(15, __qtablewidgetitem59);
        QTableWidgetItem *__qtablewidgetitem60 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(16, __qtablewidgetitem60);
        QTableWidgetItem *__qtablewidgetitem61 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(17, __qtablewidgetitem61);
        QTableWidgetItem *__qtablewidgetitem62 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(18, __qtablewidgetitem62);
        QTableWidgetItem *__qtablewidgetitem63 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(19, __qtablewidgetitem63);
        QTableWidgetItem *__qtablewidgetitem64 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(20, __qtablewidgetitem64);
        QTableWidgetItem *__qtablewidgetitem65 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(21, __qtablewidgetitem65);
        QTableWidgetItem *__qtablewidgetitem66 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(22, __qtablewidgetitem66);
        QTableWidgetItem *__qtablewidgetitem67 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(23, __qtablewidgetitem67);
        QTableWidgetItem *__qtablewidgetitem68 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(24, __qtablewidgetitem68);
        QTableWidgetItem *__qtablewidgetitem69 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(25, __qtablewidgetitem69);
        QTableWidgetItem *__qtablewidgetitem70 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(26, __qtablewidgetitem70);
        QTableWidgetItem *__qtablewidgetitem71 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(27, __qtablewidgetitem71);
        QTableWidgetItem *__qtablewidgetitem72 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(28, __qtablewidgetitem72);
        QTableWidgetItem *__qtablewidgetitem73 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(29, __qtablewidgetitem73);
        QTableWidgetItem *__qtablewidgetitem74 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(30, __qtablewidgetitem74);
        QTableWidgetItem *__qtablewidgetitem75 = new QTableWidgetItem();
        tableDC->setHorizontalHeaderItem(31, __qtablewidgetitem75);
        if (tableDC->rowCount() < 1)
            tableDC->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem76 = new QTableWidgetItem();
        tableDC->setVerticalHeaderItem(0, __qtablewidgetitem76);
        QTableWidgetItem *__qtablewidgetitem77 = new QTableWidgetItem();
        __qtablewidgetitem77->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 0, __qtablewidgetitem77);
        QTableWidgetItem *__qtablewidgetitem78 = new QTableWidgetItem();
        __qtablewidgetitem78->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 1, __qtablewidgetitem78);
        QTableWidgetItem *__qtablewidgetitem79 = new QTableWidgetItem();
        __qtablewidgetitem79->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 2, __qtablewidgetitem79);
        QTableWidgetItem *__qtablewidgetitem80 = new QTableWidgetItem();
        __qtablewidgetitem80->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 3, __qtablewidgetitem80);
        QTableWidgetItem *__qtablewidgetitem81 = new QTableWidgetItem();
        __qtablewidgetitem81->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 4, __qtablewidgetitem81);
        QTableWidgetItem *__qtablewidgetitem82 = new QTableWidgetItem();
        __qtablewidgetitem82->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 5, __qtablewidgetitem82);
        QTableWidgetItem *__qtablewidgetitem83 = new QTableWidgetItem();
        __qtablewidgetitem83->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 6, __qtablewidgetitem83);
        QTableWidgetItem *__qtablewidgetitem84 = new QTableWidgetItem();
        __qtablewidgetitem84->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 7, __qtablewidgetitem84);
        QTableWidgetItem *__qtablewidgetitem85 = new QTableWidgetItem();
        __qtablewidgetitem85->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 8, __qtablewidgetitem85);
        QTableWidgetItem *__qtablewidgetitem86 = new QTableWidgetItem();
        __qtablewidgetitem86->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 9, __qtablewidgetitem86);
        QTableWidgetItem *__qtablewidgetitem87 = new QTableWidgetItem();
        __qtablewidgetitem87->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 10, __qtablewidgetitem87);
        QTableWidgetItem *__qtablewidgetitem88 = new QTableWidgetItem();
        __qtablewidgetitem88->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 11, __qtablewidgetitem88);
        QTableWidgetItem *__qtablewidgetitem89 = new QTableWidgetItem();
        __qtablewidgetitem89->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 12, __qtablewidgetitem89);
        QTableWidgetItem *__qtablewidgetitem90 = new QTableWidgetItem();
        __qtablewidgetitem90->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 13, __qtablewidgetitem90);
        QTableWidgetItem *__qtablewidgetitem91 = new QTableWidgetItem();
        __qtablewidgetitem91->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 14, __qtablewidgetitem91);
        QTableWidgetItem *__qtablewidgetitem92 = new QTableWidgetItem();
        __qtablewidgetitem92->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableDC->setItem(0, 15, __qtablewidgetitem92);
        tableDC->setObjectName(QString::fromUtf8("tableDC"));
        sizePolicy.setHeightForWidth(tableDC->sizePolicy().hasHeightForWidth());
        tableDC->setSizePolicy(sizePolicy);
        tableDC->setMinimumSize(QSize(480, 55));
        tableDC->setMaximumSize(QSize(480, 55));
        tableDC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableDC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableDC->setAutoScroll(false);
        tableDC->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableDC->setSelectionMode(QAbstractItemView::NoSelection);
        tableDC->setCornerButtonEnabled(false);
        tableDC->horizontalHeader()->setDefaultSectionSize(25);
        tableDC->horizontalHeader()->setMinimumSectionSize(25);
        tableDC->verticalHeader()->setDefaultSectionSize(20);
        tableDC->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_5->addWidget(tableDC);


        verticalLayout_7->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        labelState = new QLabel(DlgChannel);
        labelState->setObjectName(QString::fromUtf8("labelState"));

        verticalLayout_6->addWidget(labelState);

        tableState = new QTableWidget(DlgChannel);
        if (tableState->columnCount() < 19)
            tableState->setColumnCount(19);
        QTableWidgetItem *__qtablewidgetitem93 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(0, __qtablewidgetitem93);
        QTableWidgetItem *__qtablewidgetitem94 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(1, __qtablewidgetitem94);
        QTableWidgetItem *__qtablewidgetitem95 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(2, __qtablewidgetitem95);
        QTableWidgetItem *__qtablewidgetitem96 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(3, __qtablewidgetitem96);
        QTableWidgetItem *__qtablewidgetitem97 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(4, __qtablewidgetitem97);
        QTableWidgetItem *__qtablewidgetitem98 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(5, __qtablewidgetitem98);
        QTableWidgetItem *__qtablewidgetitem99 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(6, __qtablewidgetitem99);
        QTableWidgetItem *__qtablewidgetitem100 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(7, __qtablewidgetitem100);
        QTableWidgetItem *__qtablewidgetitem101 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(8, __qtablewidgetitem101);
        QTableWidgetItem *__qtablewidgetitem102 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(9, __qtablewidgetitem102);
        QTableWidgetItem *__qtablewidgetitem103 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(10, __qtablewidgetitem103);
        QTableWidgetItem *__qtablewidgetitem104 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(11, __qtablewidgetitem104);
        QTableWidgetItem *__qtablewidgetitem105 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(12, __qtablewidgetitem105);
        QTableWidgetItem *__qtablewidgetitem106 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(13, __qtablewidgetitem106);
        QTableWidgetItem *__qtablewidgetitem107 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(14, __qtablewidgetitem107);
        QTableWidgetItem *__qtablewidgetitem108 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(15, __qtablewidgetitem108);
        QTableWidgetItem *__qtablewidgetitem109 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(16, __qtablewidgetitem109);
        QTableWidgetItem *__qtablewidgetitem110 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(17, __qtablewidgetitem110);
        QTableWidgetItem *__qtablewidgetitem111 = new QTableWidgetItem();
        tableState->setHorizontalHeaderItem(18, __qtablewidgetitem111);
        if (tableState->rowCount() < 3)
            tableState->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem112 = new QTableWidgetItem();
        tableState->setVerticalHeaderItem(0, __qtablewidgetitem112);
        QTableWidgetItem *__qtablewidgetitem113 = new QTableWidgetItem();
        tableState->setVerticalHeaderItem(1, __qtablewidgetitem113);
        QTableWidgetItem *__qtablewidgetitem114 = new QTableWidgetItem();
        tableState->setVerticalHeaderItem(2, __qtablewidgetitem114);
        QTableWidgetItem *__qtablewidgetitem115 = new QTableWidgetItem();
        __qtablewidgetitem115->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 0, __qtablewidgetitem115);
        QTableWidgetItem *__qtablewidgetitem116 = new QTableWidgetItem();
        __qtablewidgetitem116->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 1, __qtablewidgetitem116);
        QTableWidgetItem *__qtablewidgetitem117 = new QTableWidgetItem();
        __qtablewidgetitem117->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 2, __qtablewidgetitem117);
        QTableWidgetItem *__qtablewidgetitem118 = new QTableWidgetItem();
        __qtablewidgetitem118->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 3, __qtablewidgetitem118);
        QTableWidgetItem *__qtablewidgetitem119 = new QTableWidgetItem();
        __qtablewidgetitem119->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 4, __qtablewidgetitem119);
        QTableWidgetItem *__qtablewidgetitem120 = new QTableWidgetItem();
        __qtablewidgetitem120->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 5, __qtablewidgetitem120);
        QTableWidgetItem *__qtablewidgetitem121 = new QTableWidgetItem();
        __qtablewidgetitem121->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 6, __qtablewidgetitem121);
        QTableWidgetItem *__qtablewidgetitem122 = new QTableWidgetItem();
        __qtablewidgetitem122->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 7, __qtablewidgetitem122);
        QTableWidgetItem *__qtablewidgetitem123 = new QTableWidgetItem();
        __qtablewidgetitem123->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 8, __qtablewidgetitem123);
        QTableWidgetItem *__qtablewidgetitem124 = new QTableWidgetItem();
        __qtablewidgetitem124->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 9, __qtablewidgetitem124);
        QTableWidgetItem *__qtablewidgetitem125 = new QTableWidgetItem();
        __qtablewidgetitem125->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 10, __qtablewidgetitem125);
        QTableWidgetItem *__qtablewidgetitem126 = new QTableWidgetItem();
        __qtablewidgetitem126->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 11, __qtablewidgetitem126);
        QTableWidgetItem *__qtablewidgetitem127 = new QTableWidgetItem();
        __qtablewidgetitem127->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 12, __qtablewidgetitem127);
        QTableWidgetItem *__qtablewidgetitem128 = new QTableWidgetItem();
        __qtablewidgetitem128->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 13, __qtablewidgetitem128);
        QTableWidgetItem *__qtablewidgetitem129 = new QTableWidgetItem();
        __qtablewidgetitem129->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 14, __qtablewidgetitem129);
        QTableWidgetItem *__qtablewidgetitem130 = new QTableWidgetItem();
        __qtablewidgetitem130->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 15, __qtablewidgetitem130);
        QTableWidgetItem *__qtablewidgetitem131 = new QTableWidgetItem();
        __qtablewidgetitem131->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 16, __qtablewidgetitem131);
        QTableWidgetItem *__qtablewidgetitem132 = new QTableWidgetItem();
        __qtablewidgetitem132->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 17, __qtablewidgetitem132);
        QTableWidgetItem *__qtablewidgetitem133 = new QTableWidgetItem();
        __qtablewidgetitem133->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(0, 18, __qtablewidgetitem133);
        QTableWidgetItem *__qtablewidgetitem134 = new QTableWidgetItem();
        __qtablewidgetitem134->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 0, __qtablewidgetitem134);
        QTableWidgetItem *__qtablewidgetitem135 = new QTableWidgetItem();
        __qtablewidgetitem135->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 1, __qtablewidgetitem135);
        QTableWidgetItem *__qtablewidgetitem136 = new QTableWidgetItem();
        __qtablewidgetitem136->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 2, __qtablewidgetitem136);
        QTableWidgetItem *__qtablewidgetitem137 = new QTableWidgetItem();
        __qtablewidgetitem137->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 3, __qtablewidgetitem137);
        QTableWidgetItem *__qtablewidgetitem138 = new QTableWidgetItem();
        __qtablewidgetitem138->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 4, __qtablewidgetitem138);
        QTableWidgetItem *__qtablewidgetitem139 = new QTableWidgetItem();
        __qtablewidgetitem139->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 5, __qtablewidgetitem139);
        QTableWidgetItem *__qtablewidgetitem140 = new QTableWidgetItem();
        __qtablewidgetitem140->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 6, __qtablewidgetitem140);
        QTableWidgetItem *__qtablewidgetitem141 = new QTableWidgetItem();
        __qtablewidgetitem141->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 7, __qtablewidgetitem141);
        QTableWidgetItem *__qtablewidgetitem142 = new QTableWidgetItem();
        __qtablewidgetitem142->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 8, __qtablewidgetitem142);
        QTableWidgetItem *__qtablewidgetitem143 = new QTableWidgetItem();
        __qtablewidgetitem143->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 9, __qtablewidgetitem143);
        QTableWidgetItem *__qtablewidgetitem144 = new QTableWidgetItem();
        __qtablewidgetitem144->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 10, __qtablewidgetitem144);
        QTableWidgetItem *__qtablewidgetitem145 = new QTableWidgetItem();
        __qtablewidgetitem145->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 11, __qtablewidgetitem145);
        QTableWidgetItem *__qtablewidgetitem146 = new QTableWidgetItem();
        __qtablewidgetitem146->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 12, __qtablewidgetitem146);
        QTableWidgetItem *__qtablewidgetitem147 = new QTableWidgetItem();
        __qtablewidgetitem147->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 13, __qtablewidgetitem147);
        QTableWidgetItem *__qtablewidgetitem148 = new QTableWidgetItem();
        __qtablewidgetitem148->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 14, __qtablewidgetitem148);
        QTableWidgetItem *__qtablewidgetitem149 = new QTableWidgetItem();
        __qtablewidgetitem149->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 15, __qtablewidgetitem149);
        QTableWidgetItem *__qtablewidgetitem150 = new QTableWidgetItem();
        __qtablewidgetitem150->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 16, __qtablewidgetitem150);
        QTableWidgetItem *__qtablewidgetitem151 = new QTableWidgetItem();
        __qtablewidgetitem151->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 17, __qtablewidgetitem151);
        QTableWidgetItem *__qtablewidgetitem152 = new QTableWidgetItem();
        __qtablewidgetitem152->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(1, 18, __qtablewidgetitem152);
        QTableWidgetItem *__qtablewidgetitem153 = new QTableWidgetItem();
        __qtablewidgetitem153->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 0, __qtablewidgetitem153);
        QTableWidgetItem *__qtablewidgetitem154 = new QTableWidgetItem();
        __qtablewidgetitem154->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 1, __qtablewidgetitem154);
        QTableWidgetItem *__qtablewidgetitem155 = new QTableWidgetItem();
        __qtablewidgetitem155->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 2, __qtablewidgetitem155);
        QTableWidgetItem *__qtablewidgetitem156 = new QTableWidgetItem();
        __qtablewidgetitem156->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 3, __qtablewidgetitem156);
        QTableWidgetItem *__qtablewidgetitem157 = new QTableWidgetItem();
        __qtablewidgetitem157->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 4, __qtablewidgetitem157);
        QTableWidgetItem *__qtablewidgetitem158 = new QTableWidgetItem();
        __qtablewidgetitem158->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 5, __qtablewidgetitem158);
        QTableWidgetItem *__qtablewidgetitem159 = new QTableWidgetItem();
        __qtablewidgetitem159->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 6, __qtablewidgetitem159);
        QTableWidgetItem *__qtablewidgetitem160 = new QTableWidgetItem();
        __qtablewidgetitem160->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 7, __qtablewidgetitem160);
        QTableWidgetItem *__qtablewidgetitem161 = new QTableWidgetItem();
        __qtablewidgetitem161->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 8, __qtablewidgetitem161);
        QTableWidgetItem *__qtablewidgetitem162 = new QTableWidgetItem();
        __qtablewidgetitem162->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 9, __qtablewidgetitem162);
        QTableWidgetItem *__qtablewidgetitem163 = new QTableWidgetItem();
        __qtablewidgetitem163->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 10, __qtablewidgetitem163);
        QTableWidgetItem *__qtablewidgetitem164 = new QTableWidgetItem();
        __qtablewidgetitem164->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 11, __qtablewidgetitem164);
        QTableWidgetItem *__qtablewidgetitem165 = new QTableWidgetItem();
        __qtablewidgetitem165->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 12, __qtablewidgetitem165);
        QTableWidgetItem *__qtablewidgetitem166 = new QTableWidgetItem();
        __qtablewidgetitem166->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 13, __qtablewidgetitem166);
        QTableWidgetItem *__qtablewidgetitem167 = new QTableWidgetItem();
        __qtablewidgetitem167->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 14, __qtablewidgetitem167);
        QTableWidgetItem *__qtablewidgetitem168 = new QTableWidgetItem();
        __qtablewidgetitem168->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 15, __qtablewidgetitem168);
        QTableWidgetItem *__qtablewidgetitem169 = new QTableWidgetItem();
        __qtablewidgetitem169->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 16, __qtablewidgetitem169);
        QTableWidgetItem *__qtablewidgetitem170 = new QTableWidgetItem();
        __qtablewidgetitem170->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 17, __qtablewidgetitem170);
        QTableWidgetItem *__qtablewidgetitem171 = new QTableWidgetItem();
        __qtablewidgetitem171->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableState->setItem(2, 18, __qtablewidgetitem171);
        tableState->setObjectName(QString::fromUtf8("tableState"));
        sizePolicy.setHeightForWidth(tableState->sizePolicy().hasHeightForWidth());
        tableState->setSizePolicy(sizePolicy);
        tableState->setMinimumSize(QSize(560, 95));
        tableState->setMaximumSize(QSize(560, 95));
        tableState->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableState->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableState->setAutoScroll(false);
        tableState->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableState->setSelectionMode(QAbstractItemView::NoSelection);
        tableState->setCornerButtonEnabled(false);
        tableState->horizontalHeader()->setDefaultSectionSize(25);
        tableState->horizontalHeader()->setMinimumSectionSize(25);
        tableState->verticalHeader()->setDefaultSectionSize(20);
        tableState->verticalHeader()->setMinimumSectionSize(20);

        verticalLayout_6->addWidget(tableState);


        verticalLayout_7->addLayout(verticalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer1);

        pushClose = new QPushButton(DlgChannel);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setDefault(true);

        horizontalLayout->addWidget(pushClose);

        horizontalSpacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer2);


        verticalLayout_7->addLayout(horizontalLayout);


        retranslateUi(DlgChannel);
        QObject::connect(pushClose, SIGNAL(clicked()), DlgChannel, SLOT(hide()));

        QMetaObject::connectSlotsByName(DlgChannel);
    } // setupUi

    void retranslateUi(QDialog *DlgChannel)
    {
        DlgChannel->setWindowTitle(QApplication::translate("DlgChannel", "\320\224\320\260\320\275\320\275\321\213\320\265 \320\272\320\260\320\275\320\260\320\273\320\260 \320\220\320\241\320\232\320\243", 0, QApplication::UnicodeUTF8));
        labelCommand->setText(QApplication::translate("DlgChannel", "\320\232\320\276\320\274\320\260\320\275\320\264\321\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableCommand->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableCommand->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DlgChannel", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableCommand->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DlgChannel", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableCommand->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("DlgChannel", "534\320\243\320\23701   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableCommand->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("DlgChannel", "534\320\243\320\22301   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableCommand->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("DlgChannel", "536\320\243\320\22101   ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = tableCommand->isSortingEnabled();
        tableCommand->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem6 = tableCommand->item(0, 0);
        ___qtablewidgetitem6->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableCommand->item(0, 1);
        ___qtablewidgetitem7->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableCommand->item(0, 2);
        ___qtablewidgetitem8->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableCommand->item(1, 0);
        ___qtablewidgetitem9->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableCommand->item(1, 1);
        ___qtablewidgetitem10->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableCommand->item(1, 2);
        ___qtablewidgetitem11->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem12 = tableCommand->item(2, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableCommand->item(2, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableCommand->item(2, 2);
        ___qtablewidgetitem14->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableCommand->setSortingEnabled(__sortingEnabled);

        labelCommand1->setText(QApplication::translate("DlgChannel", "\320\232\320\262\320\270\321\202\320\260\320\275\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableCommand1->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem16 = tableCommand1->verticalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("DlgChannel", "534\320\243\320\22301   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem17 = tableCommand1->verticalHeaderItem(1);
        ___qtablewidgetitem17->setText(QApplication::translate("DlgChannel", "534\320\243\320\23701   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem18 = tableCommand1->verticalHeaderItem(2);
        ___qtablewidgetitem18->setText(QApplication::translate("DlgChannel", "536\320\243\320\22101   ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableCommand1->isSortingEnabled();
        tableCommand1->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem19 = tableCommand1->item(0, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem20 = tableCommand1->item(1, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem21 = tableCommand1->item(2, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableCommand1->setSortingEnabled(__sortingEnabled1);

        labelTest1->setText(QApplication::translate("DlgChannel", "\320\242\320\265\321\201\321\202 1 \321\203\321\200\320\276\320\262\320\275\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem22 = tableTest1->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem23 = tableTest1->verticalHeaderItem(0);
        ___qtablewidgetitem23->setText(QApplication::translate("DlgChannel", "534\320\243\320\23701   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem24 = tableTest1->verticalHeaderItem(1);
        ___qtablewidgetitem24->setText(QApplication::translate("DlgChannel", "534\320\243\320\22301   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem25 = tableTest1->verticalHeaderItem(2);
        ___qtablewidgetitem25->setText(QApplication::translate("DlgChannel", "536\320\243\320\22101   ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled2 = tableTest1->isSortingEnabled();
        tableTest1->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem26 = tableTest1->item(0, 0);
        ___qtablewidgetitem26->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem27 = tableTest1->item(1, 0);
        ___qtablewidgetitem27->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem28 = tableTest1->item(2, 0);
        ___qtablewidgetitem28->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableTest1->setSortingEnabled(__sortingEnabled2);

        labelTest2->setText(QApplication::translate("DlgChannel", "\320\242\320\265\321\201\321\202 2 \321\203\321\200\320\276\320\262\320\275\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem29 = tableTest2->horizontalHeaderItem(0);
        ___qtablewidgetitem29->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem30 = tableTest2->horizontalHeaderItem(1);
        ___qtablewidgetitem30->setText(QApplication::translate("DlgChannel", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem31 = tableTest2->horizontalHeaderItem(2);
        ___qtablewidgetitem31->setText(QApplication::translate("DlgChannel", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem32 = tableTest2->verticalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("DlgChannel", "534\320\243\320\23701   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem33 = tableTest2->verticalHeaderItem(1);
        ___qtablewidgetitem33->setText(QApplication::translate("DlgChannel", "534\320\243\320\22301   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem34 = tableTest2->verticalHeaderItem(2);
        ___qtablewidgetitem34->setText(QApplication::translate("DlgChannel", "536\320\243\320\22101   ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled3 = tableTest2->isSortingEnabled();
        tableTest2->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem35 = tableTest2->item(0, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem36 = tableTest2->item(0, 1);
        ___qtablewidgetitem36->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem37 = tableTest2->item(0, 2);
        ___qtablewidgetitem37->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem38 = tableTest2->item(1, 0);
        ___qtablewidgetitem38->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem39 = tableTest2->item(1, 1);
        ___qtablewidgetitem39->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem40 = tableTest2->item(1, 2);
        ___qtablewidgetitem40->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem41 = tableTest2->item(2, 0);
        ___qtablewidgetitem41->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem42 = tableTest2->item(2, 1);
        ___qtablewidgetitem42->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem43 = tableTest2->item(2, 2);
        ___qtablewidgetitem43->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableTest2->setSortingEnabled(__sortingEnabled3);

        labelDC->setText(QApplication::translate("DlgChannel", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem44 = tableDC->horizontalHeaderItem(0);
        ___qtablewidgetitem44->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem45 = tableDC->horizontalHeaderItem(1);
        ___qtablewidgetitem45->setText(QApplication::translate("DlgChannel", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem46 = tableDC->horizontalHeaderItem(2);
        ___qtablewidgetitem46->setText(QApplication::translate("DlgChannel", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem47 = tableDC->horizontalHeaderItem(3);
        ___qtablewidgetitem47->setText(QApplication::translate("DlgChannel", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem48 = tableDC->horizontalHeaderItem(4);
        ___qtablewidgetitem48->setText(QApplication::translate("DlgChannel", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem49 = tableDC->horizontalHeaderItem(5);
        ___qtablewidgetitem49->setText(QApplication::translate("DlgChannel", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem50 = tableDC->horizontalHeaderItem(6);
        ___qtablewidgetitem50->setText(QApplication::translate("DlgChannel", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem51 = tableDC->horizontalHeaderItem(7);
        ___qtablewidgetitem51->setText(QApplication::translate("DlgChannel", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem52 = tableDC->horizontalHeaderItem(8);
        ___qtablewidgetitem52->setText(QApplication::translate("DlgChannel", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem53 = tableDC->horizontalHeaderItem(9);
        ___qtablewidgetitem53->setText(QApplication::translate("DlgChannel", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem54 = tableDC->horizontalHeaderItem(10);
        ___qtablewidgetitem54->setText(QApplication::translate("DlgChannel", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem55 = tableDC->horizontalHeaderItem(11);
        ___qtablewidgetitem55->setText(QApplication::translate("DlgChannel", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem56 = tableDC->horizontalHeaderItem(12);
        ___qtablewidgetitem56->setText(QApplication::translate("DlgChannel", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem57 = tableDC->horizontalHeaderItem(13);
        ___qtablewidgetitem57->setText(QApplication::translate("DlgChannel", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem58 = tableDC->horizontalHeaderItem(14);
        ___qtablewidgetitem58->setText(QApplication::translate("DlgChannel", "15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem59 = tableDC->horizontalHeaderItem(15);
        ___qtablewidgetitem59->setText(QApplication::translate("DlgChannel", "16", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem60 = tableDC->horizontalHeaderItem(16);
        ___qtablewidgetitem60->setText(QApplication::translate("DlgChannel", "17", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem61 = tableDC->horizontalHeaderItem(17);
        ___qtablewidgetitem61->setText(QApplication::translate("DlgChannel", "18", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem62 = tableDC->horizontalHeaderItem(18);
        ___qtablewidgetitem62->setText(QApplication::translate("DlgChannel", "19", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem63 = tableDC->horizontalHeaderItem(19);
        ___qtablewidgetitem63->setText(QApplication::translate("DlgChannel", "20", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem64 = tableDC->horizontalHeaderItem(20);
        ___qtablewidgetitem64->setText(QApplication::translate("DlgChannel", "21", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem65 = tableDC->horizontalHeaderItem(21);
        ___qtablewidgetitem65->setText(QApplication::translate("DlgChannel", "22", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem66 = tableDC->horizontalHeaderItem(22);
        ___qtablewidgetitem66->setText(QApplication::translate("DlgChannel", "23", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem67 = tableDC->horizontalHeaderItem(23);
        ___qtablewidgetitem67->setText(QApplication::translate("DlgChannel", "24", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem68 = tableDC->horizontalHeaderItem(24);
        ___qtablewidgetitem68->setText(QApplication::translate("DlgChannel", "25", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem69 = tableDC->horizontalHeaderItem(25);
        ___qtablewidgetitem69->setText(QApplication::translate("DlgChannel", "26", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem70 = tableDC->horizontalHeaderItem(26);
        ___qtablewidgetitem70->setText(QApplication::translate("DlgChannel", "27", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem71 = tableDC->horizontalHeaderItem(27);
        ___qtablewidgetitem71->setText(QApplication::translate("DlgChannel", "28", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem72 = tableDC->horizontalHeaderItem(28);
        ___qtablewidgetitem72->setText(QApplication::translate("DlgChannel", "29", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem73 = tableDC->horizontalHeaderItem(29);
        ___qtablewidgetitem73->setText(QApplication::translate("DlgChannel", "30", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem74 = tableDC->horizontalHeaderItem(30);
        ___qtablewidgetitem74->setText(QApplication::translate("DlgChannel", "31", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem75 = tableDC->horizontalHeaderItem(31);
        ___qtablewidgetitem75->setText(QApplication::translate("DlgChannel", "32", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem76 = tableDC->verticalHeaderItem(0);
        ___qtablewidgetitem76->setText(QApplication::translate("DlgChannel", "\320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled4 = tableDC->isSortingEnabled();
        tableDC->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem77 = tableDC->item(0, 0);
        ___qtablewidgetitem77->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem78 = tableDC->item(0, 1);
        ___qtablewidgetitem78->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem79 = tableDC->item(0, 2);
        ___qtablewidgetitem79->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem80 = tableDC->item(0, 3);
        ___qtablewidgetitem80->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem81 = tableDC->item(0, 4);
        ___qtablewidgetitem81->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem82 = tableDC->item(0, 5);
        ___qtablewidgetitem82->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem83 = tableDC->item(0, 6);
        ___qtablewidgetitem83->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem84 = tableDC->item(0, 7);
        ___qtablewidgetitem84->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem85 = tableDC->item(0, 8);
        ___qtablewidgetitem85->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem86 = tableDC->item(0, 9);
        ___qtablewidgetitem86->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem87 = tableDC->item(0, 10);
        ___qtablewidgetitem87->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem88 = tableDC->item(0, 11);
        ___qtablewidgetitem88->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem89 = tableDC->item(0, 12);
        ___qtablewidgetitem89->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem90 = tableDC->item(0, 13);
        ___qtablewidgetitem90->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem91 = tableDC->item(0, 14);
        ___qtablewidgetitem91->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem92 = tableDC->item(0, 15);
        ___qtablewidgetitem92->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableDC->setSortingEnabled(__sortingEnabled4);

        labelState->setText(QApplication::translate("DlgChannel", "\320\241\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem93 = tableState->horizontalHeaderItem(0);
        ___qtablewidgetitem93->setText(QApplication::translate("DlgChannel", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem94 = tableState->horizontalHeaderItem(1);
        ___qtablewidgetitem94->setText(QApplication::translate("DlgChannel", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem95 = tableState->horizontalHeaderItem(2);
        ___qtablewidgetitem95->setText(QApplication::translate("DlgChannel", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem96 = tableState->horizontalHeaderItem(3);
        ___qtablewidgetitem96->setText(QApplication::translate("DlgChannel", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem97 = tableState->horizontalHeaderItem(4);
        ___qtablewidgetitem97->setText(QApplication::translate("DlgChannel", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem98 = tableState->horizontalHeaderItem(5);
        ___qtablewidgetitem98->setText(QApplication::translate("DlgChannel", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem99 = tableState->horizontalHeaderItem(6);
        ___qtablewidgetitem99->setText(QApplication::translate("DlgChannel", "7", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem100 = tableState->horizontalHeaderItem(7);
        ___qtablewidgetitem100->setText(QApplication::translate("DlgChannel", "8", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem101 = tableState->horizontalHeaderItem(8);
        ___qtablewidgetitem101->setText(QApplication::translate("DlgChannel", "9", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem102 = tableState->horizontalHeaderItem(9);
        ___qtablewidgetitem102->setText(QApplication::translate("DlgChannel", "10", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem103 = tableState->horizontalHeaderItem(10);
        ___qtablewidgetitem103->setText(QApplication::translate("DlgChannel", "11", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem104 = tableState->horizontalHeaderItem(11);
        ___qtablewidgetitem104->setText(QApplication::translate("DlgChannel", "12", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem105 = tableState->horizontalHeaderItem(12);
        ___qtablewidgetitem105->setText(QApplication::translate("DlgChannel", "13", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem106 = tableState->horizontalHeaderItem(13);
        ___qtablewidgetitem106->setText(QApplication::translate("DlgChannel", "14", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem107 = tableState->horizontalHeaderItem(14);
        ___qtablewidgetitem107->setText(QApplication::translate("DlgChannel", "15", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem108 = tableState->horizontalHeaderItem(15);
        ___qtablewidgetitem108->setText(QApplication::translate("DlgChannel", "16", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem109 = tableState->horizontalHeaderItem(16);
        ___qtablewidgetitem109->setText(QApplication::translate("DlgChannel", "17", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem110 = tableState->horizontalHeaderItem(17);
        ___qtablewidgetitem110->setText(QApplication::translate("DlgChannel", "18", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem111 = tableState->horizontalHeaderItem(18);
        ___qtablewidgetitem111->setText(QApplication::translate("DlgChannel", "19", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem112 = tableState->verticalHeaderItem(0);
        ___qtablewidgetitem112->setText(QApplication::translate("DlgChannel", "534\320\243\320\23701   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem113 = tableState->verticalHeaderItem(1);
        ___qtablewidgetitem113->setText(QApplication::translate("DlgChannel", "534\320\243\320\22301   ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem114 = tableState->verticalHeaderItem(2);
        ___qtablewidgetitem114->setText(QApplication::translate("DlgChannel", "536\320\243\320\22101   ", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled5 = tableState->isSortingEnabled();
        tableState->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem115 = tableState->item(0, 0);
        ___qtablewidgetitem115->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem116 = tableState->item(0, 1);
        ___qtablewidgetitem116->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem117 = tableState->item(0, 2);
        ___qtablewidgetitem117->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem118 = tableState->item(0, 3);
        ___qtablewidgetitem118->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem119 = tableState->item(0, 4);
        ___qtablewidgetitem119->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem120 = tableState->item(0, 5);
        ___qtablewidgetitem120->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem121 = tableState->item(0, 6);
        ___qtablewidgetitem121->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem122 = tableState->item(0, 7);
        ___qtablewidgetitem122->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem123 = tableState->item(0, 8);
        ___qtablewidgetitem123->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem124 = tableState->item(0, 9);
        ___qtablewidgetitem124->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem125 = tableState->item(0, 10);
        ___qtablewidgetitem125->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem126 = tableState->item(0, 11);
        ___qtablewidgetitem126->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem127 = tableState->item(0, 12);
        ___qtablewidgetitem127->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem128 = tableState->item(0, 13);
        ___qtablewidgetitem128->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem129 = tableState->item(0, 14);
        ___qtablewidgetitem129->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem130 = tableState->item(0, 15);
        ___qtablewidgetitem130->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem131 = tableState->item(0, 16);
        ___qtablewidgetitem131->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem132 = tableState->item(0, 17);
        ___qtablewidgetitem132->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem133 = tableState->item(0, 18);
        ___qtablewidgetitem133->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem134 = tableState->item(1, 0);
        ___qtablewidgetitem134->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem135 = tableState->item(1, 1);
        ___qtablewidgetitem135->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem136 = tableState->item(1, 2);
        ___qtablewidgetitem136->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem137 = tableState->item(1, 3);
        ___qtablewidgetitem137->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem138 = tableState->item(1, 4);
        ___qtablewidgetitem138->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem139 = tableState->item(1, 5);
        ___qtablewidgetitem139->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem140 = tableState->item(1, 6);
        ___qtablewidgetitem140->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem141 = tableState->item(1, 7);
        ___qtablewidgetitem141->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem142 = tableState->item(1, 8);
        ___qtablewidgetitem142->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem143 = tableState->item(1, 9);
        ___qtablewidgetitem143->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem144 = tableState->item(1, 10);
        ___qtablewidgetitem144->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem145 = tableState->item(1, 11);
        ___qtablewidgetitem145->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem146 = tableState->item(1, 12);
        ___qtablewidgetitem146->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem147 = tableState->item(1, 13);
        ___qtablewidgetitem147->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem148 = tableState->item(1, 14);
        ___qtablewidgetitem148->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem149 = tableState->item(1, 15);
        ___qtablewidgetitem149->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem150 = tableState->item(1, 16);
        ___qtablewidgetitem150->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem151 = tableState->item(1, 17);
        ___qtablewidgetitem151->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem152 = tableState->item(1, 18);
        ___qtablewidgetitem152->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem153 = tableState->item(2, 0);
        ___qtablewidgetitem153->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem154 = tableState->item(2, 1);
        ___qtablewidgetitem154->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem155 = tableState->item(2, 2);
        ___qtablewidgetitem155->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem156 = tableState->item(2, 3);
        ___qtablewidgetitem156->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem157 = tableState->item(2, 4);
        ___qtablewidgetitem157->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem158 = tableState->item(2, 5);
        ___qtablewidgetitem158->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem159 = tableState->item(2, 6);
        ___qtablewidgetitem159->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem160 = tableState->item(2, 7);
        ___qtablewidgetitem160->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem161 = tableState->item(2, 8);
        ___qtablewidgetitem161->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem162 = tableState->item(2, 9);
        ___qtablewidgetitem162->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem163 = tableState->item(2, 10);
        ___qtablewidgetitem163->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem164 = tableState->item(2, 11);
        ___qtablewidgetitem164->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem165 = tableState->item(2, 12);
        ___qtablewidgetitem165->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem166 = tableState->item(2, 13);
        ___qtablewidgetitem166->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem167 = tableState->item(2, 14);
        ___qtablewidgetitem167->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem168 = tableState->item(2, 15);
        ___qtablewidgetitem168->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem169 = tableState->item(2, 16);
        ___qtablewidgetitem169->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem170 = tableState->item(2, 17);
        ___qtablewidgetitem170->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem171 = tableState->item(2, 18);
        ___qtablewidgetitem171->setText(QApplication::translate("DlgChannel", "00", 0, QApplication::UnicodeUTF8));
        tableState->setSortingEnabled(__sortingEnabled5);

        pushClose->setText(QApplication::translate("DlgChannel", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgChannel: public Ui_DlgChannel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANNEL_H
