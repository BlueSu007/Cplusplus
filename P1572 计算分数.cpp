#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a , b , c , d ;
inline int gcd ( int x , int y ) ;

int main () {

    scanf ( "%d/%d" , &a , &b ) ;
    while ( scanf ( "%d/%d" , &c , &d ) != EOF ) {
        int tmp = gcd ( b , d ) ;
        a *= d / tmp , c *= b / tmp ;
        a += c ;

        b *= d / tmp ;
        tmp = gcd ( a , b ) ;
        a /= tmp , b /= tmp ;
    }

    if ( b < 0 ) {
        b = -b , a = -a ;
    }

    if ( b == 1 ) {
        printf ( "%d" , a ) ;
    }
    else {
        printf ( "%d/%d" , a , b ) ;
    }

    return 0 ;
}

inline int gcd ( int x , int y ) {
    if ( y == 0 ) {
        return x ;
    }

    return gcd ( y , x % y ) ;
}
