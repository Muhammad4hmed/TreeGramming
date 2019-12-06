#ifndef BSTFORSTRINGS_H
#define BSTFORSTRINGS_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class BSTforStrings;
}

class BSTforStrings : public QWidget
{
    Q_OBJECT

public:
    explicit BSTforStrings(QWidget *parent = nullptr);
    ~BSTforStrings();

private:
    Ui::BSTforStrings *ui;
};

#endif // BSTFORSTRINGS_H
