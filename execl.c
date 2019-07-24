#include<stdio.h>
int main()
{
	char *arglist[3];
	arglist[0]="ls";
	arglist[1]="-l";
	arglist[2]=0;
	printf("exec ls -l\n");
	execvp("ls",arglist);
	printf("***** ls is done\n");
}
