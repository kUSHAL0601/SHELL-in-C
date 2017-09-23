#include "redirect.h"

void redirect()
{
	int saved_stdout;
	int saved_stdin;
	saved_stdout = dup(1);
	saved_stdin=dup(0);
	int lt=-1;
	int gt=-1;
	int a=0;
	int rndm=i;
	int error=0;
	char* forexe[101]={NULL};
	int fx=0;
	while(arg[rndm][0]!=';')
	{
		if(arg[rndm][0]=='<')
		{
			lt=rndm;
			FILE* f1=fopen(arg[rndm+1],"r");
			if(!f1)error=1;
			else {
				fclose(f1);
			}
			rndm++;			
		}
		else if(arg[rndm][0]=='>')
		{
			gt=rndm;
			if(arg[rndm][1]=='>')
			{
				a=1;
				FILE* f1=fopen(arg[rndm+1],"a");
				if(!f1)error=1;
				else fclose(f1);
				rndm++;
			}
			else
			{
				a=0;
				FILE* f1=fopen(arg[rndm+1],"w");
				if(!f1)error=1;
				else fclose(f1);
				rndm++;
			}
		}
		else if(arg[rndm][0]!='&')
			forexe[fx++]=arg[rndm];
		rndm++;
	}
	if(error==1)
	{
		printf(RED "No such file exsists" RESET "\n");
		return;
	}
	int in,out,status;
	if(lt>=0)
	{
	in = open(arg[lt+1],O_RDONLY);
		dup2(in,0);
		char ar[1000];
		scanf("%s",ar);
		int x,z,asd=0;
		char temp[10000];
		for(z=0;z<strlen(ar);z++)
		{
			if(ar[z]=='~')
			{
				for(x=0;x<strlen(pr_dir);x++)
					temp[asd++]=pr_dir[x];
			}
			else
				temp[asd++]=ar[z];
		}
		forexe[fx++]=temp;
		close(in);
	}
	if(gt>=0)
	{
	out = open(arg[gt+1],O_WRONLY | O_APPEND);
		dup2(out,1);
		close(out);
	}
	pid_t pid;
	if((pid=fork())==0)
	{
		if(execvp(forexe[0],forexe)==-1)
		{
			printf(RED "Not a valid command" RESET "\n");
			kill(getpid(),SIGKILL);
		}
		close(0);
		close(1);
	}
	else
	{
	while(wait(&status)!=pid);
	printf("%s exited\n",forexe[0]);
	dup2(saved_stdout, 1);
	close(saved_stdout);
	dup2(saved_stdin, 0);
	close(saved_stdin);
	while(arg[i][0]!=';')
		i++;

	}
}