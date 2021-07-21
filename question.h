#ifndef QUESTION_H
#define QUESTION_H
#include<QString>
#include "answer.h"

class Question
{
public:
    Question(QString,QString,Answer);
    Question(QString,QString);
    Question(Answer);
    void addTitle();
    Answer returnanswer();
    QString getsubjects();
    QString getTitle();
    void Editanswer(Answer);
    Answer answer;
private :
    QString  Title;
    QString subject;


};

#endif // QUESTION_H
