#include<stdio.h>
#include<algorithm>


struct Program{
	int begin;
	int end;
	bool operator < ( const Program & rhs){
		return this->end < rhs.end;
	}
}buf[100];





int main(int argc, char * argv[]){
	int n;
	while( scanf("%d", &n) != EOF ){
		if(n==0) break;
		for( int i=0; i < n ; i++){
			Program tmp;
			scanf("%d%d",&tmp.begin,&tmp.end);
			buf[i]=tmp;
		}
		std::sort(buf,buf+n);
		int count=0;
		int p=0;
		for( int i=0; i< n ; i++){
			if(buf[i].begin >= p){
				count++;
				p=buf[i].end;
			}
		}

		printf("%d\n",count);

		}
	return 0;
}