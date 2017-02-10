#include<stdio.h>

#define  IsLeapYear(x) x%100 !=0 && x%4 ==0 || x % 400 ==0 ? 1 : 0


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





struct Date{
	int year;
	int month;
	int day;

	void NextDay(){
		day ++;
		
		if( day > MonthDay[year][IsLeapYear(year)] ){
			day=1;
			month++;
			if( month > 12 ){
				month=1;
				year++;
			}
		}
	}
};


int buf[5000][13][32];

int abs( int a  ){
	return a> 0 ? a: -a;
}


int main( int argc , char * argv[] ){


	Date tmp;
	tmp.day=1;
	tmp.month=1;
	tmp.year=0;
	int cnt=0;
	while(tmp.year < 5000 ){
		tmp.NextDay();
		cnt++;
		buf[tmp.year][tmp.month][tmp.day]=cnt;
	}
	int y1,m1,d1;
	int y2,m2,d2;
	while( scanf("%4d%2d%2d",&y1,&m1,&d1) !=EOF ){
		scanf("%4d%2d%2d",&y2,&m2,&d2);
		int days=abs(buf[y1][m1][d1]-buf[y2][m2][d2]);
		printf("%d%\n",days+1);
	}



	return 0;
}





