#include<stdio.h>
#include<string.h>

#define IsLeapYear( x )  x % 100 !=0 && x % 4 ==0 || x % 400 ==0 ? 1 :0


char MonthName[13][10]={
	"",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

char WeekName[7][10]={
	"Sunday",
	"Monday",
	"Tuesday",
	"Wenesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int MonthDay[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};


int buf[5000][13][32];


struct Date{
	int year;
	int month;
	int day;
	void NextDay(){
		day++;
		if (day > MonthDay[month][IsLeapYear(year)]){
			day=1;
			month++;
			if(month > 12){
				month =1;
				year++;

			}
		}
	}
};




int main( int argc, char * argv[]){

	Date tmp;
	tmp.year=0;
	tmp.day=1;
	tmp.month=1;
	int cnt=0;
	while(tmp.year <= 3000 ){
		tmp.NextDay();
		cnt++;
		buf[tmp.year][tmp.month][tmp.day]=cnt;
	}
	int y,d;
	char m[10];
	while( scanf("%d%s%d",&d,m,&y) != EOF){
		int month=0;
		for(int i=0; i<=12;i++){
			if( strcmp(m,MonthName[i]) == 0 ) {
				month=i;
				break;
			}
		}
		int days=buf[y][month][d]-buf[2017][2][6];
		days++;
		int wd=(days%7+7)%7;
		printf("%s\n",WeekName[wd]);
	}

	return 0;
}


