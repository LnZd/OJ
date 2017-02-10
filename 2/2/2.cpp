#include<stdio.h>
#include<algorithm>

using namespace std;

struct Stu{
	char name[100];
	int age;
	int score;
	bool operator < ( const Stu & lhs) {
		if( this->score != lhs.score) return this->score < lhs.score;
		int tmp = strcmp(this->name, lhs.name);
		if (tmp !=0) return tmp < 0;
		return this->age < lhs.age;
	}

}buf[1000];

//bool cmp(Stu a, Stu b){
//
//	if (a.score != b.score) return a.score < b.score;
//	int tmp = strcmp(a.name ,b.name);
//	if(tmp !=0 ) return tmp < 0;
//	return a.age < b.age;
//
//}


int main(int argc, char * argv[]){

	int n;
	while( scanf("%d",&n)!=EOF){
		for( int i =0; i< n;i++){
			scanf("%s%d%d",buf[i].name,&buf[i].age,&buf[i].score);
		}
		//sort(buf,buf+n,cmp);
		sort(buf,buf+n);
		for(int i=0;i<n;i++){
			printf("%s %d %d\n",buf[i].name, buf[i].age, buf[i].score);
		}
	}



	return 0;
}