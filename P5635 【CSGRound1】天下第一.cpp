#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , mod , x , y ;
short a[10000 + 5][10000 + 5] ;
inline int func ( int x , int y ) ;

int main () {

	scanf ( "%d %d" , &n , &mod ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d" , &x , &y ) ;
		int tmp = func ( x , y ) ;
		if ( tmp == 3 ) {
			printf ( "error\n" ) ;
		}
		else {
			printf ( "%d\n" , tmp ) ;
		}
	}

	return 0 ;
}

inline int func ( int x , int y ) {
	if ( a[x][y] == -1 ) {
		return 3 ;
	}
	if ( a[x][y] ) {
		return a[x][y] ;
	}

	a[x][y] = -1 ;
	if ( x == 0 ) {
		return a[x][y] = 1 ;
	}
	if ( y == 0 ) {
		return a[x][y] = 2 ; 
	}

	return a[x][y] = func ( ( x + y ) % mod , ( ( x + y ) % mod + y ) % mod ) ;
}
