1. 設計一個名為lexico.cpp的程式
2. 讓使用者輸入一個整數n，以決定其後將輸入的字串數目
3. 使用迴圈讓使用者輸入n個英文字串
4. 每個字串皆不超過20個字元，使用Enter結束每一次的輸入，字串內容全部為大寫或小寫字母，並可包含空白字元
5. 將這n個字串中的大寫字母都轉換為小寫字母，再依Lexicographical order(也就是字典順序)輸出
6. 你必須要以動態字串陣列來實作，其宣告必須為：
```
  int n;
   cout << "How many strings do you want to input? ";
   cin >> n;
 
   char **str = new char * [n];
   ...
   for(int i=0;i<n;i++)
   {
      ...
      str[i] = new char[21];
      ...
   }
   ...
```
你可能須要載入「#include <string>」或「#include <cstring>」等相關的標頭檔<br>

```
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout << "How many strings do you want to input? ";
    cin >> n;

    char** str = new char* [n];
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cout << "Input " << i + 1 << ": ";
        str[i] = new char[21];
        cin.getline(str[i], 21);
    }
    for (int i = 0; i < n; i++)
    {
        char* tmp = str[i];
        while (*tmp) {
            *tmp = tolower(*tmp);
            tmp++;
        }
    }
    cout << "Lexicographical Ordering..." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (strcmp(str[i], str[j]) < 0)
            {
                swap(str[i], str[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}
```
  
