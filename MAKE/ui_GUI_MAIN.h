/********************************************************************************
** Form generated from reading UI file 'GUI_MAIN.UI'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUI_MAIN_H
#define UI_GUI_MAIN_H

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

class Ui_GUI_MAIN
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GUI_MAIN)
    {
        if (GUI_MAIN->objectName().isEmpty())
            GUI_MAIN->setObjectName(QString::fromUtf8("GUI_MAIN"));
        GUI_MAIN->setEnabled(true);
        GUI_MAIN->resize(1200, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(GUI_MAIN->sizePolicy().hasHeightForWidth());
        GUI_MAIN->setSizePolicy(sizePolicy);
        GUI_MAIN->setAutoFillBackground(false);
        GUI_MAIN->setIconSize(QSize(64, 64));
        GUI_MAIN->setUnifiedTitleAndToolBarOnMac(true);
        centralWidget = new QWidget(GUI_MAIN);
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
        GUI_MAIN->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GUI_MAIN);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1200, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        GUI_MAIN->setMenuBar(menuBar);
        statusBar = new QStatusBar(GUI_MAIN);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GUI_MAIN->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(GUI_MAIN);

        QMetaObject::connectSlotsByName(GUI_MAIN);
    } // setupUi

    void retranslateUi(QMainWindow *GUI_MAIN)
    {
        GUI_MAIN->setWindowTitle(QApplication::translate("GUI_MAIN", "\346\234\272\345\257\206\346\226\207\344\273\266\344\277\235\351\231\251\347\256\261", nullptr));
        pushButton->setText(QString());
        menu->setTitle(QApplication::translate("GUI_MAIN", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GUI_MAIN: public Ui_GUI_MAIN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUI_MAIN_H
