#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n;
    cout << "How many strings do you want to input? ";
    cin >> n;

    char** str = new char* [n];
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Input " << i + 1 << ": ";
        str[i] = new char[21];
        cin.getline(str[i], 21);

    }

    for (int i = 0; i < n; i++)
    {
        char* tmp = str[i];
        while (*tmp) {
            *tmp = tolower(*tmp);
            tmp++;
        }
    }
    cout << "Lexicographical Ordering..." << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(strcmp(str[i],str[j])<0)
            {
                swap(str[i],str[j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << str[i] << endl;
    }
    return 0;
}