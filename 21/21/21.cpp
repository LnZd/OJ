#include<stdio.h>


int main( int argc, char * argv[]){

	int a, b ;
	while( scanf("%d%d",&a,&b) !=EOF ){
		int ans=1;
		while( b !=0 ){
			if( b % 2 == 1 ){
				ans *= a;			
				ans = ans % 1000;
			}
			a = a*a;
			a = a %1000;
			b = b /2;
		}
		printf("%d\n",ans);
	}
	return 0;
}

