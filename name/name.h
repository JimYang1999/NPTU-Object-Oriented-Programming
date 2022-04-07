#define LenFN 20
#define LenLN 10

#ifndef STRUCT_NAME
#define STRUCT_NAME

struct Name
{
	char firstname[LenFN + 1];
	char lastname[LenLN + 1];
};

Name* setName(const char* name);

#endif
