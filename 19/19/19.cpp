#include<stdio.h>

int prime[10000]={0};
int psize=0;
bool mark[10000]={0};

void init(){

	for( int i=2; i < 10000 ; i++ ){
			if( mark[i]) continue;
			prime[psize++]=i;
			for( int j=i+i; j < 10000;  j +=i ){
				mark[j]=true;
			}
	}
}



int main(int argc, char * argv[]){
	init();
	int n;
	int buf[1000];
	int j=0;
	while( scanf("%d", &n) != EOF ){
		int num=0;
		int AnsP[100];
		for( int i=0; i< psize && prime[i] < n ; i++){
			if( n % prime[i] == 0  ){
				AnsP[num]=0;
				while( n % prime[i]==0){
					AnsP[num]++;
					n= n/prime[i];
				}
				num++;
			}
			if( n == 1 ) break;
		}
		if( num ==0 ){
			AnsP[num++]=1;
		}
		int ans = 0;
		for( int i=0; i< num ; i++){
			ans+=AnsP[i];
		}
		printf("%d\n",ans);

	}


	return 0;
}
