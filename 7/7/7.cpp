#include<stdio.h>
#include<stdlib.h>



int main( int argc ,char * argv[]){

	int h;
	while(scanf("%d",&h) != EOF ){
		for(int i=0; i< h ;i ++){
			for( int j=i; j < h-1;j++){
				printf(" ");
			}	
			for( int k=0; k < h+i;k++){
				printf("*");
			}
			printf("\n");
		}
	}

	return 0;
}




