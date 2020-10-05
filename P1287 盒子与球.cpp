#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int dp[100][100] , n , m , ans = 1 ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    
    dp[0][0] = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] * j ;
        }
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        ans *= i ;
    }

    printf ( "%d" , ans * dp[n][m] ) ;

    return 0 ;
}
