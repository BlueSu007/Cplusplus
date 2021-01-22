#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
long long n , m , map[LEN][LEN] , dp[LEN][LEN][2] ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%lld" , &map[j][i] ) ;
        }
    }

    swap ( n , m ) ;
    for ( int i = 0 ; i <= n + 1 ; i++ ) {
        for ( int j = 0 ; j <= m + 1 ; j++ ) {
            dp[i][j][0] = dp[i][j][1] = -1e18 ;
            dp[1][1][0] = dp[1][1][1] = map[1][1] ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( i != 1 ) {
                dp[i][j][0] = max ( dp[i][j][0] , max ( dp[i - 1][j][0] , dp[i - 1][j][1] ) + map[i][j] ) ;
                dp[i][j][1] = max ( dp[i][j][1] , max ( dp[i - 1][j][0] , dp[i - 1][j][1] ) + map[i][j] ) ;
            }
            if ( j != 1 ) {
                dp[i][j][0] = max ( dp[i][j][0] , dp[i][j - 1][0] + map[i][j] ) ;
            }
        }

        for ( int j = m ; j >= 1 ; j-- ) {
            if ( j != m ) {
                dp[i][j][1] = max ( dp[i][j][1] , dp[i][j + 1][1] + map[i][j] ) ;
            }
        }
    }

    printf ( "%lld" , max ( dp[n][m][0] , dp[n][m][1] ) ) ;

    return 0 ;
}
