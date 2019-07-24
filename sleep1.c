#include<stdio.h>
#include<signal.h>
#define SHHHHHH
int main()
{
   void wakeup(int);
   printf("about to sleep for 4 s\n");
   signal(SIGALRM,wakeup);
   alarm(400);
   pause();
   printf("morning so soon?\n");
}
void wakeup(int sigum)
{
	printf("received from kernel\n");
}

