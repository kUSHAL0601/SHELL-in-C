#include "ampfunction.h"
#include "jobs.h"
void ampfunction(int flag,char **cmd)
{
	if (flag==0)
	{
		int status;
		pid_t tpid = fork();
		if (tpid==0)
		{
				// printf("%s\n",cmd[0]);
				int err=execvp(cmd[0],cmd);
				if (err==-1)
				{
					printf(RED "Enter a valid command" RESET "\n");
					
					kill(getpid(),9);
				}
		}
		else
		{
			while(wait(&status)!=tpid);
			//kill(tpid,SIGTERM);
		}
	}
	else
	{
		int tpid = fork();
		if (tpid == 0)
		{
			addtojobs(getpid(),cmd[0]);
			int err = execvp(cmd[0], cmd);
			if (err == -1)
			{
				printf(RED "Enter a valid command" RESET "\n");
				kill(getpid(),9);
			}
		}
	}
}