#include<stdio.h>


struct Node{
	int data;
	Node * lchild;
	Node * rchild;
} buf[100];

int aloc=0;


Node * CreateNode( int x){
	buf[aloc].data=x;
	buf[aloc].lchild=NULL;
	buf[aloc].rchild=NULL;
	return &buf[aloc++];
}

void FreeBuff(){
	aloc=0;
}

Node * InsertNode( Node * bt, int x ){
	if( bt==NULL){
		bt=CreateNode(x);
	}else if ( x < bt->data){
		bt->lchild=InsertNode(bt->lchild,x);
	}else{
		bt->rchild=InsertNode(bt->rchild,x);
	}
	return bt;
}

void PreOrder( Node * bt){
	if( bt){
		printf("%d ",bt->data);
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}

void InOrder(Node * bt){
	if( bt){
		InOrder( bt->lchild);
		printf("%d ",bt->data);
		InOrder(bt->rchild);
	}
}


void PostOrder( Node * bt){
	
	if(bt){
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		printf("%d ",bt->data);
	}
}


int main( int argc, char * argv[] ){

	int n;
	while( scanf("%d",&n) != EOF){
		Node * bt=NULL;
		for(int i=0; i< n ;i++){
			int x;
			scanf("%d",&x);
			bt=InsertNode(bt,x);
		}	
		PreOrder(bt);
		printf("\n");
		InOrder(bt);
		printf("\n");
		PostOrder(bt);
		printf("\n");
		FreeBuff();
	}
	return 0;
}



