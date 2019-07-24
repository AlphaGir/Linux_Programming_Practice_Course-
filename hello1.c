#include<stdio.h>
#define LEFTEDGE 10
#define RIGHTEDGE 30
#define ROW 10
#include<curses.h>
int main()
{
	int i;
	char *message="hello";
	int dir= +1;
	int pos=LEFTEDGE;
	initscr();
	clear();
	while(1)
	{
		move(ROW,pos);
	addstr(message);
	move(LINES-1,COLS-1);
	refresh();
	sleep(1);
	move(ROW,pos);
	addstr("                   ");
	pos+=dir;
	if(pos>=RIGHTEDGE)
		dir=-1;
	if(pos<=LEFTEDGE)
		dir=+1;
	}
	getch();
	endwin();
}
