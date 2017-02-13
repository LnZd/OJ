#include<stdio.h>


int data[26];
int min[26];
int len[26];


int main( int argc, char * argv[] ){
	int n;
	while( scanf("%d", &n) != EOF ){
		
		for( int i=0; i< n; i++ ){
			scanf( "%d", &data[i]);
		}

		len[0]=1;
		min[0]=data[0];
		int max=0;
		for( int i=1; i< n; i++  ){
			int len_t=1;
			int min_t=data[i];
			for( int j=0 ; j < i ; j++  ){
				if( min[j] >= data[i] && len[j] + 1 > len_t ){
					len_t = len[j]+1;
					min_t = data[i];
				}
			}
			min[i]=min_t;
			len[i]=len_t;
			if( max < len_t){
				max=len_t;
			}

		}


		printf("%d\n", len[n-1]);

	}
	return 0;
}