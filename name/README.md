- 考慮以下兩個C++標頭檔：
name.h

```
#define LenFN 20
#define LenLN 10
 
#ifndef STRUCT_NAME
#define STRUCT_NAME
 
struct Name
{
  char firstname[LenFN+1];
  char lastname[LenLN+1];
};
 
Name *setName(const char *name);
 
#endif
```


initial.h
```
#include "name.h"
 
char *initial(Name *n);
```


以及下面這個main.cpp程式：

main.cpp
```
#include <iostream>  
using namespace std; 
#include <cstring>   
#include "name.h"
#include "initial.h"
 
int main()
{
  Name *someone;
  char *name = new char[LenFN+LenLN+1];
 
  cout << "Please input your name: ";
 
  cin.getline(name, LenFN+LenLN);
 
  someone = setName(name);
 
  cout << "Your first name is " << someone->firstname << "." << endl;
  cout << "Your last name is " << someone->lastname << "." << endl;
  cout << "The initial of your name is " << initial(someone) << endl;
 
  return 0;
}
```

- 請設計一個檔名為name.cpp的程式，完成函式「setName()」的實作
  - 此函式接收一個華人的名字為參數
    - 其型式可為「Firstname Lastname」或「Lastname, Firstname」，例如:
      - 該字串內容可為「Yo-Yo Ma」或「Ma, Yo-Yo」
      - 該字串內容可為「Jun Wu」或「Wu, Jun」
     - 動態建立一個Name結構體，將使用者所輸入的名字的姓氏與名字分別放入該結構體的lastname與firstname欄位中
     - 完成後將該結構體傳回
   - 此函式之實作可以參考以下的程式：
```
using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include "name.h"
 
Name *setName(const char *name)
{
  Name *somebody = new Name;
 
   ...
 
  return somebody;
}
```

至於initial.cpp則是負責initial()函式的實作，用以接收一個Name的結構體，並傳回一個字串：
- 所傳回的字串格式為Name結構體中的「lastname」「,」「firstname的initial」
- initial指得是名字第一個字母所組成的縮寫
- 例如Yo-Yo Ma應輸出為Ma, Y.-Y.
- 例如Jun Wu應輸出為Wu, J.

- 程式執行結果參考:

```
[02:16 junwu@ws hw1]$ ./a.out 
Please input your name: Yo-Yo Ma
Your first name is Yo-Yo.
Your last name is Ma.
The initial of your name is Ma, Y.-Y.
[02:16 junwu@ws hw1]$ ./a.out
Please input your name: Wu, Jun
Your first name is Jun.
Your last name is Wu.
The initial of your name is Wu, J.
```
