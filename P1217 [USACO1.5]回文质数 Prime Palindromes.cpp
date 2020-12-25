#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

int leftbound , rightbound ;
inline bool isPrime ( int x ) ;
inline bool isReverse ( int x ) ;
inline bool isEvenDigit ( int x ) ;

int main () {

	scanf ( "%d %d" , &leftbound , &rightbound ) ;
	rightbound = min ( rightbound , 9999999 ) , leftbound += ( leftbound + 1 ) % 2 ;
	for ( int i = leftbound ; i <= rightbound ; i += 2 ) {
		if ( isEvenDigit (i) && isReverse (i) && isPrime (i) ) {
			printf ( "%d\n" , i ) ;
		}
	}

	return 0 ;
}

inline bool isPrime ( int x ) {
	for ( int i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			return false ;
		}
	}

	return true ;
}

inline bool isReverse ( int x ) {
	int a[20] , cnt = 1 ;
	while ( x ) {
		a[cnt] = x % 10 ;
		x /= 10 , cnt++ ;
	}

	for ( int i = 1 ; i <= cnt / 2 ; i++ ) {
		if ( a[i] != a[cnt - i] ) {
			return false ;
		}
	}

	return true ;
}

inline bool isEvenDigit ( int x ) {
	if ( ( x >= 1000 && x <= 9999 ) || ( x >= 100000 && x <= 999999 ) ) {
		return false ;
	}

	return true ;
}
