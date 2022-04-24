#include <iostream>
using namespace std;

int rounding(int);
int rounding(double);

int main()
{
    int x;
    double y;

    cin >> x;
    cin >> y;
    cout << rounding(x) << endl;
    cout << rounding(y) << endl;
}
//start
int rounding(int x)
{
    if (x < 0)
        return x / 10 * 10;
    return x / 10 == x / 10.0 ? x / 10 * 10 : (x / 10 + 1) * 10;

}

int rounding(double x)
{
    if (x < 0)
        return (int)x;
    return x == (int)x ? (int)x : (int)x + 1;
}
//end