#include<stdio.h>

int fun( int n){

	if( n == 0){
		return 1;
	}else if ( n >= 1){
		int a= fun(n-1);
		int b= fun(n-2);
		return a+b;
	}
	return 0;
}


int main( int argc, char * argv[] ){
	int a;
	while( scanf("%d",&a) != EOF ){
		int ans = fun(a);
		printf("%d\n", ans);
	}


	return 0;
}