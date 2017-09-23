#include "echo_function.h"

void echo_function()
{
	int lst=i;
	while(1)
	{
		if(arg[lst][0]==';')break;
		else lst++;
	}
	for(k=i+1;k<lst;k++)
	{
		for(j=0;j<strlen(arg[k]);j++)
		{
			if(arg[k][j]!='\"' && arg[k][j]!='\'')
			{
				printf("%c",arg[k][j]);
			}
		}
		printf(" ");
	}
	printf("\n");
	i=lst+1;
	return;
}

void gen_echo_child()
{
	int lst=i-1;
	while(1)
	{
		if(arg[lst][0]==';')break;
		else lst++;
	}
	lst --;
	for(k=i+1;k<lst;k++)
	{
		for(j=0;j<strlen(arg[k]);j++)
		{
			if(arg[k][j]!='\"' && arg[k][j]!='\'')
			{
				printf("%c",arg[k][j]);
			}
		}
		printf(" ");
	}
	printf("\n");
	i=lst+1;
printf(RESET "echo with pid %d exited normally\n" RESET,getpid() );
kill(getpid(),SIGKILL);
ampcount--;
exit(0);
}
