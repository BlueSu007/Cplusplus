#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>
using namespace std ;

int n , a[1960817] ;
long long ans , f[19190810] ;

int main () {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
		f[i] = 1 ;
	}
	
	for ( int i = 2 ; i <= n ; i++ ) {
		if ( a[i] > a[i - 1] ) {
			f[i] = f[i - 1] + 1 ;
		}
		else if ( a[i] == a[i - 1] ) {
			f[i] = f[i - 1] ;
		}
	}
	
	for ( int i = n ; i >= 2 ; i-- ) {
		if ( a[i] < a[i - 1] ) {
			f[i - 1] = max ( f[i - 1] , f[i] + 1 ) ;
		}
		else if ( a[i] == a[i - 1] ) {
			f[i - 1] = max ( f[i] , f[i - 1] ) ;
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		ans += f[i] ;
	}
	printf ( "%lld" , ans ) ;
	
	return 0 ;
}
