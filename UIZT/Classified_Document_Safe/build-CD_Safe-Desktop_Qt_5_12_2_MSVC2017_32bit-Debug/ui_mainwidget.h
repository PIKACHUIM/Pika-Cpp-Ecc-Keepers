/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QToolButton *toolButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(690, 630);
        MainWidget->setMinimumSize(QSize(690, 630));
        toolButton = new QToolButton(MainWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(50, 500, 100, 100));
        toolButton->setMinimumSize(QSize(100, 100));
        toolButton->setStyleSheet(QString::fromUtf8("border-image: url(:/start_button.png);\n"
"color: rgb(75, 75, 75);\n"
"font: 75 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        label = new QLabel(MainWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 590, 61, 40));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/entercaption.png);\n"
"color: rgb(0, 0, 0);"));
        label_2 = new QLabel(MainWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 20, 100, 500));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/caption.png);"));

        retranslateUi(MainWidget);

        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", nullptr));
        toolButton->setText(QString());
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
