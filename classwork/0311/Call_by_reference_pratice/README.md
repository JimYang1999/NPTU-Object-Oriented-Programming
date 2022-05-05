# Call by reference實作

請參考下方程式，完成所需的swap()與max()函式設計。

```
#include <iostream>
using namespace std;

#include <cstdio>

void show(int i, int j, int k)
{
    printf("(%d, %d, %d)\n", i,j,k);
}

void swap(int &a, int &b);

int & max(int &i, int &j, int &k);

int main()
{
    int x,y,z;
    cin >> x;
    cin >> y;
    cin >> z;

    show(x,y,z);
    swap(x,z);
    show(x,y,z);
    max(x,y,z)=0;
    show(x,y,z);
}
```
此程式執行結果可參考如下：

```
執行結果1
輸入	3
5
6
輸出	(3,5,6)
(6,5,3)
(0,5,3)

執行結果2
輸入	300
200
100
輸出	(300,200,100)
(100,200,300)
(100,200,0)
```

完整程式碼如下：
```
#include <iostream>
using namespace std;

#include <cstdio>

void show(int i, int j, int k)
{
    printf("(%d, %d, %d)\n", i, j, k);
}

void swap(int& a, int& b);

int& max(int& i, int& j, int& k);

int main()
{
    int x, y, z;
    cin >> x;
    cin >> y;
    cin >> z;

    show(x, y, z);
    swap(x, z);
    show(x, y, z);
    max(x, y, z) = 0;
    show(x, y, z);
}
//start
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int& max(int& i, int& j, int& k)
{
    int temp = 0;
    if (i > j)
    {
        temp = i;
    }
    else
    {
        temp = j;
    }
    if (k > temp)
    {
        temp = k;
    }
    if (temp == i) return i;
    if (temp == j) return j;
    if (temp == k) return k;
}
//end
```
