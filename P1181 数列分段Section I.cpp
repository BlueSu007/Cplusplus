#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , a[100000 + 5] , ans = 1 , cnt ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        cnt += a[i] ;
        if ( cnt > m ) {
            ans++ ;
            cnt = a[i] ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
