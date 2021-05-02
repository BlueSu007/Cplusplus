#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

int n , ans ;
inline int qwq ( int a , int b , int c , int d ) ;

int main () {

	scanf ( "%d" , &n ) ;
	for ( int i = ( n + 3 ) / 4 ; i < ( n + 1 ) / 2 ; i++ ) {
		for ( int j = ( n - i + 2 ) / 3 ; j <= i ; j++ ) {
			for ( int k = ( n - i - j + 1 ) / 2 ; k <= j ; k++ ) {
				int l = n - i - j - k ;
				if ( l <= 0 ) {
					break ;
				}

				if ( l > k ) {
					continue ;
				}
				ans += qwq ( i , j , k , l ) ;
			}
		}
	}

	printf ( "%d" , ans ) ;

	return 0 ;
}

inline int qwq ( int a , int b , int c , int d ) {
	if ( a == b && a == c && a == d ) {
		return 1 ;
	}
	if ( ( a == b && a == c ) || ( b == c && c == d ) ) {
		return 4 ;
	}
	if ( a == b && c == d ) {
		return 6 ;
	}
	if ( a == b || b == c || c == d ) {
		return 12 ;
	}
	return 24 ;
}
