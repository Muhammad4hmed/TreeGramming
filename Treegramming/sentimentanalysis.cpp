#include "sentimentanalysis.h"
#include <QPainter>
#include "ui_sentimentanalysis.h"
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QThread>

SentimentAnalysis::SentimentAnalysis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SentimentAnalysis)
{
    ui->setupUi(this);
    setFixedSize(width(), height());
    ui->textEdit->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
}

SentimentAnalysis::~SentimentAnalysis()
{
    delete ui;
}
bool isPositive( QString s ) {
    for(int i = 0 ; i < s.size() - 8; i ++ ) {
        if( s[ i ] == 'P' && s[ i + 1 ] == 'o' && s[ i + 2 ] == 's' && s[ i + 3 ] == 'i' && s[ i + 4 ] == 't' && s[ i + 5 ] == 'i' && s[ i + 6 ] == 'v' && s[ i + 7 ] == 'e')
            return true;
    }
    return false;
}
void SentimentAnalysis::on_pushButton_clicked()
{
    QMessageBox mbox;
    mbox.setWindowTitle("Wait");
    QPixmap qpp( 30 , 30 ) ;
    qpp.load("C:/Users/Muhammad Ahmed/Downloads/33-512.png");
    mbox.setIconPixmap(qpp);
    mbox.setStandardButtons(0);
    mbox.setText("\n <font size = 20 >The model is training, kindly wait </font>");
    mbox.show();
    qApp->processEvents();
    QProcess *process;
    QString path = "D:/DS Project/Treegramming/";
    QString  command("py");
    QStringList params = QStringList() << "train.py";
    process = new QProcess();
    process->setWorkingDirectory(path);
    process->start(command, params);
    process->waitForFinished();
    mbox.close();
    ui->textEdit->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
}

void SentimentAnalysis::on_pushButton_2_clicked()
{
    QString text = ui->textEdit->toPlainText();
    if( text.isEmpty() || text == "") {
        QMessageBox::critical( nullptr ,"Blank Text","Kindly enter correct information");
        return;
    }
    QString path = "D:/DS Project/Treegramming/";
    QString  command("py");
    std::string qr = "'" + text.toStdString() + "'";
    QString qr2 = QString::fromStdString(qr);
    QStringList params = QStringList() << "test.py " << qr2;
    QProcess *process = new QProcess;
    qApp->processEvents();
    process->setWorkingDirectory(path);
    process->start(command, params);
    process->waitForFinished();
    QString result = process->readAll();
    qDebug() << result << " \n" << qr2;
    if( isPositive( result ) ) {
        QMessageBox box;
        box.setWindowTitle("Positive");
        QPixmap qmap(30,30);
        qmap.load("C:/Users/Muhammad Ahmed/Downloads/happy.png");
        box.setIconPixmap(qmap);
        box.setText("\n <font size = 30 >Your sentence was positive </font>");
        box.exec();
    } else {
        QMessageBox box;
        box.setWindowTitle("Negative");
        QPixmap qmap(30,30);
        qmap.load("C:/Users/Muhammad Ahmed/Downloads/sad.png");
        box.setIconPixmap(qmap);
        box.setText("\n <font size = 30 >Your sentence was negative </font>");
        box.exec();
    }
}
