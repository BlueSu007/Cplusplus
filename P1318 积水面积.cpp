#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[10000 + 5] , n , leftn[10000 + 5] , rightn[10000 + 5] , maxn , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        leftn[i] = maxn ;
        maxn = max ( maxn , a[i] ) ;
    }

    maxn = 0 ;

    for ( int j = n ; j >= 1 ; j-- ) {
        rightn[j] = maxn ;
        maxn = max ( maxn , a[j] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( min ( leftn[i] , rightn[i] ) - a[i] > 0 ) {
            ans += min ( leftn[i] , rightn[i] ) - a[i] ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
