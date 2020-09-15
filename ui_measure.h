/********************************************************************************
** Form generated from reading UI file 'measure.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEASURE_H
#define UI_MEASURE_H

#include <Qt3Support/Q3MimeSourceFactory>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgMeasure
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *hboxLayout;
    QLabel *textLabelProgress;
    QProgressBar *progressBar;
    QFrame *line1;
    QHBoxLayout *hboxLayout1;
    QLabel *textLabelStatus;
    QLabel *textStatus;
    QHBoxLayout *hboxLayout2;
    QLabel *textLabelPrd;
    QLabel *textPrd;
    QLabel *textLabelModule;
    QLabel *textModule;
    QLabel *textLabelPhase;
    QLabel *textPhase;
    QPushButton *pushSetPhase;
    QLineEdit *linePhase;
    QFrame *line2;
    QHBoxLayout *hboxLayout3;
    QSpacerItem *spacer1;
    QPushButton *pushCancel;
    QPushButton *pushNext;
    QSpacerItem *spacer2;

    void setupUi(QDialog *DlgMeasure)
    {
        if (DlgMeasure->objectName().isEmpty())
            DlgMeasure->setObjectName(QString::fromUtf8("DlgMeasure"));
        DlgMeasure->resize(483, 160);
        verticalLayout = new QVBoxLayout(DlgMeasure);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        textLabelProgress = new QLabel(DlgMeasure);
        textLabelProgress->setObjectName(QString::fromUtf8("textLabelProgress"));
        textLabelProgress->setWordWrap(false);

        hboxLayout->addWidget(textLabelProgress);

        progressBar = new QProgressBar(DlgMeasure);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        hboxLayout->addWidget(progressBar);


        verticalLayout->addLayout(hboxLayout);

        line1 = new QFrame(DlgMeasure);
        line1->setObjectName(QString::fromUtf8("line1"));
        line1->setFrameShape(QFrame::HLine);
        line1->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line1);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setSpacing(6);
        hboxLayout1->setObjectName(QString::fromUtf8("hboxLayout1"));
        textLabelStatus = new QLabel(DlgMeasure);
        textLabelStatus->setObjectName(QString::fromUtf8("textLabelStatus"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textLabelStatus->sizePolicy().hasHeightForWidth());
        textLabelStatus->setSizePolicy(sizePolicy);
        textLabelStatus->setWordWrap(false);

        hboxLayout1->addWidget(textLabelStatus);

        textStatus = new QLabel(DlgMeasure);
        textStatus->setObjectName(QString::fromUtf8("textStatus"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(textStatus->sizePolicy().hasHeightForWidth());
        textStatus->setSizePolicy(sizePolicy1);
        textStatus->setFrameShape(QFrame::Panel);
        textStatus->setFrameShadow(QFrame::Sunken);
        textStatus->setWordWrap(false);

        hboxLayout1->addWidget(textStatus);


        verticalLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setSpacing(6);
        hboxLayout2->setObjectName(QString::fromUtf8("hboxLayout2"));
        textLabelPrd = new QLabel(DlgMeasure);
        textLabelPrd->setObjectName(QString::fromUtf8("textLabelPrd"));
        sizePolicy.setHeightForWidth(textLabelPrd->sizePolicy().hasHeightForWidth());
        textLabelPrd->setSizePolicy(sizePolicy);
        textLabelPrd->setWordWrap(false);

        hboxLayout2->addWidget(textLabelPrd);

        textPrd = new QLabel(DlgMeasure);
        textPrd->setObjectName(QString::fromUtf8("textPrd"));
        sizePolicy.setHeightForWidth(textPrd->sizePolicy().hasHeightForWidth());
        textPrd->setSizePolicy(sizePolicy);
        textPrd->setMinimumSize(QSize(30, 0));
        textPrd->setFrameShape(QFrame::Panel);
        textPrd->setFrameShadow(QFrame::Sunken);
        textPrd->setAlignment(Qt::AlignCenter);
        textPrd->setWordWrap(false);

        hboxLayout2->addWidget(textPrd);

        textLabelModule = new QLabel(DlgMeasure);
        textLabelModule->setObjectName(QString::fromUtf8("textLabelModule"));
        sizePolicy.setHeightForWidth(textLabelModule->sizePolicy().hasHeightForWidth());
        textLabelModule->setSizePolicy(sizePolicy);
        textLabelModule->setWordWrap(false);

        hboxLayout2->addWidget(textLabelModule);

        textModule = new QLabel(DlgMeasure);
        textModule->setObjectName(QString::fromUtf8("textModule"));
        sizePolicy.setHeightForWidth(textModule->sizePolicy().hasHeightForWidth());
        textModule->setSizePolicy(sizePolicy);
        textModule->setMinimumSize(QSize(40, 0));
        textModule->setFrameShape(QFrame::Panel);
        textModule->setFrameShadow(QFrame::Sunken);
        textModule->setAlignment(Qt::AlignCenter);
        textModule->setWordWrap(false);

        hboxLayout2->addWidget(textModule);

        textLabelPhase = new QLabel(DlgMeasure);
        textLabelPhase->setObjectName(QString::fromUtf8("textLabelPhase"));
        sizePolicy.setHeightForWidth(textLabelPhase->sizePolicy().hasHeightForWidth());
        textLabelPhase->setSizePolicy(sizePolicy);
        textLabelPhase->setWordWrap(false);

        hboxLayout2->addWidget(textLabelPhase);

        textPhase = new QLabel(DlgMeasure);
        textPhase->setObjectName(QString::fromUtf8("textPhase"));
        sizePolicy.setHeightForWidth(textPhase->sizePolicy().hasHeightForWidth());
        textPhase->setSizePolicy(sizePolicy);
        textPhase->setMinimumSize(QSize(80, 0));
        textPhase->setFrameShape(QFrame::Panel);
        textPhase->setFrameShadow(QFrame::Sunken);
        textPhase->setAlignment(Qt::AlignCenter);
        textPhase->setWordWrap(false);

        hboxLayout2->addWidget(textPhase);

        pushSetPhase = new QPushButton(DlgMeasure);
        pushSetPhase->setObjectName(QString::fromUtf8("pushSetPhase"));

        hboxLayout2->addWidget(pushSetPhase);

        linePhase = new QLineEdit(DlgMeasure);
        linePhase->setObjectName(QString::fromUtf8("linePhase"));
        linePhase->setMinimumSize(QSize(80, 0));

        hboxLayout2->addWidget(linePhase);


        verticalLayout->addLayout(hboxLayout2);

        line2 = new QFrame(DlgMeasure);
        line2->setObjectName(QString::fromUtf8("line2"));
        line2->setFrameShape(QFrame::HLine);
        line2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setSpacing(6);
        hboxLayout3->setObjectName(QString::fromUtf8("hboxLayout3"));
        spacer1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer1);

        pushCancel = new QPushButton(DlgMeasure);
        pushCancel->setObjectName(QString::fromUtf8("pushCancel"));

        hboxLayout3->addWidget(pushCancel);

        pushNext = new QPushButton(DlgMeasure);
        pushNext->setObjectName(QString::fromUtf8("pushNext"));
        pushNext->setDefault(true);

        hboxLayout3->addWidget(pushNext);

        spacer2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout3->addItem(spacer2);


        verticalLayout->addLayout(hboxLayout3);

        QWidget::setTabOrder(linePhase, pushSetPhase);
        QWidget::setTabOrder(pushSetPhase, pushNext);
        QWidget::setTabOrder(pushNext, pushCancel);

        retranslateUi(DlgMeasure);

        QMetaObject::connectSlotsByName(DlgMeasure);
    } // setupUi

    void retranslateUi(QDialog *DlgMeasure)
    {
        DlgMeasure->setWindowTitle(QApplication::translate("DlgMeasure", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265 \321\204\320\260\320\267\321\213 \320\243\320\234\320\230 \320\237\320\240\320\224", 0, QApplication::UnicodeUTF8));
        textLabelProgress->setText(QApplication::translate("DlgMeasure", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201\321\201:", 0, QApplication::UnicodeUTF8));
        textLabelStatus->setText(QApplication::translate("DlgMeasure", "\320\241\321\202\320\260\321\202\321\203\321\201:", 0, QApplication::UnicodeUTF8));
        textStatus->setText(QString());
        textLabelPrd->setText(QApplication::translate("DlgMeasure", "\320\237\320\240\320\224:", 0, QApplication::UnicodeUTF8));
        textPrd->setText(QString());
        textLabelModule->setText(QApplication::translate("DlgMeasure", "\320\243\320\234\320\230:", 0, QApplication::UnicodeUTF8));
        textModule->setText(QString());
        textLabelPhase->setText(QApplication::translate("DlgMeasure", "\320\244\320\260\320\267\320\260:", 0, QApplication::UnicodeUTF8));
        textPhase->setText(QString());
        pushSetPhase->setText(QApplication::translate("DlgMeasure", "<<", 0, QApplication::UnicodeUTF8));
        pushCancel->setText(QApplication::translate("DlgMeasure", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        pushNext->setText(QApplication::translate("DlgMeasure", "\320\224\320\260\320\273\320\265\320\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgMeasure: public Ui_DlgMeasure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEASURE_H
