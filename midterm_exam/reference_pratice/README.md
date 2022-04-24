# 以參考做為函式參數或傳回值

完成所需的swap()與max()函式設計。此程式執行結果可參考如下：
(注意：此題所輸入的兩個數字不會有相等的情況。)
```
執行結果1
輸入	3
5
輸出	(3,5)
(5,3)
(0,3)

執行結果2
輸入	300
100
輸出	(300,100)
(100,300)
(100,0)

執行結果3
輸入	-3
-5
輸出	(-3,-5)
(-5,-3)
(-5,0)

執行結果4
輸入	5
5
輸出	Error!
```

完整程式碼如下：
```
#include <iostream>
using namespace std;

#include <cstdio>

void show(int i, int j)
{
    printf("(%d, %d)\n", i, j);
}
//start
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int& max(int& i, int& j)
{
    if (i > j)
        return i;
    else
        return j;
}
//end
int main()
{
    int x, y;
    cin >> x;
    cin >> y;

    if (x != y)
    {
        show(x, y);
        swap(x, y);
        show(x, y);
        max(x, y) = 0;
        show(x, y);
    }
    else
        cout << "Error!" << endl;
}



```
