#include "interrupt.h"
int kbhit2()
{
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(0, &fds);
    return select(1, &fds, NULL, NULL, &tv);
}

int getch2()
{
    int r;
    unsigned char c;
    if ((r = read(0, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

void interrupt()
{
		int pcnt=0;
		int waittime = atoi(arg[i+2]);

		time_t starttime,curtime;
		starttime=time(NULL);

		while(!kbhit2())
		{
		
			while(1)
			{
				curtime = time(NULL);
				if(curtime - starttime >= waittime) 
					break;
			}	

			FILE * fp = fopen("/proc/interrupts","r");
			int	linecount=0;
			while (fgets(line, sizeof(line), fp) != NULL)
			{

				if (strstr(line,"CPU") && pcnt==0)
				{
					printf("%s", line);
					pcnt=1;
				}	
				if (strstr(line,"i8042"))
				{
					printf("%s", line);
					linecount++;
					if (linecount==2)
					{
						break;
					}
				}
			}
			sleep(waittime);
			fclose(fp);
		}
		i+=4;
		(void)getch2();
	
}