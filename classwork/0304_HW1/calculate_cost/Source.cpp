#include<iostream>
using namespace std;
int main()
{
    int i;
    char x;
    cin >> i;
    cin >> x;
    int a = 30;
    int b = 25;
    int c = 20;
    if (x == 'S')
    {
        switch (i) {
        case 1:
            cout << a << endl;
            break;
        case 2:
            cout << b << endl;
            break;
        case 3:
            cout << c << endl;
            break;
        default:
            cout << "Wrong location!" << endl;
        }
    }
    else if (x == 'R')
    {
        switch (i) {
        case 1:
            cout << a - 5 << endl;
            break;
        case 2:
            cout << b - 5 << endl;
            break;
        case 3:
            cout << c - 5 << endl;
            break;
        default:
            cout << "Wrong location!" << endl;
        }
    }
    else {
        if (i != 1 && i != 2 && i != 3)
        {
            cout << "Wrong location and type!" << endl;
        }
        else
        {
            cout << "Wrong type!" << endl;
        }
    }


}