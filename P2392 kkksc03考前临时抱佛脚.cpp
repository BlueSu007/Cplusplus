#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[5] , sum , ans , b[20 + 5] , dp[2500 + 5] ;

int main () {

    for ( int i = 1 ; i <= 4 ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= 4 ; i++ ) {
        sum = 0 ;
        for ( int j = 1 ; j <= a[i] ; j++ ) {
            scanf ( "%d" , &b[j] ) ;
            sum += b[j] ;
        }

        for ( int j = 1 ; j <= a[i] ; j++ ) {
            for ( int k = sum / 2 ; k >= b[j] ; k-- ) {
                dp[k] = max ( dp[k] , dp[k - b[j]] + b[j] ) ;
            }
        }

        ans += sum - dp[sum / 2] ;
        for ( int j = 1 ; j <= sum / 2 ; j++ ) {
            dp[j] = 0 ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
