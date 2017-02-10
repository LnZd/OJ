#include<stdio.h>


int prime[10000];
int psize=0;
int mark[10000]={0};


struct Data {
	int prime;
	int cnt;
};


Data Nbuf[1000];
int nsize=0;
Data Abuf[1000];
int asize=0;

void init(){

	for( int i=2; i< 10000 ; i++){
		if( mark[i]){
			continue;
		} 
		prime[psize++]= i;
		
		for( int j= i*i; j< 10000; j= j+i){
			mark[j]=true;			
		}
	}
}


int main( int argc, char * argv[] ){
	init();
	int n , a;
	while( scanf("%d%d",&n,&a) != EOF){
		asize=0;
		nsize=0;
		for( int i=0; i < psize && prime[i] <= a; i++){
			if( a % prime[i] ==0){
				Abuf[asize].cnt=0;
				while( a%prime[i] == 0 ){
					Abuf[asize].cnt++;
					a=a/prime[i];
				}
				Abuf[asize++].prime=prime[i];
			}
		}

		for( int i=0; i< psize && prime[i] <= n ; i++){
			int tmp=prime[i];
			Nbuf[nsize].prime=tmp;
			Nbuf[nsize].cnt=1;
			tmp*=tmp;
			while( n % tmp ==0 ){
				Nbuf[nsize].cnt = n /tmp;
				tmp *=tmp;
			}
			nsize++;
		}

		int ans = 0xFFFFFFFF>>1;
		for( int i=0; i< asize ;i++){
			for( int j=0; j < nsize ;j++){
				if( Nbuf[j].prime == Abuf[i].prime){
						int tmp = Nbuf[j].cnt / Abuf[i].cnt;
						if (tmp < ans) ans =tmp;
				}

			}
		}
		printf("%d\n",ans);
	}
	return 0;
}



