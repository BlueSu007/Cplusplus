#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100010
int a[LEN] , dp[LEN][2] , n , tmp ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    dp[1][0] = dp[1][1] = 1 ;

    for ( int i = 2 ; i <= n ; i++ ) {
        if ( a[i] > a[i - 1] ) {
            dp[i][0] = dp[i - 1][1] + 1 ;
        }
        else {
            dp[i][0] = dp[i - 1][0] ;
        }

        if ( a[i] < a[i - 1] ) {
            dp[i][1] = dp[i - 1][0] + 1 ;
        }
        else {
            dp[i][1] = dp[i - 1][1] ;
        }
    }

    printf ( "%d" , max ( dp[n][0] , dp[n][1] ) ) ;

    return 0 ;
}
