#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bstforstrings.h"
#include "decisiontree.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    BSTforStrings *bst = new BSTforStrings;
    bst->show();
    bst->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    DecisionTree *decisionTree = new DecisionTree;
    decisionTree->show();
}
