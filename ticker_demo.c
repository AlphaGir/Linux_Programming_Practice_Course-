#include<stdio.h>
#include<sys/time.h>
#include<signal.h>
int main()
{
	void countdown(int);
	signal(SIGALRM,countdown);
	if(set_ticker(500)==-1)
		perror("set_ticker");
	else
		while(1)
			pause();
	return 0;
}
void countdown(int signum)
{
	static int num=10;
	printf("%d..",num--);
	fflush(stdout);
	if(num<0)
	{
		printf("done!\n");
		exit(0);
	}
}
int set_ticker(int n)
{
	struct itimerval new;
	long n_s,n_u;
	n_s=n/1000;
	n_u=(n%1000)*1000L;
	new.it_interval.tv_sec=n_s;
        new.it_interval.tv_usec=n_u;
	new.it_value.tv_sec=n_s;
	new.it_value.tv_usec=n_u;
	return setitimer(ITIMER_REAL,&new,NULL);
}


