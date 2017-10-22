#include "user_input.h"

void user_input()
{
	while(scanf("%c",&a))
		{
			if(a=='\n')
			{
				arg[i][j++]=0;
				arg[++i][0]=';';
				arg[i][1]=0;
				break;
			}
			if(a==' ')
			{
				arg[i][j++]=0;
				i++;
				j=0;
				continue;
			}
			if(a==';')
			{
				arg[i][j++]=0;
				arg[++i][0]=';';
				arg[i][1]=0;
				i++;
				j=0;
				continue;
			}
			if(a=='~')
			{
				for(k=0;k<strlen(pr_dir);k++)
					arg[i][j++]=pr_dir[k];
			}
			else
			{
				arg[i][j++]=a;
			}
		}
	return;
}