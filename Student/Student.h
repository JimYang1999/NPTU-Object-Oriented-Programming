#ifndef _STUDENT_
#define _STUDENT_

class Student
{
public:
    char name[21];
    char name_first[21];
    char number[11];
    float homework; //作業平均
    float sscore;//學期成績
    float score[5]; //作業成績
    float midscore;
    float finalscore;
    void calculateScore();
    Student();
};
#endif
