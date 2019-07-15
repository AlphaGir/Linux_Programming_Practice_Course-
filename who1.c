#include<stdio.h>
#include<stdlib.h>
#include<utmp.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#define SHOWHOST
#ifndef UTMP_FILE
#define UTMP_FILE "/var/run/utmp"
#endif
void showtime(long timeval)
{
	char *cp;
	cp=ctime(&timeval);
	printf("%12.12s",cp);
}
void show_info(struct utmp *utbufp)
{
    if(utbufp->ut_type!=USER_PROCESS)
	    return;
    printf("%-8.8s",utbufp->ut_user);
    printf(" ");
    printf("%-8.8s",utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);
    printf("%-8.8s",utbufp->ut_host);
    printf(" ");
    printf("\n");
}

int loggout(char *line)
{
	int out,in;
	
        struct utmp ut;
	int ret=0;
	int len=sizeof(struct utmp);
	if((in=open(UTMP_FILE,O_RDONLY))==-1)
	{
		perror("ERRO:cant open file");
		return 0;
	}
	while(ret=read(in,&ut,len)!=0)
	{
		if(strcmp(ut.ut_user,line)==0)
		{
                    ut.ut_type=DEAD_PROCESS;
		    lseek(in,-len,SEEK_CUR);
		    if(write(in,&ut,len)==len)
                    ret=1;
		    break;
		}
	}
	close(in);
	return ret;
}

	

int main()
{
	struct utmp current_record;
	int utmpfd=-1;
	int reclen=sizeof(current_record);
	if((utmpfd=open(UTMP_FILE,O_RDONLY))==-1)
	{
			perror(UTMP_FILE);
			exit(1);
	}
			
	while(read(utmpfd,&current_record,reclen)==reclen)
	{
	show_info(&current_record);
	}
	//close(utmpfd);
	int r=loggout("lord");
	printf("ret=%d",r);
	return 0;
}

