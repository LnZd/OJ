#include<stdio.h>
#include<string.h>


char str1[101];
char str2[101];
int map[101][101];

int main( int argc, char * argv[] ){

	while( scanf("%s%s", str1, str2) != EOF ){
		int len1= strlen(str1);
		int len2= strlen(str2);
		for( int i=0; i<= len1; i++){
			map[i][0]=0;
		}
		for( int j=0; j <= len2; j++){
			map[0][j]=0;
		}

		for( int i=1; i <= len1; i++ ){
			for( int j=1; j<= len2; j++){
				if( str1[i-1] == str2[j-1] ){
				
					map[i][j]=map[i-1][j-1]+1;
				}else{
					int max = map[i-1][j] > map[i][j-1] ? map[i-1][j] : map[i][j-1]; 
					map[i][j]=max;
				}
	
			}
		}
		
		for( int i=0; i<=len1; i++){
			for( int j=0; j<= len2; j++ ){
				printf("%d ", map[i][j]);
			}
			printf("\n");
		}


		printf("%d\n", map[len1][len2]);

	}
	return 0;
}