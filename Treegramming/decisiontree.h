#ifndef DECISIONTREE_H
#define DECISIONTREE_H

#include <QMainWindow>

namespace Ui {
class DecisionTree;
}

class DecisionTree : public QMainWindow
{
    Q_OBJECT

public:
    explicit DecisionTree(QWidget *parent = nullptr);
    ~DecisionTree();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DecisionTree *ui;
};

#endif // DECISIONTREE_H
