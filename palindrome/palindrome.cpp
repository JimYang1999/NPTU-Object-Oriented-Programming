#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cout << "Please input a string (up to 255 characters):";
	getline(cin, str);
	str.erase(remove_if(str.begin(), str.end(), ispunct), str.end());  //string& erase (size_t pos = 0, size_t len = npos);
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	//因remove_if無法真正刪除元素，只能把要刪除的元素移到容器末並返回要被刪除元素的迭代器，然後通過erase成員函式來真正刪除。
	//remove_if (ForwardIterator first, ForwardIterator last,UnaryPredicate pred);
	int k = str.size()-1;
	int flag = 0;
	for (int i = 0; i < str.size()/2; i++)
	{
		str[i] = tolower(str[i]);
		str[k] = tolower(str[k]);
		if (str[i] != str[k])
		{
			flag = 1;
			break;
		}
		k--;
	}
	(flag == 0 ? cout << "Yes, this is a palindrome." << endl : cout << "No, this is not a palindrome." << endl);
	return 0;	
}