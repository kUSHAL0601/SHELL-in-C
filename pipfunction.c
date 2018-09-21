#include "pipfunction.h"

void pipfunction()
{
	int SIN,SOUT;
	dup2(0,SIN);
	dup2(1,SOUT);
	char *cmd[150]={NULL};
	int fd[2][2],pipcount=0;
	int temp=i,end=0;
	int in_rdrct=0,out_rdrct=0;
	pid_t pid;
	while(arg[temp][0]!=';')
	{
		if(arg[temp][0]=='|')
			pipcount++;
		else if (arg[temp][0]=='<')
			in_rdrct=temp+1;
		else if (arg[temp][0]=='>')
			out_rdrct=temp+1;
		temp++;
	}
	int k=0,jj=0;
	while(arg[i][0]!=';' && end != 1)
	{
		k=0;
		while(!(arg[i][0]=='|' || arg[i][0]=='<' || arg[i][0]=='>'))
		{
			cmd[k]=arg[i++];
			if(arg[i][0] == ';' || strcmp(arg[i],"")==0 )
			{
				end=1;
				k++;
				break;
			}
			k++;
		}
		i++;
		pipe(fd[jj%2]);

		if(jj==0 && in_rdrct && arg[i-1][0]=='<')
			i+=2;

		if(jj == pipcount && out_rdrct && arg[i-1][0]=='>' )
			i+=2;
		pid=fork();
		
		if(pid==-1){			
			if(jj!=pipcount){
				close(fd[jj%2][1]);
			}			
			printf("Child process could not be created\n");
			return;
		}
		if(pid==0){
			if (jj == 0)
			{
				if(in_rdrct)
				{
					int in=open(arg[in_rdrct],O_RDONLY);
					dup2(in,0);
					close(in);
				}
				dup2(fd[0][1],1);
			}
			else if(jj==pipcount)
			{
				if(out_rdrct)
				{
					int out=open(arg[out_rdrct],O_WRONLY|O_CREAT,0644);
					dup2(out,1);
					close(out);
				}
				dup2(fd[( pipcount + 1 ) % 2 ][0],0);
			}
			else
			{
				dup2(fd[(jj+1)%2][0],0);
				dup2(fd[jj%2][0],1);
			}

			if (execvp(cmd[0],cmd)== -1)
			{
				kill(getpid(),SIGTERM);
			}		
		}
		if(jj==0){
			close(fd[0][1]);
		}
		else if(jj==pipcount)
		{
			close(fd[(pipcount+1)%2][0]);
		}
		else{

			close(fd[(jj+1)%2][0]);
			close(fd[jj%2][1]);
		}

		waitpid(pid,NULL,0);      
		jj++;	
	}
}