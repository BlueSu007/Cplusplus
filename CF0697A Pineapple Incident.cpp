#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

long long t , s , x ;

int main () {

	scanf ( "%lld %lld %lld" , &t , &s , &x ) ;
	long long time = t ;

	while ( time <= x ) {
		if ( time == x || ( ( time + 1 == x ) && time != t ) ) {
			printf ( "YES" ) ;
			exit ( false ) ;
		}
		time += s ;
	}

	printf ( "NO" ) ;

	return 0 ;
}
