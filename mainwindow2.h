#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H
#include "answer.h"
#include <QDialog>
#include "question.h"
#include<QList>

namespace Ui {
class mainwindow2;
}

class mainwindow2 : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow2(QWidget *parent = nullptr);
    mainwindow2(QList<Question>,QString,QWidget *parent = nullptr);
    void showQestions();
    void clear();
    ~mainwindow2();
private slots:
    void on_pushButton_add_clicked();
    void on_pushButton_back_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);
private:
    Ui::mainwindow2 *ui;
    QList<Question>list;
    QString subject;



};

#endif // MAINWINDOW2_H
