/********************************************************************************
** Form generated from reading UI file 'verify_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VERIFY_WIDGET_H
#define UI_VERIFY_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Verify_Widget
{
public:
    QLabel *label;
    QToolButton *enter;
    QLineEdit *code_input;
    QLineEdit *name_input;
    QLabel *code;
    QLabel *name;
    QLabel *info;
    QLabel *picture;

    void setupUi(QWidget *Verify_Widget)
    {
        if (Verify_Widget->objectName().isEmpty())
            Verify_Widget->setObjectName(QString::fromUtf8("Verify_Widget"));
        Verify_Widget->resize(500, 500);
        label = new QLabel(Verify_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 470, 45, 30));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/backcaption.png);"));
        enter = new QToolButton(Verify_Widget);
        enter->setObjectName(QString::fromUtf8("enter"));
        enter->setGeometry(QRect(200, 390, 111, 81));
        enter->setStyleSheet(QString::fromUtf8("border-image: url(:/key.png);\n"
"font: 24pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";"));
        code_input = new QLineEdit(Verify_Widget);
        code_input->setObjectName(QString::fromUtf8("code_input"));
        code_input->setGeometry(QRect(202, 119, 191, 31));
        name_input = new QLineEdit(Verify_Widget);
        name_input->setObjectName(QString::fromUtf8("name_input"));
        name_input->setGeometry(QRect(200, 40, 191, 31));
        code = new QLabel(Verify_Widget);
        code->setObjectName(QString::fromUtf8("code"));
        code->setGeometry(QRect(80, 122, 54, 31));
        code->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        name = new QLabel(Verify_Widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setGeometry(QRect(80, 40, 54, 31));
        name->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        info = new QLabel(Verify_Widget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(150, 210, 311, 60));
        info->setStyleSheet(QString::fromUtf8(""));
        picture = new QLabel(Verify_Widget);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setGeometry(QRect(40, 180, 105, 105));
        picture->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(Verify_Widget);

        QMetaObject::connectSlotsByName(Verify_Widget);
    } // setupUi

    void retranslateUi(QWidget *Verify_Widget)
    {
        Verify_Widget->setWindowTitle(QApplication::translate("Verify_Widget", "Form", nullptr));
        label->setText(QString());
        enter->setText(QApplication::translate("Verify_Widget", "\350\277\233\345\205\245", nullptr));
        code->setText(QApplication::translate("Verify_Widget", "\345\257\206\347\240\201", nullptr));
        name->setText(QApplication::translate("Verify_Widget", "\345\220\215\347\247\260", nullptr));
        info->setText(QString());
        picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Verify_Widget: public Ui_Verify_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VERIFY_WIDGET_H
