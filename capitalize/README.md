設計一個名為capitalize.cpp的程式
要求使用者輸入一個長度不超過200的英文字串（其中可包含空白鍵）
將使用者所輸入字串，其中每一個字的第一個字母改成大寫，其餘皆以小寫輸出
但其中若有某個字原本就是由大寫字母組成，則維持以大寫輸出
程式執行結果參考:
```
Please input a string: To do or not to do, that is a question!
Capitalizing...
Output: To Do Or Not To Do, That Is A Question!
```
```
Please input a string: in 2013, the government of the US was shut down for more than TWO WEEKS.
Capitalizing...
Output: In 2013, The Government Of The US Was Shut Down For More Than TWO WEEKS.
```
主程式
```
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cout << "Please input a string:" << endl;
	getline(cin, str);
	cout << "Capitalizing..." << endl;
	/* 陣列版本
	str[0]=toupper(str[0]);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str[i + 1] = toupper(str[i + 1]);
		}
		if (i == str.size() - 1)
		{
			cout << str << endl;
		}
	}
	*/
	/* toupper函數版本
	int pos = 0;
	while (pos!=-1)
	{
		pos = str.find(' ',pos);
		str.replace(pos+1,1,1, toupper(str[pos+1]));  //string& replace (size_t pos,  size_t len,  size_t n, char c);
		if (pos!=-1)pos += 1;
	}
	*/
	/*ASCII版本*/
	if (int(str[0]) >= 97)str[0] = char(int(str[0] - 32));
	for (int i = 0; i < str.size(); i++)
	{
		(int(str[i]) == 32 and int(str[i + 1]) >= 97 and int(str[i + 1]) <= 122) ? str[i + 1] = char(int(str[i + 1]) - 32) : 0;
	}
	cout << str;
	return 0;
}
```
