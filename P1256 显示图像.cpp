#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int n , m , a[200][200] , dp[4][200][200] , ans ;
char c ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    memset ( dp , 0x3f , sizeof (dp) ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            a[i][j] = c - '0' ;
            if ( a[i][j] == 1 ) {
                dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = dp[3][i][j] = 0 ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( dp[0][i][j] == 0 ) {
                continue ;
            }

            dp[0][i][j] = min ( dp[0][i - 1][j] , dp[0][i][j - 1] ) ;
            dp[0][i][j] += ( dp[0][i][j] == INT_MAX ? 0 : 1 ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = m ; j >= 1 ; j-- ) {
            if ( dp[1][i][j] == 0 ) {
                continue ;
            }

            dp[1][i][j] = min ( dp[1][i - 1][j] , dp[1][i][j + 1] ) ;
            dp[1][i][j] += ( dp[1][i][j] == INT_MAX ? 0 : 1 ) ;
        }
    }

    for ( int i = n ; i >= 1 ; i-- ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( dp[1][i][j] == 0 ) {
                continue ;
            }

            dp[2][i][j] = min ( dp[2][i + 1][j] , dp[2][i][j - 1] ) ;
            dp[2][i][j] += ( dp[2][i][j] == INT_MAX ? 0 : 1 ) ;
        }
    }

    for ( int i = n ; i >= 1 ; i-- ) {
        for ( int j = m ; j >= 1 ; j-- ) {
            if ( dp[3][i][j] == 0 ) {
                continue ;
            }

            dp[3][i][j] = min ( dp[3][i + 1][j] , dp[3][i][j + 1] ) ;
            dp[3][i][j] += ( dp[3][i][j] == INT_MAX ? 0 : 1 ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            ans = min ( min ( dp[0][i][j] , dp[1][i][j] ) , min ( dp[2][i][j] , dp[3][i][j] ) ) ;
            printf ( "%d " , ans ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}
