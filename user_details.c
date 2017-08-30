#include "user_details.h"

void user_details()
{
	if (pw)
		{
			printf(CYAN "<%s@" RESET,pw->pw_name);
		}
		else 
		{
			printf(CYAN "<Anonymous@" RESET);
		}
		uname(&unm);
		printf(CYAN "%s:" RESET,unm.sysname);
		if (getcwd(pwd, sizeof(pwd)) != NULL)
		{
			if(strcmp(pr_dir,pwd)==0)
				printf(CYAN "~>" RESET);
			else
				printf(CYAN "%s>" RESET,pwd);
		}
	return;
}
