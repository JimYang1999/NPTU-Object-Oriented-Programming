# 蘋果多少錢？

此程式接收使用者所輸入所欲購買的蘋果電腦名稱，比對陣列內容後輸出該項產品的價格，以及最接近該產品價格的替代產品。若是所輸入的名稱不在陣列內（若英文大小寫不同，視為不相同），則請輸出「Not Found!」 。

此題的執行結果可參考如下：
```
執行結果1
輸入	Mac Mini
輸出	Mac Mini:$19800.
You can also consider MacBook Air:$36800.

執行結果2
輸入	MacBook Air
輸出	MacBook Air:$36800.
You can also consideri Mac:$38900.

執行結果3
輸入	iPhone X
輸出	Not Found!
```

完整程式碼如下：

```

#include<iostream>
using namespace std;
#include <string>
int main()
{
    string mac[5] = { "Mac Mini", "Mac Studio", "iMac", "MacBook Air", "MacBook Pro" };
    int price[5] = { 19800,        59800,  38900,         36800,         59980 };
    string what2buy;
    bool found = false;

    getline(cin, what2buy);

    for (int i = 0; i < 5; i++)
    {
        if (what2buy.compare(mac[i]) == 0)
        {
            cout << what2buy << ":$" << price[i] << "." << endl;
            int diff[5] = { 0 };
            int j;
            for (j = 0; j < 5; j++)
            {
                diff[j] = price[i] > price[j] ? price[i] - price[j] : price[j] - price[i];
            }

            int min = -1;
            for (j = 0; j < 5; j++)
            {
                if (diff[j] != 0)
                {
                    if (min == -1) min = j;
                    else if (diff[j] < diff[min])
                        min = j;
                }
            }

            cout << "You can also consider " << mac[min] << ":$" << price[min] << "." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Not Found!" << endl;
    }
}

```
