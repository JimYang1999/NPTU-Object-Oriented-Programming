#ifndef _INTERNSTUDENT_
#define _INTERNSTUDENT_
#include "Student.h"

class InternStudent : public Student
{
public:
    float praticescore;
    void calculateScore();
    InternStudent();
};
#endif