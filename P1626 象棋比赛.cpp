#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std ;

int n , m , a[100000 + 5] , b[100000 + 5] , ans ;

int main () {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}
	
	sort ( a + 1 , a + 1 + n ) ;
	
	for ( int i = 2 ; i <= n ; i++ ) {
		b[i] = a[i] - a[i - 1] ;
	}
	
	sort ( b + 2 , b + 1 + n ) ;
	
	for ( int i = 2 ; i <= m + 1 ; i++ ) {
		ans += b[i] ;
	}
	
	printf ( "%d" , ans ) ;
	
	return 0 ;
}
