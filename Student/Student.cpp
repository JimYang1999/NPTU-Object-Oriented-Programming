#include<iostream>
using namespace std;
#include "Student.h"
#include<cmath>
void Student::calculateScore()
{
    int times1 = 0;//�ʥ榸��
    int times2 = 0;//��ŧ����
    float homework = 0.0f;
    for (int i = 0; i < sizeof(score) / sizeof(score[0]); i++)
    {
        if (int(score[i] + 1) == 0)//�ʥ�
        {
            score[i] = 0.0f;
            times1 += 1;
        }
        if (int(score[i] + 2) == 0)//��ŧ
        {
            score[i] = 0.0f;
            times2 += 1;
        }
        homework += score[i];
    }
    homework = homework / 5.0f; //�@�~�������Z
    homework -= float(times1) * 5.0f;
    if (homework < 0.0) //�@�~���Z����<0
    {
        homework = 0.0f;
    }
    if (int(midscore + 1) == 0) //�����ʦ�
    {
        midscore = 0.0f;
    }
    if (int(finalscore + 1) == 0)//�����ʦ�
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
