/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgAbout
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *pixLbl;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *nameLbl;
    QLabel *copyrightLbl;
    QLabel *versionLblText;
    QLabel *versionLbl;
    QLabel *versionLbl1Text;
    QLabel *versionLbl1;
    QLabel *versionLbl2Text;
    QLabel *versionLbl2;
    QSpacerItem *verticalSpacer;
    QPushButton *closeBtn;

    void setupUi(QDialog *DlgAbout)
    {
        if (DlgAbout->objectName().isEmpty())
            DlgAbout->setObjectName(QString::fromUtf8("DlgAbout"));
        DlgAbout->resize(550, 150);
        DlgAbout->setMinimumSize(QSize(550, 150));
        DlgAbout->setMaximumSize(QSize(550, 150));
        DlgAbout->setBaseSize(QSize(481, 150));
        horizontalLayout = new QHBoxLayout(DlgAbout);
        horizontalLayout->setSpacing(12);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pixLbl = new QLabel(DlgAbout);
        pixLbl->setObjectName(QString::fromUtf8("pixLbl"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pixLbl->sizePolicy().hasHeightForWidth());
        pixLbl->setSizePolicy(sizePolicy);
        pixLbl->setMinimumSize(QSize(141, 131));
        pixLbl->setMaximumSize(QSize(141, 131));
        pixLbl->setScaledContents(true);
        pixLbl->setAlignment(Qt::AlignCenter);
        pixLbl->setMargin(10);
        pixLbl->setTextInteractionFlags(Qt::NoTextInteraction);

        horizontalLayout->addWidget(pixLbl);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        nameLbl = new QLabel(DlgAbout);
        nameLbl->setObjectName(QString::fromUtf8("nameLbl"));
        nameLbl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameLbl, 0, 0, 1, 2);

        copyrightLbl = new QLabel(DlgAbout);
        copyrightLbl->setObjectName(QString::fromUtf8("copyrightLbl"));
        copyrightLbl->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(copyrightLbl, 1, 0, 1, 2);

        versionLblText = new QLabel(DlgAbout);
        versionLblText->setObjectName(QString::fromUtf8("versionLblText"));

        gridLayout->addWidget(versionLblText, 2, 0, 1, 1);

        versionLbl = new QLabel(DlgAbout);
        versionLbl->setObjectName(QString::fromUtf8("versionLbl"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(versionLbl->sizePolicy().hasHeightForWidth());
        versionLbl->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(versionLbl, 2, 1, 1, 1);

        versionLbl1Text = new QLabel(DlgAbout);
        versionLbl1Text->setObjectName(QString::fromUtf8("versionLbl1Text"));

        gridLayout->addWidget(versionLbl1Text, 3, 0, 1, 1);

        versionLbl1 = new QLabel(DlgAbout);
        versionLbl1->setObjectName(QString::fromUtf8("versionLbl1"));
        sizePolicy1.setHeightForWidth(versionLbl1->sizePolicy().hasHeightForWidth());
        versionLbl1->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(versionLbl1, 3, 1, 1, 1);

        versionLbl2Text = new QLabel(DlgAbout);
        versionLbl2Text->setObjectName(QString::fromUtf8("versionLbl2Text"));

        gridLayout->addWidget(versionLbl2Text, 4, 0, 1, 1);

        versionLbl2 = new QLabel(DlgAbout);
        versionLbl2->setObjectName(QString::fromUtf8("versionLbl2"));
        sizePolicy1.setHeightForWidth(versionLbl2->sizePolicy().hasHeightForWidth());
        versionLbl2->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(versionLbl2, 4, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        closeBtn = new QPushButton(DlgAbout);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));

        verticalLayout->addWidget(closeBtn);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(DlgAbout);
        QObject::connect(closeBtn, SIGNAL(clicked()), DlgAbout, SLOT(close()));

        QMetaObject::connectSlotsByName(DlgAbout);
    } // setupUi

    void retranslateUi(QDialog *DlgAbout)
    {
        DlgAbout->setWindowTitle(QApplication::translate("DlgAbout", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", 0, QApplication::UnicodeUTF8));
        nameLbl->setText(QApplication::translate("DlgAbout", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202\320\270\320\267\320\270\321\200\320\276\320\262\320\260\320\275\320\275\320\260\321\217 \320\241\320\270\321\201\321\202\320\265\320\274\320\260 \320\232\320\276\320\275\321\202\321\200\320\276\320\273\321\217 \320\270 \320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        copyrightLbl->setText(QApplication::translate("DlgAbout", "\320\220\320\262\321\202\320\276\321\200\321\201\320\272\320\270\320\265 \320\277\321\200\320\260\320\262\320\260: \320\220\320\236 \320\235\320\237\320\236 \320\220\320\233\320\234\320\220\320\227 \320\236\320\232\320\221, 2007-2019 \320\263\320\263.", 0, QApplication::UnicodeUTF8));
        versionLblText->setText(QApplication::translate("DlgAbout", "\320\222\320\265\321\200\321\201\320\270\321\217: ", 0, QApplication::UnicodeUTF8));
        versionLbl->setText(QString());
        versionLbl1Text->setText(QApplication::translate("DlgAbout", "\320\222\320\265\321\200\321\201\320\270\321\217 (\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 1): ", 0, QApplication::UnicodeUTF8));
        versionLbl1->setText(QString());
        versionLbl2Text->setText(QApplication::translate("DlgAbout", "\320\222\320\265\321\200\321\201\320\270\321\217 (\320\236\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260 2): ", 0, QApplication::UnicodeUTF8));
        versionLbl2->setText(QString());
        closeBtn->setText(QApplication::translate("DlgAbout", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgAbout: public Ui_DlgAbout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
