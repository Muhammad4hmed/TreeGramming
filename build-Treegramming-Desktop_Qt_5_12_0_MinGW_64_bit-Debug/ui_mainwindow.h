/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuTreegramming;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(647, 715);
        QFont font;
        font.setFamily(QString::fromUtf8("Gill Sans Ultra Bold"));
        font.setPointSize(16);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 16pt \"Gill Sans Ultra Bold\";\n"
"color: rgb(0, 0, 0);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 380, 461, 211));
        verticalLayoutWidget->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"alternate-background-color: rgb(79, 171, 4);\n"
"background-color: rgb(35, 121, 4);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(35, 121, 4);\n"
"background-color: rgb(51, 179, 11);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(35, 121, 4);\n"
"background-color: rgb(51, 179, 11);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(35, 121, 4);\n"
"background-color: rgb(51, 179, 11);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(35, 121, 4);\n"
"background-color: rgb(51, 179, 11);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 0, 361, 371));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Muhammad Ahmed/Downloads/1575625496538.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(-10, 320, 670, 310));
        label_2->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Muhammad Ahmed/Downloads/grass.png")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        label_2->raise();
        verticalLayoutWidget->raise();
        label->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 647, 36));
        menuTreegramming = new QMenu(menuBar);
        menuTreegramming->setObjectName(QString::fromUtf8("menuTreegramming"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuTreegramming->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "BST for Strings", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Decision Tree ", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Natural Language Processing", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "About", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        menuTreegramming->setTitle(QApplication::translate("MainWindow", "Treegramming", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
