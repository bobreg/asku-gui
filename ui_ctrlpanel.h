/********************************************************************************
** Form generated from reading UI file 'ctrlpanel.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CTRLPANEL_H
#define UI_CTRLPANEL_H

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
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgControlPanel
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupRegime;
    QVBoxLayout *verticalLayout;
    QGridLayout *regimeLayout;
    QGroupBox *rgdvBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *rgdvLayout;
    QLabel *rgdvReady;
    QPushButton *rgdvButtonOn;
    QPushButton *rgdvButtonOff;
    QGroupBox *rafBox;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *rafLayout;
    QLabel *rafReady;
    QPushButton *rafButtonOff;
    QPushButton *rafButtonOn;
    QGroupBox *howlBox;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *howlLayout;
    QPushButton *howlButtonOn;
    QPushButton *howlButtonOff;
    QPushButton *howlButtonReset;
    QGroupBox *groupRafList;
    QVBoxLayout *verticalLayout_18;
    QVBoxLayout *verticalLayout_17;
    QTableWidget *tableRaf;
    QProgressBar *progressBarRaf;
    QGroupBox *groupPORL;
    QVBoxLayout *verticalLayout_16;
    QGridLayout *prlLayout;
    QGroupBox *prlObrBox;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *prlObrLayout;
    QPushButton *prlObrButton1;
    QPushButton *prlObrButton2;
    QGroupBox *prlAutoBox;
    QVBoxLayout *verticalLayout_13;
    QGridLayout *prlAutoLayout;
    QPushButton *prlAutoButtonOff;
    QPushButton *prlAutoButtonOn;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_15;
    QGridLayout *prdLayout;
    QGroupBox *pumiBox;
    QVBoxLayout *verticalLayout_7;
    QGridLayout *pumiLayout;
    QPushButton *pumiButton1;
    QPushButton *pumiButton2;
    QGroupBox *prdBox;
    QVBoxLayout *verticalLayout_10;
    QGridLayout *prdLayout2;
    QPushButton *prdButtonOff;
    QPushButton *prdButtonOn;
    QSpacerItem *horizontalSpacer2;
    QGroupBox *azimuthBox;
    QVBoxLayout *verticalLayout_8;
    QGridLayout *azimuthLayout;
    QPushButton *azimuthButton1;
    QPushButton *azimuthButton2;
    QGroupBox *prvBox;
    QVBoxLayout *verticalLayout_9;
    QGridLayout *prvLayout;
    QPushButton *prvButtonOff;
    QPushButton *prvButtonOn;
    QGroupBox *overviewBox;
    QVBoxLayout *verticalLayout_19;
    QGridLayout *azimuthLayout_2;
    QPushButton *overviewButton1;
    QPushButton *overviewButton2;
    QGroupBox *groupMVRL;
    QVBoxLayout *verticalLayout_6;
    QGridLayout *gridLayout;
    QGroupBox *mvrlObrBox;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *vrlObrLayout;
    QPushButton *mvrlObrButton1;
    QPushButton *mvrlObrButton2;
    QGroupBox *vrlAutoBox;
    QVBoxLayout *verticalLayout_11;
    QGridLayout *vrlAutoLayout;
    QPushButton *vrlAutoButtonOff;
    QPushButton *vrlAutoButtonOn;
    QSpacerItem *horizontalSpacer1;
    QHBoxLayout *horizontalLayout;
    QPushButton *closeButton;

    void setupUi(QDialog *DlgControlPanel)
    {
        if (DlgControlPanel->objectName().isEmpty())
            DlgControlPanel->setObjectName(QString::fromUtf8("DlgControlPanel"));
        DlgControlPanel->resize(930, 659);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DlgControlPanel->sizePolicy().hasHeightForWidth());
        DlgControlPanel->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(DlgControlPanel);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupRegime = new QGroupBox(DlgControlPanel);
        groupRegime->setObjectName(QString::fromUtf8("groupRegime"));
        groupRegime->setMinimumSize(QSize(300, 0));
        groupRegime->setAlignment(Qt::AlignCenter);
        verticalLayout = new QVBoxLayout(groupRegime);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        regimeLayout = new QGridLayout();
        regimeLayout->setObjectName(QString::fromUtf8("regimeLayout"));
        rgdvBox = new QGroupBox(groupRegime);
        rgdvBox->setObjectName(QString::fromUtf8("rgdvBox"));
        rgdvBox->setMinimumSize(QSize(120, 0));
        rgdvBox->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(rgdvBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        rgdvLayout = new QGridLayout();
        rgdvLayout->setObjectName(QString::fromUtf8("rgdvLayout"));
        rgdvReady = new QLabel(rgdvBox);
        rgdvReady->setObjectName(QString::fromUtf8("rgdvReady"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(rgdvReady->sizePolicy().hasHeightForWidth());
        rgdvReady->setSizePolicy(sizePolicy1);
        rgdvReady->setMinimumSize(QSize(0, 60));
        rgdvReady->setAutoFillBackground(true);
        rgdvReady->setFrameShape(QFrame::Panel);
        rgdvReady->setFrameShadow(QFrame::Raised);
        rgdvReady->setAlignment(Qt::AlignCenter);

        rgdvLayout->addWidget(rgdvReady, 0, 0, 1, 2);

        rgdvButtonOn = new QPushButton(rgdvBox);
        rgdvButtonOn->setObjectName(QString::fromUtf8("rgdvButtonOn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(rgdvButtonOn->sizePolicy().hasHeightForWidth());
        rgdvButtonOn->setSizePolicy(sizePolicy2);
        rgdvButtonOn->setMaximumSize(QSize(45, 16777215));
        rgdvButtonOn->setCheckable(true);

        rgdvLayout->addWidget(rgdvButtonOn, 1, 1, 1, 1);

        rgdvButtonOff = new QPushButton(rgdvBox);
        rgdvButtonOff->setObjectName(QString::fromUtf8("rgdvButtonOff"));
        sizePolicy2.setHeightForWidth(rgdvButtonOff->sizePolicy().hasHeightForWidth());
        rgdvButtonOff->setSizePolicy(sizePolicy2);
        rgdvButtonOff->setMaximumSize(QSize(45, 16777215));
        rgdvButtonOff->setCheckable(true);
        rgdvButtonOff->setChecked(true);

        rgdvLayout->addWidget(rgdvButtonOff, 1, 0, 1, 1);


        verticalLayout_2->addLayout(rgdvLayout);


        regimeLayout->addWidget(rgdvBox, 0, 0, 1, 1);

        rafBox = new QGroupBox(groupRegime);
        rafBox->setObjectName(QString::fromUtf8("rafBox"));
        rafBox->setMinimumSize(QSize(120, 0));
        rafBox->setAlignment(Qt::AlignCenter);
        verticalLayout_3 = new QVBoxLayout(rafBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        rafLayout = new QGridLayout();
        rafLayout->setObjectName(QString::fromUtf8("rafLayout"));
        rafReady = new QLabel(rafBox);
        rafReady->setObjectName(QString::fromUtf8("rafReady"));
        sizePolicy1.setHeightForWidth(rafReady->sizePolicy().hasHeightForWidth());
        rafReady->setSizePolicy(sizePolicy1);
        rafReady->setMinimumSize(QSize(0, 60));
        rafReady->setAutoFillBackground(true);
        rafReady->setFrameShape(QFrame::Panel);
        rafReady->setFrameShadow(QFrame::Raised);
        rafReady->setAlignment(Qt::AlignCenter);

        rafLayout->addWidget(rafReady, 0, 0, 1, 2);

        rafButtonOff = new QPushButton(rafBox);
        rafButtonOff->setObjectName(QString::fromUtf8("rafButtonOff"));
        sizePolicy2.setHeightForWidth(rafButtonOff->sizePolicy().hasHeightForWidth());
        rafButtonOff->setSizePolicy(sizePolicy2);
        rafButtonOff->setMaximumSize(QSize(45, 16777215));
        rafButtonOff->setCheckable(true);
        rafButtonOff->setChecked(true);
        rafButtonOff->setAutoDefault(false);

        rafLayout->addWidget(rafButtonOff, 1, 0, 1, 1);

        rafButtonOn = new QPushButton(rafBox);
        rafButtonOn->setObjectName(QString::fromUtf8("rafButtonOn"));
        sizePolicy2.setHeightForWidth(rafButtonOn->sizePolicy().hasHeightForWidth());
        rafButtonOn->setSizePolicy(sizePolicy2);
        rafButtonOn->setMaximumSize(QSize(45, 16777215));
        rafButtonOn->setCheckable(true);
        rafButtonOn->setAutoDefault(false);

        rafLayout->addWidget(rafButtonOn, 1, 1, 1, 1);


        verticalLayout_3->addLayout(rafLayout);


        regimeLayout->addWidget(rafBox, 0, 1, 1, 1);


        verticalLayout->addLayout(regimeLayout);


        horizontalLayout_2->addWidget(groupRegime);

        howlBox = new QGroupBox(DlgControlPanel);
        howlBox->setObjectName(QString::fromUtf8("howlBox"));
        howlBox->setMinimumSize(QSize(130, 0));
        howlBox->setAlignment(Qt::AlignCenter);
        verticalLayout_4 = new QVBoxLayout(howlBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        howlLayout = new QGridLayout();
        howlLayout->setObjectName(QString::fromUtf8("howlLayout"));
        howlButtonOn = new QPushButton(howlBox);
        howlButtonOn->setObjectName(QString::fromUtf8("howlButtonOn"));
        howlButtonOn->setMaximumSize(QSize(45, 16777215));
        howlButtonOn->setCheckable(true);
        howlButtonOn->setChecked(true);

        howlLayout->addWidget(howlButtonOn, 0, 1, 1, 1);

        howlButtonOff = new QPushButton(howlBox);
        howlButtonOff->setObjectName(QString::fromUtf8("howlButtonOff"));
        howlButtonOff->setMaximumSize(QSize(45, 16777215));
        howlButtonOff->setCheckable(true);

        howlLayout->addWidget(howlButtonOff, 0, 0, 1, 1);

        howlButtonReset = new QPushButton(howlBox);
        howlButtonReset->setObjectName(QString::fromUtf8("howlButtonReset"));
        howlButtonReset->setCheckable(false);

        howlLayout->addWidget(howlButtonReset, 1, 0, 1, 2);


        verticalLayout_4->addLayout(howlLayout);


        horizontalLayout_2->addWidget(howlBox);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        groupRafList = new QGroupBox(DlgControlPanel);
        groupRafList->setObjectName(QString::fromUtf8("groupRafList"));
        verticalLayout_18 = new QVBoxLayout(groupRafList);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        tableRaf = new QTableWidget(groupRafList);
        if (tableRaf->columnCount() < 3)
            tableRaf->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableRaf->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableRaf->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableRaf->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableRaf->setObjectName(QString::fromUtf8("tableRaf"));
        tableRaf->setMinimumSize(QSize(380, 0));
        tableRaf->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableRaf->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableRaf->setSelectionMode(QAbstractItemView::NoSelection);
        tableRaf->setShowGrid(false);
        tableRaf->setGridStyle(Qt::NoPen);
        tableRaf->setWordWrap(false);
        tableRaf->setCornerButtonEnabled(false);
        tableRaf->horizontalHeader()->setVisible(true);
        tableRaf->horizontalHeader()->setCascadingSectionResizes(true);
        tableRaf->horizontalHeader()->setDefaultSectionSize(120);
        tableRaf->horizontalHeader()->setMinimumSectionSize(45);
        tableRaf->horizontalHeader()->setStretchLastSection(true);
        tableRaf->verticalHeader()->setVisible(false);
        tableRaf->verticalHeader()->setDefaultSectionSize(22);

        verticalLayout_17->addWidget(tableRaf);

        progressBarRaf = new QProgressBar(groupRafList);
        progressBarRaf->setObjectName(QString::fromUtf8("progressBarRaf"));
        progressBarRaf->setValue(0);
        progressBarRaf->setTextVisible(false);

        verticalLayout_17->addWidget(progressBarRaf);


        verticalLayout_18->addLayout(verticalLayout_17);


        gridLayout_2->addWidget(groupRafList, 0, 1, 3, 1);

        groupPORL = new QGroupBox(DlgControlPanel);
        groupPORL->setObjectName(QString::fromUtf8("groupPORL"));
        groupPORL->setAlignment(Qt::AlignCenter);
        verticalLayout_16 = new QVBoxLayout(groupPORL);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        prlLayout = new QGridLayout();
        prlLayout->setObjectName(QString::fromUtf8("prlLayout"));
        prlObrBox = new QGroupBox(groupPORL);
        prlObrBox->setObjectName(QString::fromUtf8("prlObrBox"));
        prlObrBox->setMinimumSize(QSize(130, 0));
        prlObrBox->setAlignment(Qt::AlignCenter);
        verticalLayout_14 = new QVBoxLayout(prlObrBox);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        prlObrLayout = new QGridLayout();
        prlObrLayout->setObjectName(QString::fromUtf8("prlObrLayout"));
        prlObrButton1 = new QPushButton(prlObrBox);
        prlObrButton1->setObjectName(QString::fromUtf8("prlObrButton1"));
        prlObrButton1->setMaximumSize(QSize(45, 16777215));
        prlObrButton1->setCheckable(true);

        prlObrLayout->addWidget(prlObrButton1, 0, 0, 1, 1);

        prlObrButton2 = new QPushButton(prlObrBox);
        prlObrButton2->setObjectName(QString::fromUtf8("prlObrButton2"));
        prlObrButton2->setMaximumSize(QSize(45, 16777215));
        prlObrButton2->setCheckable(true);

        prlObrLayout->addWidget(prlObrButton2, 0, 1, 1, 1);


        verticalLayout_14->addLayout(prlObrLayout);


        prlLayout->addWidget(prlObrBox, 0, 0, 1, 1);

        prlAutoBox = new QGroupBox(groupPORL);
        prlAutoBox->setObjectName(QString::fromUtf8("prlAutoBox"));
        prlAutoBox->setMinimumSize(QSize(130, 0));
        prlAutoBox->setAlignment(Qt::AlignCenter);
        verticalLayout_13 = new QVBoxLayout(prlAutoBox);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        prlAutoLayout = new QGridLayout();
        prlAutoLayout->setObjectName(QString::fromUtf8("prlAutoLayout"));
        prlAutoButtonOff = new QPushButton(prlAutoBox);
        prlAutoButtonOff->setObjectName(QString::fromUtf8("prlAutoButtonOff"));
        prlAutoButtonOff->setMaximumSize(QSize(45, 16777215));
        prlAutoButtonOff->setCheckable(true);
        prlAutoButtonOff->setChecked(false);

        prlAutoLayout->addWidget(prlAutoButtonOff, 0, 0, 1, 1);

        prlAutoButtonOn = new QPushButton(prlAutoBox);
        prlAutoButtonOn->setObjectName(QString::fromUtf8("prlAutoButtonOn"));
        prlAutoButtonOn->setMaximumSize(QSize(45, 16777215));
        prlAutoButtonOn->setCheckable(true);

        prlAutoLayout->addWidget(prlAutoButtonOn, 0, 1, 1, 1);


        verticalLayout_13->addLayout(prlAutoLayout);


        prlLayout->addWidget(prlAutoBox, 0, 1, 1, 1);

        groupBox = new QGroupBox(groupPORL);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_15 = new QVBoxLayout(groupBox);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(0, -1, 0, 0);
        prdLayout = new QGridLayout();
        prdLayout->setObjectName(QString::fromUtf8("prdLayout"));
        pumiBox = new QGroupBox(groupBox);
        pumiBox->setObjectName(QString::fromUtf8("pumiBox"));
        pumiBox->setMinimumSize(QSize(130, 0));
        pumiBox->setAlignment(Qt::AlignCenter);
        verticalLayout_7 = new QVBoxLayout(pumiBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        pumiLayout = new QGridLayout();
        pumiLayout->setObjectName(QString::fromUtf8("pumiLayout"));
        pumiButton1 = new QPushButton(pumiBox);
        pumiButton1->setObjectName(QString::fromUtf8("pumiButton1"));
        pumiButton1->setMaximumSize(QSize(45, 16777215));
        pumiButton1->setCheckable(true);

        pumiLayout->addWidget(pumiButton1, 0, 0, 1, 1);

        pumiButton2 = new QPushButton(pumiBox);
        pumiButton2->setObjectName(QString::fromUtf8("pumiButton2"));
        pumiButton2->setMaximumSize(QSize(45, 16777215));
        pumiButton2->setCheckable(true);

        pumiLayout->addWidget(pumiButton2, 0, 1, 1, 1);


        verticalLayout_7->addLayout(pumiLayout);


        prdLayout->addWidget(pumiBox, 0, 0, 1, 1);

        prdBox = new QGroupBox(groupBox);
        prdBox->setObjectName(QString::fromUtf8("prdBox"));
        prdBox->setMinimumSize(QSize(130, 0));
        prdBox->setAlignment(Qt::AlignCenter);
        verticalLayout_10 = new QVBoxLayout(prdBox);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        prdLayout2 = new QGridLayout();
        prdLayout2->setObjectName(QString::fromUtf8("prdLayout2"));
        prdButtonOff = new QPushButton(prdBox);
        prdButtonOff->setObjectName(QString::fromUtf8("prdButtonOff"));
        prdButtonOff->setMaximumSize(QSize(45, 16777215));
        prdButtonOff->setCheckable(true);
        prdButtonOff->setChecked(true);

        prdLayout2->addWidget(prdButtonOff, 0, 0, 1, 1);

        prdButtonOn = new QPushButton(prdBox);
        prdButtonOn->setObjectName(QString::fromUtf8("prdButtonOn"));
        prdButtonOn->setMaximumSize(QSize(45, 16777215));
        prdButtonOn->setCheckable(true);

        prdLayout2->addWidget(prdButtonOn, 0, 1, 1, 1);


        verticalLayout_10->addLayout(prdLayout2);


        prdLayout->addWidget(prdBox, 0, 1, 1, 1);

        horizontalSpacer2 = new QSpacerItem(126, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        prdLayout->addItem(horizontalSpacer2, 0, 2, 1, 1);


        verticalLayout_15->addLayout(prdLayout);


        prlLayout->addWidget(groupBox, 2, 0, 1, 3);

        azimuthBox = new QGroupBox(groupPORL);
        azimuthBox->setObjectName(QString::fromUtf8("azimuthBox"));
        azimuthBox->setMinimumSize(QSize(130, 0));
        azimuthBox->setAlignment(Qt::AlignCenter);
        verticalLayout_8 = new QVBoxLayout(azimuthBox);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        azimuthLayout = new QGridLayout();
        azimuthLayout->setObjectName(QString::fromUtf8("azimuthLayout"));
        azimuthButton1 = new QPushButton(azimuthBox);
        azimuthButton1->setObjectName(QString::fromUtf8("azimuthButton1"));
        azimuthButton1->setMaximumSize(QSize(45, 16777215));
        azimuthButton1->setCheckable(true);

        azimuthLayout->addWidget(azimuthButton1, 0, 0, 1, 1);

        azimuthButton2 = new QPushButton(azimuthBox);
        azimuthButton2->setObjectName(QString::fromUtf8("azimuthButton2"));
        azimuthButton2->setMaximumSize(QSize(45, 16777215));
        azimuthButton2->setCheckable(true);

        azimuthLayout->addWidget(azimuthButton2, 0, 1, 1, 1);


        verticalLayout_8->addLayout(azimuthLayout);


        prlLayout->addWidget(azimuthBox, 1, 1, 1, 1);

        prvBox = new QGroupBox(groupPORL);
        prvBox->setObjectName(QString::fromUtf8("prvBox"));
        prvBox->setMinimumSize(QSize(130, 0));
        prvBox->setAlignment(Qt::AlignCenter);
        verticalLayout_9 = new QVBoxLayout(prvBox);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        prvLayout = new QGridLayout();
        prvLayout->setObjectName(QString::fromUtf8("prvLayout"));
        prvButtonOff = new QPushButton(prvBox);
        prvButtonOff->setObjectName(QString::fromUtf8("prvButtonOff"));
        prvButtonOff->setMaximumSize(QSize(45, 16777215));
        prvButtonOff->setCheckable(true);
        prvButtonOff->setChecked(true);

        prvLayout->addWidget(prvButtonOff, 0, 0, 1, 1);

        prvButtonOn = new QPushButton(prvBox);
        prvButtonOn->setObjectName(QString::fromUtf8("prvButtonOn"));
        prvButtonOn->setMaximumSize(QSize(45, 16777215));
        prvButtonOn->setCheckable(true);

        prvLayout->addWidget(prvButtonOn, 0, 1, 1, 1);


        verticalLayout_9->addLayout(prvLayout);


        prlLayout->addWidget(prvBox, 0, 2, 1, 1);

        overviewBox = new QGroupBox(groupPORL);
        overviewBox->setObjectName(QString::fromUtf8("overviewBox"));
        overviewBox->setMinimumSize(QSize(130, 0));
        overviewBox->setAlignment(Qt::AlignCenter);
        verticalLayout_19 = new QVBoxLayout(overviewBox);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        azimuthLayout_2 = new QGridLayout();
        azimuthLayout_2->setObjectName(QString::fromUtf8("azimuthLayout_2"));
        overviewButton1 = new QPushButton(overviewBox);
        overviewButton1->setObjectName(QString::fromUtf8("overviewButton1"));
        overviewButton1->setMaximumSize(QSize(45, 16777215));
        overviewButton1->setCheckable(true);

        azimuthLayout_2->addWidget(overviewButton1, 0, 0, 1, 1);

        overviewButton2 = new QPushButton(overviewBox);
        overviewButton2->setObjectName(QString::fromUtf8("overviewButton2"));
        overviewButton2->setMaximumSize(QSize(45, 16777215));
        overviewButton2->setCheckable(true);

        azimuthLayout_2->addWidget(overviewButton2, 0, 1, 1, 1);


        verticalLayout_19->addLayout(azimuthLayout_2);


        prlLayout->addWidget(overviewBox, 1, 2, 1, 1);


        verticalLayout_16->addLayout(prlLayout);


        gridLayout_2->addWidget(groupPORL, 1, 0, 1, 1);

        groupMVRL = new QGroupBox(DlgControlPanel);
        groupMVRL->setObjectName(QString::fromUtf8("groupMVRL"));
        groupMVRL->setMaximumSize(QSize(16777215, 110));
        groupMVRL->setAlignment(Qt::AlignCenter);
        verticalLayout_6 = new QVBoxLayout(groupMVRL);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mvrlObrBox = new QGroupBox(groupMVRL);
        mvrlObrBox->setObjectName(QString::fromUtf8("mvrlObrBox"));
        mvrlObrBox->setMinimumSize(QSize(130, 0));
        mvrlObrBox->setMaximumSize(QSize(16777215, 70));
        mvrlObrBox->setAlignment(Qt::AlignCenter);
        verticalLayout_12 = new QVBoxLayout(mvrlObrBox);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        vrlObrLayout = new QGridLayout();
        vrlObrLayout->setObjectName(QString::fromUtf8("vrlObrLayout"));
        mvrlObrButton1 = new QPushButton(mvrlObrBox);
        mvrlObrButton1->setObjectName(QString::fromUtf8("mvrlObrButton1"));
        mvrlObrButton1->setMaximumSize(QSize(45, 16777215));
        mvrlObrButton1->setCheckable(true);

        vrlObrLayout->addWidget(mvrlObrButton1, 0, 0, 1, 1);

        mvrlObrButton2 = new QPushButton(mvrlObrBox);
        mvrlObrButton2->setObjectName(QString::fromUtf8("mvrlObrButton2"));
        mvrlObrButton2->setMaximumSize(QSize(45, 16777215));
        mvrlObrButton2->setCheckable(true);

        vrlObrLayout->addWidget(mvrlObrButton2, 0, 1, 1, 1);


        verticalLayout_12->addLayout(vrlObrLayout);


        gridLayout->addWidget(mvrlObrBox, 0, 0, 1, 1);

        vrlAutoBox = new QGroupBox(groupMVRL);
        vrlAutoBox->setObjectName(QString::fromUtf8("vrlAutoBox"));
        vrlAutoBox->setMinimumSize(QSize(130, 0));
        vrlAutoBox->setMaximumSize(QSize(16777215, 70));
        vrlAutoBox->setAlignment(Qt::AlignCenter);
        verticalLayout_11 = new QVBoxLayout(vrlAutoBox);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        vrlAutoLayout = new QGridLayout();
        vrlAutoLayout->setObjectName(QString::fromUtf8("vrlAutoLayout"));
        vrlAutoButtonOff = new QPushButton(vrlAutoBox);
        vrlAutoButtonOff->setObjectName(QString::fromUtf8("vrlAutoButtonOff"));
        vrlAutoButtonOff->setMaximumSize(QSize(45, 16777215));
        vrlAutoButtonOff->setCheckable(true);
        vrlAutoButtonOff->setChecked(true);

        vrlAutoLayout->addWidget(vrlAutoButtonOff, 0, 0, 1, 1);

        vrlAutoButtonOn = new QPushButton(vrlAutoBox);
        vrlAutoButtonOn->setObjectName(QString::fromUtf8("vrlAutoButtonOn"));
        vrlAutoButtonOn->setMaximumSize(QSize(45, 16777215));
        vrlAutoButtonOn->setCheckable(true);

        vrlAutoLayout->addWidget(vrlAutoButtonOn, 0, 1, 1, 1);


        verticalLayout_11->addLayout(vrlAutoLayout);


        gridLayout->addWidget(vrlAutoBox, 0, 1, 1, 1);

        horizontalSpacer1 = new QSpacerItem(130, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer1, 0, 2, 1, 1);


        verticalLayout_6->addLayout(gridLayout);


        gridLayout_2->addWidget(groupMVRL, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        closeButton = new QPushButton(DlgControlPanel);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setMaximumSize(QSize(80, 16777215));
        closeButton->setDefault(true);

        horizontalLayout->addWidget(closeButton);


        gridLayout_2->addLayout(horizontalLayout, 3, 0, 1, 2);

        QWidget::setTabOrder(rgdvButtonOff, rgdvButtonOn);
        QWidget::setTabOrder(rgdvButtonOn, rafButtonOff);
        QWidget::setTabOrder(rafButtonOff, rafButtonOn);
        QWidget::setTabOrder(rafButtonOn, howlButtonOff);
        QWidget::setTabOrder(howlButtonOff, howlButtonOn);
        QWidget::setTabOrder(howlButtonOn, howlButtonReset);
        QWidget::setTabOrder(howlButtonReset, prvButtonOff);
        QWidget::setTabOrder(prvButtonOff, prvButtonOn);
        QWidget::setTabOrder(prvButtonOn, pumiButton1);
        QWidget::setTabOrder(pumiButton1, pumiButton2);
        QWidget::setTabOrder(pumiButton2, azimuthButton1);
        QWidget::setTabOrder(azimuthButton1, azimuthButton2);

        retranslateUi(DlgControlPanel);
        QObject::connect(closeButton, SIGNAL(clicked()), DlgControlPanel, SLOT(hide()));

        QMetaObject::connectSlotsByName(DlgControlPanel);
    } // setupUi

    void retranslateUi(QDialog *DlgControlPanel)
    {
        DlgControlPanel->setWindowTitle(QApplication::translate("DlgControlPanel", "\320\237\320\260\320\275\320\265\320\273\321\214 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\240\320\233\320\232", 0, QApplication::UnicodeUTF8));
        groupRegime->setTitle(QApplication::translate("DlgControlPanel", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213", 0, QApplication::UnicodeUTF8));
        rgdvBox->setTitle(QApplication::translate("DlgControlPanel", "\320\240\320\223\320\224\320\222", 0, QApplication::UnicodeUTF8));
        rgdvReady->setText(QApplication::translate("DlgControlPanel", "\320\223\320\276\321\202\320\276\320\262", 0, QApplication::UnicodeUTF8));
        rgdvButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        rgdvButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        rafBox->setTitle(QApplication::translate("DlgControlPanel", "\320\240\320\220\320\244", 0, QApplication::UnicodeUTF8));
        rafReady->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275", 0, QApplication::UnicodeUTF8));
        rafButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        rafButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        howlBox->setTitle(QApplication::translate("DlgControlPanel", "\320\240\320\265\320\262\321\203\320\275", 0, QApplication::UnicodeUTF8));
        howlButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        howlButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        howlButtonReset->setText(QApplication::translate("DlgControlPanel", "\320\241\320\261\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        groupRafList->setTitle(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265/\320\236\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\240\320\220\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableRaf->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DlgControlPanel", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\320\265", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableRaf->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("DlgControlPanel", "\320\222\321\200\320\265\320\274\321\217, \321\201\320\265\320\272.", 0, QApplication::UnicodeUTF8));
        groupPORL->setTitle(QApplication::translate("DlgControlPanel", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\237\320\236\320\240\320\233", 0, QApplication::UnicodeUTF8));
        prlObrBox->setTitle(QApplication::translate("DlgControlPanel", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260-\320\237\320\240\320\234-\320\227\320\223", 0, QApplication::UnicodeUTF8));
        prlObrButton1->setText(QApplication::translate("DlgControlPanel", "I", 0, QApplication::UnicodeUTF8));
        prlObrButton2->setText(QApplication::translate("DlgControlPanel", "II", 0, QApplication::UnicodeUTF8));
        prlAutoBox->setTitle(QApplication::translate("DlgControlPanel", "\320\220\320\222\320\242 \320\240\320\225\320\227", 0, QApplication::UnicodeUTF8));
        prlAutoButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        prlAutoButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DlgControlPanel", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\265\321\200\320\265\320\264\320\260\321\202\321\207\320\270\320\272\320\276\320\274", 0, QApplication::UnicodeUTF8));
        pumiBox->setTitle(QApplication::translate("DlgControlPanel", "\320\237\320\243\320\234", 0, QApplication::UnicodeUTF8));
        pumiButton1->setText(QApplication::translate("DlgControlPanel", "I", 0, QApplication::UnicodeUTF8));
        pumiButton2->setText(QApplication::translate("DlgControlPanel", "II", 0, QApplication::UnicodeUTF8));
        prdBox->setTitle(QApplication::translate("DlgControlPanel", "\320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        prdButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        prdButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        azimuthBox->setTitle(QApplication::translate("DlgControlPanel", "\320\220\320\267. \320\264\320\260\321\202\321\207\320\270\320\272", 0, QApplication::UnicodeUTF8));
        azimuthButton1->setText(QApplication::translate("DlgControlPanel", "I", 0, QApplication::UnicodeUTF8));
        azimuthButton2->setText(QApplication::translate("DlgControlPanel", "II", 0, QApplication::UnicodeUTF8));
        prvBox->setTitle(QApplication::translate("DlgControlPanel", "\320\221\320\255\320\237", 0, QApplication::UnicodeUTF8));
        prvButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        prvButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        overviewBox->setTitle(QApplication::translate("DlgControlPanel", "\320\240\320\265\320\266\320\270\320\274 \320\276\320\261\320\267\320\276\321\200\320\260", 0, QApplication::UnicodeUTF8));
        overviewButton1->setText(QApplication::translate("DlgControlPanel", "I", 0, QApplication::UnicodeUTF8));
        overviewButton2->setText(QApplication::translate("DlgControlPanel", "II", 0, QApplication::UnicodeUTF8));
        groupMVRL->setTitle(QApplication::translate("DlgControlPanel", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\234\320\222\320\240\320\233-\320\232\320\235", 0, QApplication::UnicodeUTF8));
        mvrlObrBox->setTitle(QApplication::translate("DlgControlPanel", "\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260-\320\237\320\240\320\234-\320\227\320\223", 0, QApplication::UnicodeUTF8));
        mvrlObrButton1->setText(QApplication::translate("DlgControlPanel", "I", 0, QApplication::UnicodeUTF8));
        mvrlObrButton2->setText(QApplication::translate("DlgControlPanel", "II", 0, QApplication::UnicodeUTF8));
        vrlAutoBox->setTitle(QApplication::translate("DlgControlPanel", "\320\220\320\222\320\242 \320\240\320\225\320\227", 0, QApplication::UnicodeUTF8));
        vrlAutoButtonOff->setText(QApplication::translate("DlgControlPanel", "\320\236\321\202\320\272\320\273", 0, QApplication::UnicodeUTF8));
        vrlAutoButtonOn->setText(QApplication::translate("DlgControlPanel", "\320\222\320\272\320\273", 0, QApplication::UnicodeUTF8));
        closeButton->setText(QApplication::translate("DlgControlPanel", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgControlPanel: public Ui_DlgControlPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CTRLPANEL_H
