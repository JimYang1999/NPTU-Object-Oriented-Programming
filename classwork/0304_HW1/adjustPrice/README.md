# 阿龍的生意經

阿龍是一個成功的生意人，他有一個拉攏顧客的小撇步：「結帳時去小數也去尾數」，讓顧客都很喜歡和他買東西！請參考右側的程式碼，完成adjustPrice() function的多載設計。adjustPrice()函式接受一個數值做為參數，依據參數的型態，請完成以下的設計：

1. 該數值若為大於10的整數，則將該數值捨棄個位數，例如如92調整後為90，158調整後為150；若原本個位數就是0，則不做調整。
2. 該數值若為大於10的浮點數，則先無條件捨棄小數，再將個位數捨棄，例如43.14調整後為40，784.6調整後為780，10.05調整後為10。
3. 該數值若為小於等於10的浮點數，則無條件捨棄小數，例如3.14調整後為3，10.0調整後為10。


此題的執行結果可參考如下：

```
input：
92
13.12
output：
90
10

input：
100
33.6	
output：
100
30

input：
7
3.8
output：
7
3
```

完整程式碼如下：
```
#include<iostream>
using namespace std;
int adjustPrice(int);
int adjustPrice(double);

int main()
{
	double x;
	cin >> x;
	cout<<adjustPrice(x);
}
int adjustPrice(int x)
{
	x = x - x % 10;
	return x;
}
int adjustPrice(double x)
{
	x = int(x) - (int(x) & 10);
	return x;
}
```
