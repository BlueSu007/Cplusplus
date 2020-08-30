#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a , b , c , d , n ;

inline int gcd ( int x , int y ) {
    if ( y == 0 ) {
        return x ;
    }

    return gcd ( y , x % y ) ;
}

int main () {

    scanf ( "%d/%d %d/%d" , &a , &b , &c , &d) ;
    a *= c , b *= d ;
    n = gcd ( a , b ) ;
    a /= n , b /= n ;
    printf ( "%d %d" , b , a ) ;

    return 0 ;
}
