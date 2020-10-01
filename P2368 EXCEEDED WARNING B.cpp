#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n ;

int main () {

    scanf ( "%d" , &n ) ;

    if ( n < 9 ) {
        printf ( "0" ) ;
    }
    else if ( n == 9 ) {
        printf ( "8" ) ;
    }
    else {
        printf ( "72" ) ;
        for ( int i = 1 ; i <= n - 10 ; i++ ) {
            printf ( "0" ) ;
        }
    }

    return 0 ;
}
