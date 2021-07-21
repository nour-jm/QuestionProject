#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "mainwindow2.h"
#include <QList>
#include "question.h"
#include<QFile>
#include<QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QList<Question>,QWidget *parent = nullptr);
    void addsubjects();
    void showQuestions(QList<Question>);
    void stores();
    void load();
    ~MainWindow();
private slots:
   void on_pushButton_add_clicked();
   void on_pushButton_addanswer_clicked();
   void on_comboBox_currentTextChanged(const QString &arg1);
private:
    Ui::MainWindow *ui;
        QString Title;
        QString subject;
        mainwindow2 *m;
        QList<Question>list;

};

#endif // MAINWINDOW_H
