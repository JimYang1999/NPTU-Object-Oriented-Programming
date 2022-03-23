#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	cout << "Please input a string:" << endl;
	getline(cin, str);
	cout << "Capitalizing..." << endl;

	str[0] = toupper(str[0]);
	int pos = 0;
	while (pos != -1)
	{
		pos = str.find(' ', pos);
		str.replace(pos + 1, 1, 1, toupper(str[pos + 1]));  //string& replace (size_t pos,  size_t len,  size_t n, char c);
		if (pos != -1)pos += 1;
	}
	cout << str;
	return 0;
}