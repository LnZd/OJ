#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp(int i, int j ){ return i > j;};

int main(int argc, char *argv[]){

	int buf[100];
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n; i++) {
			scanf("%d",&buf[i]);
		}
		//int j=n-1;
		//bool flag=false;
		//for(int i=0;i<j;j--){
		//	for(int k=i; k<j;k++){
		//		if( buf[k] > buf[k+1]){
		//			int tmp=buf[k];
		//			buf[k]=buf[k+1];
		//			buf[k+1]=tmp;
		//			flag=true;
		//		}
		//	}
		//	if(flag==false) break;
		//}

		sort(buf,buf+n,cmp);
		for(int i=0;i < n;i++){
			printf("%d ",buf[i]);
		}
		printf("\n");
	}

	return 0;
}