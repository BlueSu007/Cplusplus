#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , q , x , y , f[10000 + 5] ;
inline int find ( int x ) ;

int main () {
	
	scanf ( "%d %d %d" , &n , &m , &q ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		f[i] = i ;
	}
	
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d" , &x , &y ) ;
		f[find(x)] = find (y) ;
	}
	
	for ( int i = 1 ; i <= q ; i++ ) {
		scanf ( "%d %d" , &x , &y ) ;
		if ( find (x) == find (y) ) {
			printf ( "Y\n" ) ;
		}
		else {
			printf ( "N\n" ) ;
		}
	}
	
	return 0 ;
}

inline int find ( int x ) {
	if ( f[x] == x ) {
		return x ;
	}
	
	return f[x] = find (f[x]) ;
}
