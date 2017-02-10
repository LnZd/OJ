#include<stdio.h>
#include<math.h>


bool judge(int x){
	if(x<1){
		return false;
	}
	else{
		 int m = sqrt( double(x))+1;
		 for( int i=2; i< m ;i++){
			 if( x%i == 0){
				return false;
			 }
		 }
	}
	return true;
}

int main( int argc, char * argv[]){

	int n;
	while( scanf("%d",&n) != EOF){
		printf("%s\n",judge(n)?"yes":"no");
	}
	return 0;
}