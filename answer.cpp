#include "answer.h"
Answer::Answer(){
}
Answer::Answer(QString ans1,QString ans2,QString ans3,QString ans4,QString Rightanswer)
{
    this->ans1=ans1;
    this->ans2=ans2;
    this->ans3=ans3;
    this->ans4=ans4;
    this->Rightanswer=Rightanswer;
}
QString Answer::getAns1(){
   return ans1;
}
QString Answer::getAns2(){
    return ans2;
}
QString Answer::getAns3(){
    return ans3;
}
QString Answer::getAns4(){
    return ans4;
}
QString Answer::getRightAnswer(){
   return Rightanswer;
}
void Answer::setAns1(QString ans1){
   this->ans1=ans1;
}
void Answer::setAns2(QString ans2){
    this->ans2=ans2;
}
void Answer::setAns3(QString ans3){
   this->ans3=ans3;
}
void Answer::setAns4(QString ans4){
   this->ans4=ans4;
}
void Answer::setRightAnswer(QString Rightanswer){
   this->Rightanswer=Rightanswer;
}
