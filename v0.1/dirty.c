#include "dirty.h"
int kbhit()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

void dirty()
{
	if(strcmp(arg[i+1],"-n")!=0 || arg[i+2][0]==';' || arg[i+3][0]==';')
	{
		printf("Invalid Input\n Proper format is:\t nightswatch -n [seconds] [command]\n");
		if(arg[i+1][0]==';')i+=1;
		else if(arg[i+2][0]==';')i+=2;
		else if(arg[i+3][0]==';')i+=3;
	}
	else if(strcmp(arg[i+3],"dirty")!=0 && strcmp(arg[i+3],"interrupt")!=0)
	printf("command can be either 'dirty' or 'interrupt'\n");
	else
	{
		int waittime = atoi(arg[i+2]);
		//printf("%d\n",waittime);
		time_t starttime,curtime;
		starttime=time(NULL);
		while(!kbhit())
		{
			//printf("HERE\n");
			while(1)
			{
				curtime = time(NULL);
				if(curtime - starttime >= waittime)
					break;
				//printf("TIME CHECK\n");

			}	
		//	printf("HERE2\n");		
			FILE * fp = fopen("/proc/meminfo","r");
			int	linecount=1;
			while (fgets(line, sizeof(line), fp) != NULL)
			{   
				if (linecount==17)
				{
					printf("%s", line);
					break;
				}
				linecount++;
			}
				sleep(waittime);
				fclose(fp);
		}
		while(arg[i][0]!=';')i+=1;
		(void)getch();
	}
}
