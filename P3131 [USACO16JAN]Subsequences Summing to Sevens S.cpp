#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 50005
int n , a[LEN] , pre[LEN] , first[LEN] , last[LEN] ;

int main () {

	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
		pre[i] = ( a[i] + pre[i - 1] ) % 7 ;
	}

	for ( int i = n ; i >= 1 ; i-- ) {
		first[pre[i]] = i ;
	}

	for ( int i = 1 ; i <= n ; i++ ) {
		last[pre[i]] = i ;
	}

	int maxn = -1 ;
	for ( int i = 0 ; i < 7 ; i++ ) {
		maxn = max ( last[i] - first[i] , maxn ) ;
	}

	printf ( "%d" , maxn ) ;
	
	return 0 ;
}
