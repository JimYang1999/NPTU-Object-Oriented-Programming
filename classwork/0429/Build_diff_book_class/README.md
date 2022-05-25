# 不同Book類別的建立

輸出以下的結果：

```
執行結果1
輸入	
輸出	b1 is created as a Book!
Programming in C(Jun Wu), 987-123-456-1
----------
b2 is created as a Book and it is a copy of b1.
Programming in C(Jun Wu), 987-123-456-1
----------
cb is created as a ComicBook!
unknown(Colored Comic)(unknown), undefined
----------
setting data for cb...ok...print out it again
Call me Spider-Man(Colored Comic)(Stan Lee and Steve Ditko), undefined
----------
casting b1 as a ComicBook
Programming in C(Colored Comic)(Jun Wu), 987-123-456-1
----------
casting cb as a Book
Programming in C(Jun Wu), 987-123-456-1
```

完整程式碼如下：

```
#include <iostream>
using namespace std;
 
class Book
{
    private:
        string title;
        string author;
        string ISBN;
    public:   
        Book()
        {
            title="unknown";
            author="unknown";
            ISBN="undefined";
        }
        Book(string t, string a, string i)
        {
            title=t;
            author=a;
            ISBN=i;
        }
        void setTitle(string t) {title=t;}
        void setAuthor(string a) {author=a;}
        void setISBN(string i) {ISBN=i;}
        string getTitle() {return title;}
        string getAuthor() {return author;}
        string getISBN() {return ISBN;}
        void showInfo()
        {
            cout << title << "(" << author << "), " << ISBN << endl;
        }
};


class ComicBook : public Book
{
    private:
        bool colored;
    public:
        ComicBook()
        { 
           colored=true;
        }
        void showInfo()
        {
            if(colored)
                cout << getTitle() << "(Colored Comic)(" << getAuthor() << "), " << getISBN() << endl;
            else
                cout << getTitle() << "(B/W Comic)(" << getAuthor() << "), " << getISBN() << endl;
        }
};

int main()
{
    cout << "b1 is created as a Book!" << endl;
    Book b1 ("Programming in C", "Jun Wu", "987-123-456-1");
    b1.showInfo();
    
    cout << "----------" << endl;
    cout << "b2 is created as a Book and it is a copy of b1." << endl;    
    Book b2;
    b2=b1;
    b2.showInfo();

    cout << "----------" << endl;
    cout << "cb is created as a ComicBook!" << endl;
    ComicBook *cb=new ComicBook();
    cb->showInfo();
    
    cout << "----------" << endl;
    cout << "setting data for cb...ok...print out it again" << endl;
    cb->setTitle("Call me Spider-Man");
    cb->setAuthor("Stan Lee and Steve Ditko");
    cb->showInfo();
    
    cout << "----------" << endl;
    cout << "casting b1 as a ComicBook" << endl;
    cb=(ComicBook *)&b1;
    cb->showInfo();
    
    cout << "----------" << endl;
    cout << "casting cb as a Book" << endl;
    b2=(Book)*cb;
    b2.showInfo();
}

```
