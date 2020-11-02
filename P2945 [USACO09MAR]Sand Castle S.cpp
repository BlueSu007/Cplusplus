#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int n , x , y ;
int a[19260817] , b[19190810] ;
long long ans ;

int main () {
	
	scanf ( "%d %d %d" , &n , &x , &y ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d" , &a[i] , &b[i] ) ;
	}
	
	sort ( a + 1 , a + 1 + n ) ;
	sort ( b + 1 , b + 1 + n ) ;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( b[i] > a[i] ) {
			ans += x * ( b[i] - a[i] ) ;
		}
		else {
			ans += y * ( a[i] - b[i] ) ;
		}
	}
	
	printf ( "%lld" , ans ) ;
	
	return 0 ;
}
