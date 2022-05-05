#include<iostream>
#include<string>
#include<cstdio>
#include "Student.h"
#include "InternStudent.h"
using namespace std;
int main()
{
    InternStudent* student = new InternStudent[10];
    float maxscore = 0.0f;
    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (student[i].sscore < student[j].sscore)
            {
                InternStudent temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
            if (student[i].sscore == student[j].sscore)
            {
                for (int k = 0; k < 10; k++)
                {
                    if (student[i].number[k] < student[j].number[k])
                    {
                        InternStudent temp = student[i];
                        student[i] = student[j];
                        student[j] = temp;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        cout << student[i].name << " (" << student[i].number << ") " << student[i].sscore << endl;
    }
    return 0;
}
