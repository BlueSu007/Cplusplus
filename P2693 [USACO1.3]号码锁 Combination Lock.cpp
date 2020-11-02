#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , y , z , a , b , c ;
long long ans ;

int main () {
	
	scanf ( "%d %d %d %d %d %d %d" , &n , &x , &y , &z , &a , &b , &c ) ;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			for ( int k = 1 ; k <= n ; k++ ) {
				if ( ( ( abs ( i - a ) <= 2 || abs ( i - a ) >= n - 2 ) 
					&& ( abs ( j - b ) <= 2 || abs ( j - b ) >= n - 2 ) 
					&& ( abs ( k - c ) <= 2 || abs ( k - c ) >= n - 2 ) )
					|| ( ( abs ( i - x ) <= 2 || abs ( i - x ) >= n - 2 ) 
					&& ( abs ( j - y ) <= 2 || abs ( j - y ) >= n - 2 ) 
					&& ( abs ( k - z ) <= 2 || abs ( k - z ) >= n - 2 ) ) ) {
						ans++ ;
				}
			}
		}
	}
	
	printf ( "%lld" , ans ) ;
	
	return 0 ;
}
