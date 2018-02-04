#include<stdio.h>

void gotoxy(int x, int y) {
	printf("\033[%d;%df",y,x);
}
void print_color(int b,int q ,int x,int y) {
	gotoxy(x*2,y);
	printf("\033[%d;%dm",b,q);
	gotoxy(x*2+1,y);
	printf("\033[0m")
}
