#include<stdio.h>
#include<signal.h>
#define INPUTLEN 100
int main()
{
	struct sigaction new;
	sigset_t blocked;
	void inthandler();
	char x[INPUTLEN];
	new.sa_handler=inthandler;
	new.sa_flags=SA_RESETHAND|SA_RESTART;
	sigemptyset(&blocked);
	sigaddset(&blocked,SIGQUIT);
	new.sa_mask=blocked;
	if(sigaction(SIGINT,&new,NULL)==-1)
		perror("sigaction");
	else
		while(1)
		{
			fgets(x,INPUTLEN,stdin);
			printf("input:%s",x);
		}
}
void inthandler(int s)
{
	printf("called with signl %d\n",s);
	sleep(s);
	printf("done handling signal %d\n",s);
}
