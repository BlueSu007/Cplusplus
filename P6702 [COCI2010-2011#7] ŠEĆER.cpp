#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#define MAX 19260817
using namespace std ;

int dp[5000 + 5] , n ;

int main () {

    scanf ( "%d" , &n )  ;
    for ( int i = 1 ; i <= n ; i++ ) {
        dp[i] = INT_MAX - 1 ;
    }

    dp[0] = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( i >= 3 ) {
            dp[i] = min ( dp[i] , dp[i - 3] + 1 ) ;
        }
        if ( i >= 5 ) {
            dp[i] = min ( dp[i] , dp[i - 5] + 1 ) ;
        }
    }

    if ( dp[n] == INT_MAX - 1 ) {
        printf ( "-1" ) ;
    }
    else {
        printf ( "%d" , dp[n] ) ;
    }

    return 0 ;
}
