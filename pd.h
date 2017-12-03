#include<stdio.h>
int Is_ow(int a[13][13]){
	int i,j,bl=0,wl=0;
	for(i=0;i<13;i++){
		for(j=0;j<13;j++)
			if(a[i][j]==1&&bl!=5&&wl!=5){	
				wl++;
				bl=0;
			}
			else if(a[i][j]==2&&bl!=5&&wl!=5){
				wl=0;
				bl++;
			}
		if(bl==5)
			return 2;
		else if(wl==5)
			return 1;
	}
	for(j=0;j<13;j++){
		for(i=0;i<13;i++)
			if(a[i][j]==1&&bl!=5&&wl!=5){	
				wl++;
				bl=0;
			}
			else if(a[i][j]==2&&bl!=5&&wl!=5){
				wl=0;
				bl++;
			}
		if(bl==5)
			return 2;
		else if(wl==5)
			return 1;
	}
	for(i=0,j=0;i<13&&j<13;i++,j++){
		if(a[i][j]==1&&bl!=5&&wl!=5){	
			wl++;
			bl=0;
		}
		else if(a[i][j]==2&&bl!=5&&wl!=5){
			wl=0;
			bl++;
		}
		else if(bl==5)
			return 2;
		else if(wl==5)
			return 1;
	}
	for(i=0,j=0;i<13&&j<13;i++,j--){
		if(a[i][j]==1&&bl!=5&&wl!=5){	
			wl++;
			bl=0;
		}
		else if(a[i][j]==2&&bl!=5&&wl!=5){
			wl=0;
			bl++;
		}
		else if(bl==5)
			return 2;
		else if(wl==5)
			return 1;
	}
	return 0;
}
