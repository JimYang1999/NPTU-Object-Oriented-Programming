#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i;
    int n;
    int* p;
    //start
    cin >> n;
    p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (p[i] & 2 != 0)
        {
            p[i] = p[i] + 1;
        }
    }
    //end
    for (i = 0; i < n; i++)
    {
        cout << p[i];
        if (i < (n - 1))
            cout << " ";
    }
    cout << endl;
    delete[] p;
}