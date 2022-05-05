本題接續作業"Student"，為實習生建立新的類別。請完成以下要求：
1. 設計一個c++的類別名為InternStudent，並定義於InternStudent.h，其member function的實作則撰寫於InternStudent.cpp，包含有以下的data members:
  - 姓名(字串，長度含\0不超過20個字)
  - 學號(字串，10碼)
  - 實習成績(浮點數)
  - 學期成績(浮點數，請記得在Student類別中加入此資料成員)
  - 期中考成績(浮點數，-1表示缺考)
  - 期末考成績(浮點數，-1表示缺考)
  - 為簡化程式設計起見，請讓InternStudent類別繼承自作業4所完成的Student類別，並重載（覆載）繼承自Student類別的calculateScore() member function，實習學生的學期成績計算標準如下:
    - 實習成績與期中、期末及學期成績最低均為0分。
    - 學期成績＝實習成績\*0.4 + 期中考\*0.3 + 期末考\*0.3
2. 請修改原本設計好的score.cpp程式，在執行時使用「<」將測試檔「/home/stu/public/cpp2022/hw5/cpp2022intern.dat」導入10位學生的資料
3. 依據所取得的資料，動態建立對應的Student類別與InternStudent類別的物件，請儲存在陣列中（可假設學生人數為10人）
4. 請依學期成績由高而低輸出學生的姓名、學號與學期成績
5. 你可以視需要設計其它的data members或member functions
6. 你必須提供Makefile，並將所有需要的檔案都上傳
7. 程式執行結果參考
```
[22:10 cbf107020@ws hw5]$ ./a.out <cpp2022intern.dat
Yu-Liang Chang (1044180028) 94.24
Jun Wu (1044180000) 92.7
I-ping Li (1044180029) 92
Shou-Liang Sun (1044180004) 86
Shiu-Jia Hong (1044181234) 84.6
Jian-Fu Li (1044180005) 79
Chen-Yuan Huang (1044180025) 76.11
Tommy Wu (1044180033) 75
Yu-Chen Wang (1044180020) 70.7
Amy Chang (1044180011) 19
```

**cpp2022intern.dat**
```
I
Jun Wu
1044180000
90
90
99
S
Amy Chang
1044180011
100
100
-2
-2
-1
30
20
S
Jian-Fu Li
1044180005
90
80
70
60
50
80
90
I
Shou-Liang Sun
1044180004
80
100
80
I
Shiu-Jia Hong
1044181234
88.5
66
98
S
Yu-Chen Wang
1044180020
90
90
90
-1
-2
89
98
S
Chen-Yuan Huang
1044180025
80
80
87
0
65
90
80.5
S
Yu-Liang Chang
1044180028
90
98
100
100
100
89
95
I
I-ping Li
1044180029
80
100
100
I
Tommy Wu
1044180033
60
80
90     
```

**Makefile**
```
all:Score.cpp Student.o InternStudent.o
        c++ Score.cpp Student.o InternStudent.o

Student.o:Student.h Student.cpp
        c++ -c Student.cpp

InternStudent.o:InternStudent.h InternStudent.cpp
        c++ -c InternStudent.cpp

clean:
        rm -rf *.o *.*~ a.out *~
```

**Student.h**
```
#ifndef _STUDENT_
#define _STUDENT_

class Student
{
public:
    char name[21];
    char number[11];
    float homework; //作業平均
    float sscore; //學期成績
    float score[5]; //作業成績
    float midscore;
    float finalscore;
    void calculateScore();
};
#endif
```

**InternStudent.h**
```
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
```

**Student.cpp**
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
```

**InternStudent.cpp**
```
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
```

**Score.cpp**
```
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
```
