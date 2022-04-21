#include<iostream>
#include<string>
using namespace std;

void insertString();
void listStrings();
void deleteStrings();

int Size = 0;
string* sBox = NULL;

int main()
{
    bool quit = false;
    char cmd;

    while (!quit)
    {
        cin >> cmd;
        cin.get();
      
        switch (cmd)
        {
        case 'l': case 'L':
            listStrings();
            break;
        case 'd': case 'D':
            deleteStrings();
            break;
        case 'i': case 'I':
            insertString();
            break;
        case 'q': case 'Q':
            quit = true;
            if (Size != 0)
                delete[] sBox;
            break;
        }
    }
    cout << "Bye." << endl;
}
void insertString()
{
    string* sBoxTemp;
    string temp;
    getline(cin, temp);
    if (Size % 3 == 0)
    {
//start
        sBoxTemp = new string[Size + 3];
        for (int i = 0; i < Size; i++)
        {
            sBoxTemp[i] = sBox[i];
        }
//end
        if (sBox != NULL)
            delete[] sBox;
        sBox = sBoxTemp;
    }
    sBox[Size++] = temp;
}

void listStrings()
{
    if (Size != 0)
    {
        for (int i = 0; i < Size; i++)
        {
            cout << "[" << sBox[i] << "]";
        }
        cout << endl;
    }
    else
    {
        cout << "The box is empty!" << endl;
    }
}

void deleteStrings()
{
    //start
    if (Size != 0)
    {
        Size = 0;
        if (sBox != NULL)
        {
            delete[] sBox;
            sBox = NULL;
        }
    }
    else
    {
        cout << "Nothing to delete!" << endl;
    }
}
