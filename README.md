C++ 
=======

浮點數比較
------
C++預設使用之浮點數值的型別為double，欲將某浮點數值指定為float時，必須在數值的字尾加上「f」或「F」<br>
因為程式內浮點數的儲存值與指定數值有些微差距，對於比較浮點數的判斷要特別注意，**不能**直接使用以下方式判斷
```
#include<iostream>
using namespace std;
int main()
{
	float f = 1e36f;
	if (f == 1e36f)
	{
		f += 5e35f;
	}
	return 0;
}
```
應用以下邏輯<br><br>
**|(f-1e36)| <= 微小數**


完整程式碼如下

```
#include<iostream>
using namespace std;
int main()
{
	float f = 1e36f;
	if (abs(f-1e36)< 1e30)
	{
		f += 5e35f;
	}
	return 0;
}
```

字元(char)
----
字元是用ASCII碼的方式儲存，所以字元可以視為一個位元組的整數，範圍從-128到127，在執行運算時將被當成整數使用。

字串
----
**char 字串名稱[字串長度];**
<br>字串將以「\0」字元作為結尾，所以字串實際可儲存長度為宣告的字串長度-1

區域變數
---
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

常數
---
常數是程式中不會變動的資料
- 整數常數:
- 
