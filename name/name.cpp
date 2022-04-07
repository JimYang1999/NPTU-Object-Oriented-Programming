using namespace std;
#include <iostream>
#include <cstring>
#include <string>
#include "name.h"

Name* setName(const char* name)
{
	int temp = 0;
	int score = 0;
	Name* somebody = new Name;
	while (*name != '\0')
	{
		if (*name == ' ')score += 1;
		if (*name == ',')score += 50;
		if (*name == '-')score += 100;
		temp++;
		name++;
		//Jun Wu  =1
		//Wu, Jun =51
		//Yo-Yo Ma = 101
		//Ma, Yo-Yo 151
	}
	name -= temp;
	if (score == 1)//Jun Wu
	{
		int flag = 0;
		int i = 0;
		while (*name != '\0')
		{
			if (flag == 0)
			{
				somebody->firstname[i] = *name;
				if (*name == ' ')
				{
					somebody->firstname[i] = '\0';
					flag = 1;
					i = 0;
					name++;
				}
			}
			if (flag == 1)//lastname
			{
				somebody->lastname[i] = *name;
			}
			i++;
			name++;
		}
		somebody->lastname[i] = '\0';
		return somebody;
	}
	if (score == 51)//Wu, Jun  last,first
	{
		int flag = 0;
		int i = 0;
		while (*name != '\0')
		{
			if (flag == 0)//last
			{
				if (*name == ',')
				{
					flag = 1;
					somebody->lastname[i] = '\0';
					i = 0;
					name++;
				}
				else
				{
					somebody->lastname[i] = *name;
				}
			}
			if (flag == 1)//first
			{
				somebody->firstname[i] = *name;
			}
			i++;
			name++;
		}
		somebody->firstname[i] = '\0';
		return somebody;
	}
	if (score == 101) //Yo-Yo Ma first , last
	{
		int i = 0;
		int flag = 0;
		while (*name != '\0')
		{
			if (flag == 0)
			{
				if (*name == ' ')
				{
					somebody->firstname[i] = '\0';
					flag = 1;
					i = 0;
				}
				else
				{
					somebody->firstname[i] = *name;
				}
			}
			if (flag == 1)
			{
				somebody->lastname[i] = *name;
			}
			name++;
			i++;
		}
		somebody->lastname[i] = '\0';
		return somebody;
	}
	if (score == 151)
	{
		int i = 0;
		int flag = 0;
		while (*name != '\0') //Ma, Yo-Yo last,first
		{
			if (flag == 0)
			{
				if (*name == ',')
				{
					somebody->lastname[i] = '\0';
					i = 0;
					flag = 1;
					name++;
				}
				else
				{
					somebody->lastname[i] = *name;
				}
			}
			if (flag == 1)
			{
				somebody->firstname[i] = *name;
			}
			i++;
			name++;
		}
		somebody->firstname[i] = '\0';
		return somebody;
	}
}