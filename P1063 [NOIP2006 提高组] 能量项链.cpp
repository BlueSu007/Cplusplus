#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 205
int n , a[LEN] , dp[LEN][LEN] , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        a[i + n] = a[i] ;
    }

    for ( int len = 2 ; len <= n ; len++ ) {
        for ( int leftn = 1 ; leftn + len - 1 <= 2 * n ; leftn++ ) {
            int rightn = leftn + len - 1 ;
            for ( int k = leftn ; k < rightn ; k++ ) {
                dp[leftn][rightn] = max ( dp[leftn][rightn] , ( dp[leftn][k] + dp[k + 1][rightn] + a[leftn] * a[k + 1] * a[rightn + 1] ) ) ;
            }

            if ( len == n ) {
                ans = max ( ans , dp[leftn][rightn] ) ;
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
