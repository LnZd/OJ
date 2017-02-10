#include<stdio.h>

int gcd( int a, int b){
	if( b !=0 ){
		return gcd(b, a%b);
	}
	return a;
}

int main(int argc, char *argv[] ){
	int a,b;
	while( scanf("%d%d",&a,&b) !=EOF){
		int c;
		c= a>b? gcd(a,b):gcd(b,a);
		printf("%d",a*b/c);
	}

	return 0;
}



