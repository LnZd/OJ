#include<stdio.h>
#include<string>
using namespace std;

struct Node {
	char data;
	Node * lchild;
	Node * rchild;
};


Node * CreateNode( char x){
	Node * nd = new Node();
	nd->data=x;
	nd->lchild=NULL;
	nd->rchild=NULL;
	return nd;
}

void DelTree( Node * bt){
	if(bt){
		DelTree(bt->lchild);
		DelTree(bt->rchild);
	}
}


Node * InsertNode( Node * bt, char x){
	if ( !bt ){
		bt = CreateNode(x);
	}else if ( x < bt->data ) {
		bt->lchild=InsertNode(bt->lchild,x);
	}else{
		bt->rchild=InsertNode(bt->rchild, x );
	}
	return bt;
}

void PreOrder( Node * bt , string  & str){
	if( bt ){
		str=str+bt->data;
		PreOrder(bt->lchild,str);
		PreOrder(bt->rchild,str);
	}
}

void InOrder( Node * bt ,string & str  ){
	if( bt){
		InOrder(bt->lchild, str);
		str = str+ bt->data;
		InOrder(bt->rchild, str);
	}
}

string GetPatern(){
	char tmp1[50];
	scanf("%s",tmp1);
	Node * bt1=NULL;
	for( char *  p1=tmp1; *p1 != '\0'; p1++ ){
		bt1=InsertNode( bt1, *p1);
	}
	string pat1;
	PreOrder(bt1, pat1);
	InOrder(bt1, pat1);
	DelTree(bt1);
	return pat1;
}


int main( int argc, char * argv[]){
	int cnt;
	while( scanf("%d",&cnt) != EOF ){
		if(cnt==0) break;
		string pat1= GetPatern();
		for( int i=0; i < cnt ; i++ ){
			char  buf2[50];
			string pat2=GetPatern();
			pat1==pat2 ? printf("YES\n") : printf("NO\n");
		}
	}
	return 0;
}




