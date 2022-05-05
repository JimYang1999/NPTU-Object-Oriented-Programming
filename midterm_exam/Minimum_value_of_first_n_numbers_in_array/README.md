# 陣列前n個數字的最小值

此程式執行時，先取得使用者輸入的10個整數並放入一個大小為10的整數陣列裡；接著讓使用再輸入一個整數n，計算並找出其中前n個整數中的最小值後輸出。

注意，當n小於等於0時，則找出全部10個整數中的最小值。

此題的執行結果可參考如下：
```
執行結果1
輸入	90 87 66 98 60 100 0 80 85 50
3
輸出	66

執行結果2
輸入	10 8 12 15 6 7 18 29 1 13
5
輸出	6

執行結果3
輸入	4 4 4 1 2 1 3 22 11 10
0
輸出	1
```

完整程式碼如下：
```
#include<iostream>
using namespace std;
#define Size 10
//start
int minValue(int* data, int n = 0)
{
	if (n != 0)
	{
		int min = data[0];
		for (int i = 0; i < n; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}
	else
	{
		int min = data[0];
		for (int i = 0; i < Size; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}
}
//end
int main()
{
	int data[Size];
	int n;

	for (int i = 0; i < Size; i++)
	{
		cin >> data[i];
	}
	cin >> n;

	if (n < 1)
		cout << minValue(data) << endl;
	else
		cout << minValue(data, n) << endl;
}
```
