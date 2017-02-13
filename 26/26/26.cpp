#include<stdio.h>

int Map[101][101];


int main( int argc, char * argv[] ){

	int n, m;
	while( scanf("%d%d", &n, &m) != EOF ){
		if( n==0 && m==0) break;

		for( int i=1; i<=n; i++){
			for( int j=1; j< n; j++){
				Map[i][j]=-1;
			}
		}	
		for( int i=1; i<= m; i++){
			int a, b, c;
			scanf("%d%d%d",&a,&b,&c);
			Map[a][b]=c;
		}

		for( int k=1; k<=n; k++){
			for( int i=1; i<=n; i++ ){
				for( int j=1; j<=n; j++ ){
					if(Map[i][k] == -1 || Map[k][j]  == -1 ) continue;			
					if( Map[i][j]==-1 || Map[i][k] + Map[k][j] < Map[i][j] )
						Map[i][j]=Map[i][k]+Map[k][j];
				}
			}
		}

		printf("%d\n", Map[1][n]);

	}
	return 0;
}