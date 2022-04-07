using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include "name.h"
char* initial(Name* n)
{
	int i = 0;
	char* last = new char[20];
	for ( i; i <= strlen(n->lastname); i++)
	{
		if (i == strlen(n->lastname))
		{
			last[i] = ',';
			break;
		}
		last[i] = n->lastname[i];
	}
	i++;
	last[i] = ' ';
	int flag = 0;
	for (int k = 0; k < strlen(n->firstname); k++)
	{
		if (int(n->firstname[k]) != 32 && flag == 0)
		{
			i++;
			last[i] = n->firstname[k];
			i++;
			last[i] = '.';
			flag = 1;
		}
		if (n->firstname[k] == '-')
		{
			i++;
			last[i] = n->firstname[k];
			i++;
			last[i] = n->firstname[k + 1];
			i++;
			last[i] = '.';
			break;
		}
	}
	i++;
	last[i] = '\0';
	return last;
}