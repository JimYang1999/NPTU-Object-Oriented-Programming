#include<iostream>
using namespace std;
#include "Student.h"
#include<cmath>
void Student::calculateScore()
{
    int times1 = 0;//缺交次數
    int times2 = 0;//抄襲次數
    float homework = 0.0f;
    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++)
    {
        if (int(score[i] + 1) == 0)//缺交
        {
            score[i] = 0.0f;
            times1 += 1;
        }
        if (int(score[i] + 2) == 0)//抄襲
        {
            score[i] = 0.0f;
            times2 += 1;
        }
        homework += score[i];
    }
    homework = homework / 5.0f; //作業平均成績
    homework -= float(times1) * 5.0f;
    if (homework < 0.0) //作業成績平均<0
    {
        homework = 0.0f;
    }
    if (int(midscore + 1) == 0) //期中缺考
    {
        midscore = 0.0f;
    }
    if (int(finalscore + 1) == 0)//期末缺考
    {
        finalscore = 0.0f;
    }
    sscore = homework * 0.4f + midscore * 0.3f + finalscore * 0.3f;
    sscore -= times2 * 5.0f;
    if (sscore < 0.0)
    {
        sscore = 0;
    }
}
Student::Student() {
    cin >> name >> name_first >> number;
    for (int i = 0; i < 5; i++)
    {
        cin >> score[i];
    }
    cin >> midscore >> finalscore;
}
