/********************************************************************************
** Form generated from reading UI file 'phase.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PHASE_H
#define UI_PHASE_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgPhase
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *topLayout;
    QLabel *textLabelPrd;
    QComboBox *comboSelectPrd;
    QLabel *textLabelModule;
    QComboBox *comboSelectModule;
    QSpacerItem *spacer4;
    QCheckBox *checkBoxAuto;
    QPushButton *pushMeasure;
    QSpacerItem *spacer5;
    QPushButton *pushMiddle;
    QLabel *textLabelPhase;
    QLineEdit *lineEditPhase;
    QPushButton *pushPhase;
    QFrame *line1;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *textLabel1;
    QTableWidget *tablePhase1;
    QVBoxLayout *verticalLayout_2;
    QLabel *textLabel2;
    QTableWidget *tablePhase2;
    QFrame *line2;
    QHBoxLayout *bottomLayout;
    QPushButton *pushCalculate;
    QSpacerItem *spacer1;
    QPushButton *pushClear1;
    QPushButton *pushClearPhase1;
    QPushButton *pushRefresh;
    QPushButton *pushClear2;
    QPushButton *pushClearPhase2;
    QSpacerItem *spacer2;
    QPushButton *pushApply;
    QPushButton *pushClose;

    void setupUi(QDialog *DlgPhase)
    {
        if (DlgPhase->objectName().isEmpty())
            DlgPhase->setObjectName(QString::fromUtf8("DlgPhase"));
        DlgPhase->resize(1095, 494);
        verticalLayout_3 = new QVBoxLayout(DlgPhase);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        topLayout = new QHBoxLayout();
        topLayout->setSpacing(6);
        topLayout->setObjectName(QString::fromUtf8("topLayout"));
        textLabelPrd = new QLabel(DlgPhase);
        textLabelPrd->setObjectName(QString::fromUtf8("textLabelPrd"));
        textLabelPrd->setWordWrap(false);

        topLayout->addWidget(textLabelPrd);

        comboSelectPrd = new QComboBox(DlgPhase);
        comboSelectPrd->setObjectName(QString::fromUtf8("comboSelectPrd"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboSelectPrd->sizePolicy().hasHeightForWidth());
        comboSelectPrd->setSizePolicy(sizePolicy);
        comboSelectPrd->setMinimumSize(QSize(80, 0));

        topLayout->addWidget(comboSelectPrd);

        textLabelModule = new QLabel(DlgPhase);
        textLabelModule->setObjectName(QString::fromUtf8("textLabelModule"));
        textLabelModule->setWordWrap(false);

        topLayout->addWidget(textLabelModule);

        comboSelectModule = new QComboBox(DlgPhase);
        comboSelectModule->setObjectName(QString::fromUtf8("comboSelectModule"));
        sizePolicy.setHeightForWidth(comboSelectModule->sizePolicy().hasHeightForWidth());
        comboSelectModule->setSizePolicy(sizePolicy);
        comboSelectModule->setMinimumSize(QSize(100, 0));
        comboSelectModule->setMaxVisibleItems(16);

        topLayout->addWidget(comboSelectModule);

        spacer4 = new QSpacerItem(116, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topLayout->addItem(spacer4);

        checkBoxAuto = new QCheckBox(DlgPhase);
        checkBoxAuto->setObjectName(QString::fromUtf8("checkBoxAuto"));
        checkBoxAuto->setChecked(true);

        topLayout->addWidget(checkBoxAuto);

        pushMeasure = new QPushButton(DlgPhase);
        pushMeasure->setObjectName(QString::fromUtf8("pushMeasure"));

        topLayout->addWidget(pushMeasure);

        spacer5 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        topLayout->addItem(spacer5);

        pushMiddle = new QPushButton(DlgPhase);
        pushMiddle->setObjectName(QString::fromUtf8("pushMiddle"));

        topLayout->addWidget(pushMiddle);

        textLabelPhase = new QLabel(DlgPhase);
        textLabelPhase->setObjectName(QString::fromUtf8("textLabelPhase"));
        textLabelPhase->setWordWrap(false);

        topLayout->addWidget(textLabelPhase);

        lineEditPhase = new QLineEdit(DlgPhase);
        lineEditPhase->setObjectName(QString::fromUtf8("lineEditPhase"));

        topLayout->addWidget(lineEditPhase);

        pushPhase = new QPushButton(DlgPhase);
        pushPhase->setObjectName(QString::fromUtf8("pushPhase"));

        topLayout->addWidget(pushPhase);


        verticalLayout_3->addLayout(topLayout);

        line1 = new QFrame(DlgPhase);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textLabel1 = new QLabel(DlgPhase);
        textLabel1->setObjectName(QString::fromUtf8("textLabel1"));
        textLabel1->setWordWrap(false);

        verticalLayout->addWidget(textLabel1);

        tablePhase1 = new QTableWidget(DlgPhase);
        if (tablePhase1->columnCount() < 5)
            tablePhase1->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablePhase1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablePhase1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablePhase1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablePhase1->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tablePhase1->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tablePhase1->setObjectName(QString::fromUtf8("tablePhase1"));

        verticalLayout->addWidget(tablePhase1);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textLabel2 = new QLabel(DlgPhase);
        textLabel2->setObjectName(QString::fromUtf8("textLabel2"));
        textLabel2->setWordWrap(false);

        verticalLayout_2->addWidget(textLabel2);

        tablePhase2 = new QTableWidget(DlgPhase);
        if (tablePhase2->columnCount() < 5)
            tablePhase2->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablePhase2->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tablePhase2->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tablePhase2->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tablePhase2->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tablePhase2->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tablePhase2->setObjectName(QString::fromUtf8("tablePhase2"));

        verticalLayout_2->addWidget(tablePhase2);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);

        line2 = new QFrame(DlgPhase);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line2);

        bottomLayout = new QHBoxLayout();
        bottomLayout->setSpacing(6);
        bottomLayout->setObjectName(QString::fromUtf8("bottomLayout"));
        pushCalculate = new QPushButton(DlgPhase);
        pushCalculate->setObjectName(QString::fromUtf8("pushCalculate"));

        bottomLayout->addWidget(pushCalculate);

        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomLayout->addItem(spacer1);

        pushClear1 = new QPushButton(DlgPhase);
        pushClear1->setObjectName(QString::fromUtf8("pushClear1"));

        bottomLayout->addWidget(pushClear1);

        pushClearPhase1 = new QPushButton(DlgPhase);
        pushClearPhase1->setObjectName(QString::fromUtf8("pushClearPhase1"));

        bottomLayout->addWidget(pushClearPhase1);

        pushRefresh = new QPushButton(DlgPhase);
        pushRefresh->setObjectName(QString::fromUtf8("pushRefresh"));

        bottomLayout->addWidget(pushRefresh);

        pushClear2 = new QPushButton(DlgPhase);
        pushClear2->setObjectName(QString::fromUtf8("pushClear2"));

        bottomLayout->addWidget(pushClear2);

        pushClearPhase2 = new QPushButton(DlgPhase);
        pushClearPhase2->setObjectName(QString::fromUtf8("pushClearPhase2"));

        bottomLayout->addWidget(pushClearPhase2);

        spacer2 = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        bottomLayout->addItem(spacer2);

        pushApply = new QPushButton(DlgPhase);
        pushApply->setObjectName(QString::fromUtf8("pushApply"));

        bottomLayout->addWidget(pushApply);

        pushClose = new QPushButton(DlgPhase);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));

        bottomLayout->addWidget(pushClose);


        verticalLayout_3->addLayout(bottomLayout);

        QWidget::setTabOrder(comboSelectPrd, comboSelectModule);
        QWidget::setTabOrder(comboSelectModule, checkBoxAuto);
        QWidget::setTabOrder(checkBoxAuto, pushMeasure);
        QWidget::setTabOrder(pushMeasure, pushMiddle);
        QWidget::setTabOrder(pushMiddle, lineEditPhase);
        QWidget::setTabOrder(lineEditPhase, pushPhase);
        QWidget::setTabOrder(pushPhase, pushCalculate);
        QWidget::setTabOrder(pushCalculate, pushClear1);
        QWidget::setTabOrder(pushClear1, pushRefresh);
        QWidget::setTabOrder(pushRefresh, pushClear2);
        QWidget::setTabOrder(pushClear2, pushApply);
        QWidget::setTabOrder(pushApply, pushClose);

        retranslateUi(DlgPhase);

        QMetaObject::connectSlotsByName(DlgPhase);
    } // setupUi

    void retranslateUi(QDialog *DlgPhase)
    {
        DlgPhase->setWindowTitle(QApplication::translate("DlgPhase", "\320\244\320\260\320\267\320\270\321\200\320\276\320\262\320\272\320\260 \320\274\320\276\320\264\321\203\320\273\320\265\320\271 \320\277\320\265\321\200\320\265\320\264\320\260\321\202\321\207\320\270\320\272\320\260", 0, QApplication::UnicodeUTF8));
        textLabelPrd->setText(QApplication::translate("DlgPhase", "\320\237\320\240\320\224:", 0, QApplication::UnicodeUTF8));
        comboSelectPrd->clear();
        comboSelectPrd->insertItems(0, QStringList()
         << QApplication::translate("DlgPhase", "\320\222\320\241\320\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\237\320\240\320\224-1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\237\320\240\320\224-2", 0, QApplication::UnicodeUTF8)
        );
        textLabelModule->setText(QApplication::translate("DlgPhase", "\320\243\320\234\320\230:", 0, QApplication::UnicodeUTF8));
        comboSelectModule->clear();
        comboSelectModule->insertItems(0, QStringList()
         << QApplication::translate("DlgPhase", "\320\222\320\241\320\225", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-5", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-6", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-7", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-9", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-11", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-12", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-13", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-14", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-15", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-17", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-18", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-19", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-21", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-22", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-23", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-24", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-25", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-26", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-27", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-28", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-29", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-31", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-32", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-1...16", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("DlgPhase", "\320\243\320\234\320\230-17...32", 0, QApplication::UnicodeUTF8)
        );
        checkBoxAuto->setText(QApplication::translate("DlgPhase", "\320\220\320\262\321\202\320\276", 0, QApplication::UnicodeUTF8));
        pushMeasure->setText(QApplication::translate("DlgPhase", "\320\230\320\267\320\274\320\265\321\200\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushMiddle->setText(QApplication::translate("DlgPhase", "\320\241\321\200\320\265\320\264\320\275\320\265\320\265 >>", 0, QApplication::UnicodeUTF8));
        textLabelPhase->setText(QApplication::translate("DlgPhase", "\320\244\321\206\320\265\320\273 (\320\263\321\200\320\260\320\264) =", 0, QApplication::UnicodeUTF8));
        pushPhase->setText(QApplication::translate("DlgPhase", "\320\241\321\204\320\260\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        textLabel1->setText(QApplication::translate("DlgPhase", "\320\237\320\240\320\224-1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tablePhase1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("DlgPhase", "\320\235\320\276\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tablePhase1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("DlgPhase", "\320\227\320\260\320\262\320\276\320\264\321\201\320\272\320\276\320\271 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tablePhase1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("DlgPhase", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tablePhase1->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("DlgPhase", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tablePhase1->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("DlgPhase", "\320\244\320\260\320\267\320\260 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        textLabel2->setText(QApplication::translate("DlgPhase", "\320\237\320\240\320\224-2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tablePhase2->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("DlgPhase", "\320\235\320\276\320\274\320\265\321\200", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tablePhase2->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("DlgPhase", "\320\227\320\260\320\262\320\276\320\264\321\201\320\272\320\276\320\271 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tablePhase2->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("DlgPhase", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tablePhase2->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("DlgPhase", "\320\237\320\276\320\277\321\200\320\260\320\262\320\272\320\260 \320\232\320\244", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tablePhase2->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("DlgPhase", "\320\244\320\260\320\267\320\260 \320\243\320\234\320\230", 0, QApplication::UnicodeUTF8));
        pushCalculate->setText(QApplication::translate("DlgPhase", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214 \320\237\320\232\320\244", 0, QApplication::UnicodeUTF8));
        pushClear1->setText(QApplication::translate("DlgPhase", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\237\320\232\320\244 1", 0, QApplication::UnicodeUTF8));
        pushClearPhase1->setText(QApplication::translate("DlgPhase", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\244 1", 0, QApplication::UnicodeUTF8));
        pushRefresh->setText(QApplication::translate("DlgPhase", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClear2->setText(QApplication::translate("DlgPhase", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\237\320\232\320\244 2", 0, QApplication::UnicodeUTF8));
        pushClearPhase2->setText(QApplication::translate("DlgPhase", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\244 2", 0, QApplication::UnicodeUTF8));
        pushApply->setText(QApplication::translate("DlgPhase", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("DlgPhase", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgPhase: public Ui_DlgPhase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PHASE_H
