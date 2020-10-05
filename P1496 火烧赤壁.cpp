#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[20000 + 5] , b[20000 + 5] , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a[i] , &b[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;
    sort ( b + 1 , b + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        ans += b[i] - a[i] ;
        if ( i + 1 <= n ) {
            if ( b[i] > a[i + 1] ) {
                ans -= b[i] - a[i + 1] ;
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
