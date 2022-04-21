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