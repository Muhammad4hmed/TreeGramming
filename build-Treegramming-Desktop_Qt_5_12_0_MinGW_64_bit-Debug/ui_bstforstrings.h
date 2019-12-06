/********************************************************************************
** Form generated from reading UI file 'bstforstrings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BSTFORSTRINGS_H
#define UI_BSTFORSTRINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BSTforStrings
{
public:
    QLabel *label;

    void setupUi(QWidget *BSTforStrings)
    {
        if (BSTforStrings->objectName().isEmpty())
            BSTforStrings->setObjectName(QString::fromUtf8("BSTforStrings"));
        BSTforStrings->resize(569, 486);
        label = new QLabel(BSTforStrings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(440, 80, 47, 13));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);\n"
"font: 14pt \"Gill Sans Ultra Bold\";"));

        retranslateUi(BSTforStrings);

        QMetaObject::connectSlotsByName(BSTforStrings);
    } // setupUi

    void retranslateUi(QWidget *BSTforStrings)
    {
        BSTforStrings->setWindowTitle(QApplication::translate("BSTforStrings", "BST for Strings", nullptr));
        label->setText(QApplication::translate("BSTforStrings", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BSTforStrings: public Ui_BSTforStrings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BSTFORSTRINGS_H
