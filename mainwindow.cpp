#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFile>
#include <QMessageBox>
#include<QTextStream>
#include<iostream>
#include<QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load();
    addsubjects();
}

MainWindow::~MainWindow()
{
    delete ui;
}
MainWindow::MainWindow(QList<Question>list,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->list=list;
    ui->setupUi(this);
    stores();
    addsubjects();
}
void MainWindow::on_pushButton_add_clicked()
{
    Title=ui->lineEdit->text();
    subject=ui->comboBox->currentText();
    Question Q1(subject,Title);
    list.push_back(Q1);
    ui->listWidget->clear();
    stores();
    showQuestions(list);
    ui->lineEdit->clear();

}
void MainWindow::on_pushButton_addanswer_clicked()
{
  subject=ui->comboBox->currentText();
  m=new mainwindow2(list,subject,this);
  this->close();
  m->show();

}
void MainWindow::addsubjects(){

    ui->comboBox->addItem("operating systems");
    ui->comboBox->addItem("algorithms");
    ui->comboBox->addItem("software engineering");
    ui->comboBox->addItem("media systems");
    ui->comboBox->addItem("programming 1");
    ui->comboBox->addItem("web programing");
    ui->comboBox->addItem("Math");
    ui->comboBox->addItem("English");
    ui->comboBox->addItem("Artificial intelligence");
}
void MainWindow::showQuestions(QList<Question>list)
{    QList<Question>::iterator it;
    if (ui->comboBox->currentText()=="operating systems"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="operating systems")
     ui->listWidget->addItem(it->getTitle());
}
    else if (ui->comboBox->currentText()=="algorithms"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="algorithms")
     ui->listWidget->addItem(it->getTitle());
    }
    else if (ui->comboBox->currentText()=="software engineering"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="software engineering")
     ui->listWidget->addItem(it->getTitle());
    }
   else  if (ui->comboBox->currentText()=="media systems"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="media systems")
     ui->listWidget->addItem(it->getTitle());
    }
   else  if (ui->comboBox->currentText()=="programming 1"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="programming 1")
     ui->listWidget->addItem(it->getTitle());
    }
   else  if (ui->comboBox->currentText()=="web programing"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="web programing")
     ui->listWidget->addItem(it->getTitle());
    }
   else  if (ui->comboBox->currentText()=="Math"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="Math")
     ui->listWidget->addItem(it->getTitle());
    }
   else if (ui->comboBox->currentText()=="Artificial intelligence"){
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="Artificial intelligence")
     ui->listWidget->addItem(it->getTitle());
    }


}
void MainWindow::load(){
  Answer a;
  QFile file("C:/New folder/newproject/file2.txt");
  if (!file.open(QFile::ReadOnly| QFile::Text)){
       QMessageBox::warning(this,"title","file not open");
  }
   QTextStream in(&file);
   while(!in.atEnd()){
     subject=in.readLine();
     Title=in.readLine();
     a.setAns1(in.readLine());
     a.setAns2(in.readLine());
     a.setAns3(in.readLine());
     a.setAns4(in.readLine());
     a.setRightAnswer(in.readLine());
     Question Q1(subject,Title,a);
     list.push_back(Q1);
     }
    file.close();
}
void MainWindow::stores(){
  QFile file("C:/New folder/newproject/file2.txt");
  QList<Question>::iterator it;
  QTextStream out(&file);
  if (!file.open(QIODevice::ReadWrite)){
    QMessageBox::warning(this,"title","file not open");}
   else {
     for (it=list.begin();it!=list.end();it++){
       out<<it->getsubjects()<<"\n";
       out<<it->getTitle()<<"\n";
       out<<it->answer.getAns2()<<"\n";
       out<<it->answer.getAns1()<<"\n";
       out<<it->answer.getAns3()<<"\n";
       out<<it->answer.getAns4()<<"\n";
       out<<it->answer.getRightAnswer()<<"\n";
        }
}}
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{   QList<Question>::iterator it;
    if (arg1=="operating systems"){
         ui->listWidget->clear();
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="operating systems")
     ui->listWidget->addItem(it->getTitle());
}
    else if (arg1=="algorithms"){
         ui->listWidget->clear();
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="algorithms")
     ui->listWidget->addItem(it->getTitle());
    }
    else if (arg1=="software engineering"){
         ui->listWidget->clear();
    for (it=list.begin();it!=list.end();it++)
        if (it->getsubjects()=="software engineering")
     ui->listWidget->addItem(it->getTitle());
    }
    if (arg1=="Math"){
        ui->listWidget->clear();
        for (it=list.begin();it!=list.end();it++)
            if (it->getsubjects()=="Math")
         ui->listWidget->addItem(it->getTitle());
        }

    else  if (arg1=="media systems"){
         ui->listWidget->clear();
     for (it=list.begin();it!=list.end();it++)
         if (it->getsubjects()=="media systems")
      ui->listWidget->addItem(it->getTitle());
     }
else if (arg1=="Artificial intelligence"){
        ui->listWidget->clear();
 for (it=list.begin();it!=list.end();it++)
     if (it->getsubjects()=="Artificial intelligence")
  ui->listWidget->addItem(it->getTitle());
    }
    else  if (arg1=="web programing"){
         ui->listWidget->clear();
     for (it=list.begin();it!=list.end();it++)
         if (it->getsubjects()=="web programing")
      ui->listWidget->addItem(it->getTitle());
     }
    else  if (arg1=="programming 1"){
         ui->listWidget->clear();
     for (it=list.begin();it!=list.end();it++)
         if (it->getsubjects()=="programming 1")
      ui->listWidget->addItem(it->getTitle());
     }
    else if (arg1=="English"){
         ui->listWidget->clear();
     for (it=list.begin();it!=list.end();it++)
         if (it->getsubjects()=="English")
      ui->listWidget->addItem(it->getTitle());
     }


}
