#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>


enum MemberType {Gold,Silver};

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

		cout << "Name¡G";
		cin.getline(tempName, 20);

		if (strcmp(tempName, "quit") == 0)
		{
			quit = true;
		}
		else
		{
			cout << "Phone¡G";
			cin.getline(tempPhone, 11);

			cout << "Type(g/s)¡G";
			cin >> tempType;
			cin.get();

			if (tempType == 'g')
			{
				cout << "Discount¡G";
				cin >> tempD;
				cin.get();
			}
			else
			{
				cout << "Free Minutes¡G";
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
		cout << "Input a name¡G";
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