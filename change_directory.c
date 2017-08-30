#include "change_directory.h"
void change_directory()
{
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