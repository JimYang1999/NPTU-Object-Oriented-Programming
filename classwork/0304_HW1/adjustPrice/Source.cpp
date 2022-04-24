#include<iostream>
using namespace std;
int adjustPrice(int);
int adjustPrice(double);

int main()
{
	double x;
	cin >> x;
	cout<<adjustPrice(x);
}
int adjustPrice(int x)
{
	x = x - x % 10;
	return x;
}
int adjustPrice(double x)
{
	x = int(x) - (int(x) & 10);
	return x;
}