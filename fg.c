#include "fg.h"
#include "bg.h"

void fg(char* jobno)
{
int jbn=atoi(jobno);
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
			//tostr(pidst,pid);
			kill(pid,SIGKILL);
			pid_t abc;
			int status;
			abc=fork();
			if(abc==0)
			{
				int err=execvp(forexe[0],forexe);
				if (err==-1)
				{
					printf(RED "Enter a valid command" RESET "\n");
					kill(getpid(),9);
				}
			}
			else
			{
				while(wait(&status)!=abc);
				printf("%s exited\n",forexe[0]);
				return;
			}
			break;
	    }
	    d++;
    }
    if(entered==0)
    	printf(RED "Enter a valid job no" RESET "\n");

}