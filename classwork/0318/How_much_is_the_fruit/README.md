# 水果多少錢？(string版)

此程式接收使用者所輸入的一個水果名稱，比對陣列內容後輸出該項水果的價錢。若是所輸入的水果名稱不在陣列內（若英文大小寫不同，視為不相同），則請輸出「Not Found!」 。

此題的執行結果可參考如下：

```
執行結果1
輸入	Apple
輸出	15

執行結果2
輸入	Banana
輸出	20

執行結果3
輸入	apple
輸出	Not Found!

執行結果4
輸入	Passion
輸出	Not Found!
```

完整程式碼如下：
#include<iostream>
#include<string>
using namespace std;


int main()
{
    string fruits[5] = { "Apple", "Banana", "Cherry", "Durian", "Fig" };
    int prices[5] = { 15, 20, 2, 40, 10 };
    string fruitName;
    bool found;


    //start
    cin >> fruitName;
    for (int i = 0; i < 5; i++)
    {
        if (fruitName.compare(fruits[i]) == 0)
        {
            cout << prices[i] << endl;
            found = true;
            break;
        }
    }
    //end

    if (!found)
    {
        cout << "Not Found!" << endl;
    }
}
```
