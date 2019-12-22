#ifndef SENTIMENTANALYSIS_H
#define SENTIMENTANALYSIS_H

#include <QMainWindow>

namespace Ui {
class SentimentAnalysis;
}

class SentimentAnalysis : public QMainWindow
{
    Q_OBJECT

public:
    explicit SentimentAnalysis(QWidget *parent = nullptr);
    ~SentimentAnalysis();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SentimentAnalysis *ui;
};

#endif // SENTIMENTANALYSIS_H
