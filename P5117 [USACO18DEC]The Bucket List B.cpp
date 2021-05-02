#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 1005
int n , s , t , b , qwq[LEN] , ans , preSum ;

int main () {

	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d %d" , &s , &t , &b ) ;
		qwq[s - 1] += b , qwq[t] -= b ;
	}

	for ( int i = 0 ; i <= 1000 ; i++ ) {
		ans = max ( ans , preSum ) ;
		preSum += qwq[i] ;
	}

	printf ( "%d" , ans ) ;

	return 0 ;
}
