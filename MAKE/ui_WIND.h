/********************************************************************************
** Form generated from reading UI file 'WIND.UI'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIND_H
#define UI_WIND_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIPF_MAIN
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UIPF_MAIN)
    {
        if (UIPF_MAIN->objectName().isEmpty())
            UIPF_MAIN->setObjectName(QString::fromUtf8("UIPF_MAIN"));
        UIPF_MAIN->setEnabled(true);
        UIPF_MAIN->resize(1200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UIPF_MAIN->sizePolicy().hasHeightForWidth());
        UIPF_MAIN->setSizePolicy(sizePolicy);
        UIPF_MAIN->setAutoFillBackground(false);
        UIPF_MAIN->setIconSize(QSize(64, 64));
        UIPF_MAIN->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(UIPF_MAIN);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(650, 200, 113, 20));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(640, 270, 120, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font.setPointSize(18);
        pushButton->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../IMGS/01.BMP"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(120, 60));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(40, 90, 256, 192));
        UIPF_MAIN->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UIPF_MAIN);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        UIPF_MAIN->setMenuBar(menuBar);
        statusBar = new QStatusBar(UIPF_MAIN);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        UIPF_MAIN->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(UIPF_MAIN);

        QMetaObject::connectSlotsByName(UIPF_MAIN);
    } // setupUi

    void retranslateUi(QMainWindow *UIPF_MAIN)
    {
        UIPF_MAIN->setWindowTitle(QApplication::translate("UIPF_MAIN", "\346\234\272\345\257\206\346\226\207\344\273\266\344\277\235\351\231\251\347\256\261", nullptr));
        pushButton->setText(QString());
        menu->setTitle(QApplication::translate("UIPF_MAIN", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIPF_MAIN: public Ui_UIPF_MAIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIND_H
