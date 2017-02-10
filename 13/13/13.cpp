#include<stdio.h>
#include<queue>

int main( int argc, char * argv[] ){

	int n;
	std::priority_queue< int, std::vector<int> , std::greater<int>> que;
	while( scanf("%d", &n) !=EOF){
		int total=0;
		while( !que.empty()) que.pop();
		for( int i=0; i< n ;i ++){
			int tmp;
			scanf("%d",&tmp);
			que.push(tmp);
		}
		while( que.size()  > 1 ){
			int num1 = que.top();
			que.pop();
			int num2 = que.top();
			que.pop();
			total += num1+ num2;
			que.push(num1+num2);
		}
		printf("%d\n",total);
	}


}