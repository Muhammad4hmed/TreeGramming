/********************************************************************************
** Form generated from reading UI file 'sentimentanalysis.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENTIMENTANALYSIS_H
#define UI_SENTIMENTANALYSIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SentimentAnalysis
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuSentiment_Analysis;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SentimentAnalysis)
    {
        if (SentimentAnalysis->objectName().isEmpty())
            SentimentAnalysis->setObjectName(QString::fromUtf8("SentimentAnalysis"));
        SentimentAnalysis->resize(718, 706);
        SentimentAnalysis->setStyleSheet(QString::fromUtf8("background-color: rgb(90, 90, 90);\n"
"background-color: rgb(94, 94, 94);\n"
"color: rgb(255, 255, 255);\n"
"font: 16pt \"Kristen ITC\";"));
        centralwidget = new QWidget(SentimentAnalysis);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 570, 340));
        label->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Muhammad Ahmed/Downloads/1575646741876.png")));
        label->setScaledContents(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(76, 390, 271, 20));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(80, 420, 570, 170));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 350, 150, 39));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 125, 6);\n"
"color: rgb(255, 255, 255);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 600, 90, 39));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(58, 125, 6);\n"
"color: rgb(255, 255, 255);"));
        SentimentAnalysis->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SentimentAnalysis);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 718, 35));
        menuSentiment_Analysis = new QMenu(menubar);
        menuSentiment_Analysis->setObjectName(QString::fromUtf8("menuSentiment_Analysis"));
        menuSentiment_Analysis->setGeometry(QRect(261, 114, 204, 70));
        menuSentiment_Analysis->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 16pt \"MV Boli\";"));
        SentimentAnalysis->setMenuBar(menubar);
        statusbar = new QStatusBar(SentimentAnalysis);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SentimentAnalysis->setStatusBar(statusbar);

        menubar->addAction(menuSentiment_Analysis->menuAction());

        retranslateUi(SentimentAnalysis);

        QMetaObject::connectSlotsByName(SentimentAnalysis);
    } // setupUi

    void retranslateUi(QMainWindow *SentimentAnalysis)
    {
        SentimentAnalysis->setWindowTitle(QApplication::translate("SentimentAnalysis", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QApplication::translate("SentimentAnalysis", "Enter sentence:", nullptr));
        pushButton->setText(QApplication::translate("SentimentAnalysis", "Train Model", nullptr));
        pushButton_2->setText(QApplication::translate("SentimentAnalysis", "Check", nullptr));
        menuSentiment_Analysis->setTitle(QApplication::translate("SentimentAnalysis", "A.I club", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SentimentAnalysis: public Ui_SentimentAnalysis {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENTIMENTANALYSIS_H
