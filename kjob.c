#include "kjob.h"

void kjob()
{
	if (arg[i+1][0]==';' || arg[i+2][0]==';')
	{
		printf("Use kjob in a proper format \nkjob <jobnumber> <signal-number>\n");
	}

	else
	{
		int jbn=atoi(arg[i+1]);
		int signum=atoi(arg[i+2]);
		int d=1,entered=0;
		char * line = NULL;
		char *temp;
		int pid;
		char *forexe[100]={NULL};
		char cmd[100]={};
		char pidst[100]={};
		size_t len = 0;
		ssize_t read;
		FILE *fptr=fopen("jobs.txt","r");
		
		while ((read = getline(&line, &len, fptr)) != -1) 
    	{
	    if(d==2*jbn)
	    {
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
	    		//printf("%c\n",temp[r]);
	    		pidst[y]=temp[r];
	    		y++;r++;
	    	}
			pid=atoi(pidst);
			kill(pid,signum);
			break;
	    }
	    d++;
    }
    fclose(fptr);
	}
	while(arg[i][0]!=';')
	{
		i++;
	}

}