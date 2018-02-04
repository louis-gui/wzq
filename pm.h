#include<stdio.h>
#include<string.h>

void draw_board(int* board, int bw, int gbx, int gby){
	int i,j,p;
	// clear screen
	printf("\033[H\033[J");
	for(i=0;i<bw;i++){
		for(j=0;j<bw;j++){
			p = board[i*bw+j];
			if(j==gbx&&i==gby) {
				printf("\033[30;46m");
			}
			if(p==1) {
				printf("●");
			} else if(p == 2) {
				printf("○");
			} else {
				if(j==0) {
					if(i==0)
						printf("┏");
					else if(i==bw-1)
						printf("┗");
					else
						printf("┣");
				} else if(j==bw-1) {
					if(i==0)
						printf("┓");
					else if(i==bw-1)
						printf("┛");
					else
						printf("┫");
				} else {
					if(i==0)
						printf("┳");
					else if(i==bw-1)
						printf("┻");
					else if(i!=0&&i!=bw-1)
						printf("╋");
				}
			}
			if(j==gbx&&i==gby) {
				printf("\033[0m");
			}
			if(j<bw-1) {
				printf("━");
			} else {
				printf("\n");
			}
		}
	}
	printf("\n");
}
void pmcsh(int n){
	int i,j;
	printf("\033[H\033[J");
	for(i=0;i<n;i++){
		if(i==0)
			printf("┏━");
		else if(i==n-1)
			printf("┗━");
		else
			printf("┣━");
		for(j=0;j<n-2;j++){
			if(i==0)
				printf("┳━");
			else if(i==n-1)
				printf("┻━");
			else
				printf("╋━");
		}
		if(i==0)
			printf("┓\n");
		else if(i==n-1)
			printf("┛\n");
		else
			printf("┫\n");
	}
	printf("\n\n                                          ");
}
void scan(char* a){
	int i=0, j;
	do {
		a[i]=getchar();
		i++;
	} while(a[i-1]!=' ');
	for(j=0;j<i;j++)
		printf("\b");
}
int dqlen(char a[10]){
	int i;
	for(i=0;a[i-1]!='.';i++)
		;
	return i;
}

char* fdq(char a[10]){
	int i;
	for(i=dqlen(a);i<10;i++)
		a[i]='\0';
	return a;
}

char* fdh(char a[10]){
	int i;
	for(i=dqlen(a);i>=0;i--)
		a[i]=a[dqlen(a)+i];
	return a;
}
int fl(char a[10]){
	if(a[2]=='\0' ||  a[2] == '.')
		return a[1]-48;
	else
		return (a[1]-48)*10+a[2];
}
void hqz(int x,int y,int dqys){
	printf("\033[%d;%dH",y,x);
	if(dqys==2)
		printf("○");
	else
		printf("●");
	printf("\033[16;43H");
}
