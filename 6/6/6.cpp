#include<stdio.h>
#include<string.h>

#define OFFSET 500000

bool buf[1000001];


int main( int argc ,char * argv[]){

	memset(buf,0,sizeof(buf));

	int n,m;

	while( scanf("%d%d",&n,&m) != EOF){

		for( int i=0; i< n; i++){
			int a;
			scanf("%d",&a);
			buf[ OFFSET + a ]=true;
		}

		for( int i=OFFSET; i > -OFFSET; i--){

			if( buf[i+OFFSET] ){
				printf("%d",i);
				m--;
				if( m !=0){
					printf(" ");
				}else{
					printf("\n");
					break;
				}
			}

		}

	}

	return 0;
}




