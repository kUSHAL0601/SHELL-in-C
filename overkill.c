#include "overkill.h"

void overkill()
{
	int d=1,entered=0;
	char * line = NULL;
	char temp2[256]="/proc/\0";
	int pid;
	char *forexe[100]={NULL};
	char cmd[100]={};
	char pidst[100]={};
	size_t len = 0;
	ssize_t read;
	FILE *fptr=fopen("jobs.txt","r");
	
	while ((read = getline(&line, &len, fptr)) != -1) 
    {
	char temp2[256]="/proc/\0";
    	if(d%2==0)
    	{
		char *temp;
    	entered=1;
    	int r=0;
    	temp=line;
    	while(temp[r]!='[')
    	{
    		cmd[r]=temp[r];
    		r++;
    	}

    	forexe[0]=cmd;
    	int y=0;
    	r++;

    	while(temp[r]!=']')
    	{
    		pidst[y]=temp[r];
    		y++;r++;
    	}
		pid=atoi(pidst);
		strcat(temp2,pidst);
		strcat(temp2,"/status");
		if(fopen(temp2,"r"))
			kill(pid,9);
		}
		d++;
    }
	
	while(arg[i][0]!=';')
	{
		i++;
	}
	fclose(fptr);
}
