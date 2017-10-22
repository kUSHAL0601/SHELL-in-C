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

int main()
{
	getcwd(pr_dir, sizeof(pr_dir));
	while(1)
	{
		int t1,t2;
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
				if(arg[i][0]==';')
					continue;

				if(strcmp(arg[i],"e")==0)
					exit(0);

				else if(strcmp(arg[i],"cd")==0)
				{
					if(arg[i+2][0]==';')
					{
						change_directory();
					}
					else if(arg[i+2][0]=='&')
					{
						int pid = fork();
						if (pid == 0 )
						{
							gen_cd_child();
						}
						else
						{
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
							gen_pwd_child();
						}
						else
						{
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
							gen_echo_child();
						}
						else
						{
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
							gen_ls_child();
						}
						else
						{
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
							gen_pinfo_child();
						}
						else
						{
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
				else
				{
					printf(RED "Enter a valid command" RESET "\n");
					break;
				}
			}

	}
	return 0;
}
