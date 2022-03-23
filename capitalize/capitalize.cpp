#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cout << "Please input a string:" << endl;
	getline(cin, str);
	cout << "Capitalizing..." << endl;
	/* Array version
	str[0]=toupper(str[0]);
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			str[i + 1] = toupper(str[i + 1]);
		}
		if (i == str.size() - 1)
		{
			cout << str << endl;
		}
	}
	*/
	/* function version
	int pos = 0;
	while (pos!=-1)
	{
		pos = str.find(' ',pos);
		str.replace(pos+1,1,1, toupper(str[pos+1]));  //string& replace (size_t pos,  size_t len,  size_t n, char c);
		if (pos!=-1)pos += 1;
	}
	*/
	/*ASCII version*/
	if (int(str[0]) >= 97)str[0] = char(int(str[0] - 32));
	for (int i = 0; i < str.size(); i++)
	{
		(int(str[i]) == 32 and int(str[i + 1]) >= 97 and int(str[i + 1]) <= 122) ? str[i + 1] = char(int(str[i + 1]) - 32) : 0;
	}
	
	cout << str;
	return 0;
}
