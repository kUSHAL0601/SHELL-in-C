#include "pinfo_function.h"
void pinfo_function()
{
	memset(new_dir,'\0',2000);
	memset(exec_path,'\0',2000);
	memset(exec,'\0',2000);
	memset(procid,'\0',20);
	memset(line,'\0',1000);
	new_dir[0]='/';new_dir[1]='p';new_dir[2]='r';new_dir[3]='o';new_dir[4]='c';new_dir[5]='/';
	int cur_size=6;
	int ld=0;
	int size=0;
	if(arg[i+2][0]==';')
	{
		strcpy(procid,arg[i+1]);
		size=strlen(procid);
		strcat(new_dir,procid);
		i+=2;
	}
	else
	{
		int temp_uid=getpid();
		while(temp_uid!=0)
		{
			ld=temp_uid%10;
			temp_uid/=10;
			procid[size++]=ld+48;
		}

		size-=1;
		while(size>=0)
		{
			new_dir[cur_size++]=procid[size--];
		}
		i+=1;
	}
	strcpy(exec_path,new_dir);
	strcat(exec_path,"/exe");
	strcat(new_dir,"/status");
	FILE *file=fopen(new_dir,"r");
	if(!file)
	{
		printf(RED "Process doesn't exsist" RESET "\n");
		return;
	}
	int count=1;
	while (fgets(line, sizeof line, file) != NULL)
	{   
		if ( strstr(line,"Name:") || strstr(line,"State:") || (strstr(line,"Pid:") && !strstr(line,"TracerPid:")) || strstr(line,"PPid:"))
			printf("%s", line);
		count++;
	}
	struct rusage usage;
	readlink(exec_path,exec,sizeof(exec));
	getrusage(RUSAGE_SELF,&usage);
	printf("Executable Path: %s\n",exec);
	printf("Memory Usage %ld\n",usage.ru_maxrss);
	fclose(file);
	return;
}
void gen_pinfo_child()
{
	memset(new_dir,'\0',2000);
	memset(exec_path,'\0',2000);
	memset(exec,'\0',2000);
	memset(procid,'\0',20);
	memset(line,'\0',1000);
	new_dir[0]='/';new_dir[1]='p';new_dir[2]='r';new_dir[3]='o';new_dir[4]='c';new_dir[5]='/';
	int cur_size=6;
	int ld=0;
	int size=0;
	if(arg[i+3][0]==';')
	{
		strcpy(procid,arg[i+1]);
		size=strlen(procid);
		strcat(new_dir,procid);
		i+=2;
	}
	else
	{
		int temp_uid=getpid();
		while(temp_uid!=0)
		{
			ld=temp_uid%10;
			temp_uid/=10;
			procid[size++]=ld+48;
		}

		size-=1;
		while(size>=0)
		{
			new_dir[cur_size++]=procid[size--];
		}
		i+=1;
	}
	strcpy(exec_path,new_dir);
	strcat(exec_path,"/exe");
	strcat(new_dir,"/status");
	FILE *file=fopen(new_dir,"r");
	if(!file)
	{
		printf(RED "Process doesn't exsist" RESET "\n");
		printf(RESET "pinfo with pid %d exited with error\n" RESET,getpid() );
		kill(getpid(),SIGKILL);
		ampcount--;
		exit(0);
	}
	int count=1;
	while (fgets(line, sizeof line, file) != NULL)
	{   
		if ( strstr(line,"Name:") || strstr(line,"State:") || (strstr(line,"Pid:") && !strstr(line,"TracerPid:")) || strstr(line,"PPid:"))
			printf("%s", line);
		count++;
	}
	struct rusage usage;
	readlink(exec_path,exec,sizeof(exec));
	getrusage(RUSAGE_SELF,&usage);
	printf("Executable Path: %s\n",exec);
	printf("Memory Usage %ld\n",usage.ru_maxrss);
	fclose(file);
	printf(RESET "pinfo with pid %d exited normally\n" RESET,getpid() );
	kill(getpid(),SIGKILL);
	ampcount--;
	exit(0);
}