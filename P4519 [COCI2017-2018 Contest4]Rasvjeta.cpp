#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std ;

long long n , m , k , vis[100000000] , x , ans ;

int main () {
	
	scanf ( "%lld %lld %lld" , &n , &m , &k ) ;
	n += 114514 ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%lld" , &x ) ;
		x += 114514 ;
		
		for ( int j = x - k ; j <= x + k ; j++ ) {
			vis[j] = true ;
		}
	}
	
	for ( int i = 114515 ; i <= n ; i++ ) {
		if ( !vis[i] ) {
			ans++ ;
			for ( int j = i ; j <= i + 2 * k ; j++ ) {
				vis[j] = true ;
			}
		}
	}
	
	printf ( "%lld" , ans ) ;
	
	return 0 ;
}
