#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int map[100 + 5][100 + 5] , dp[100 + 5][100 + 5] , n , m , ans ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &map[i][j] ) ;
            if ( map[i][j] ) {
                dp[i][j] = min ( min ( dp[i - 1][j] , dp[i][j - 1] ) , dp[i - 1][j - 1] ) + 1 ;
            }
            ans = max ( ans , dp[i][j] ) ;
        }
    }
    printf ( "%d" , ans ) ;

    return 0 ;
}
