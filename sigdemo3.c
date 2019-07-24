#include<stdio.h>
#include<signal.h>
#define INPUTLEN 100
int main(int ac,char *av[])
{
	void inthandler(int);
	void quithandler(int);
	char input[INPUTLEN];
	int nc;
	signal(SIGINT,inthandler);
	signal(SIGQUIT,quithandler);
	do
	{
		printf("\nType a message\n");
		nc=read(0,input,(INPUTLEN-1));
		if(nc==-1)
			perror("read returned an error");
		else
		{
			input[nc]='\0';
			printf("you type:%s",input);
		}
	}while(strncmp(input,"quit",4)!=0);
}
void inthandler(int s)
{
	printf("received signl %d ...waiting\n",s);
	sleep(2);
	printf("leaving inthandler\n");
}
void quithandler(int s)
{
	printf("received signal %d..waiting\n",s);
	sleep(3);
	printf("leaving quithandler\n");
}
