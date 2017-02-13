#include<stdio.h>

char map[8][8];
bool visited[8][8];
int success=false;

int m=0, n=0, t=0;

int next[4][2]={
	1,0,
	0,1,
	-1,0,
	0,-1
};



void DFS( int x, int y, int cost ){
	

	if( map[x][y] == 'D' && cost <= t  ){
		success= true;
		return ;
	}

	for( int i=0; i< 4 ; i++ ){
		int dx = next[i][0];
		int dy = next[i][1];
		int nx=x+dx;
		int ny=y+dy;
		if( nx < 1 || nx > n || ny < 1 || ny > m ) continue;
		if( visited[nx][ny] || map[nx][ny] == 'X' ) continue; 
		visited[nx][ny]=true;
		DFS( nx, ny, cost+1 );
		if(success) return; 
	}
}



int main( int argc, char * argv[] ){


	while( scanf("%d%d%d", &n, &m ,&t) != EOF ){
		if( m==0 && n==0 && t==0) break;

		int x=0;
		int y=0;
		for( int i=1; i<=n; i++){
			scanf("%s",&map[i][1]);
		}

		for( int i=1; i<=n; i++){
			for( int j=1; j <=m ; j++){
				visited[i][j]=false;
				if( map[i][j] == 'S'){
					x=i;
					y=j;
				}
			}
		}


		DFS(x,y,0);
		if( success){
			printf("YES\n");
		}else{
			printf("NO\n");
		}

	}

	return 0;
}