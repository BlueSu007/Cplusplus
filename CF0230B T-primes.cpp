#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

long long n , k ;
inline bool isprime ( int x ) ;

int main () {

	scanf ( "%lld" , &n ) ;
	while ( n-- ) {
		scanf ( "%lld" , &k ) ;
		double tmp = sqrt ( ( double ) k ) ;
		if ( tmp - ( int ) tmp == 0 && isprime (tmp) ) {
			printf ( "YES\n" ) ;
		}
		else {
			printf ( "NO\n" ) ;
		}
	}

	return 0 ;
}

inline bool isprime ( int x ) {
	if ( x == 1 ) {
		return false ;
	}

	for ( int i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			return false ;
		}
	}

	return true ;
}
