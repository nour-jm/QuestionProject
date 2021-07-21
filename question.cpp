#include "question.h"
#include "answer.h"
Question::Question(QString Subject,QString Title)
{

this->subject=Subject;
this->Title=Title;

}
Question::Question(QString Subject,QString Title,Answer answer)
{
    this->subject=Subject;
    this->Title=Title;
    this->answer=answer;
}
Question::Question(Answer ans){

  answer=ans;
}
QString Question::getsubjects()
{
    return subject;
}
QString Question::getTitle(){
    return Title;
}
Answer Question::returnanswer()
{
    return answer;
}
void  Question::Editanswer(Answer a)
{
    this->answer=a;
}
