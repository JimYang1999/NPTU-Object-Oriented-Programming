#include <iostream>  
using namespace std;
#include <cstring>   
#include "name.h"
#include "initial.h"

int main()
{
	Name* someone;
	char* name = new char[LenFN + LenLN + 1];

	cout << "Please input your name: ";

	cin.getline(name, LenFN + LenLN);

	someone = setName(name);

	cout << "Your first name is " << someone->firstname << "." << endl;
	cout << "Your last name is " << someone->lastname << "." << endl;
	cout << "The initial of your name is " << initial(someone) << endl;

	return 0;
}
