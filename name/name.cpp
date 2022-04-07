using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include "name.h"

Name* setName(const char* name)
{
	int temp = 0;
	Name* somebody = new Name;
	while (*name != NULL)
	{
		if (*name == ',')
		{
			name -= temp;
			for (int i = 0; i <= temp; i++)
			{
				if (i == temp)
				{
					somebody->lastname[i] = '\0';
					break;
				}
				somebody->lastname[i] = *name;
				name++;
			}
			name++;
			int i = 0;
			while (*name != '\0')
			{
				somebody->firstname[i] = *name;
				name++;
				i++;
			}
			somebody->firstname[i] = '\0';
			return somebody;
		}
		if (*name == ' ')
		{
			name -= temp;
			for (int i = 0; i <= temp; i++)
			{
				if (i == temp)
				{
					somebody->firstname[i] = '\0';
					break;
				}
				somebody->firstname[i] = *name;
				name++;
			}
			int i = 0;
			while (*name != '\0')
			{
				somebody->lastname[i] = *name;
				name++;
				i++;
			}
			somebody->lastname[i] = '\0';
			return somebody;
		}
		temp++;
		name++;
	}
}