#include<stdio.h>
#include<signal.h>
int main()
	{
		void f(int);
		int i;
		signal(SIGINT,f);
		for(i=0;i<5;i++)
		{
			printf("hello \n");
			sleep(1);
		}
	}
void f(int signum)
{
	printf("ouch!\n");
}
