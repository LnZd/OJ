#include<stdio.h>


struct BigInt {
	int buf[1000];
	int size;
	BigInt(){
		init();
	}
	void init(){
		for(int i=0; i< 1000; i++){
			buf[i]=false;
		}
		size=0;
	}

	void set( int x){
		while( x !=0){
			int tmp= x%10000;
			buf[size++]=tmp;
			x=x/10000;
		}
	}

	BigInt operator * ( int x ){
		BigInt tmp;
		int carry=0;
		for( int i=0; i< size ;i++ ){
			int k=buf[i]*x + carry;
			tmp.buf[tmp.size++] = k %10000;
			carry = k /10000;
		}

		while( carry != 0 ){
			tmp.buf[tmp.size++]=carry %10000;
			carry = carry /10000;
		}

		return tmp;
	}
	

	void output(){
		for( int i=size -1 ; i>=0; i--){
			if( i == size-1){	
				printf("%d",buf[i]);
			}else{
				printf("%04d",buf[i]);
			}
		}
		printf("\n");
	}
};

BigInt data;

int main( int argc, char * argv[]){

	int n;
	while( scanf("%d",&n)!=EOF){
		data.init();
		data.set(n);
		for( int i=1; i<n ; i++){
			data=data * i;
		}
		data.output();
	}
	return 0;
}

