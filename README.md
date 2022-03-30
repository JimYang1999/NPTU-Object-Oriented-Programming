C++ 
=======
- [浮點數比較](#浮點數比較)
- [字元char](#字元char)
- [字串](#字串)
- [區域變數](#區域變數)
- [以define自訂常數](#以define自訂常數)
- [const常數](#const常數)
- [條件運算子-「?:」](#條件運算子)
- [運算式中的型別轉換](#運算式中的型別轉換)
- [switch...case...判斷式](#switch判斷式)
- [指標](#指標)


## 浮點數比較

C++預設使用之浮點數值的型別為double，欲將某浮點數值指定為float時，必須在數值的字尾加上「f」或「F」<br>
因為程式內浮點數的儲存值與指定數值有些微差距，對於比較浮點數的判斷要特別注意，**不能**直接使用以下方式判斷
```
#include<iostream>
using namespace std;
int main()
{
	float f = 1e33f;
	if (f == 1e33f)
	{
		f += 5e33f;
	}
	return 0;
}
```
應用以下邏輯<br><br>
**|(f-1e33)| <= 微小數**


完整程式碼如下

```
#include<iostream>
using namespace std;
int main()
{
	float f = 1e33f;
	if (abs(f-1e33)< 1e30)
	{
		f += 5e33f;
	}
	return 0;
}
```

## 字元char

字元是用ASCII碼的方式儲存，所以字元可以視為一個位元組的整數，範圍從-128到127，在執行運算時將被當成整數使用。

## 字串

**char 字串名稱[字串長度];**
<br>字串將以「\0」字元作為結尾，所以字串實際可儲存長度為宣告的字串長度-1

## 區域變數

C++可運用 「{ }」在大括號內寫入敘述(statement)，當某變數宣告在此區塊內，將只能在該區塊內使用，稱**區域變數(local variable)**。
<br>

```
#include<iostream>
using namespace std;
int main()
{
	int i = 1;
	{
		int j =2;
		cout << "i = " << i << endl << "j = " << j << endl;
	}
	cout << "i= " << i << endl;
	//cout << "j= " << j << endl;
	return 0;
}
```
因j只能在區塊內使用，因此若刪除註解，將會導致編譯錯誤(j變數尚未被宣告)<br>

當程式內宣告的廣域變數與區域變數名稱相同時，程式會優先使用**區域變數**，廣域變數將暫時被區域變數蓋住，若需指定存取廣域變數，可運用 **「::」範圍解析運算子**
```
::廣域變數名稱;
```
```
#include<iostream>
using namespace std;
int i = 1; //global variable
int main()
{
	int i = 2; //local variable
	cout << "i = " << i << endl;
	cout << "::i = " << ::i << endl;
	return 0;
}
```
執行結果如下

```
i = 2
::i = 1
```

## 以define自訂常數

define為程式的前置處理敘述，只需在define前加上「#」，結尾不需加上「;」，在程式編譯時，編譯器會把程式中使用到常數名稱的地方，換為定義的常數數值
```
#define 常數名稱 常數數值
```
有以下優點
- 常數一經定義就無法更改，因此常數不會被改變。
- 常數名稱代替數值較有意義 (例如 PI代表3.14)
- 若常數的值需要變動，只要更改定義常數的敘述，不需要修改程式內每一個用到該常數的地方，方便維護。

```
#include<iostream>
using namespace std;
#define PI 3.14
int main()
{
	double Radius =5.0, Area;
	Area = PI * Radius * Radius;
	cout << "The area of radius" << Radius << "is" << Area << endl;
	return 0;
}
```
亦可使用define取代程式內的敘述
```
#include<iostream>
using namespace std;
#define C cout << "C++ " << endl;
int main()
{
	C C C //不需要「;」，因為已包含在C中
	return 0;
}
```
執行結果為
```
C++
C++
C++
```
取消常數定義#undef <br>

```
#undef 已定義過的常數名稱
```

## const常數

利用const修飾詞限制變數在執行過程中，不可更改在宣告時所定義的數值
```
const 資料型別 常數名稱 = 常數值 ;
```

## 條件運算子 
```
(條件式) ? 程式敘述1 : 程式敘述2 ;
```
當條件式判斷為True ，將執行程式敘述1，否則執行程式敘述2。

```
int i = 3;
cout << "Integer " << ((i>5) ? "i>5" : "i<=5") << endl;
```
執行結果
```
i<=5
```
當然也能配合define

```
#include<iostream>
using namespace std;
#define MAX(a,b) (a>b)? (a) : (b)
int main()
{
	cout << "MAX(5 , 10)=" << (MAX(5, 10));
	return 0;
}
```

## 運算式中的型別轉換

C++分為 **隱式型別轉換(Implicit Type Conversions)** 與 **顯式型別轉換(Explicit Conversions)**
- 隱式型別轉換：<br>
```
#include<iostream>
using namespace std;
#define MAX(a,b) (a>b)? (a) : (b)
int main()
{
	cout << "7/2 = " << 7 / 2 << endl;
	cout << "7.0/2 = " << 7.0 / 2 << endl;
	return 0;
}
```
執行結果
```
7/2 = 3
7.0/2 = 3.5
```
7/2結果等於3，因7與2皆是整數，相除後將得到整數，但將7改成7.0後，則會因為7.0為float，除以整數2後，編譯器自行把2改成2.0，兩個浮點數相除，可得到float 3.5。
中間轉換過程由C++編譯器自動執行，因此稱為 **隱式(Implicit)**
- 顯式型別轉換：
```
(欲轉換的型別) 運算式;  (float) 7/2;
or
欲轉換的型別 (運算式);  float (7)/2;
```

## switch判斷式
```
switch (條件式){
case 條件值一:
  程式區段一;
  break;
case 條件值二:
  程式區段二;
  break;
......
default:
  程式區段;
}
```
```
#include<iostream>
using namespace std;
int main()
{
	char student;
	cout << "Are you a student? (y/n)";
	cin >> student;
	switch(student)
	{
	case 'y':
	case 'Y':
		cout << "You are a student!" << endl;
		break;
	case 'n':
	case 'N':
		cout << "You are not a student!" << endl;
		break;
	default:
		cout << "?" << endl;
	}
}
```

## 指標

**位址值可以被儲存在變數裡，這種儲存位址值的變數，稱為指標變數**<br>

```
資料型別 *指標變數名稱;
int *ptr ;
```

- &amp;取址運算子：取得**變數**儲存位置之**位址**
```
&變數名稱;
```
- *取值運算子：取得**指標變數**儲存之位址值指向的**變數**，執行該變數內資料的存取
```
*指標變數名稱;
```

# 指標變數的設定

```
指標變數名稱 = & 已宣告變數名稱;
or
資料型別 *指標名稱 = &變數;
```
```
int *ptr = &value;
```

在以下範例，先將temp的**位址**給專門存放**指標變數**的ptr，因此目前ptr所指向的是temp的位址。
```
#include<iostream>
using namespace std;
int main()
{
	int temp=5;
	int* ptr = &temp;
	
	cout << "The address of temp： " << &temp << endl;
	cout << "The value of temp： " << temp << endl;
	cout << "The address of ptr： " << &ptr << endl;
	cout << "The value of ptr： " << ptr << endl;
	cout << "The value of ptr's value address： " << *ptr << endl;
	return 0;
}
```
輸出為
```
The address of temp： 000000F550F4F894
The value of temp： 5
The address of ptr： 000000F550F4F8B8
The value of ptr： 000000F550F4F894
The value of ptr's value address： 5
```
可以看到 &temp與ptr的輸出皆為同一個位址<br>
若要看到ptr這個**指標變數**所存放的**內容**(內容為temp的值，也就是5)，則需運用到取值運算子*<br>
因此temp與*ptr的輸出是相同的。

