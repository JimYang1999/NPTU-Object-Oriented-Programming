#include <iostream>
using namespace std;

#include <cstdio>

void show(int i, int j, int k)
{
    printf("(%d, %d, %d)\n", i, j, k);
}

void swap(int& a, int& b);

int& max(int& i, int& j, int& k);

int main()
{
    int x, y, z;
    cin >> x;
    cin >> y;
    cin >> z;

    show(x, y, z);
    swap(x, z);
    show(x, y, z);
    max(x, y, z) = 0;
    show(x, y, z);
}
//start
void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int& max(int& i, int& j, int& k)
{
    int temp = 0;
    if (i > j)
    {
        temp = i;
    }
    else
    {
        temp = j;
    }
    if (k > temp)
    {
        temp = k;
    }
    if (temp == i) return i;
    if (temp == j) return j;
    if (temp == k) return k;
}