#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int n , beginLevel , maxLevel , c[LEN] , dp[LEN][LEN] ;

int main () {

    scanf ( "%d %d %d" , &n , &beginLevel , &maxLevel ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &c[i] ) ;
    }

    dp[0][beginLevel] = true ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = maxLevel ; j >= 0 ; j-- ) {
            if ( dp[i - 1][j] && j + c[i] <= maxLevel ) {
                dp[i][j + c[i]] = true ;
            }
            if ( dp[i - 1][j] && j - c[i] >= 0 ) {
                dp[i][j - c[i]] = true ;
            }
        }
    }

    for ( int i = maxLevel ; i >= 0 ; i-- ) {
        if ( dp[n][i] ) {
            printf ( "%d" , i ) ;
            exit ( false ) ;
        }
    }

    puts ( "-1" ) ;

    return 0 ;
}
