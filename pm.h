#include<stdio.h>
#include<string.h>
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
char* scan(){
	char* a[6]="\0\0\0\0\0\0";
	a[-1]='\0';
	int i=0;
	while(a[i-1]!=' '){
		a[i]=getchar();
		i++;
	}
	return a;
}

