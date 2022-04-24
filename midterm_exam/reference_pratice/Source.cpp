#include <iostream>
using namespace std;

#include <cstdio>

void show(int i, int j)
{
    printf("(%d, %d)\n", i, j);
}
//start
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int& max(int& i, int& j)
{
    if (i > j)
        return i;
    else
        return j;
}
//end
int main()
{
    int x, y;
    cin >> x;
    cin >> y;

    if (x != y)
    {
        show(x, y);
        swap(x, y);
        show(x, y);
        max(x, y) = 0;
        show(x, y);
    }
    else
        cout << "Error!" << endl;
}


