#include<iostream>
#include<string>
#include<cstdio>
#include "Student.h"
using namespace std;
int main()
{
    Student* student = new Student[10];
    Student temp;
    float maxscore = 0.0f;
    for (int k = 0; k < 10; k++)
    {
        student[k].calculateScore();
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j < 10; j++)
        {
            if (student[i].sscore < student[j].sscore)
            {
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
            if (student[i].sscore == student[j].sscore)
            {
                for (int k = 0; k < 10; k++)
                {
                    if (student[i].number[k] < student[j].number[k])
                    {
                        temp = student[i];
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
        cout << student[i].name << " " << student[i].name_first << " (" << student[i].number << ") " << student[i].sscore << endl;
    }
    return 0;
}
