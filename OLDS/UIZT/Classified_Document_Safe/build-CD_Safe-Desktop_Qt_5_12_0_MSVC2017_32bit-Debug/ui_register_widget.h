/********************************************************************************
** Form generated from reading UI file 'register_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_WIDGET_H
#define UI_REGISTER_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register_Widget
{
public:
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QToolButton *toolButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *Register_Widget)
    {
        if (Register_Widget->objectName().isEmpty())
            Register_Widget->setObjectName(QString::fromUtf8("Register_Widget"));
        Register_Widget->resize(690, 630);
        label = new QLabel(Register_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 590, 61, 40));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/backcaption.png);"));
        label_2 = new QLabel(Register_Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 80, 91, 30));
        label_2->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        comboBox = new QComboBox(Register_Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(200, 80, 280, 30));
        toolButton = new QToolButton(Register_Widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(490, 80, 70, 30));
        lineEdit = new QLineEdit(Register_Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 150, 280, 30));
        lineEdit_2 = new QLineEdit(Register_Widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 200, 280, 30));
        lineEdit_3 = new QLineEdit(Register_Widget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(200, 250, 280, 30));
        pushButton = new QPushButton(Register_Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(280, 390, 104, 150));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/confirm_button.png);\n"
"color: rgb(255, 255, 255);\n"
"font: 22pt \"\351\273\221\344\275\223\";"));
        label_6 = new QLabel(Register_Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 150, 91, 30));
        label_6->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_3 = new QLabel(Register_Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 200, 91, 30));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        label_4 = new QLabel(Register_Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 250, 91, 30));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));

        retranslateUi(Register_Widget);

        QMetaObject::connectSlotsByName(Register_Widget);
    } // setupUi

    void retranslateUi(QWidget *Register_Widget)
    {
        Register_Widget->setWindowTitle(QApplication::translate("Register_Widget", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("Register_Widget", "\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        toolButton->setText(QApplication::translate("Register_Widget", "\346\265\217\350\247\210...", nullptr));
        lineEdit_2->setText(QString());
        pushButton->setText(QApplication::translate("Register_Widget", "\347\241\256 \350\256\244", nullptr));
        label_6->setText(QApplication::translate("Register_Widget", "\345\220\215\347\247\260", nullptr));
        label_3->setText(QApplication::translate("Register_Widget", "\345\257\206\347\240\201", nullptr));
        label_4->setText(QApplication::translate("Register_Widget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register_Widget: public Ui_Register_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WIDGET_H
