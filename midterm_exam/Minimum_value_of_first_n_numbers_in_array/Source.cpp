#include<iostream>
using namespace std;
#define Size 10
//start
int minValue(int* data, int n = 0)
{
	if (n != 0)
	{
		int min = data[0];
		for (int i = 0; i < n; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}
	else
	{
		int min = data[0];
		for (int i = 0; i < Size; i++)
		{
			if (data[i] < min)
			{
				min = data[i];
			}
		}
		return min;
	}
}
int main()
{
	int data[Size];
	int n;

	for (int i = 0; i < Size; i++)
	{
		cin >> data[i];
	}
	cin >> n;

	if (n < 1)
		cout << minValue(data) << endl;
	else
		cout << minValue(data, n) << endl;
}