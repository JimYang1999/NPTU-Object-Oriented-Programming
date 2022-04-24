# 存放偶數的動態陣列

完成設計一個C++語言程式的設計。此程式讓使用者輸入一個整數n，並依整數n的大小動態建立一個「動態陣列」，然後連續讓使用者輸入n個正整數，並存放到該陣列中。然後，將該陣列中所有的奇數加一，使得陣列中所有的數字皆成為偶數。最後，在程式結束前，將陣列內容加以輸出後，將該陣列的記憶體空間回收。

此題的執行結果可參考如下：

```
執行結果1
輸入	3
1
2
3
輸出	2 2 4

執行結果2
輸入	4
11
12
12
13
輸出	12 12 12 14
```

完整程式碼如下：
```
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int n;
    int* p;
    //start
    cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] & 2 != 0)
        {
            p[i] = p[i] + 1;
        }
    }
    //end
    for (i = 0; i < n; i++)
    {
        cout << p[i];
        if (i < (n - 1))
            cout << " ";
    }
    cout << endl;
    delete[] p;
}
```
