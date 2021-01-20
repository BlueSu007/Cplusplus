#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , a[300005] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;
    n = unique ( a + 1 , a + 1 + n ) - a - 1 ;

    a[0] = 0 ;

    if ( n <= 1 ) {
        printf ( "-1" ) ;
    }
    else {
        printf ( "%d" , max ( a[n - 2] , a[n] % a[n - 1] ) ) ;
    }

    return 0 ;
}
