#include<stdio.h>
#include<string.h>


struct  Node{
	char data;
	Node * lchild;
	Node * rchild;
};



Node * CreateNode( char ch ){
	Node * node = new Node;
	node->data=ch;
	node->rchild=NULL;
	node->lchild=NULL;
	return node;
}

void DelTree( Node * bt){
	if(bt){
		DelTree(bt->lchild);
		DelTree(bt->rchild);
		delete bt;
	}
}

Node * CreateBiTree( char * s1, char * e1, char * s2, char * e2){
	if( s1 <= e1 && s2 <= e2   ){
		Node * node = CreateNode(*s1);
		char * root = s2;
		for( ; root <= e2 ; root++)
			if( *root == *s1 ) break;
		Node * left = CreateBiTree( s1+1,  s1 + (root-s2), s2, root -1 );
		Node * right = CreateBiTree( s1 + (root-s2 )+1 , e1, root+1, e2);
		node->lchild=left;
		node->rchild=right;
		return node;
	}
	return NULL;
}

void PostOrder( Node *  bt){

	if( bt){
		PostOrder( bt->lchild );
		PostOrder( bt->rchild );
		printf( "%c",bt->data );
	}
}


int main(){
	char str1[100];
	char str2[100];
	while( scanf("%s", str1) !=EOF ){
		scanf("%s",str2);
		int len1= strlen(str1);
		int len2=strlen(str2);
		Node *  tree=CreateBiTree(str1, str1 + len1-1, str2, str2+len2-1);
		PostOrder(tree);
		printf("\n");
		DelTree(tree);

	}
};

