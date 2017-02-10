#include<stdio.h>
#include<string.h>
#include<algorithm>


struct Stu{
	char id[20];
	char name[20];
	char sex[5];
	int age;
	bool operator < ( const  Stu & rhs){
		return strcmp(id , rhs.id) < 0;
	}
}buf[1000];


int main( int argc, char * argv[]){

	int n;
	while( scanf("%d",&n) != EOF){
			for( int i=0; i< n ; i++){
			Stu tmp;
			scanf("%s%s%s%d",tmp.id,tmp.name,tmp.sex,&tmp.age);	
			buf[i]=tmp;
		}
		std::sort(buf, buf+n);
		
		int m;
		scanf("%d",&m);
		while( m>0){
			char id[20];
			scanf("%s",&id);
			m--;
			int low=0;
			int high=n-1;
			while( low <= high){
				int mid=low + ((high-low)>>2);
				int r = strcmp(buf[mid].id,id);
				if ( r ==0 ){
					printf("%s %s %s %d\n",buf[mid].id,buf[mid].name,buf[mid].sex,buf[mid].age);
					break;
				}else if ( r < 0 ){
					low = mid+1;
				}else{
					high=mid-1;
				}
			}
			if (low > high){
				printf("No Answer!\n");
			}
		}
	}
	return 0;
}



