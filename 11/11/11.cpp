#include<stdio.h>
#include<stack>

char buf[101]={0};
char output[101]={0};

int main(int argc, char * argv[]){

	while(scanf("%s",buf) != EOF ){
		std::stack< int > s;
		int i;
		for( i=0; buf[i] != 0; i++){
			if( buf[i] == '(' ){
				s.push(i);
				output[i]=' ';
			} else if( buf[i] == ')') {
				if( !s.empty()){
					s.pop();
					output[i]=' ';
				}else{
					output[i]='$';
				}
			}else{
				output[i]=' ';
			}
		}
		while( !s.empty()){
			output[s.top()]='?';
			s.pop();
		}
		output[i]='\0';
		printf("%s\n",buf);
		printf("%s\n",output);
	}

	return 0;
}

