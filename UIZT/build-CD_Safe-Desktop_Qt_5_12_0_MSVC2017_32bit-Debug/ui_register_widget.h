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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register_Widget
{
public:
    QLabel *back;
    QLabel *path;
    QComboBox *dircomboBox;
    QToolButton *search;
    QLineEdit *name_input;
    QLineEdit *code_input;
    QLineEdit *recode_input;
    QLabel *name;
    QLabel *code;
    QLabel *recode;
    QToolButton *confirm;
    QLabel *picture;
    QLabel *info;

    void setupUi(QWidget *Register_Widget)
    {
        if (Register_Widget->objectName().isEmpty())
            Register_Widget->setObjectName(QString::fromUtf8("Register_Widget"));
        Register_Widget->resize(690, 630);
        back = new QLabel(Register_Widget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(10, 590, 61, 40));
        back->setStyleSheet(QString::fromUtf8("font: 20pt \"\351\273\221\344\275\223\";\n"
"border-image: url(:/backcaption.png);"));
        path = new QLabel(Register_Widget);
        path->setObjectName(QString::fromUtf8("path"));
        path->setGeometry(QRect(100, 80, 91, 30));
        path->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        dircomboBox = new QComboBox(Register_Widget);
        dircomboBox->setObjectName(QString::fromUtf8("dircomboBox"));
        dircomboBox->setGeometry(QRect(200, 80, 280, 30));
        search = new QToolButton(Register_Widget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(490, 80, 70, 30));
        search->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";"));
        name_input = new QLineEdit(Register_Widget);
        name_input->setObjectName(QString::fromUtf8("name_input"));
        name_input->setGeometry(QRect(200, 150, 280, 30));
        code_input = new QLineEdit(Register_Widget);
        code_input->setObjectName(QString::fromUtf8("code_input"));
        code_input->setGeometry(QRect(200, 200, 280, 30));
        recode_input = new QLineEdit(Register_Widget);
        recode_input->setObjectName(QString::fromUtf8("recode_input"));
        recode_input->setGeometry(QRect(200, 250, 280, 30));
        name = new QLabel(Register_Widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(100, 150, 91, 30));
        name->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        code = new QLabel(Register_Widget);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(100, 200, 91, 30));
        code->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        recode = new QLabel(Register_Widget);
        recode->setObjectName(QString::fromUtf8("recode"));
        recode->setGeometry(QRect(100, 250, 91, 30));
        recode->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        confirm = new QToolButton(Register_Widget);
        confirm->setObjectName(QString::fromUtf8("confirm"));
        confirm->setGeometry(QRect(540, 470, 104, 150));
        confirm->setStyleSheet(QString::fromUtf8("border-image: url(:/confirm_button.png);\n"
"font: 24pt \"\351\273\221\344\275\223\";\n"
"color: rgb(255, 255, 255);"));
        picture = new QLabel(Register_Widget);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(100, 330, 105, 105));
        info = new QLabel(Register_Widget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(220, 350, 311, 60));

        retranslateUi(Register_Widget);

        QMetaObject::connectSlotsByName(Register_Widget);
    } // setupUi

    void retranslateUi(QWidget *Register_Widget)
    {
        Register_Widget->setWindowTitle(QApplication::translate("Register_Widget", "Form", nullptr));
        back->setText(QString());
        path->setText(QApplication::translate("Register_Widget", "\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        search->setText(QApplication::translate("Register_Widget", "\346\265\217\350\247\210...", nullptr));
        code_input->setText(QString());
        name->setText(QApplication::translate("Register_Widget", "\345\220\215\347\247\260", nullptr));
        code->setText(QApplication::translate("Register_Widget", "\345\257\206\347\240\201", nullptr));
        recode->setText(QApplication::translate("Register_Widget", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
        confirm->setText(QApplication::translate("Register_Widget", "\347\241\256  \350\256\244", nullptr));
        picture->setText(QString());
        info->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register_Widget: public Ui_Register_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_WIDGET_H
