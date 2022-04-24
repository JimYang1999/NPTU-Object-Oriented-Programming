# 屏東火車站接駁車資計算

屏東火車站有開往屏東大學不同校區的接駁車服務，單程車資如下：
- 屏東火車站<-->屏商(1)  30元
- 屏東火車站<-->民生(2)  25元
- 屏東火車站<-->林森(3)  20元

若購買來回則優惠5元。

請設計一個C語言程式，不論是從火車站到屏東大學，或是從屏東大學到火車站，都讓使用者輸入屏東大學的校區(以整數1, 2, 3 分別代表屏商、民生及林森校區)以及單程(以字元S代表)或來回(以字元R代表)。如果使用者輸入錯誤的地點，則輸出「Wrong location!」；錯誤的票種則輸出「Wrong type!」，兩者皆錯則輸出「Wrong location and type!」。

完整程式碼如下：
```
#include<iostream>
using namespace std;
int main()
{
    int i;
    char x;
    cin >> i;
    cin >> x;
    int a = 30;
    int b = 25;
    int c = 20;
    if (x == 'S')
    {
        switch (i) {
        case 1:
            cout << a << endl;
            break;
        case 2:
            cout << b << endl;
            break;
        case 3:
            cout << c << endl;
            break;
        default:
            cout << "Wrong location!" << endl;
        }
    }
    else if (x == 'R')
    {
        switch (i) {
        case 1:
            cout << a - 5 << endl;
            break;
        case 2:
            cout << b - 5 << endl;
            break;
        case 3:
            cout << c - 5 << endl;
            break;
        default:
            cout << "Wrong location!" << endl;
        }
    }
    else {
        if (i != 1 && i != 2 && i != 3)
        {
            cout << "Wrong location and type!" << endl;
        }
        else
        {
            cout << "Wrong type!" << endl;
        }
    }


}
```
