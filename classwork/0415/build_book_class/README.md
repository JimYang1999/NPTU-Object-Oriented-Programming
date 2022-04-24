# Book類別的建立與使用

輸出以下的結果：

```
執行結果1
輸入	
輸出	Programming in C (Jun Wu), ISBN:987-123-456-1
Jun Wu's book has been deleted!
Smart Programming (Tony Liu), ISBN:987-111-222-3
unknown (unknown), ISBN:undefined
unknown's book has been deleted!
Tony Liu's book has been deleted!
```

完整程式碼如下：

```
#include<iostream>
using namespace std;

class Book
{
public:
	string title;
	string author;
	string ISBN;
	//start
	Book()
	{
		title = "unknown";
		author = "unknown";
		ISBN = "undefined";
	}
	Book(string t, string a, string i)
	{
		title = t;
		author = a;
		ISBN = i;
	}
	//end
	~Book()
	{
		cout << author << "'s book has been deleted!" << endl;
	}

	void showInfo()
	{
		cout << title << " (" << author << ")" << ", ISBN:" << ISBN << endl;
	}
};

int main()
{
	Book* b1 = new Book("Programming in C", "Jun Wu", "987-123-456-1");
	Book b2("Smart Programming", "Tony Liu", "987-111-222-3");
	Book b3;

	b1->showInfo();
	delete b1;
	b2.showInfo();
	b3.showInfo();
}
```
