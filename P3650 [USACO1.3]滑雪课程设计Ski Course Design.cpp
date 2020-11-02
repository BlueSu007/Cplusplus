#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

int n , a[1000 + 5] , ans = INT_MAX ;

int main () {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}
	
	sort ( a + 1 , a + 1 + n ) ;
	
	for ( int i = a[1] ; i <= a[n] ; i++ ) {
		int tmp = 0 ;
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( a[j] - i > 17 ) {
				tmp += ( a[j] - i - 17 ) * ( a[j] - i - 17 ) ;
			}
			if ( a[j] < i ) {
				tmp += ( a[j] - i ) * ( a[j] - i ) ;
			}
		}
		ans = min ( ans , tmp ) ;
	}
	
	printf ( "%d" , ans ) ;
	
	return 0 ;
}
