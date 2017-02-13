#include<stdio.h>
#include<queue>

int map[50][50][50];

struct Point{
	int x;
	int y;
	int z;
	int cost;
};

bool mark[50][50][50]={0};



int next[6][3]={
	0,0,-1,
	0,0,1,
	1,0,0,
	-1,0,0,
	0,-1,0,
	0,1,0
};



int BFS( int a, int b, int c){
	
	std::queue< Point > q;
	Point t;
	t.x=t.y=t.z=0;
	t.cost=0;
	q.push(t);
	int ans =0;
	mark[0][0][0]=true;
	while( q.size() > 0 ){

		Point  tmp = q.front();
		q.pop();
		for( int i=0; i< 6; i++){
			int xn, yn, zn;
			xn = next[i][0];
			zn = next[i][1];
			yn = next[i][2];
			Point pt ;
			pt.x=tmp.x+xn;
			pt.y=tmp.y+yn;
			pt.z=tmp.z+zn;
			if( pt.x > a || pt.y > b || pt.z > c) {
				continue;	
			}
			if( map[pt.x][pt.y][pt.z] || mark[pt.x][pt.y][pt.z] ) continue;
			
			mark[pt.x][pt.y][pt.z]=true;
			pt.cost = tmp .cost+1;
			q.push(pt);

		}
		if( tmp.x == a && tmp.y==b && tmp.z==c ){
			return tmp.cost;
		}

	
	
	}
	return -1;

}



int main( int argc, char * argv[]){

	int a, b, c, t;
	while( scanf("%d%d%d", &a,&b,&c) != EOF ){

		for( int i=0; i< a; i++){
			for( int j=0; j< b; j++ ){
				for( int k=0; k< c ; k++){
					int tmp;
					scanf("%d",&tmp);
					map[i][j][k]=tmp;
					mark[i][j][k]=false;
				}
			}
		}

		int ans = BFS(a,b,c);
		if( ans != -1  && ans < t){
			printf("%d\n",ans);
		}

	}
	return 0;
}