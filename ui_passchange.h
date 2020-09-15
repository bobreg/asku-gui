/********************************************************************************
** Form generated from reading UI file 'passchange.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSCHANGE_H
#define UI_PASSCHANGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgPassChange
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *labelOld;
    QLineEdit *editOld;
    QLabel *labelNew1;
    QLineEdit *editNew1;
    QLabel *labelNew2;
    QLineEdit *editNew2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonChange;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DlgPassChange)
    {
        if (DlgPassChange->objectName().isEmpty())
            DlgPassChange->setObjectName(QString::fromUtf8("DlgPassChange"));
        DlgPassChange->resize(333, 140);
        verticalLayout = new QVBoxLayout(DlgPassChange);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelOld = new QLabel(DlgPassChange);
        labelOld->setObjectName(QString::fromUtf8("labelOld"));

        gridLayout->addWidget(labelOld, 0, 0, 1, 1);

        editOld = new QLineEdit(DlgPassChange);
        editOld->setObjectName(QString::fromUtf8("editOld"));
        editOld->setMaxLength(64);
        editOld->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editOld, 0, 1, 1, 1);

        labelNew1 = new QLabel(DlgPassChange);
        labelNew1->setObjectName(QString::fromUtf8("labelNew1"));

        gridLayout->addWidget(labelNew1, 1, 0, 1, 1);

        editNew1 = new QLineEdit(DlgPassChange);
        editNew1->setObjectName(QString::fromUtf8("editNew1"));
        editNew1->setMaxLength(64);
        editNew1->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editNew1, 1, 1, 1, 1);

        labelNew2 = new QLabel(DlgPassChange);
        labelNew2->setObjectName(QString::fromUtf8("labelNew2"));

        gridLayout->addWidget(labelNew2, 2, 0, 1, 1);

        editNew2 = new QLineEdit(DlgPassChange);
        editNew2->setObjectName(QString::fromUtf8("editNew2"));
        editNew2->setMaxLength(64);
        editNew2->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(editNew2, 2, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonChange = new QPushButton(DlgPassChange);
        buttonChange->setObjectName(QString::fromUtf8("buttonChange"));
        buttonChange->setMinimumSize(QSize(81, 0));

        horizontalLayout->addWidget(buttonChange);

        buttonCancel = new QPushButton(DlgPassChange);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setMinimumSize(QSize(81, 0));

        horizontalLayout->addWidget(buttonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DlgPassChange);

        QMetaObject::connectSlotsByName(DlgPassChange);
    } // setupUi

    void retranslateUi(QDialog *DlgPassChange)
    {
        DlgPassChange->setWindowTitle(QApplication::translate("DlgPassChange", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\276\320\273\321\217", 0, QApplication::UnicodeUTF8));
        labelOld->setText(QApplication::translate("DlgPassChange", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        labelNew1->setText(QApplication::translate("DlgPassChange", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        labelNew2->setText(QApplication::translate("DlgPassChange", "\320\237\320\276\320\262\321\202\320\276\321\200\320\270\321\202\321\214 \320\275\320\276\320\262\321\213\320\271", 0, QApplication::UnicodeUTF8));
        buttonChange->setText(QApplication::translate("DlgPassChange", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("DlgPassChange", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgPassChange: public Ui_DlgPassChange {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSCHANGE_H
