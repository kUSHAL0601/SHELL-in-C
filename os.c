#include "global.h"
#include "change_directory.h"
#include "echo_function.h"
#include "user_details.h"
#include "list_function.h"
#include "user_input.h"
#include "pwd_function.h"
#include "pinfo_function.h"
#include "dirty.h"
#include "interrupt.h"
#include "setenv.h"
#include "unsetenv.h"
#include "jobs.h"
#include "redirect.h"
#include "ampfunction.h"
#include "pipfunction.h"
#include "kjob.h"
#include "bg.h"
#include "fg.h"
#include "overkill.h"

volatile int gTerminate = 0;
volatile int gTerminate1 = 0;

void SIGTSTP_handler(int signal_num)
{
	printf("CZ PRESSED\n");
	if(signal_num == SIGTSTP)
	{
		if(fork()==0)
		{
			gTerminate1=1;
			signal(SIGTSTP,&SIGTSTP_handler);
		}
		else
		{
			gTerminate=0;
			gTerminate1=0;
		}
	}


}

void sigkill(int p)
{
//    printf("HERE\n");
    if(fork()==0)
    {
    gTerminate = 1;
   	signal(SIGINT, &sigkill);
    }
    else
    {
    	gTerminate=0;
    	gTerminate1=0;
	}
 //   signal(SIGINT, &sigkill);  
}

int main()
{
	signal(SIGINT, sigkill);
	oin=dup(0);
	oout=dup(1);
	FILE *a=fopen( "jobs.txt","w" );
	fclose(a);
	getcwd(pr_dir, sizeof(pr_dir));
	while(gTerminate==0 && gTerminate1==0)
	{
		int t1=0,t2=0;
		for(t1=0;t1<100;t1++)
			for(t2=0;t2<1024;t2++)
				arg[t1][t2]=0;
		ampcount=0;
		uid = geteuid ();
		pw = getpwuid (uid);
				
		user_details();
		
		i=0,j=0;

		user_input();
		
		int len=i;
		
		for(i=0;i<=len;i++)
			
			if(strcmp(arg[i],"")!=0)
			{
				int redi=i,red=0;
				int pipflag=0;
				int pipc=i;
				
				while(arg[pipc][0]!=';')
				{
					if(arg[pipc][0]=='|')
					{
						pipflag=1;
						break;
					}
					pipc++;
				}

				while(arg[redi][0]!=';' && pipflag!=1)
				{
					if(arg[redi][0]=='<' || arg[redi][0]=='>')
					{
						red=1;
						break;
					}
					redi++;
				}
				
				if(arg[i][0]==';')
					continue;

				if(strcmp(arg[i],"quit")==0)
					exit(0);
				
				if(pipflag==1)
				{
					pipfunction();
				}
				
				else if(red==1)
				{
					if(ampcount==0)
					{
						redirect();
					}
					else
					{
						pid_t pidr=fork();
						if(pidr==0)
						{
							redirect();
							addtojobs(getpid(),arg[i]);
							kill(getpid(),SIGKILL);
						}
					}
				}
				
				else if(strcmp(arg[i],"cd")==0)
				{
					int ampflag=0;
					int j=i;
					while(arg[j][0]!=';')
					{
						if(arg[j][0]=='&')
							ampflag=1;
						j++;
					}
					if(ampflag==0)
					{
						change_directory();
					}
					else if(ampflag==1)
					{
						int pid = fork();
						if (pid == 0 )
						{
							addtojobs(getpid(),arg[i]);
							gen_cd_child();
						}
						else
						{
							wait(NULL);
							while(arg[i+1][0]!=';'){i++;}
							continue;
						}
					}
					else
						printf(RED "Error:Expected format cd <dirname>" RESET "\n");
				}
				
				else if(strcmp(arg[i],"pwd")==0)
				{
					if(arg[i+1][0]==';')
					{
						pwd_function();
					}
					else if(arg[i+1][0]=='&')
					{
						int pid = fork();
						if (pid == 0 )
						{
							addtojobs(getpid(),arg[i]);
							gen_pwd_child();
						}
						else
						{
							wait(NULL);
							while(arg[i+1][0]!=';'){i++;}
							continue;
						}
					}
				}

				else if(strcmp(arg[i],"echo")==0)
				{
					int ap=0;
					int ed=i+1;
					while(1)
					{
						if(arg[ed][0]=='&')
						{
							ap++;
						}
						if(arg[ed][0]==';')
							break;
						ed++;
					}
					if(ap==0)
					{
					echo_function();
					}
					else if(ap==1)
					{
						int pid = fork();
						if (pid == 0 )
						{
							addtojobs(getpid(),arg[i]);
							gen_echo_child();
						}
						else
						{
							wait(NULL);
							while(arg[i+1][0]!=';'){i++;}
							continue;
						}
					}
					else
					{
						printf(RED "Expected format echo <string> &(optional)" RESET "\n");
					}
				}

				else if(strcmp(arg[i],"ls")==0)
				{
					int oi=i;
					hid=0,lng=0,ap=0;
					if(arg[i+1][0]==';')
					{
						mydir=opendir(pwd);
						mydir1=opendir(pwd);
						i++;
					}
					else
					{
						int count=0;
						while(arg[i+1][0]!=';')
						{
							if(arg[i+1][0]=='-')
							{
								for(j=0;j<strlen(arg[i+1]);j++)
								{
									if(arg[i+1][j]=='a')
										hid=1;
									if(arg[i+1][j]=='l')
										lng=1;
								}
							}
							else if(arg[i+1][0]=='&')
								ap=1;
							else
							{
								count++;
								mydir=opendir(arg[i+1]);
								mydir1=opendir(arg[i+1]);
							}
							i++;
						}
							if(count==0)
								mydir=opendir(pwd);
							mydir1=opendir(pwd);
					}
					if(ap==0)
					{
						list_function();
					}
					else
					{
						int pid = fork();
						if (pid == 0 )
						{
							addtojobs(getpid(),arg[oi]);
							gen_ls_child();
						}
						else
						{
							wait(NULL);
							while(arg[i+1][0]!=';'){i++;}
							continue;
						}
					}
				}
				
				else if(strcmp(arg[i],"pinfo")==0)
				{
					if(arg[i+1][0]=='&' || arg[i+2][0]=='&')
					{
						int pid = fork();
						if (pid == 0 )
						{
							addtojobs(getpid(),arg[i]);
							gen_pinfo_child();
						}
						else
						{
							wait(NULL);
							while(arg[i+1][0]!=';'){i++;}
							continue;
						}
					}
					else
						pinfo_function();
				}
				
				else if(strcmp(arg[i],"nightswatch")==0)
				{
					if(strcmp(arg[i+1],"-n")!=0 || arg[i+2][0]==';' || arg[i+3][0]==';')
					{
						printf(RED "Invalid Input\n Proper format is:\t nightswatch -n [seconds] [command]" RESET "\n");
						if(arg[i+1][0]==';')i+=1;
						else if(arg[i+2][0]==';')i+=2;
						else if(arg[i+3][0]==';')i+=3;
					}
		
					else if(strcmp(arg[i+3],"dirty")!=0 && strcmp(arg[i+3],"interrupt")!=0)
						printf(RED "command can be either 'dirty' or 'interrupt'" RESET "\n");
		
					else if(strcmp(arg[i+3],"dirty")==0)
						dirty();
		
					else if(strcmp(arg[i+3],"interrupt")==0)
						interrupt();

				}
				
				else if(strcmp(arg[i],"setenv")==0)
				{
					if(arg[i+2][0]==';' || arg[i+3][0]==';')
						set_env();
					else
						printf(RED "Expected format setenv varname [value]" RESET "\n");
					while(arg[i][0]!=';')
						i++;
				}
				
				else if(strcmp(arg[i],"unsetenv")==0)
				{
					if(arg[i+2][0]==';')
						unset_env();
					else
						printf(RED "Expected format unsetenv varname" RESET "\n");
					while(arg[i][0]!=';')
						i++;
				}
				
				else if(strcmp(arg[i],"jobs")==0)
				{
					if(arg[i+1][0]==';')
						jobs();
					else
						printf(RED "Expected format jobs" RESET "\n");
					while(arg[i][0]!=';')
						i++;
				}
				
				else if(strcmp(arg[i],"kjob")==0)
				{
					kjob();
				}
				
				else if(strcmp(arg[i],"overkill")==0)
				{
					if (arg[i+1][0]==';')
					{
						overkill();
					}
					else
					{
						printf("Format for OverKill\noverkill\n");
					}
				}

				else
				{
					char *cmd[105]={NULL};
					int cmdindex=0;
					int amppflag=0;
					while (arg[i][0] != ';' )
					{
						if (arg[i][0] == '&')
						{
							amppflag=1;
							break;
						}
						cmd[cmdindex++] = arg[i++];
					}
					ampfunction(amppflag,cmd);
				}
			}

	}
	return 0;
}