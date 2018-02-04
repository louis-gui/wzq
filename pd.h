#include<stdio.h>
int Is_ow(int a[169]){
	int i,j,k,bl=0,wl=0,p=0;
	// ——
	for(i=0;i<13;i++){
		wl=bl=0;
		for(j=0;j<13;j++){
			p = a[i*13+j];
			if(p==0) {
				wl=bl=0;
			}
			else if(p==1){	
				wl++;
				bl=0;
			}
			else if(p==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("--\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	//| 
	for(j=0;j<13;j++){
		bl=wl=0;
		for(i=0;i<13;i++) {
			p = a[i*13+j];

			if(!p){
				bl=0;
				wl=0;
			}
			else if(a[i*13+j]==1){	
				wl++;
				bl=0;
			}
			else if(a[i*13+j]==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("|\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	// \-
	for(k=0;k<13;k++) {
		wl=bl=0;
		for(i=0,j=k;i<13&&j<13;i++,j++){
			p = a[i*13+j];
			if(!p){
				wl=0;
				bl=0;
			}
			else if(a[i*13+j]==1){	
				wl++;
				bl=0;
			}
			else if(a[i*13+j]==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("\\\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	// \|
	for(k=1;k<13;k++) {
		wl=bl=0;
		for(i=k,j=0;i<13&&j<13;i++,j++){
			p = a[i*13+j];
			if(!p){
				wl=0;
				bl=0;
			}
			else if(a[i*13+j]==1){	
				wl++;
				bl=0;
			}
			else if(a[i*13+j]==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("\\\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	// /--
	for(k=0;k<13;k++){
		wl=bl=0;
		for(i=0,j=k;i<13&&j>=0;i++,j--){
			p = a[i*13+j];
			if(!p){
				bl=0;
				wl=0;
			}
			else if(a[i*13+j]==1){	
				wl++;
				bl=0;
			}
			else if(a[i*13+j]==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("/\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	for(k=0;k<13;k++){
		wl=bl=0;
		for(i=k,j=12;i<13&&j>=0;i++,j--){
			p = a[i*13+j];
			if(!p){
				bl=0;
				wl=0;
			}
			else if(a[i*13+j]==1){	
				wl++;
				bl=0;
			}
			else if(a[i*13+j]==2){
				wl=0;
				bl++;
			}
			if(bl==5||wl==5) {
				printf("/\n");
			}
			if(bl==5)
				return 2;
			else if(wl==5)
				return 1;
		}
	}
	return 0;
}
