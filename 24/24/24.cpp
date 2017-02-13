#include<stdio.h>

int Tree[1000];


void InitTree(){
	for( int i=0; i< 1000; i++){
		Tree[i]=-1;
	}
}


int FindRoot( int x){

	if( Tree[x] == -1 ){
		return x;
	}else{
		int tmp = FindRoot(Tree[x] );
		Tree[x]=tmp;
		return tmp;
	}
}



int main( int argc, char *argv[]){

	int n=0;
	int m=0;
	while( scanf("%d", &n) != EOF){
		if( n == 0 ) break;
		scanf("%d", &m);
		InitTree();
		for( int i=0; i<m ; i++){
			int a,b;
			scanf( "%d%d",&a,&b);
			int ar = FindRoot(a);
			int br = FindRoot(b);
			Tree[ar]=br;
		}
		int ans=0;
		for( int i=1; i < n ; i++){
			if( Tree[i] == -1)
				ans++;
		}
		printf("%d\n",ans-1);
	}


	return 0;
}