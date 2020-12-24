#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

long long n ;

int main () {

	scanf ( "%lld" , &n ) ;
	long long tmp = 0 ;

	if ( n == 1 ) {
		printf ( "1" ) ;
		exit ( false ) ;
	}

	for ( long long i = 1 ; i <= n ; i++ ) {
		if ( tmp == n ) {
			printf ( "%lld" , i - 1 ) ;
			exit ( false ) ;
		}
		if ( tmp + i > n ) {
			printf ( "%lld" , n - tmp ) ;
			exit ( false ) ;
		}
		tmp += i ;
	}

	return 0 ;
}
