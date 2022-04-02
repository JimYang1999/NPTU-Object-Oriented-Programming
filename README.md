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
	- [指標變數的設定](#指標變數的設定)
 	- [指標的指標](#指標的指標)
 	- [指標與陣列](#指標與陣列)
 	- [指向陣列的指標](#指向陣列的指標)
 	- [字串陣列](#字串陣列)
 	- [以動態配置記憶體起始設定指標](#以動態配置記憶體起始設定指標)


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

### 指標變數的設定

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

### 指標的指標

指標的指標意即**指標指向另一個指標**

```
#include<iostream>
using namespace std;
int main()
{
	int temp=5;
	int* ptr_to_int = &temp;
	int** ptr_to_ptr = &ptr_to_int;
	return 0;
}
```
以上範例，首先將ptr_to_int這個指標變數指向temp，因此ptr_to_int目前存放的是temp的**位址**，再將ptr_to_ptr這個指標變數指向ptr_to_int，目前ptr_to_ptr存放的是ptr_to_int的**位址**。

ptr_to_ptr 指向 ptr_to_int ， ptr_to_int  指向  temp

### 指標與陣列

```
陣列名稱 [indxe]
相當於
* (陣列名稱 + indxe)
```

因陣列名稱是陣列起始**位址**的代名，因此可以將它看成是一個指標去存取陣列。<br>

array[3] 等於 *(array +3)  //value<br>
&array[3] 等於 (array+3)  //address<br>


```
#include<iostream>
using namespace std;
int main()
{
	int array[4];
	cout << "array：" << array << endl;
	for (int i = 0; i < 4; i++)
	{
		array[i] = i;
		cout << "array[" << i << "]   |   " << &array[i] << "   |   " << array[i] << endl;
		cout << "array + " << i << "  |   " << (array + i) << "   |   " << *(array + i) << endl<<endl;
	}
	
	return 0;
}
```
輸出結果為
```
array：000000A0A9AFF8B8
array[0]   |   000000A0A9AFF8B8   |   0
array + 0  |   000000A0A9AFF8B8   |   0

array[1]   |   000000A0A9AFF8BC   |   1
array + 1  |   000000A0A9AFF8BC   |   1

array[2]   |   000000A0A9AFF8C0   |   2
array + 2  |   000000A0A9AFF8C0   |   2

array[3]   |   000000A0A9AFF8C4   |   3
array + 3  |   000000A0A9AFF8C4   |   3
```
不難看出array的位址與&array[0]及array+0是一樣的，並且array每+1就會跳一個**陣列資料型別**(此為int，4Byte)的位址

二維陣列： 
```
array[i][j] 等於 *(*(array+i)+j) 等於 *( array[i] + j)
```

### 指向陣列的指標


```
int array[4] = {0,1,2,3} , *ptr ;
ptr = array ;
for(int i=0 ; i<4 ; i++ )
    {
        cout << "array[" << i << "]  |  " << ptr << "  |  " << *ptr << endl ;
        ptr++;
    }
```
輸出結果

```
array[0]  |  0x7fffbbbb3c80  |  0
array[1]  |  0x7fffbbbb3c84  |  1
array[2]  |  0x7fffbbbb3c88  |  2
array[3]  |  0x7fffbbbb3c8c  |  3
```

運用指標存取二維陣列

```
指標變數名稱[列索引 * 行大小 + 行索引]
或
*(指標變數名稱 + 列索引 * 行大小 + 行索引)
```

### 字串陣列

較節省空間，有多少用多少。

用二維字串陣列宣告會有浪費空間和字串長度限制問題，但字串指標陣列沒有。
```
#include <iostream>

using namespace std;

int main()
{
    char str_array[7][5] = {"Mon","Tue","Wed","Thu","Frid","Sat","Sun"};
    char *str_ptr_array[7] = {"Mon","Tuesday","Wed","Thursday","Friday","Sat","Sun"};
    
    cout << "2d char array：" << endl << "----------------" << endl ;
    for (int i = 0 ; i < 7 ; i++)
    {
        cout << "{";
        for ( int j=0 ; j<5 ;j++)
        {
            cout << str_array[i][j] << ".";
        }
        cout << "}"<< endl;
    }
    
    cout << endl << "char pointer array ：" << endl << "----------------" << endl;
    
    for(int i=0 ; i<7; i++)
    {
        cout << "{";
        int j=0;
        while(str_ptr_array[i][j]!=NULL)
        {
            cout <<str_ptr_array[i][j++] <<"."; 
        }
        cout << "}" <<endl;
    }
    return 0;
}
```
輸出結果

```
2d char array：
----------------
{M.o.n...}
{T.u.e...}
{W.e.d...}
{T.h.u...}
{F.r.i.d..}
{S.a.t...}
{S.u.n...}

char pointer array ：
----------------
{M.o.n.}
{T.u.e.s.d.a.y.}
{W.e.d.}
{T.h.u.r.s.d.a.y.}
{F.r.i.d.a.y.}
{S.a.t.}
{S.u.n.}

```
能明顯看到二維陣列用到較多的空間，因此用指標宣告字串所使用的空間較節省。

### 以動態配置記憶體起始設定指標

使用new運算子，動態配置儲存某資料型別之記憶體空間，且完成初值的設定，再將起始位置值指派給相同資料型別的指標。

```
資料型別 *指標變數名稱 = new 資料型別 (初值);
or--------------
資料型別 *指標變數名稱 = new 資料型別;
*指標變數名稱 = 初值;
```
```
int *ptr = new int (20);
or--------------
double *dptr = new double ;
*dptr = 3.14;
```
以new配置記憶體後，使用完要用delete運算子釋放這塊記憶體

```
delete 指標變數;

delete ptr;
delete dptr;
```

```
#include <iostream>

using namespace std;

int main()
{
    int *ptr = new int (20);
    cout <<"name\t| address\t| value"<< endl;
    cout <<"----------------------------------"<<endl;
    cout << "ptr\t| " <<ptr << "\t| " << *ptr <<endl ;
    
    delete ptr;
    return 0;
}

```
執行結果
```
name	| address	| value
----------------------------------
ptr	| 0x56496a2a5eb0| 20
```

### 以const修飾詞限制指標變數

- 將const修飾詞加在資料型別宣告之前，或資料型別與「*」中間，兩者是一樣的。將限制程式不可修改指標所指向之位址值內儲存的資料。
```
const 資料型別 * 指標變數名稱;
資料型別 const * 指標變數名稱;
```
雖然const**不能更改**指標所指向**記憶體空間內的資料**，但可以更改指標所指向的位址。

```
#include <iostream>

using namespace std;

int main()
{
    int i =3;
    const int *pi;
    pi = &i; //更動指標所指之變數，可以
    //*pi =5; //更便指標所指之資料，不行
    cout << "*pi= " << *pi;
    return 0;
}

```
- 將const修飾詞加在「*」之後
