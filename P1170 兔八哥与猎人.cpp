#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , a , b , c , d ;

int main () {

    scanf ( "%d" , &n ) ;
    while ( n-- ) {
        scanf ( "%d %d %d %d" , &a , &b , &c , &d ) ;
        if ( abs( __gcd ( a - c , b - d ) ) > 1 ) {
            printf ( "yes\n" ) ;
        }
        else {
            printf ( "no\n" ) ;
        }
    }

    return 0 ;
}
