#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std ;

int n , m , a , b , cnt[10000] , qwq ;

int main () {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d" , &a , &b ) ;
		cnt[a]++ , cnt[b]++ ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		qwq += cnt[i] % 2 ;
	}
	
	if ( qwq == 0 ) {
		printf ( "1" ) ;
	}
	else {
		printf ( "%d" , qwq / 2 ) ;
	}
	
	return 0 ;
}
