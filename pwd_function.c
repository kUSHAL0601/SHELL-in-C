#include "pwd_function.h"

void pwd_function()
{
	printf("%s\n",pwd);
	i+=1;
	return;
}
void gen_pwd_child()
{
	printf(RESET "%s\n pwd with pid %d exited normally\n" RESET,pwd,getpid() );
	kill(getpid(),SIGKILL);
	ampcount--;
	exit(0);
}