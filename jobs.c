#include "jobs.h"

void tostring(char str[], int num)

{
   int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

void addtojobs(int pid,char* cname)
{
		memset(new_dir,'\0',2000);
		memset(exec_path,'\0',2000);
		memset(exec,'\0',2000);
		memset(procid,'\0',20);
		memset(line,'\0',1000);
		new_dir[0]='/';new_dir[1]='p';new_dir[2]='r';new_dir[3]='o';new_dir[4]='c';new_dir[5]='/';
		int cur_size=6;
		int ld=0;
		char snum[10]={};
		tostring(snum,pid);
		strcat(new_dir,snum);
		strcpy(exec_path,new_dir);
		strcat(exec_path,"/exe");
		FILE *fl=fopen(new_dir,"r");
		FILE *fptr=fopen("jobs.txt","a");
		if(fl && fptr)
		{
			fprintf(fptr,"%s\n", new_dir);
			fprintf(fptr, "%s[%d]\n", cname,pid);
		}
		fclose(fptr);
		fclose(fl);
	return;
}

void jobs()
{
	int count=0;
	char * line = NULL;
    size_t len = 0;
    ssize_t read;
	FILE *fptr=fopen("jobs.txt","r");
    while ((read = getline(&line, &len, fptr)) != -1) 
    {
    if(count%2==0)
    {
    	printf("[%d] ",(count/2)+1);
		DIR* dir = opendir(line);
	    if(dir)
	    	printf("Running ");
	    else
	    	printf("Stopped ");
	    closedir(dir);
	    count++;
    }
    else
    {
    	printf("%s",line);
    	count++;
    }
    }
    fclose(fptr);
    if (line)
        free(line);
};