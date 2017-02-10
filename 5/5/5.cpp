#include<stdio.h>


int main(int argc, char * argv[]){

	int n=0;
	while( scanf("%d",&n) != EOF){
		int buf[101]={0};
		for( int i=0; i< n; i++){
			int score=0;
			scanf("%d", &score);
			buf[score]++;
		}
		int score1;
		scanf("%d",&score1);
		printf("%d\n",buf[score1]);
	}

	return 0;
}