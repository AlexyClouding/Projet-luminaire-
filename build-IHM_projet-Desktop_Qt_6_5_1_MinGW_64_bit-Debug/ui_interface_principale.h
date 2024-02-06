/********************************************************************************
** Form generated from reading UI file 'interface_principale.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_PRINCIPALE_H
#define UI_INTERFACE_PRINCIPALE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface_principale
{
public:
    QWidget *centralwidget;
    QFrame *frame_4;
    QProgressBar *progressBar;
    QDateTimeEdit *dateTimeEdit;
    QFrame *frame_2;
    QLabel *label;
    QLabel *label_2;
    QFrame *frame;
    QPushButton *button_parametre;
    QPushButton *button_information;
    QPushButton *quitter;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *interface_principale)
    {
        if (interface_principale->objectName().isEmpty())
            interface_principale->setObjectName("interface_principale");
        interface_principale->resize(864, 437);
        interface_principale->setMaximumSize(QSize(16777215, 489));
        centralwidget = new QWidget(interface_principale);
        centralwidget->setObjectName("centralwidget");
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(40, 0, 791, 391));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        progressBar = new QProgressBar(frame_4);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(0, 10, 437, 24));
        progressBar->setValue(24);
        dateTimeEdit = new QDateTimeEdit(frame_4);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(450, 10, 326, 22));
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(50, 150, 171, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame_4);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 120, 49, 16));
        label->setSizeIncrement(QSize(800, 800));
        label->setBaseSize(QSize(800, 800));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(600, 120, 49, 16));
        frame = new QFrame(frame_4);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(535, 150, 191, 101));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        button_parametre = new QPushButton(frame_4);
        button_parametre->setObjectName("button_parametre");
        button_parametre->setGeometry(QRect(40, 300, 326, 24));
        button_information = new QPushButton(frame_4);
        button_information->setObjectName("button_information");
        button_information->setGeometry(QRect(460, 300, 301, 24));
        quitter = new QPushButton(frame_4);
        quitter->setObjectName("quitter");
        quitter->setGeometry(QRect(350, 350, 75, 24));
        interface_principale->setCentralWidget(centralwidget);
        menubar = new QMenuBar(interface_principale);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 864, 22));
        interface_principale->setMenuBar(menubar);
        statusbar = new QStatusBar(interface_principale);
        statusbar->setObjectName("statusbar");
        interface_principale->setStatusBar(statusbar);
        toolBar = new QToolBar(interface_principale);
        toolBar->setObjectName("toolBar");
        interface_principale->addToolBar(Qt::RightToolBarArea, toolBar);

        retranslateUi(interface_principale);

        QMetaObject::connectSlotsByName(interface_principale);
    } // setupUi

    void retranslateUi(QMainWindow *interface_principale)
    {
        interface_principale->setWindowTitle(QCoreApplication::translate("interface_principale", "interface_principale", nullptr));
        label->setText(QCoreApplication::translate("interface_principale", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("interface_principale", "TextLabel", nullptr));
        button_parametre->setText(QCoreApplication::translate("interface_principale", "parametre", nullptr));
        button_information->setText(QCoreApplication::translate("interface_principale", "information", nullptr));
        quitter->setText(QCoreApplication::translate("interface_principale", "quitter", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("interface_principale", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface_principale: public Ui_interface_principale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_PRINCIPALE_H
