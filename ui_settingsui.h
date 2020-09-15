/********************************************************************************
** Form generated from reading UI file 'settingsui.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSUI_H
#define UI_SETTINGSUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingsUI
{
public:
    QVBoxLayout *verticalLayout_3;
    QGroupBox *schemeGBox;
    QHBoxLayout *horizontalLayout;
    QComboBox *schemeCBox;
    QPushButton *saveAsBtn;
    QPushButton *deleteBtn;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *view;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *elemGBox;
    QVBoxLayout *verticalLayout;
    QComboBox *elemCBox;
    QGridLayout *gridLayout_2;
    QPushButton *elemColorBtn;
    QPushButton *elemFontColorBtn;
    QGridLayout *gridLayout;
    QPushButton *headerFontBtn;
    QPushButton *headerColorBtn;
    QPushButton *mainFontBtn;
    QPushButton *lineColorBtn;
    QPushButton *dlgFontBtn;
    QPushButton *bgColorBtn;
    QGroupBox *scaleGBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *scaleXLbl;
    QSpinBox *scaleXSBox;
    QLabel *scaleYLbl;
    QSpinBox *scaleYSBox;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *okBtn;
    QPushButton *applyBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *SettingsUI)
    {
        if (SettingsUI->objectName().isEmpty())
            SettingsUI->setObjectName(QString::fromUtf8("SettingsUI"));
        SettingsUI->resize(666, 409);
        SettingsUI->setBaseSize(QSize(591, 343));
        verticalLayout_3 = new QVBoxLayout(SettingsUI);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        schemeGBox = new QGroupBox(SettingsUI);
        schemeGBox->setObjectName(QString::fromUtf8("schemeGBox"));
        horizontalLayout = new QHBoxLayout(schemeGBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        schemeCBox = new QComboBox(schemeGBox);
        schemeCBox->setObjectName(QString::fromUtf8("schemeCBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(schemeCBox->sizePolicy().hasHeightForWidth());
        schemeCBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(schemeCBox);

        saveAsBtn = new QPushButton(schemeGBox);
        saveAsBtn->setObjectName(QString::fromUtf8("saveAsBtn"));

        horizontalLayout->addWidget(saveAsBtn);

        deleteBtn = new QPushButton(schemeGBox);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        deleteBtn->setEnabled(false);

        horizontalLayout->addWidget(deleteBtn);


        verticalLayout_3->addWidget(schemeGBox);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        view = new QGraphicsView(SettingsUI);
        view->setObjectName(QString::fromUtf8("view"));
        view->setMinimumSize(QSize(320, 280));
        view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_4->addWidget(view);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        elemGBox = new QGroupBox(SettingsUI);
        elemGBox->setObjectName(QString::fromUtf8("elemGBox"));
        verticalLayout = new QVBoxLayout(elemGBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        elemCBox = new QComboBox(elemGBox);
        elemCBox->setObjectName(QString::fromUtf8("elemCBox"));
        sizePolicy.setHeightForWidth(elemCBox->sizePolicy().hasHeightForWidth());
        elemCBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(elemCBox);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        elemColorBtn = new QPushButton(elemGBox);
        elemColorBtn->setObjectName(QString::fromUtf8("elemColorBtn"));
        elemColorBtn->setMinimumSize(QSize(142, 0));

        gridLayout_2->addWidget(elemColorBtn, 0, 0, 1, 1);

        elemFontColorBtn = new QPushButton(elemGBox);
        elemFontColorBtn->setObjectName(QString::fromUtf8("elemFontColorBtn"));
        elemFontColorBtn->setMinimumSize(QSize(142, 0));

        gridLayout_2->addWidget(elemFontColorBtn, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        verticalLayout_2->addWidget(elemGBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        headerFontBtn = new QPushButton(SettingsUI);
        headerFontBtn->setObjectName(QString::fromUtf8("headerFontBtn"));
        headerFontBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(headerFontBtn, 0, 0, 1, 1);

        headerColorBtn = new QPushButton(SettingsUI);
        headerColorBtn->setObjectName(QString::fromUtf8("headerColorBtn"));
        headerColorBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(headerColorBtn, 0, 1, 1, 1);

        mainFontBtn = new QPushButton(SettingsUI);
        mainFontBtn->setObjectName(QString::fromUtf8("mainFontBtn"));
        mainFontBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(mainFontBtn, 1, 0, 1, 1);

        lineColorBtn = new QPushButton(SettingsUI);
        lineColorBtn->setObjectName(QString::fromUtf8("lineColorBtn"));
        lineColorBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(lineColorBtn, 1, 1, 1, 1);

        dlgFontBtn = new QPushButton(SettingsUI);
        dlgFontBtn->setObjectName(QString::fromUtf8("dlgFontBtn"));
        dlgFontBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(dlgFontBtn, 2, 0, 1, 1);

        bgColorBtn = new QPushButton(SettingsUI);
        bgColorBtn->setObjectName(QString::fromUtf8("bgColorBtn"));
        bgColorBtn->setMinimumSize(QSize(152, 0));

        gridLayout->addWidget(bgColorBtn, 2, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        scaleGBox = new QGroupBox(SettingsUI);
        scaleGBox->setObjectName(QString::fromUtf8("scaleGBox"));
        horizontalLayout_2 = new QHBoxLayout(scaleGBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        scaleXLbl = new QLabel(scaleGBox);
        scaleXLbl->setObjectName(QString::fromUtf8("scaleXLbl"));

        horizontalLayout_2->addWidget(scaleXLbl);

        scaleXSBox = new QSpinBox(scaleGBox);
        scaleXSBox->setObjectName(QString::fromUtf8("scaleXSBox"));
        sizePolicy.setHeightForWidth(scaleXSBox->sizePolicy().hasHeightForWidth());
        scaleXSBox->setSizePolicy(sizePolicy);
        scaleXSBox->setMinimum(60);
        scaleXSBox->setMaximum(120);
        scaleXSBox->setSingleStep(5);
        scaleXSBox->setValue(100);

        horizontalLayout_2->addWidget(scaleXSBox);

        scaleYLbl = new QLabel(scaleGBox);
        scaleYLbl->setObjectName(QString::fromUtf8("scaleYLbl"));

        horizontalLayout_2->addWidget(scaleYLbl);

        scaleYSBox = new QSpinBox(scaleGBox);
        scaleYSBox->setObjectName(QString::fromUtf8("scaleYSBox"));
        sizePolicy.setHeightForWidth(scaleYSBox->sizePolicy().hasHeightForWidth());
        scaleYSBox->setSizePolicy(sizePolicy);
        scaleYSBox->setMinimum(60);
        scaleYSBox->setMaximum(120);
        scaleYSBox->setSingleStep(5);
        scaleYSBox->setValue(100);

        horizontalLayout_2->addWidget(scaleYSBox);


        verticalLayout_2->addWidget(scaleGBox);


        horizontalLayout_4->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        okBtn = new QPushButton(SettingsUI);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(okBtn);

        applyBtn = new QPushButton(SettingsUI);
        applyBtn->setObjectName(QString::fromUtf8("applyBtn"));
        applyBtn->setEnabled(false);
        applyBtn->setMinimumSize(QSize(100, 0));
        applyBtn->setChecked(false);

        horizontalLayout_3->addWidget(applyBtn);

        cancelBtn = new QPushButton(SettingsUI);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(cancelBtn);


        verticalLayout_3->addLayout(horizontalLayout_3);


        retranslateUi(SettingsUI);

        QMetaObject::connectSlotsByName(SettingsUI);
    } // setupUi

    void retranslateUi(QDialog *SettingsUI)
    {
        SettingsUI->setWindowTitle(QApplication::translate("SettingsUI", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260 \320\263\321\200\320\260\321\204\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        schemeGBox->setTitle(QApplication::translate("SettingsUI", "\320\241\321\205\320\265\320\274\320\260", 0, QApplication::UnicodeUTF8));
        schemeCBox->clear();
        schemeCBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsUI", "\320\237\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", 0, QApplication::UnicodeUTF8)
        );
        saveAsBtn->setText(QApplication::translate("SettingsUI", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272...", 0, QApplication::UnicodeUTF8));
        deleteBtn->setText(QApplication::translate("SettingsUI", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        elemGBox->setTitle(QApplication::translate("SettingsUI", "\320\255\320\273\320\265\320\274\320\265\320\275\321\202 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
        elemCBox->clear();
        elemCBox->insertItems(0, QStringList()
         << QApplication::translate("SettingsUI", "\320\235\320\276\321\200\320\274\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\243\321\205\321\203\320\264\321\210\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\236\321\202\320\272\320\260\320\267", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\235\320\265 \320\276\320\261\321\201\320\273\321\203\320\266\320\270\320\262\320\260\320\265\321\202\321\201\321\217", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\237\320\276\320\264\320\273\320\276\320\266\320\272\320\260", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SettingsUI", "\320\234\320\265\321\201\321\202\320\275\320\276\320\265", 0, QApplication::UnicodeUTF8)
        );
        elemColorBtn->setText(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", 0, QApplication::UnicodeUTF8));
        elemFontColorBtn->setText(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \321\202\320\265\320\272\321\201\321\202\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        headerFontBtn->setToolTip(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        headerFontBtn->setText(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        headerColorBtn->setToolTip(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        headerColorBtn->setText(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\263\320\276\320\273\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        mainFontBtn->setToolTip(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\276\320\262 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        mainFontBtn->setText(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \320\276\321\201\320\275.\321\202\320\265\320\272\321\201\321\202\320\260", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        lineColorBtn->setToolTip(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        lineColorBtn->setText(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dlgFontBtn->setToolTip(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \321\202\320\265\320\272\321\201\321\202\320\260 \320\262 \320\264\320\270\320\260\320\273\320\276\320\263\320\276\320\262\321\213\321\205 \320\276\320\272\320\275\320\260\321\205", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        dlgFontBtn->setText(QApplication::translate("SettingsUI", "\320\250\321\200\320\270\321\204\321\202 \320\264\320\270\320\260\320\273\320\276\320\263\320\276\320\262", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        bgColorBtn->setToolTip(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260 \321\201\321\205\320\265\320\274\321\213", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        bgColorBtn->setText(QApplication::translate("SettingsUI", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", 0, QApplication::UnicodeUTF8));
        scaleGBox->setTitle(QApplication::translate("SettingsUI", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261", 0, QApplication::UnicodeUTF8));
        scaleXLbl->setText(QApplication::translate("SettingsUI", "\320\237\320\276 X:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scaleXSBox->setToolTip(QApplication::translate("SettingsUI", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261 \321\201\321\205\320\265\320\274\321\213 \320\277\320\276 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        scaleYLbl->setText(QApplication::translate("SettingsUI", "\320\237\320\276 Y:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        scaleYSBox->setToolTip(QApplication::translate("SettingsUI", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261 \321\201\321\205\320\265\320\274\321\213 \320\277\320\276 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        okBtn->setToolTip(QApplication::translate("SettingsUI", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\270 \320\262\321\213\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        okBtn->setText(QApplication::translate("SettingsUI", "OK", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        applyBtn->setToolTip(QApplication::translate("SettingsUI", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        applyBtn->setText(QApplication::translate("SettingsUI", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        cancelBtn->setToolTip(QApplication::translate("SettingsUI", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\270 \320\262\321\213\320\271\321\202\320\270", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        cancelBtn->setText(QApplication::translate("SettingsUI", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsUI: public Ui_SettingsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSUI_H
