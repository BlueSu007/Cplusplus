#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

char c[20] , a[100][200];
int len = 3 , wide;
const int dx[9] = { 3 , 1 , 5 , 2 , 2 , 4 , 4 , 3 , 3};
const int dy[9] = { 0 , 0 , 0 , -1 , 1 , -1 , 1 , -2 , 2 };
inline void putn ( char c , int num );

int main() {
	
	memset ( a , '.' , sizeof(a) );
	scanf ( "%s" , &c );
	
	int len = strlen(c);
	wide = ( 4 * len ) + 1;
	
	for ( int i = 1 ; i <= len ; i++ ) {
		putn ( c[i - 1] , i );
	}
	
	for ( int i = 1 ; i <= 5 ; i++ ) {
		for ( int j = 1 ; j <= wide ; j++ ) {
			printf ( "%c" , a[i][j] );
		}
		
		printf ( "\n" );
	}
	
	return 0;
}

inline void putn ( char c , int num ) {
	char ch = ( num % 3 == 0 ) ?  '*' : '#' ;
	for ( int i = 0 ; i < 9 ; i++ ) {
		if ( a[dx[i]][len + dy[i]] != '*' ) {
			a[dx[i]][len + dy[i]] = ch;
		} 
	}
	
	a[3][len] = c;
	len += 4;
}
