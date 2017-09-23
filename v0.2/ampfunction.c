#include "ampfunction.h"

void ampfunction(int flag,char **cmd)
{
//	printf("%s %s\n",cmd[0],cmd[1]);
//	printf("%d\n",flag);
	if (flag==0)
	{
		int status;
//		printf("%s\n","\nhere" );
		pid_t tpid = fork();
		if (tpid==0)
		{
				int err=execvp(cmd[0],cmd);
				if (err==-1)
				{
					printf(RED "Enter a valid command" RESET "\n");
					kill(getpid(),9);
				}
		}
		else
		{
			fgpid=tpid;
			while(wait(&status)!=tpid);
			printf("%s exited\n",cmd[0]);

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