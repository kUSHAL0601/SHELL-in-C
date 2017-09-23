#include "unsetenv.h"

void unset_env()
{
	if(getenv(arg[i+1])==NULL)
		printf(RED "No such enviorment variable" RESET "\n");
	else if(unsetenv(arg[i+1])!=0)
		printf(RED "Unidentified error" RESET "\n");
}