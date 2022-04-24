# 計算作業平均成績

吳老師期末計算學生成績時，時常使用從作業中挑選最高分的若干次做為學生平時成績的調整。請完成函式avgHomeworkScore()的設計，讓它可以找出最高分的n筆作業成績的平均值後加以輸出。

此題的執行結果可參考如下：
```
執行結果1
輸入	93 87 66 98 60 99 0 80 89 50
輸出	96.6667
93.2
72.2

執行結果2
輸入	100 100 100 100 100 50 50 50 0 0
輸出	100
100
65

執行結果3
輸入	60 70 80 60 50 100 78 88 90 0
輸出	92.6667
87.2
67.6
```

完整程式碼如下：
```
#include <iostream>
using namespace std;
#define size 10
//start
double avgHomeworkScore(int hw[], int num = 10)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (hw[j] < hw[j + 1])
            {
                int temp = hw[j];
                hw[j] = hw[j + 1];
                hw[j + 1] = temp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < num; i++)
    {
        sum += hw[i];
    }

    return sum / (double)num;
}
//end
int main()
{
    int homework[size];

    for (int i = 0; i < size; i++)
    {
        cin >> homework[i];
    }

    cout << avgHomeworkScore(homework, 3) << endl;
    cout << avgHomeworkScore(homework, 5) << endl;
    cout << avgHomeworkScore(homework) << endl;
}




```
