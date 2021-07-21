#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "answer.h"
#include <QList>
#include<QFile>
#include <QMessageBox>
#include<QTextStream>
#include<question.h>
#include "mainwindow.h"
mainwindow2::mainwindow2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow2)
{
    ui->setupUi(this);
     showQestions();

}
mainwindow2::mainwindow2(QList<Question>list,QString subject,QWidget *parent):QDialog(parent), ui(new Ui::mainwindow2){
  this->list=list;
  this->subject=subject;
  ui->setupUi(this);
  showQestions();
}
mainwindow2::~mainwindow2()
{
    delete ui;
}
void mainwindow2::showQestions(){ 
  QList<Question>::iterator it;
  for (it=list.begin();it!=list.end();it++)
    if (it->getsubjects()==this->subject)
      ui->comboBox->addItem(it->getTitle());

}
void mainwindow2::on_pushButton_add_clicked(){
    QString  RightAns;
    QString ans1=ui->lineEdit->text();
    QString ans2=ui->lineEdit_2->text();
    QString ans3=ui->lineEdit_3->text();
    QString ans4=ui->lineEdit_4->text();
    if(ui->checkBox->isChecked())RightAns="1";
    else if (ui->checkBox_2->isChecked())RightAns="2";
    else if (ui->checkBox_3->isChecked())RightAns="3";
    else if (ui->checkBox_4->isChecked())RightAns="4";
    Answer answer(ans1,ans2,ans3,ans4,RightAns);
    QList<Question>::iterator it;
    for (it=list.begin();it!=list.end();it++){
      if (it->getTitle()==ui->comboBox->currentText()){
        it->Editanswer(answer);
        clear();
       }
    }
}
void mainwindow2::on_pushButton_back_clicked(){
    MainWindow *l;
    l=new MainWindow(list);
    this->close();
    l->show();
}

void mainwindow2::clear()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);

}

void mainwindow2::on_comboBox_currentTextChanged(const QString &arg1)
{ clear();
  QList<Question>::iterator it;
  for (it=list.begin();it!=list.end();it++){
    if (it->getTitle()==arg1){
        Answer a=it->returnanswer();
        ui->lineEdit->setText(a.getAns1());
        ui->lineEdit_2->setText(a.getAns2());
        ui->lineEdit_3->setText(a.getAns3());
        ui->lineEdit_4->setText(a.getAns4());
      if(a.getRightAnswer()=="1")
        ui->checkBox->setChecked(true);
      else if (a.getRightAnswer()=="2")
        ui->checkBox_2->setChecked(true);
      else if (a.getRightAnswer()=="3")
        ui->checkBox_3->setChecked(true);
      else if (a.getRightAnswer()=="4")
        ui->checkBox_4->setChecked(true);
    }
  }
}
