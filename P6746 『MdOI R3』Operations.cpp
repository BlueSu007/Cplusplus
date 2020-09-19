#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int a , b , c , d ;

int main () {

    scanf ( "%d %d %d %d" , &a , &b , &c , &d ) ;

    if ( a == 0 && b == 0 ) {
        printf ( "0" ) ;
    }
    else if ( a == 0 || b == 0 ) {
        printf ( "%d" , d ) ;
    }
    else if ( a == b ) {
        printf ( "%d" , min ( c , d + d ) ) ;
    }
    else {
        printf ( "%d" , min ( c + d , d + d ) ) ;
    }

    return 0 ;
}
