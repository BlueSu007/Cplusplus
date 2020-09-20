#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std ;

int n , m , a , x , ans ;
set < int > s1 , s2 ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        s1.insert (x) ;
    }

    scanf( "%d" , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &x ) ;
        s2.insert (x) ;
    }

    scanf ( "%d" , &a ) ;

    for ( auto x : s2 ) {
        if ( s1.count ( x + a ) && !s2.count ( x + a ) ) {
            ans++ ;
            s2.insert ( x + a ) ;
        }
    }

    if ( ans ) {
        printf ( "%d" , ans ) ;
    }
    else {
        printf ( "Great Set!" ) ;
    }

    return 0 ;
}
