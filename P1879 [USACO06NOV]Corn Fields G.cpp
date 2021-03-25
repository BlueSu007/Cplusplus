#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define MOD 100000000
long long dp[15][5000] , a[15] , n , m , x ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            scanf ( "%d" , &x ) ;
            a[i] |= ( x << j ) ;
        }
    }

    dp[0][0] = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = a[i] ; j > 0 ; j = ( j - 1 ) & a[i] ) {
            if ( j & ( j << 1 ) ) {
                continue ;
            }

            int tmp = ( 1 << m ) - j - 1 ;
            for ( int k = tmp ; k > 0 ; k = ( k - 1 ) & tmp ) {
                if ( k & ( k << 1 ) ) {
                    continue ;
                }

                dp[i][j] += dp[i - 1][k] ;
                dp[i][j] %= MOD ;
            }

            dp[i][j] += dp[i - 1][0] ;
            dp[i][j] %= MOD ;
        }

        int tmp = ( 1 << m ) - 1 ;
        for ( int k = tmp ; k > 0 ; k = ( k - 1 ) & tmp ) {
            if ( k & ( k << 1 ) ) {
                continue ;
            }

            dp[i][0] += dp[i - 1][k] ;
            dp[i][0] %= MOD ;
        }

        dp[i][0] += dp[i - 1][0] ;
        dp[i][0] %= MOD ;
    }

    long long ans = 0 ;
    for ( int i = 0 ; i < ( 1 << m ) ; i++ ) {
        ans += dp[n][i] ;
        ans %= MOD ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
