#ifndef ANSWER_H
#define ANSWER_H
#include<QString>

class Answer
{
public:
Answer();
Answer(QString,QString,QString,QString,QString );
QString getAns1();
QString getAns2();
QString getAns3();
QString getAns4();
QString getRightAnswer();
void setAns1(QString);
void setAns2(QString);
void setAns3(QString);
void setAns4(QString);
void setRightAnswer(QString);
QString getTitle();
private:
QString Title;
QString ans1;
QString ans2;
QString ans3;
QString ans4;
QString Rightanswer;
};

#endif // ANSWER_H
