#include "change_directory.h"
void change_directory()
{
		char lt[1024]={};
		char gt[1024]={};
		int flag0=0;
		int flag1=0;
		int flag2=0;
		int l=i;
		int out=0;
		int in=0;
/*		while(arg[l][0]!=';')
		{
			if(arg[l][0]=='<' && arg[l][1]!='<' && flag0==0)
				{
					flag0=1;
					strcpy(lt,arg[l+1]);
					l++;
				}
			else if(arg[l][0]=='>'&&arg[l][1]!='>')
				{
			//		out = open(arg[l+1],O_WRONLY|O_CREAT,0644);
					flag1++;
					strcpy(gt,arg[l+1]);
					l++;
				}
			else if(arg[l][0]=='>'&&arg[l][1]=='>')
				{
					flag2++;
					strcpy(gt,arg[l+1]);
					l++;
				}
			l++;
		}
		printf("%d %d %d %s %s\n",flag0,flag1,flag2,lt,gt);
*/
		if(strcmp(arg[i+1],"~")==0)
			chdir(pr_dir);
		else if(chdir(arg[i+1])==0)
			getcwd(pwd, sizeof(pwd));
		else
			printf(RED "Error:Enter valid directory" RESET "\n");
		i+=2;
	return;
}
void gen_cd_child()
{
			if(strcmp(arg[i+1],"~")==0)
			{
				chdir(pr_dir);
				printf(RESET "cd with pid %d exited normally\n" RESET,getpid() );
			}
			else if(chdir(arg[i+1])==0)
			{
				getcwd(pwd, sizeof(pwd));
				printf(RESET "cd with pid %d exited normally\n" RESET,getpid() );
			}
			else
			{
				printf(RED "Error:Enter valid directory" RESET "\n");
			}
			i+=2;
			kill(getpid(),SIGKILL);
			ampcount--;
			exit(0);
}