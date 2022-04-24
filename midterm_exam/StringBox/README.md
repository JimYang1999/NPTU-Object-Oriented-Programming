# StringBox! 存放不定個數的字串

此程式使用動態的字串陣列來管理不定個數的字串。其中，每當所配置的空間不足時，隨即為其額外配置3個字串的空間。當使用者輸入d時，則將所有字串內容清除。

此題的執行結果可參考如下：
```
執行結果1
輸入	i
test1
i
test2
l
i
test3
i
test4
l
d
l
i
test1
d
l
q
輸出	[test1] [test2]
[test1] [test2] [test3] [test4]
The box is empty!
The box is empty!
Bye.

執行結果2
輸入	d
q
輸出	Nothing to delete!
Bye.

執行結果3
輸入	q
輸出	Bye.

執行結果4
輸入	l
q
輸出	The box is empty!
Bye.
```

完整程式碼如下：

```
#include <iostream>
#include <string>
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
    //end
}


```
