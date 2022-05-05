#include<iostream>
using namespace std;
#include "InternStudent.h"

void InternStudent::calculateScore()
{
    if (int(midscore + 1) == 0)
    {
        midscore = 0.0f;
    }
    if (int(finalscore + 1) == 0)
    {
        finalscore = 0.0f;
    }
    if (praticescore < 0)
    {
        praticescore = 0.0f;
    }
    sscore = praticescore * 0.4 + midscore * 0.3 + finalscore * 0.3;
    if (sscore < 0)
    {
        sscore = 0.0f;
    }
}
InternStudent::InternStudent()
{
    char type;
    cin >> type;
    cin.ignore();
    if (type == 'I')
    {
        cin.getline(name,21);
        cin >> number >> praticescore >> midscore >>finalscore;
        calculateScore();
    }
    else
    {
        cin.getline(name, 21);
        cin >> number;
        for (int i = 0; i < 5; i++)
        {
            cin >> score[i];
        }
        cin >> midscore >> finalscore;
        Student::calculateScore();
    }
}