#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int main(int argc,char *argv[])
{
DIR *dip;
struct dirent *dit;

int i=0;

	if ( (dip=opendir(argv[1]))==NULL)
	{
		perror("opendir");
		return 0;
	}
	while( (dit=readdir(dip)) != NULL)
	{
		if(dit->d_type == DT_REG)
		{
		i++;
		printf("\n%s",dit->d_name);
		}
	}
		if ( closedir(dip)==-1)
	{
		perror("closedir");
		return 0;
	}
		return 1;

}