#ifndef _STUDENT_
#define _STUDENT_

class Student
{
public:
    char name[21];
    char name_first[21];
    char number[11];
    float homework; //�@�~����
    float sscore;//�Ǵ����Z
    float score[5]; //�@�~���Z
    float midscore;
    float finalscore;
    void calculateScore();
    Student();
};
#endif
