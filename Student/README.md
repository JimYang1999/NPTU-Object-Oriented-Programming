1. 設計一個c++的類別名為Student，並定義於Student.h，其member function的實作則撰寫於Student.cpp，該類別包含有以下的data members:
  - 姓名(字串，長度含\0不超過20個字)
  - 學號(字串，10碼)
  - 作業成績(五次作業，每次成積可具有小數，例如90.5分。另外，我們以-1表示缺交，-2表示抄襲)
  - 期中考成績(浮點數，-1表示缺考)
  - 期末考成績(浮點數，-1表示缺考)
  - 請為Student類別設計一個calculateScore()的member function，計算其學期成績，其計算標準如下
      - 作業成績取五次的平均，缺交與抄襲該次以0分計算，每缺交一次扣作業平均成績5分，每抄襲一次扣學期成績5分。
      - 但作業成績與學期成績最低均為0分。
      - 學期成績＝平均作業成績*0.4 + 期中考*0.3 + 期末考*0.3
2. 設計一個Score.cpp程式，在執行時使用「<」將測試檔「cpp2022.dat」導入10位學生的資料
3. 依據所取得的資料，動態建立一個的Studnet類別陣列，來儲存所讀入的學生資料（可假設學生人數為10人）
4. 請依學期成績由高而低輸出學生的姓名、學號與學期成績(當成績相同時則依學號由小到大輸出)
5. 你可以視需要設計其它的data members或member functions
6. 你必須提供Makefile，將可執行檔命名為「Score」，並將所有需要的檔案都上傳

輸出:
```
[00:42 cbf107020@ws hw4]$ ./Score.out <cpp2022.dat
Yu-Liang Chang (1044180028) 94.24
I-ping Li (1044180029) 94.12
Jun Wu (1044180000) 93.46
Jian-Fu Li (1044180005) 79
Shou-Liang Sun (1044180004) 76.35
Shiu-Jia Hong (1044181234) 76.2
Chen-Yuan Huang (1044180025) 76.11
Tommy Wu (1044180033) 73.4
Yu-Chen Wang (1044180020) 70.7
Amy Chang (1044180011) 19
[00:42 cbf107020@ws hw4]$
```

Makefile：
```
all:
        make Score.out
Score.out:Score.cpp Student.o
        g++ Score.cpp Student.o -o Score.out
Student.o:Student.cpp Student.h
        g++ -c Student.cpp
clean:
        rm -f Score.out Student.o
```

Student.h：
```
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
```

Score.cpp：
```
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
```

Student.cpp：
```
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
```
