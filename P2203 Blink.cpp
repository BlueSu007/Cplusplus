#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[1 << 16] , b[1 << 16] , n , m = 1 , x ;
long long k ;

int main () {

    scanf ( "%d %lld" , &n , &k ) ;
    for ( register int i = 0 ; i < n ; i++ ) {
        scanf ( "%d" , &x ) ;
        a[1] |= x << i ;
    }

    for ( ; ! b[a[m]] ; m++ ) {
        b[a[m]] = m ;
        a[m + 1] = a[m] ^ ( a[m] << 1 & ( ( 1 << n ) - 1 ) ) ^ ( a[m] >> ( n - 1 ) ) ;
    }

    if ( ++k >= m ) {
        k = ( k - b[a[m]] ) % ( m - b[a[m]] ) + b[a[m]] ;
    }
    for ( register int i = 0 ; i < n ; i++ ) {
        printf ( "%d\n" , a[k] >> i & 1 ) ;
    }

    return 0 ;
}
