/********************************************************************************
** Form generated from reading UI file 'interface_parametre.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_PARAMETRE_H
#define UI_INTERFACE_PARAMETRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_interface_parametre
{
public:
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QPushButton *super_utlisateur;
    QPushButton *test;

    void setupUi(QDialog *interface_parametre)
    {
        if (interface_parametre->objectName().isEmpty())
            interface_parametre->setObjectName("interface_parametre");
        interface_parametre->resize(505, 398);
        horizontalSlider = new QSlider(interface_parametre);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(50, 50, 160, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(interface_parametre);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(290, 50, 160, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        super_utlisateur = new QPushButton(interface_parametre);
        super_utlisateur->setObjectName("super_utlisateur");
        super_utlisateur->setGeometry(QRect(200, 180, 75, 24));
        test = new QPushButton(interface_parametre);
        test->setObjectName("test");
        test->setGeometry(QRect(180, 280, 161, 41));

        retranslateUi(interface_parametre);

        QMetaObject::connectSlotsByName(interface_parametre);
    } // setupUi

    void retranslateUi(QDialog *interface_parametre)
    {
        interface_parametre->setWindowTitle(QCoreApplication::translate("interface_parametre", "Dialog", nullptr));
        super_utlisateur->setText(QCoreApplication::translate("interface_parametre", "super-utilisateur", nullptr));
        test->setText(QCoreApplication::translate("interface_parametre", "test d'\303\251mission HF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface_parametre: public Ui_interface_parametre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_PARAMETRE_H
