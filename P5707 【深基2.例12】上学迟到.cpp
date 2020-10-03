#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

double s , v , m ;
int n , a , t , b ;

int main () {

    scanf ( "%d %d" , &s , &v ) ;
    n = 8 * 60 + 24 * 60 ;
    t = ceil ( s / v ) + 10 ;
    n = n - t ;

    if ( n >= 24 * 60 ) {
        n -= 24 * 60 ;
    }

    a = n / 60 , b = n % 60 ;

    if ( a < 10 ) {
        if ( b < 10 ) {
            printf ( "0%d:0%d" , a , b ) ;
        }
        else {
            printf ( "0%d:%d" , a , b ) ;
        }
    }
    else {
        if ( b < 10 ) {
            printf ( "%d:0%d" , a , b ) ;
        }
        else {
            printf ( "%d:%d" , a , b ) ;
        }
    }

    return 0 ;
}
