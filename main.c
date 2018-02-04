#include"pm.h"
#include"pd.h"
#include <unistd.h>
#include <termios.h>
int noecho() {
	struct termios term;
	if (tcgetattr(STDIN_FILENO, &term) < 0) {
		printf("tcgetattr error");
	}
	term.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int board[169] = {0};
int bw = 13;
int gbx = 0;
int gby = 0;
int gameEnd = 0;
int colour = 2;
int p;
char c;

main(){
	noecho();
	draw_board(board, bw, gbx, gby);
	while(!gameEnd) {
		c = getchar();
		switch(c) {
			case 'q':
				gameEnd = 1;
				break;
			case 'h':
				if(gbx>0)
					gbx--;
				break;
			case 'j':
				if(gby<bw-1)
					gby++;
				break;
			case 'k':
				if(gby>0)
					gby--;
				break;
			case 'l':
				if(gbx<bw-1)
					gbx++;
				break;
			case ' ':
				p=board[gby*bw+gbx];
				if(p==0) {
					board[gby*bw+gbx]=colour;
					if(colour==1)
						colour=2;
					else
						colour=1;
				}
				break;
		}
		draw_board(board, bw, gbx, gby);
		printf("%d %d %d\n", p, board[gby*bw+gbx], colour);
		int t=Is_ow(board);
		if(t==1) {
			printf("White win\n");
			return;
		}
		else if(t==2){
			printf("Black win\n");
			return;
		}
		else if(colour==1) {
			printf("White move\n");
		} else {
			printf("Black move\n");
		}
	}
}
