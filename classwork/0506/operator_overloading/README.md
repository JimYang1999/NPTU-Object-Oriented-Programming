# Book類別物件的加法

```
執行結果
輸入	 
輸出	Totalpriceis188.99!
```

完整程式碼如下：
```
#include <iostream>
using namespace std;

class Book
{
    public:
        double price;
        
        void setPrice(double p)
        {
            price=p;
        }
        
        double getPrice()
        {
            return price;
        }

};
//start
double operator+(Book x, Book y)
{
    return x.getPrice() + y.getPrice();
}
//end

int main()
{
    Book b1, b2;
    
    b1.setPrice(100.0);
    b2.setPrice(88.99);
    cout << "Total price is " << b1+b2 << "!" << endl;
}

```
