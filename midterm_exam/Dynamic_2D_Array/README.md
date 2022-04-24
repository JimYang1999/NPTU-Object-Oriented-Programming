# 建立動態二維陣列，並交換其首尾列

動態配置一個3x5的二維陣列data。在已有的程式碼中，data的內容已設定為：

{{1,2,3,4,5},
 {6,7,8,9,10},
 {11,12,13,14,15}}

請將其第1列與最後1列的內容進行交換後將結果輸出。此題的執行結果可參考如下：

```
執行結果1
輸入	
輸出	11 12 13 14 15
6 7 8 9 10
1 2 3 4 5
```

完整程式碼如下：
```
using namespace std;
#include <iostream>
#define ROW 3
#define COL 5

int main()
{
    int** data;
    int i, j, k = 1;
    //請在此完成data的動態記憶體配置
    //start
    data = new int* [ROW];
    for (int i = 0; i < ROW; i++)
    {
        data[i] = new int[COL];
    }
    //end
    //設定data的內容{{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}}
    for (i = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            data[i][j] = k++;

    //請在此將data的第一列與最後一列的內容交換
    //start
    int* temp = data[ROW - 1];
    data[ROW - 1] = data[0];
    data[0] = temp;
    //end
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < ROW; i++)
        delete[] data[i];

    delete[] data;

    return 0;
}
```

