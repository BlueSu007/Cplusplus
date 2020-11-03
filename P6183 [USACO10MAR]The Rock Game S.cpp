#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

int n , vis[19260817] ;
inline void print ( int x ) ;
inline void dfs ( int step , int x ) ;

int main () {
	
	scanf ( "%d" , &n ) ;
	dfs ( 0 , 0 ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "O" ) ;
	}
	
	return 0 ;
}

inline void dfs ( int step , int x ) {
	if ( !vis[x] ) {
		print (x) ;
	}
	
	if ( step == ( 1 << n ) ) {
		exit ( false ) ;
	}
	
	for ( int i = 0 ; i <= n - 1 ; i++ ) {
		int tmp = x ^ ( 1 << i ) ;
		if ( !vis[tmp] ) {
			dfs ( step + 1 , tmp ) ;
		}
	}
}

inline void print ( int x ) {
	vis[x] = true ;
	for ( int i = n - 1 ; i >= 0 ; i-- ) {
		if ( ( x >> i ) & 1 ) {
			printf ( "X" ) ;
		}
		else {
			printf ( "O" ) ;
		}
	}
	
	printf ( "\n" ) ;
}
