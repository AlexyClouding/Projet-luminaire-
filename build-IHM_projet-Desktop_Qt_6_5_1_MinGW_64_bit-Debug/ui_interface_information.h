/********************************************************************************
** Form generated from reading UI file 'interface_information.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_INFORMATION_H
#define UI_INTERFACE_INFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_interface_information
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *interface_information)
    {
        if (interface_information->objectName().isEmpty())
            interface_information->setObjectName("interface_information");
        interface_information->resize(635, 420);
        pushButton = new QPushButton(interface_information);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 130, 75, 24));
        pushButton_2 = new QPushButton(interface_information);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(410, 130, 75, 24));
        pushButton_3 = new QPushButton(interface_information);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(240, 0, 75, 24));

        retranslateUi(interface_information);

        QMetaObject::connectSlotsByName(interface_information);
    } // setupUi

    void retranslateUi(QDialog *interface_information)
    {
        interface_information->setWindowTitle(QCoreApplication::translate("interface_information", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("interface_information", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("interface_information", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("interface_information", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface_information: public Ui_interface_information {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_INFORMATION_H
