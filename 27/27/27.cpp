#include<stdio.h>
#include<vector>




struct Edge{
	int next;
	int cost;
} ;

struct Mark {
	int cost;
	int flag;
	std::string path;
} mark[102];

std::vector< Edge > edge[102];



int main( int argc, char * argv[]){
	
	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		if( n==0 && m ==0 ) break;;

		for( int i=0; i< 102; i++ ){
			edge[i].clear();
		}

		for( int i=0; i< m; i++ ){
			int a, b, cost;
			scanf("%d%d%d", &a, &b, &cost);
			Edge ae, be;
			ae.next=b;
			ae.cost=cost;
			be.next=a;
			be.cost=cost;
			edge[a].push_back(ae);
			edge[b].push_back(be);

		}
		
		for( int i=1; i<=n ; i++ ){
			mark[i].cost=-1;
			mark[i].flag=false;
			mark[i].path.clear();
		}


		mark[1].cost=0;
		mark[1].flag=true;
		mark[1].path="0";
		int newP=1;
		for( int i=1; i< n; i++  ){

			for( int j=0;  j < edge[newP].size(); j++ ){
				int next= edge[newP][j].next;
				if( mark[next].flag ) {
					continue;
				}else{
					if( mark[next].cost == -1 || mark[ next ].cost> mark[newP].cost +  edge[newP][j].cost ){
						mark[next].cost = edge[newP][j].cost + mark[newP].cost ;
					}
				}
				
			}
			int min= 0x7FFFFFFF;
			for( int i=1; i <=n; i++ ){
				if( mark[i].flag == false ){
					if( mark[i].cost != -1 && mark[i].cost < min ){
						min = mark[i].cost;
						newP = i;
					}
				}
			}

			printf("%d\n",mark[n].cost);
		}
	}

	return 0;

}



