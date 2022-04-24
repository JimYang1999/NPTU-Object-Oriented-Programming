#include<iostream>
#include<string>
using namespace std;


int main()
{
    string fruits[5] = { "Apple", "Banana", "Cherry", "Durian", "Fig" };
    int prices[5] = { 15, 20, 2, 40, 10 };
    string fruitName;
    bool found;


    //start
    cin >> fruitName;
    for (int i = 0; i < 5; i++)
    {
        if (fruitName.compare(fruits[i]) == 0)
        {
            cout << prices[i] << endl;
            found = true;
            break;
        }
    }
    //end

    if (!found)
    {
        cout << "Not Found!" << endl;
    }
}
