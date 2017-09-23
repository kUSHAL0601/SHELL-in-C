#include "bg.h"
#include "jobs.h"

void tostr(char str[], int num)
{
   int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}


void bg(char* jobno)
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
			tostr(pidst,pid);
			kill(pid,SIGKILL);
			pid_t abc;
			abc=fork();
			if(abc==0)
			{
				addtojobs(getpid(),forexe[0]);
				int err=execvp(forexe[0],forexe);
				if (err==-1)
				{
					printf(RED "Enter a valid command" RESET "\n");
					kill(getpid(),9);
				}
			}
			break;
	    }
	    d++;
    }
    if(entered==0)
    	printf(RED "Enter a valid job no" RESET "\n");

};
