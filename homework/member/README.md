1. 設計一個C++程式名為member.cpp
2. 設計一個結構體以儲存並管理會員資料，每個會員必須包含以下資訊：
    - 姓名，不超過20個字
    - 行動電話號碼，字串
    - 會員類別，宣告一個enum，其值可以為「Gold」與「Silver」
    - 會員優惠(benefit)，請以union設計
        - Gold會員有每個月月費的折扣(discount，浮點數)
        - Silver會員有每個月免費的分鐘數(freeMinute，整數)
3. 讓使用者連續輸入會員資料，並使用動態的結構體陣列儲存（可假設會員數不超過5人），直到使用者輸入的會員姓名為「quit」為止
4. 接著，讓使用者輸入一個會員的姓名，在陣列中尋找符合的會員，並將其資料輸出
5. 反覆執行前一步驟，直到使用者輸入「quit」為止。


```
#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>


enum MemberType { Gold, Silver };

union Benefit
{
	double discount;
	int freeMinutes;
};

struct Member {
	char name[21];
	char phone[121];
	MemberType mtype;
	Benefit benefit;
};

int main()
{
	bool quit = false;
	char tempName[21], tempPhone[12], tempType;
	double tempD = 0.0;
	int tempM = 0;

	Member** members = new Member * [5];
	int membernum = 0;

	while (!quit)
	{
		fflush(stdin);

		cout << "Name：";
		cin.getline(tempName, 20);

		if (strcmp(tempName, "quit") == 0)
		{
			quit = true;
		}
		else
		{
			cout << "Phone：";
			cin.getline(tempPhone, 11);

			cout << "Type(g/s)：";
			cin >> tempType;
			cin.get();

			if (tempType == 'g')
			{
				cout << "Discount：";
				cin >> tempD;
				cin.get();
			}
			else
			{
				cout << "Free Minutes：";
				cin >> tempM;
				cin.get();
			}

			members[membernum] = new Member;
			strcpy_s(members[membernum]->name, tempName);
			strcpy_s(members[membernum]->phone, tempPhone);
			if (tempType == 'g')
			{
				members[membernum]->mtype = Gold;
				members[membernum]->benefit.discount = tempD;
			}
			else
			{
				members[membernum]->mtype = Silver;
				members[membernum]->benefit.freeMinutes = tempM;
			}
			membernum++;
		}
	}
	cout << endl;

	quit = false;
	while (!quit)
	{
		cout << "Input a name：";
		cin.getline(tempName, 20);
		if (strcmp(tempName, "quit") == 0)
		{
			quit = true;
			cout << "Bye";
		}
		else
		{
			bool found = false;
			for (int i = 0; i < membernum; i++)
			{
				if (strcmp(tempName, members[i]->name) == 0)
				{
					if (members[i]->mtype == Gold)
					{
						cout << members[i]->name << "(" << members[i]->phone << ")" << "G" << "/" << members[i]->benefit.discount << endl << endl;
					}
					if (members[i]->mtype == Silver)
					{
						cout << members[i]->name << "(" << members[i]->phone << ")" << "S" << "/" << members[i]->benefit.freeMinutes << endl << endl;
					}
					found = true;
				}
			}

			if (!found)
			{
				cout << "Member not found" << endl << endl;
			}
		}
	}
	return 0;
}
```

輸出：
```
Name:Jun Wu
Phone:0999111111
Type(g/s):g
Discount:0.95
Name:Yo Yo Ma
Phone:0999222111
Type(g/s):s
Free Minutes:100
Name:Nathan Ho
Phone:0999222333
Type(g/s):g
Discount:0.9
Name:Alice Liu
Phone:0999444444
Type(g/s):s
Discount:200
Name:quit 

Input a name:Nathan Ho
Nathan Ho(0999222333) G/0.9

Input a name:Alice Liu
Alice Liu(0999444444) S/200

Input a name:Thomas Lin
Member not found!

Input: quit
Bye
```
