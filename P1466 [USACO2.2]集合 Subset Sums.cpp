#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 10000005
long long n , m , dp[LEN] ;

int main () {

    scanf ( "%lld" , &n ) ;
    m = ( n * ( n + 1 ) ) / 2 ;

    if ( m % 2 ) {
        printf ( "0" ) ;
        exit ( false ) ;
    }

    m /= 2 , dp[0] = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = m ; j >= i ; j-- ) {
            dp[j] += dp[j - i] ;
        }
    }

    printf ( "%lld" , dp[m] / 2 ) ;

    return 0 ;
}
