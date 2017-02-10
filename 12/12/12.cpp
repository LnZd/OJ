#include<stdio.h>
#include<stack>
//+, - ,* ,/

char buf[201];

std::stack<int> OpS;
std::stack<double> NumS;
int priority[4][4]={
	0,0,0,0,
	0,0,0,0,
	1,1,0,0,
	1,1,0,0
};
//true operator
//false number
bool NumOrOp( char ch, int & op, int & num ){
	if( ch >= '0' && ch <= '9'){
		num= ch - '0';
		return false; 
	}else{
		switch( ch){
		case '+':
			op=0;
			return true;
		case '-':
			op=1;
			return true;
		case '*':
			op=2;
			return true;
		case '/':
			op=3;
			return true;
		}
	}
}

void Cal(){
	int op_tmp = OpS.top();
	OpS.pop();
	double num1= NumS.top();
	NumS.pop();
	double num2 = NumS.top();
	NumS.pop();
	double res;
	switch( op_tmp ){
	case 0 :
		res=num1+num2;
		break;
	case 1:
		res=num1-num2;
		break;
	case 2:
		res=num1*num2;
		break;
	case 3:
		res=num2/num1;
		break;
	}
	NumS.push(res);
}



int main( int argc, char * argv[]){


	while( scanf("%s",buf) != EOF){
		if(buf[0]=='0' && buf[1]== '\0' ) break;
		while( !OpS.empty() ) OpS.pop();
		while( !NumS.empty() ) NumS.pop();

		for(int i=0; buf[i] != '\0';i++){
			int op,num;
			if (NumOrOp(buf[i],op,num)){
				if( OpS.empty() || priority[op][OpS.top()] ){
					OpS.push(op);
				}else{
					Cal();
					OpS.push(op);
				}
			}else{
				NumS.push(num);
			}
		}
		while( !OpS.empty()){
			Cal();
		}
		printf("%.2f\n",NumS.top());

	}
	return 0;
}






