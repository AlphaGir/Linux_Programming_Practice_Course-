/*
 *拷贝文件 cp source-file target-file
 *
 */
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#define BUFF 4096
#define COPYMODE 0644
void oops(char *s1,char *s2);
int main(int avg,char *avgs[])
{
    int in_fd,out_fd,n;
    char buf[BUFF];
    if(avg!=3)
    {
	    fprintf(stderr,"usage:%s source destination\n",*avgs);
	    exit(1);
    }
    if((in_fd=open(avgs[1],O_RDONLY))==-1)
    {
	    oops("cannt open",avgs[1]);
    }
    if((out_fd=creat(avgs[2],COPYMODE))==-1)
    {
	    oops("cannt create",avgs[2]);
    }
    while((n=read(in_fd,buf,BUFF))>0)
    {
	    if(write(out_fd,buf,n)!=n)
	    {
		    oops("write erro to",avgs[2]);
	    }
    }
    if(n==-1)
	    oops("read erro from",avgs[1]);
    close(avgs[1]);
    close(avgs[2]);


}
void oops(char *s1,char *s2)
{
	fprintf(stderr,"error: %s",s1);
	perror(s2);
	exit(1);
}
