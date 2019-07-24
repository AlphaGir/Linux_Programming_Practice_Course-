#include<stdio.h>
int main()
{
	int ret_from_fork,mypid;
	mypid=getpid();
	printf("before: mypid is %d\n",mypid);
	ret_from_fork=fork();
	sleep(1);
	printf("after:my pid is %d,fork() said %d\n",getpid(),ret_from_fork);
}
