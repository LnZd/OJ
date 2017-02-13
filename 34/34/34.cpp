#include<stdio.h>

struct Data {
	int v;
	int t;
} data[101];

int dp[101][1001];



int main( int argc,char * argv[] ){

	int t,m ;
	while( scanf("%d%d", &t, &m) != EOF ){
		for( int i=1; i<=m; i++ ){
			scanf("%d%d", &data[i].t, &data[i].v );
		}
		for( int i=0; i<=t ; i++   ){
			dp[0][i]=0;
		}
		
		for( int i=1; i <= m ; i++){

			for( int j=data[i].t; j <= t; j++ ){
				int max= dp[i-1][j-data[i].t] + data[i].v > dp[i-1][j]?  dp[i-1][j-data[i].t] + data[i].v: dp[i-1][j];
				dp[i][j]=max;
			}
			for( int j=0; j< data[i].t; j++){
				dp[i][j]=dp[i-1][j];
			}
		}
		printf("%d\n",dp[m][t]);
	}



	return 0;
}



