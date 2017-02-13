#include<stdio.h>
#include<algorithm>


int Tree[100];
struct Edge{
	int a;
	int b;
	int cost;
	bool operator < ( const Edge & rhs){
		return this->cost < rhs.cost;
	}
} edge[100];


int FindRoot( int x){
	if( Tree[x] == -1){
		return x;
	}else{
		int tmp = FindRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}



int main( int argc, char * argv[]){
	
	int n;
	while( scanf("%d", &n) != EOF){
		if( n ==0 ) break;
		
		for( int i=0; i < n*(n-1)/2; i++ ){
			scanf("%d%d%d", &edge[i].a,&edge[i].b,&edge[i].cost);
		}
		
		std::sort(edge, edge+n*(n-1)/2 );
		for( int i=0; i< 100; i++){
			Tree[i]=-1;
		}
		int ans=0;
		for(int i=0;i< n; i++){
			int ar = FindRoot(edge[i].a);
			int br = FindRoot(edge[i].b);

			if( ar != br ){
				ans += edge[i].cost;
				Tree[ar]=br;
			}
		}

		printf("%d\n",ans);

	}



	return 0;
}