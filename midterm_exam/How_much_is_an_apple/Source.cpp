#include<iostream>
using namespace std;
#include <string>
int main()
{
    string mac[5] = { "Mac Mini", "Mac Studio", "iMac", "MacBook Air", "MacBook Pro" };
    int price[5] = { 19800,        59800,  38900,         36800,         59980 };
    string what2buy;
    bool found = false;

    getline(cin, what2buy);

    for (int i = 0; i < 5; i++)
    {
        if (what2buy.compare(mac[i]) == 0)
        {
            cout << what2buy << ":$" << price[i] << "." << endl;
            int diff[5] = { 0 };
            int j;
            for (j = 0; j < 5; j++)
            {
                diff[j] = price[i] > price[j] ? price[i] - price[j] : price[j] - price[i];
            }

            int min = -1;
            for (j = 0; j < 5; j++)
            {
                if (diff[j] != 0)
                {
                    if (min == -1) min = j;
                    else if (diff[j] < diff[min])
                        min = j;
                }
            }

            cout << "You can also consider " << mac[min] << ":$" << price[min] << "." << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Not Found!" << endl;
    }
}
