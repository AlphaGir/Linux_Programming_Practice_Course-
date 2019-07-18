#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include<dirent.h>
ino_t get_inode(char * fname);
int main()
{
	int re=-2;
	int re1=-2;
	ino_t t,t1;
	t=get_inode(".");
	t1=get_inode("..");
	DIR *dir_ptr;
	struct dirent *dirent;
	while(t1!=t)
	{
		chdir("..");

		if((dir_ptr=opendir("."))!=NULL)
		{
			while((dirent=readdir(dir_ptr))!=NULL)
			{
			       if(dirent->d_ino==t)	
			       {
				       printf("/%s\n",dirent->d_name);
				       closedir(dir_ptr);
				       break;
			       }
			}
		
		}
		else
		{
			
			perror(".");
			exit(1);
		}
                t1=get_inode("..");
                t=get_inode(".");


	}
}
ino_t get_inode(char * fname)
{
	struct stat info;
	if(stat(fname,&info)==-1)
	{
		perror(fname);
		exit(1);
	}
	return info.st_ino;
}
