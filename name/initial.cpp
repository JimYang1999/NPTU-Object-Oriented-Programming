using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include "name.h"
char* initial(Name* n)
{
	char* last = new char[20];
	for (int i = 0; i < strlen(n->lastname); i++)
	{
		last[i] = n->lastname[i];
	}
	return last;
}