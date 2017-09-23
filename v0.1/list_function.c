#include "list_function.h"

void list_function()
{
	if(mydir==NULL)
	{
		printf(RED "Error: Directory doesn't exsist\n" RESET);
	}
	else
	{
		long long int total=0;
		closedir(mydir1);
		while((entry=readdir(mydir))!=NULL)
		{
			stat(entry->d_name,&sb1);
			if(hid==1)
			{
				if(lng==1)
				{

					if(sb1.st_mode & S_IRUSR)
						printf("r");
					else
						printf("-");
					if(sb1.st_mode & S_IWUSR)
						printf("w");
					else
						printf("-");
					if(sb1.st_mode & S_IXUSR)
						printf("x");
					else
						printf("-");

					if(sb1.st_mode & S_IRGRP)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWGRP)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXGRP)
						printf("x");
					else
						printf("-");


					if(sb1.st_mode & S_IROTH)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWOTH)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXOTH)
						printf("x");
					else
						printf("-");

					printf(" ");

					printf("%ld ",(long)sb1.st_nlink);
					uidnm=getpwuid((long) sb1.st_uid);
					gidnm=getgrgid((long) sb1.st_gid);
					printf("%s %s ",uidnm->pw_name,gidnm->gr_name);
					printf("%lld ",(long long)sb1.st_size);
					strcpy(modified,ctime(&sb1.st_mtime));
					for(j=0;j<strlen(modified);j++)
						if(modified[j]!='\n')
							printf("%c",modified[j]);
					printf(" ");

				}
				if(entry->d_type==8)
					printf(GREEN "%s\n" RESET,entry->d_name);
				else
					printf(YELLOW "%s\n" RESET,entry->d_name);
			}
			else if(hid==0 && (entry->d_name)[0]!='.')
			{
				if(lng==1)
				{

					if(sb1.st_mode & S_IRUSR)
						printf("r");
					else
						printf("-");
					if(sb1.st_mode & S_IWUSR)
						printf("w");
					else
						printf("-");
					if(sb1.st_mode & S_IXUSR)
						printf("x");
					else
						printf("-");

					if(sb1.st_mode & S_IRGRP)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWGRP)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXGRP)
						printf("x");
					else
						printf("-");


					if(sb1.st_mode & S_IROTH)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWOTH)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXOTH)
						printf("x");
					else
						printf("-");

					printf(" ");

					printf("%ld ",(long)sb1.st_nlink);
					uidnm=getpwuid((long) sb1.st_uid);
					gidnm=getgrgid((long) sb1.st_gid);
					printf("%s %s ",uidnm->pw_name,gidnm->gr_name);
					printf("%lld ",(long long)sb1.st_size);
					strcpy(modified,ctime(&sb1.st_mtime));
					for(j=0;j<strlen(modified);j++)
						if(modified[j]!='\n')
							printf("%c",modified[j]);
					printf(" ");

				}
				if(entry->d_type==8)
					printf(GREEN "%s\n" RESET,entry->d_name);
				else
					printf(YELLOW "%s\n" RESET,entry->d_name);
			}
		}

		closedir(mydir);
	}
	return;
}
void gen_ls_child()
{
	int suc=0;
	if(mydir==NULL)
	{
		suc=1;
		printf(RED "Error: Directory doesn't exsist\n" RESET);
	}
	else
	{
		long long int total=0;
		closedir(mydir1);
		while((entry=readdir(mydir))!=NULL)
		{
			stat(entry->d_name,&sb1);
			if(hid==1)
			{
				if(lng==1)
				{

					if(sb1.st_mode & S_IRUSR)
						printf("r");
					else
						printf("-");
					if(sb1.st_mode & S_IWUSR)
						printf("w");
					else
						printf("-");
					if(sb1.st_mode & S_IXUSR)
						printf("x");
					else
						printf("-");

					if(sb1.st_mode & S_IRGRP)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWGRP)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXGRP)
						printf("x");
					else
						printf("-");


					if(sb1.st_mode & S_IROTH)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWOTH)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXOTH)
						printf("x");
					else
						printf("-");

					printf(" ");

					printf("%ld ",(long)sb1.st_nlink);
					uidnm=getpwuid((long) sb1.st_uid);
					gidnm=getgrgid((long) sb1.st_gid);
					printf("%s %s ",uidnm->pw_name,gidnm->gr_name);
					printf("%lld ",(long long)sb1.st_size);
					strcpy(modified,ctime(&sb1.st_mtime));
					for(j=0;j<strlen(modified);j++)
						if(modified[j]!='\n')
							printf("%c",modified[j]);
					printf(" ");

				}
				if(entry->d_type==8)
					printf(GREEN "%s\n" RESET,entry->d_name);
				else
					printf(YELLOW "%s\n" RESET,entry->d_name);
			}
			else if(hid==0 && (entry->d_name)[0]!='.')
			{
				if(lng==1)
				{

					if(sb1.st_mode & S_IRUSR)
						printf("r");
					else
						printf("-");
					if(sb1.st_mode & S_IWUSR)
						printf("w");
					else
						printf("-");
					if(sb1.st_mode & S_IXUSR)
						printf("x");
					else
						printf("-");

					if(sb1.st_mode & S_IRGRP)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWGRP)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXGRP)
						printf("x");
					else
						printf("-");


					if(sb1.st_mode & S_IROTH)
						printf("r");
					else
						printf("-");

					if(sb1.st_mode & S_IWOTH)
						printf("w");
					else
						printf("-");

					if(sb1.st_mode & S_IXOTH)
						printf("x");
					else
						printf("-");

					printf(" ");

					printf("%ld ",(long)sb1.st_nlink);
					uidnm=getpwuid((long) sb1.st_uid);
					gidnm=getgrgid((long) sb1.st_gid);
					printf("%s %s ",uidnm->pw_name,gidnm->gr_name);
					printf("%lld ",(long long)sb1.st_size);
					strcpy(modified,ctime(&sb1.st_mtime));
					for(j=0;j<strlen(modified);j++)
						if(modified[j]!='\n')
							printf("%c",modified[j]);
					printf(" ");

				}
				if(entry->d_type==8)
					printf(GREEN "%s\n" RESET,entry->d_name);
				else
					printf(YELLOW "%s\n" RESET,entry->d_name);
			}
		}

		closedir(mydir);
	}
	if(suc==0)
	{
	printf(RESET "ls with pid %d exited normally\n" RESET,getpid() );
	}
	kill(getpid(),SIGKILL);
	ampcount--;
	exit(0);
}