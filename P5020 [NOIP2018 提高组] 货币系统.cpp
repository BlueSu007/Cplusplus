#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 25005
int dp[LEN] , a[LEN] , n , k , ans ;

int main () {

    scanf ( "%d" , &k ) ;
    while ( k-- ) {
        memset ( dp , 0 , sizeof ( dp ) ) ;
        scanf ( "%d" , &n ) ;
        ans = n ;
        
        for ( int i = 1 ; i <= n ; i++ ) {
            scanf ( "%d" , &a[i] ) ;
        }

        sort ( a + 1 , a + n + 1 ) ;
        dp[0] = 1 ;

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( dp[a[i]] ) {
                ans-- ;
                continue ;
            }

            for ( int j = a[i] ; j <= a[n] ; j++ ) {
                dp[j] = dp[j] | dp[j - a[i]] ;
            }
        }

        printf ( "%d\n" , ans ) ;
    }

    return 0 ;
}
