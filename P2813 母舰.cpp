#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , you[100000 + 5] , me[100000 + 5] , ans , j = 1 ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &you[i] ) ;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &me[i] ) ;
    }

    sort ( you + 1 , you + 1 + n ) ;
    sort ( me + 1 , me + 1 + m ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        if ( you[j] == 0 ) {
            j++ ;
        }
        if ( me[i] > you[j] && you[j] ) {
            j++ , me[i] = 0 ;
        }
    }

    if ( j <= n ) {
        printf ( "0" ) ;
        exit ( false ) ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        ans += me[i] ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
