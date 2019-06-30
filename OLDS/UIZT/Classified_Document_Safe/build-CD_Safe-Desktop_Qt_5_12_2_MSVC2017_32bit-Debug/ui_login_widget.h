/********************************************************************************
** Form generated from reading UI file 'login_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_WIDGET_H
#define UI_LOGIN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Widget
{
public:
    QLabel *label;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Login_Widget)
    {
        if (Login_Widget->objectName().isEmpty())
            Login_Widget->setObjectName(QString::fromUtf8("Login_Widget"));
        Login_Widget->resize(690, 630);
        Login_Widget->setMinimumSize(QSize(690, 630));
        label = new QLabel(Login_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(590, 590, 61, 40));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/backcaption.png);\n"
"color: rgb(0\357\274\2140\357\274\2140);"));
        toolButton = new QToolButton(Login_Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(250, 70, 160, 200));
        toolButton->setMinimumSize(QSize(120, 150));
        toolButton->setStyleSheet(QString::fromUtf8("border-image: url(:/decode_button.png);"));
        toolButton_2 = new QToolButton(Login_Widget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setGeometry(QRect(260, 350, 150, 200));
        toolButton_2->setMinimumSize(QSize(120, 160));
        toolButton_2->setStyleSheet(QString::fromUtf8("border-image: url(:/create_button.png);"));
        label_2 = new QLabel(Login_Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(420, 340, 50, 225));
        label_2->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/create_caption.png);"));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2->setWordWrap(true);
        label_3 = new QLabel(Login_Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(420, 60, 50, 225));
        label_3->setStyleSheet(QString::fromUtf8("font: 22pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/open_caption.png);"));
        label_3->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_3->setWordWrap(true);
        label_4 = new QLabel(Login_Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 0, 160, 500));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/Please_choose.png);"));

        retranslateUi(Login_Widget);

        QMetaObject::connectSlotsByName(Login_Widget);
    } // setupUi

    void retranslateUi(QWidget *Login_Widget)
    {
        Login_Widget->setWindowTitle(QApplication::translate("Login_Widget", "Form", nullptr));
        label->setText(QString());
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login_Widget: public Ui_Login_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_WIDGET_H
