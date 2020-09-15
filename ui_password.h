/********************************************************************************
** Form generated from reading UI file 'password.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORD_H
#define UI_PASSWORD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DlgPassword
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *editPassword;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;
    QPushButton *buttonChange;

    void setupUi(QDialog *DlgPassword)
    {
        if (DlgPassword->objectName().isEmpty())
            DlgPassword->setObjectName(QString::fromUtf8("DlgPassword"));
        DlgPassword->setWindowModality(Qt::ApplicationModal);
        DlgPassword->resize(301, 81);
        DlgPassword->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout = new QVBoxLayout(DlgPassword);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        editPassword = new QLineEdit(DlgPassword);
        editPassword->setObjectName(QString::fromUtf8("editPassword"));
        editPassword->setMaxLength(64);
        editPassword->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(editPassword);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonOK = new QPushButton(DlgPassword);
        buttonOK->setObjectName(QString::fromUtf8("buttonOK"));
        buttonOK->setMinimumSize(QSize(81, 0));

        horizontalLayout->addWidget(buttonOK);

        buttonCancel = new QPushButton(DlgPassword);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));
        buttonCancel->setMinimumSize(QSize(81, 0));

        horizontalLayout->addWidget(buttonCancel);

        buttonChange = new QPushButton(DlgPassword);
        buttonChange->setObjectName(QString::fromUtf8("buttonChange"));
        buttonChange->setMinimumSize(QSize(81, 0));

        horizontalLayout->addWidget(buttonChange);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DlgPassword);

        QMetaObject::connectSlotsByName(DlgPassword);
    } // setupUi

    void retranslateUi(QDialog *DlgPassword)
    {
        DlgPassword->setWindowTitle(QApplication::translate("DlgPassword", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", 0, QApplication::UnicodeUTF8));
        buttonOK->setText(QApplication::translate("DlgPassword", "\320\236\320\232", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("DlgPassword", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        buttonChange->setText(QApplication::translate("DlgPassword", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DlgPassword: public Ui_DlgPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORD_H
