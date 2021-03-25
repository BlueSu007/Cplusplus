#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , k , x ;
inline int pown ( int n , int k , int p ) ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &k , &x ) ;
    printf ( "%d" , ( x % n + m % n * pown ( 10 , k , n ) % n ) % n ) ;

    return 0 ;
}

inline int pown ( int n , int k , int p ) {
	long long ans = 1 , base = n ;
	while ( k ) {
		if ( k & 1 ) {
			ans *= base ;
			ans %= p ;
		}
		
		base *= base , base %= p ;
		k >>= 1 ;
	}
	
	return ans % p ;
}
