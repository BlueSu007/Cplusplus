#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

long long k , t ;

int main () {

	scanf ( "%lld" , &k ) ;
	while ( k-- ) {
		scanf ( "%lld" , &t ) ;
		long long sum = ( 1 + t ) * t / 2 ;
		long long pow2 = 1 ;

		while ( pow2 <= t ) {
			sum -= pow2 * 2 ;
			pow2 *= 2 ;
		}
		printf ( "%lld\n" , sum ) ;
	}

	return 0 ;
}
