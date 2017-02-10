#include<stdio.h>
#include<algorithm>


struct Goods{
	int j;
	int f;
	double s;
	bool operator < ( const Goods & rhs){
		return this->s > rhs.s;
	}
} buf[1000];


int main( int argc, char * argv[] ){

	int m, n;
	while( scanf("%d%d",&m,&n) != EOF){
		if ( m==-1 && n==-1) break;
		for( int i=0; i< n; i++){
			Goods tmp;
			scanf("%d%d",&tmp.j, &tmp.f);
			tmp.s=double(tmp.j)/tmp.f;
			buf[i]=tmp;
		}
		std::sort(buf, buf+n);
		int idx=0;
		double total=0;
		while( m >0 && idx < n ){
			
			if ( m > buf[idx].f){
				total += buf[idx].j;
				m -=buf[idx].f;
			}else{
				total += buf[idx].s * m; 
				m=0;
			}
			idx++;
		
		}
		printf("%.3f\n",total);
		
	}

	return 0;
}

