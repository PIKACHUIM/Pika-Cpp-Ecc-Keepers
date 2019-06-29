/********************************************************************************
** Form generated from reading UI file 'UIPF.UI'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIPF_H
#define UI_UIPF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIPF
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIPF)
    {
        if (UIPF->objectName().isEmpty())
            UIPF->setObjectName(QString::fromUtf8("UIPF"));
        UIPF->resize(400, 300);
        menuBar = new QMenuBar(UIPF);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        UIPF->setMenuBar(menuBar);
        mainToolBar = new QToolBar(UIPF);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        UIPF->addToolBar(mainToolBar);
        centralWidget = new QWidget(UIPF);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        UIPF->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(UIPF);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIPF->setStatusBar(statusBar);

        retranslateUi(UIPF);

        QMetaObject::connectSlotsByName(UIPF);
    } // setupUi

    void retranslateUi(QMainWindow *UIPF)
    {
        UIPF->setWindowTitle(QApplication::translate("UIPF", "UIPF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIPF: public Ui_UIPF {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIPF_H
