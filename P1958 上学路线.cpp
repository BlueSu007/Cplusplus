#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , k , a[30][30] , x , y , dp[30][30] ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        a[x][y] = 1 ;
    }

    dp[1][0] = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( !a[i][j] ) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
            }
        }
    }

    printf ( "%d" , dp[n][m] ) ;

    return 0 ;
}
