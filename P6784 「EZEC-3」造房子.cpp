#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

inline long long read () ;
long long a , b , c ;

int main () {

    a = read () , b = read () , c = read () ;

    if ( a > b ) {
        swap ( a , b ) ;
    }

    if ( c < ( b - a ) ) {
        a += c ;
    }
    else {
        c -= ( b - a ) , a += ( b - a ) ;
        a += c / 2 , b += c / 2 ;
    }

    long long ans = 0 ;
    for ( long long i = 0 ; i * ( i + 1 ) / 2 <= a ; i++ ) {
        ans = i ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline long long read () {
    long long f = 1 , x = 0 ;
    char ch = getchar () ;

    while ( !isdigit (ch) ) {
        if ( ch == '-' ) {
            f = -1 ;
        }
        ch = getchar () ;
    }

    while ( isdigit (ch) ) {
        x = ( x << 1 ) + ( x << 3 ) + ( ch ^ 48 ) ;
        ch = getchar () ;
    }

    return f * x ;
}
