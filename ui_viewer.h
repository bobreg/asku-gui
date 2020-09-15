/********************************************************************************
** Form generated from reading UI file 'viewer.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWER_H
#define UI_VIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Viewer
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout1_1;
    QLabel *labelDate1;
    QSpacerItem *horizontalSpacer1_4;
    QLabel *labelWait1;
    QSpacerItem *horizontalSpacer1_1;
    QPushButton *pushFiles1;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushCurrent1;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushSelect1;
    QListWidget *list1;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *table1;
    QHBoxLayout *horizontalLayout1_2;
    QCheckBox *checkLast1;
    QSpacerItem *horizontalSpacer1_2;
    QFrame *line;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout2_1;
    QLabel *labelDate2;
    QSpacerItem *horizontalSpacer2_4;
    QLabel *labelWait2;
    QSpacerItem *horizontalSpacer2_1;
    QPushButton *pushFiles2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushCurrent2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushSelect2;
    QListWidget *list2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *table2;
    QHBoxLayout *horizontalLayout2_2;
    QCheckBox *checkLast2;
    QSpacerItem *horizontalSpacer2_2;
    QPushButton *pushClose;

    void setupUi(QDialog *Viewer)
    {
        if (Viewer->objectName().isEmpty())
            Viewer->setObjectName(QString::fromUtf8("Viewer"));
        Viewer->resize(1145, 650);
        Viewer->setBaseSize(QSize(600, 500));
        horizontalLayout_3 = new QHBoxLayout(Viewer);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout1_1 = new QHBoxLayout();
        horizontalLayout1_1->setSpacing(6);
        horizontalLayout1_1->setObjectName(QString::fromUtf8("horizontalLayout1_1"));
        labelDate1 = new QLabel(Viewer);
        labelDate1->setObjectName(QString::fromUtf8("labelDate1"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelDate1->sizePolicy().hasHeightForWidth());
        labelDate1->setSizePolicy(sizePolicy);
        labelDate1->setMinimumSize(QSize(75, 0));
        labelDate1->setFrameShape(QFrame::Panel);
        labelDate1->setFrameShadow(QFrame::Raised);
        labelDate1->setAlignment(Qt::AlignCenter);

        horizontalLayout1_1->addWidget(labelDate1);

        horizontalSpacer1_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout1_1->addItem(horizontalSpacer1_4);

        labelWait1 = new QLabel(Viewer);
        labelWait1->setObjectName(QString::fromUtf8("labelWait1"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(labelWait1->sizePolicy().hasHeightForWidth());
        labelWait1->setSizePolicy(sizePolicy1);
        labelWait1->setAlignment(Qt::AlignCenter);

        horizontalLayout1_1->addWidget(labelWait1);

        horizontalSpacer1_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout1_1->addItem(horizontalSpacer1_1);

        pushFiles1 = new QPushButton(Viewer);
        pushFiles1->setObjectName(QString::fromUtf8("pushFiles1"));
        pushFiles1->setCheckable(true);

        horizontalLayout1_1->addWidget(pushFiles1);


        verticalLayout_5->addLayout(horizontalLayout1_1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushCurrent1 = new QPushButton(Viewer);
        pushCurrent1->setObjectName(QString::fromUtf8("pushCurrent1"));

        horizontalLayout->addWidget(pushCurrent1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushSelect1 = new QPushButton(Viewer);
        pushSelect1->setObjectName(QString::fromUtf8("pushSelect1"));

        horizontalLayout->addWidget(pushSelect1);


        verticalLayout->addLayout(horizontalLayout);

        list1 = new QListWidget(Viewer);
        list1->setObjectName(QString::fromUtf8("list1"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(list1->sizePolicy().hasHeightForWidth());
        list1->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(list1);


        verticalLayout_5->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        table1 = new QTableWidget(Viewer);
        if (table1->columnCount() < 3)
            table1->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table1->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        table1->setObjectName(QString::fromUtf8("table1"));
        table1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table1->setSelectionMode(QAbstractItemView::SingleSelection);
        table1->setSelectionBehavior(QAbstractItemView::SelectRows);
        table1->setCornerButtonEnabled(false);
        table1->setColumnCount(3);

        verticalLayout_3->addWidget(table1);

        horizontalLayout1_2 = new QHBoxLayout();
        horizontalLayout1_2->setSpacing(6);
        horizontalLayout1_2->setObjectName(QString::fromUtf8("horizontalLayout1_2"));
        checkLast1 = new QCheckBox(Viewer);
        checkLast1->setObjectName(QString::fromUtf8("checkLast1"));
        checkLast1->setMinimumSize(QSize(0, 26));
        checkLast1->setChecked(true);

        horizontalLayout1_2->addWidget(checkLast1);

        horizontalSpacer1_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout1_2->addItem(horizontalSpacer1_2);


        verticalLayout_3->addLayout(horizontalLayout1_2);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(verticalLayout_5);

        line = new QFrame(Viewer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalLayout2_1 = new QHBoxLayout();
        horizontalLayout2_1->setSpacing(6);
        horizontalLayout2_1->setObjectName(QString::fromUtf8("horizontalLayout2_1"));
        labelDate2 = new QLabel(Viewer);
        labelDate2->setObjectName(QString::fromUtf8("labelDate2"));
        sizePolicy.setHeightForWidth(labelDate2->sizePolicy().hasHeightForWidth());
        labelDate2->setSizePolicy(sizePolicy);
        labelDate2->setMinimumSize(QSize(75, 0));
        labelDate2->setFrameShape(QFrame::Panel);
        labelDate2->setFrameShadow(QFrame::Raised);
        labelDate2->setAlignment(Qt::AlignCenter);

        horizontalLayout2_1->addWidget(labelDate2);

        horizontalSpacer2_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout2_1->addItem(horizontalSpacer2_4);

        labelWait2 = new QLabel(Viewer);
        labelWait2->setObjectName(QString::fromUtf8("labelWait2"));
        sizePolicy1.setHeightForWidth(labelWait2->sizePolicy().hasHeightForWidth());
        labelWait2->setSizePolicy(sizePolicy1);
        labelWait2->setAlignment(Qt::AlignCenter);

        horizontalLayout2_1->addWidget(labelWait2);

        horizontalSpacer2_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout2_1->addItem(horizontalSpacer2_1);

        pushFiles2 = new QPushButton(Viewer);
        pushFiles2->setObjectName(QString::fromUtf8("pushFiles2"));
        pushFiles2->setCheckable(true);

        horizontalLayout2_1->addWidget(pushFiles2);


        verticalLayout_6->addLayout(horizontalLayout2_1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushCurrent2 = new QPushButton(Viewer);
        pushCurrent2->setObjectName(QString::fromUtf8("pushCurrent2"));

        horizontalLayout_2->addWidget(pushCurrent2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushSelect2 = new QPushButton(Viewer);
        pushSelect2->setObjectName(QString::fromUtf8("pushSelect2"));

        horizontalLayout_2->addWidget(pushSelect2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        list2 = new QListWidget(Viewer);
        list2->setObjectName(QString::fromUtf8("list2"));
        sizePolicy2.setHeightForWidth(list2->sizePolicy().hasHeightForWidth());
        list2->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(list2);


        verticalLayout_6->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        table2 = new QTableWidget(Viewer);
        if (table2->columnCount() < 3)
            table2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table2->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        table2->setObjectName(QString::fromUtf8("table2"));
        table2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table2->setSelectionMode(QAbstractItemView::SingleSelection);
        table2->setSelectionBehavior(QAbstractItemView::SelectRows);
        table2->setCornerButtonEnabled(false);
        table2->setColumnCount(3);

        verticalLayout_4->addWidget(table2);

        horizontalLayout2_2 = new QHBoxLayout();
        horizontalLayout2_2->setSpacing(6);
        horizontalLayout2_2->setObjectName(QString::fromUtf8("horizontalLayout2_2"));
        checkLast2 = new QCheckBox(Viewer);
        checkLast2->setObjectName(QString::fromUtf8("checkLast2"));
        checkLast2->setMinimumSize(QSize(0, 26));
        checkLast2->setChecked(true);

        horizontalLayout2_2->addWidget(checkLast2);

        horizontalSpacer2_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout2_2->addItem(horizontalSpacer2_2);

        pushClose = new QPushButton(Viewer);
        pushClose->setObjectName(QString::fromUtf8("pushClose"));
        pushClose->setMinimumSize(QSize(0, 26));

        horizontalLayout2_2->addWidget(pushClose);


        verticalLayout_4->addLayout(horizontalLayout2_2);


        verticalLayout_6->addLayout(verticalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_6);

        QWidget::setTabOrder(pushFiles1, pushCurrent1);
        QWidget::setTabOrder(pushCurrent1, pushSelect1);
        QWidget::setTabOrder(pushSelect1, list1);
        QWidget::setTabOrder(list1, table1);
        QWidget::setTabOrder(table1, checkLast1);
        QWidget::setTabOrder(checkLast1, pushFiles2);
        QWidget::setTabOrder(pushFiles2, pushCurrent2);
        QWidget::setTabOrder(pushCurrent2, pushSelect2);
        QWidget::setTabOrder(pushSelect2, list2);
        QWidget::setTabOrder(list2, table2);
        QWidget::setTabOrder(table2, checkLast2);
        QWidget::setTabOrder(checkLast2, pushClose);

        retranslateUi(Viewer);
        QObject::connect(pushClose, SIGNAL(clicked()), Viewer, SLOT(hide()));

        QMetaObject::connectSlotsByName(Viewer);
    } // setupUi

    void retranslateUi(QDialog *Viewer)
    {
        Viewer->setWindowTitle(QApplication::translate("Viewer", "\320\226\321\203\321\200\320\275\320\260\320\273 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
        labelDate1->setText(QApplication::translate("Viewer", "01.01.0001", 0, QApplication::UnicodeUTF8));
        labelWait1->setText(QApplication::translate("Viewer", "\320\237\320\276\320\264\320\276\320\266\320\264\320\270\321\202\320\265, \320\270\320\264\320\265\321\202 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\204\320\260\320\271\320\273\320\260...", 0, QApplication::UnicodeUTF8));
        pushFiles1->setText(QApplication::translate("Viewer", "\320\241\320\277\320\270\321\201\320\276\320\272 >>", 0, QApplication::UnicodeUTF8));
        pushCurrent1->setText(QApplication::translate("Viewer", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271", 0, QApplication::UnicodeUTF8));
        pushSelect1->setText(QApplication::translate("Viewer", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = table1->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("Viewer", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = table1->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("Viewer", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = table1->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("Viewer", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkLast1->setText(QApplication::translate("Viewer", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        labelDate2->setText(QApplication::translate("Viewer", "01.01.0001", 0, QApplication::UnicodeUTF8));
        labelWait2->setText(QApplication::translate("Viewer", "\320\237\320\276\320\264\320\276\320\266\320\264\320\270\321\202\320\265, \320\270\320\264\320\265\321\202 \320\267\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \321\204\320\260\320\271\320\273\320\260...", 0, QApplication::UnicodeUTF8));
        pushFiles2->setText(QApplication::translate("Viewer", "\320\241\320\277\320\270\321\201\320\276\320\272 >>", 0, QApplication::UnicodeUTF8));
        pushCurrent2->setText(QApplication::translate("Viewer", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271", 0, QApplication::UnicodeUTF8));
        pushSelect2->setText(QApplication::translate("Viewer", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = table2->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("Viewer", "\320\222\321\200\320\265\320\274\321\217", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = table2->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("Viewer", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = table2->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("Viewer", "\320\241\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        checkLast2->setText(QApplication::translate("Viewer", "\320\237\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        pushClose->setText(QApplication::translate("Viewer", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Viewer: public Ui_Viewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWER_H
