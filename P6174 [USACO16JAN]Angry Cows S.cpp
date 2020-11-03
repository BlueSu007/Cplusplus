#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , k , x[19190810] ;
inline bool check ( int qwq ) ;

int main () {
	
	scanf ( "%d %d" , &n , &k ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &x[i] ) ;
	}
	
	sort ( x + 1 , x + 1 + n ) ;
	
	int leftn = 0 , rightn = x[n] ;
	while ( leftn <= rightn ) {
		int mid = leftn + rightn >> 1 ;
		if ( check (mid) ) {
			rightn = mid - 1 ;
		}
		else {
			leftn = mid + 1 ;
		}
	}
	
	printf ( "%d" , leftn ) ;
	
	return 0 ;
}

inline bool check ( int qwq ) {
	int cnt = 0 , qaq = INT_MIN ;
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( qaq < x[i] - qwq ) {
			cnt++ , qaq = x[i] + qwq ;
			if ( cnt > k ) {
				return false ;
			}
		}
	}
	
	return true ;
}
