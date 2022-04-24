# 處理整數與浮點數進位

rounding()函式接受一個數值做為參數，該數值若為整數，則將該數值進位到最接近的10的倍數(也就是增加數值到最接近的10的倍數)，但若該數值原本即為10的倍數則不需調整，例如:

* 92-->進位為100
* 150-->維持為150
* -3 --> 進位為0
* -13--> 進位為-10

若是該參數為浮點數，則進位到最接近的整數，但若該數值原本即為整數則不需調整，例如:

* 3.14 --> 進位到4
* 4.0 --> 則仍為4
* -2.12 --> 進位為-2


```
此題的執行結果可參考如下：


執行結果1
輸入	92
3.12
輸出	100
4

執行結果2
輸入	5
-3.1
輸出	10
-3

執行結果3
輸入	-13
3.0
輸出	-10
3

執行結果4
輸入	-1
0.2
輸出	0
1

執行結果5
輸入	-111
-13.23
輸出	-110
-13
```

完整程式碼如下：

```
#include <iostream>
using namespace std;

int rounding(int);
int rounding(double);

int main()
{
    int x;
    double y;

    cin >> x;
    cin >> y;
    cout << rounding(x) << endl;
    cout << rounding(y) << endl;
}
//start
int rounding(int x)
{
    if (x < 0)
        return x / 10 * 10;
    return x / 10 == x / 10.0 ? x / 10 * 10 : (x / 10 + 1) * 10;

}

int rounding(double x)
{
    if (x < 0)
        return (int)x;
    return x == (int)x ? (int)x : (int)x + 1;
}
//end
```
