#include "setenv.h"

void set_env()
{
	if(getenv(arg[i+1])==NULL)
		setenv(arg[i+1],"",1);

	if(arg[i+2][0]==';')
		setenv(arg[i+1],"",1);
	else
		setenv(arg[i+1],arg[i+2],1);

}