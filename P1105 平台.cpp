#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int n , a[1000 + 5] , b[1000 + 5] , c[1000 + 5] ;

int main() {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d %d" , &a[i] , &b[i] , &c[i] ) ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		int tmp1 = 0 , tmp2 = 0 ;
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( a[j] < a[i] && b[j] < b[i] && c[j] > b[i] ) {
				if ( a[tmp1] < a[j] ) {
					tmp1 = j ;
				}
			}
		}
		
		printf ( "%d " , tmp1 ) ;
		
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( a[j] < a[i] && b[j] < c[i] && c[j] > c[i] ) {
				if ( a[tmp2] < a[j] ) {
					tmp2 = j ;
				}
			}
		}
		
		printf ( "%d\n" , tmp2 ) ;
	}
	
	return 0 ;
}
