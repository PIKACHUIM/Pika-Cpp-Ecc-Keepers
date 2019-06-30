/********************************************************************************
** Form generated from reading UI file 'file_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_WIDGET_H
#define UI_FILE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_File_Widget
{
public:
    QLabel *label;
    QLabel *back_label;
    QToolButton *back;
    QTextBrowser *text;
    QLabel *title;
    QLabel *title_label;
    QComboBox *choose;
    QLabel *choose_label;
    QToolButton *add_button;
    QToolButton *delete_button;

    void setupUi(QWidget *File_Widget)
    {
        if (File_Widget->objectName().isEmpty())
            File_Widget->setObjectName(QString::fromUtf8("File_Widget"));
        File_Widget->resize(690, 630);
        label = new QLabel(File_Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-190, 560, 54, 12));
        back_label = new QLabel(File_Widget);
        back_label->setObjectName(QString::fromUtf8("back_label"));
        back_label->setGeometry(QRect(10, 590, 61, 40));
        back_label->setStyleSheet(QString::fromUtf8("border-image: url(:/backcaption.png);"));
        back = new QToolButton(File_Widget);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(0, 500, 100, 100));
        back->setStyleSheet(QString::fromUtf8("border-image: url(:/start_button.png);"));
        text = new QTextBrowser(File_Widget);
        text->setObjectName(QString::fromUtf8("text"));
        text->setGeometry(QRect(40, 60, 311, 401));
        text->setStyleSheet(QString::fromUtf8("border-image: url(:/file.png);"));
        title = new QLabel(File_Widget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(470, 80, 211, 51));
        title->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        title_label = new QLabel(File_Widget);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setGeometry(QRect(360, 80, 54, 51));
        title_label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        choose = new QComboBox(File_Widget);
        choose->setObjectName(QString::fromUtf8("choose"));
        choose->setGeometry(QRect(470, 40, 191, 31));
        choose_label = new QLabel(File_Widget);
        choose_label->setObjectName(QString::fromUtf8("choose_label"));
        choose_label->setGeometry(QRect(360, 30, 91, 51));
        choose_label->setStyleSheet(QString::fromUtf8("font: 16pt \"\351\273\221\344\275\223\";"));
        add_button = new QToolButton(File_Widget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(470, 150, 151, 31));
        add_button->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));
        delete_button = new QToolButton(File_Widget);
        delete_button->setObjectName(QString::fromUtf8("delete_button"));
        delete_button->setGeometry(QRect(470, 210, 151, 31));
        delete_button->setStyleSheet(QString::fromUtf8("font: 14pt \"\351\273\221\344\275\223\";"));

        retranslateUi(File_Widget);

        QMetaObject::connectSlotsByName(File_Widget);
    } // setupUi

    void retranslateUi(QWidget *File_Widget)
    {
        File_Widget->setWindowTitle(QApplication::translate("File_Widget", "Form", nullptr));
        label->setText(QApplication::translate("File_Widget", "TextLabel", nullptr));
        back_label->setText(QString());
        back->setText(QString());
        title->setText(QString());
        title_label->setText(QApplication::translate("File_Widget", "\346\240\207\351\242\230", nullptr));
        choose_label->setText(QApplication::translate("File_Widget", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        add_button->setText(QApplication::translate("File_Widget", "\346\267\273\345\212\240", nullptr));
        delete_button->setText(QApplication::translate("File_Widget", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class File_Widget: public Ui_File_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_WIDGET_H
