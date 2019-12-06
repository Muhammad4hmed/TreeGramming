/********************************************************************************
** Form generated from reading UI file 'decisiontree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DECISIONTREE_H
#define UI_DECISIONTREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DecisionTree
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QMenu *menuDecision_Tree;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DecisionTree)
    {
        if (DecisionTree->objectName().isEmpty())
            DecisionTree->setObjectName(QString::fromUtf8("DecisionTree"));
        DecisionTree->resize(800, 600);
        DecisionTree->setStyleSheet(QString::fromUtf8("font: 16pt \"Gill Sans Ultra Bold\";\n"
"background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(DecisionTree);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 440, 781, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 6);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 6);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 35, 6);\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(pushButton);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 781, 421));
        graphicsView->setStyleSheet(QString::fromUtf8("font: 10pt \"Gill Sans Ultra Bold\";"));
        DecisionTree->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DecisionTree);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 36));
        menuDecision_Tree = new QMenu(menubar);
        menuDecision_Tree->setObjectName(QString::fromUtf8("menuDecision_Tree"));
        DecisionTree->setMenuBar(menubar);
        statusbar = new QStatusBar(DecisionTree);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DecisionTree->setStatusBar(statusbar);

        menubar->addAction(menuDecision_Tree->menuAction());

        retranslateUi(DecisionTree);

        QMetaObject::connectSlotsByName(DecisionTree);
    } // setupUi

    void retranslateUi(QMainWindow *DecisionTree)
    {
        DecisionTree->setWindowTitle(QApplication::translate("DecisionTree", "MainWindow", nullptr));
        pushButton_3->setText(QApplication::translate("DecisionTree", "ADD", nullptr));
        pushButton_2->setText(QApplication::translate("DecisionTree", "Search", nullptr));
        pushButton->setText(QApplication::translate("DecisionTree", "CLEAR", nullptr));
        menuDecision_Tree->setTitle(QApplication::translate("DecisionTree", "Decision Tree", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DecisionTree: public Ui_DecisionTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DECISIONTREE_H
