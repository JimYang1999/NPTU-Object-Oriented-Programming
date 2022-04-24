# default argument 1

請參考下方的程式碼，完成函式maxHomeworkScore()的設計，讓它可以找出前n筆作業成績中的最大值後加以輸出。
```
#include <iostream>
using namespace std;
#define size 10

int maxHomeworkScore(int hw[], int num=10);

int main()
{
    int homework[size];
    
    for(int i=0;i<size;i++)
    {
        cin >> homework[i];
    }
    
    cout << maxHomeworkScore(homework, 8) << endl;
    cout << maxHomeworkScore(homework, 5) << endl;
    cout << maxHomeworkScore(homework) << endl;
}
```
此題的執行結果可參考如下：
```
input:
90 87 66 98 60 100 0 80 85 50
output:
100
98
100
```

完整程式碼如下：

```
#include <iostream>
using namespace std;
#define size 10

int maxHomeworkScore(int hw[], int num = 10);

int main()
{
    int homework[size];

    for (int i = 0; i < size; i++)
    {
        cin >> homework[i];
    }

    cout << maxHomeworkScore(homework, 8) << endl;
    cout << maxHomeworkScore(homework, 5) << endl;
    cout << maxHomeworkScore(homework) << endl;
}
//start
int maxHomeworkScore(int hw[], int num)
{
    int i, max;
    max = hw[0];
    for (int i = 1; i < num; i++)
    {
        if (max < hw[i])
            max = hw[i];
    }
    return max;
}
//end
```
