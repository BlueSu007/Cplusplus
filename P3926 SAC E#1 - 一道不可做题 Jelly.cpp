#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long ans , a , c , p , q , r , x ;

int main () {

    scanf ( "%lld %lld %lld %lld %lld %lld" , &a , &c , &p , &q , &r , &x ) ;
    
    if ( a > c ) {
        printf ( "%lld" , a + x / r ) ;
    }
    else if ( a == c ) {
        if ( x <= q ) {
            printf ( "%lld" , c ) ;
        }
        else {
            printf ( "%lld" , c + ( x - q ) / r ) ;
        }
    }
    else if ( a < c ) {
        if ( x <= ( c - a ) * p ) {
            printf ( "%lld" , a + ( x / p ) ) ;
        }
        else {
            x -= ( c - a ) * p ;
            if ( q >= x ) {
                printf ( "%lld" , c ) ;
            }
            else {
                x -= q ;
                printf ( "%lld" , c + x / r ) ;
            }
        }
    }

    return 0 ;
}
