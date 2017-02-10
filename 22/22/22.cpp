#include<stdio.h>
#include<string.h>


struct BigInt{
	int buf[1000];
	int size;

	BigInt(){
		init();
	}

	void init(){
		size=0;
		for( int i=0; i< 1000; i++ ){
			buf[i]=0;
		}
	}

	void set( char * str ){
		int len = strlen(str);
		int tmp=0;
		int c=1;
		for( int i=len-1; i >= 0  ; i--  ){
			tmp += (str[i]-'0')*c;
			c = c*10;
			if( i==0 || c == 10000 ){
				buf[size]=tmp;
				size++;
				c=1;
				tmp=0;
			}
		}
	}

	BigInt operator + (  const BigInt &  rhs) {
		
		BigInt c;
		int carry=0;
		int maxlen = this->size > rhs.size ? this->size: rhs.size;
		c.size=maxlen;
		for( int i=0; i < maxlen ; i++){
			int tmp = this->buf[i]+rhs.buf[i];
			carry = tmp /10000;
			c.buf[i]=tmp % 10000;
		}
		if( carry != 0 ){
			c.buf[maxlen]=carry;
			c.size++;
		}
		return c;
	}

	void output(){
		
		for( int i=size-1 ; i >=0; i-- ){
			if( i == size-1 ){
				printf("%d",buf[i]);
			}else{
				printf("%04d",buf[i]);
			}
		}
		printf("\n");
	}
};

char aStr[10001];
char bStr[10001];

BigInt a, b,c;

int main( int argc, char * argv[]){
	while( scanf("%s%s",&aStr, &bStr) != EOF ){
		a.set(aStr);
		b.set(bStr);
		c=a+b;
		c.output();
		a.init();
		b.init();
	}

	return 0;
}