/********************************************************************************
** Form generated from reading UI file 'file_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_WIDGET_H
#define UI_FILE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_File_Widget
{
public:

    void setupUi(QWidget *File_Widget)
    {
        if (File_Widget->objectName().isEmpty())
            File_Widget->setObjectName(QString::fromUtf8("File_Widget"));
        File_Widget->resize(690, 630);

        retranslateUi(File_Widget);

        QMetaObject::connectSlotsByName(File_Widget);
    } // setupUi

    void retranslateUi(QWidget *File_Widget)
    {
        File_Widget->setWindowTitle(QApplication::translate("File_Widget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class File_Widget: public Ui_File_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_WIDGET_H
