# try and catch

請參考以下的執行結果完成程式碼：
```
執行結果1
輸入	101
輸出	Error(1)
End of Program

執行結果2
輸入	-1
輸出	Error(2)
End of Program

執行結果3
輸入	0
輸出	End of Program

執行結果4
輸入	60
輸出	End of Program

執行結果5
輸入	100
輸出	End of Program
```

完整程式碼如下：
```
#include <iostream>
using namespace std;

int main()
{
    int score;
    cin >> score;
    try
    {
        //start
        if (score > 100) throw 1;
        else if (score < 0) throw 2;
        //end
    }
    catch (int err)
    {
        cout << "Error(" << err << ")" << endl;
    }
    cout << "End of Program" << endl;
}

```
