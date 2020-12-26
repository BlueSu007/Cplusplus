#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n ;

int main () {

    scanf ( "%lld" , &n ) ;
    if ( n % 4 == 0 ) {
        printf ( "%lld" , n ) ;
    }
    if ( n % 4 == 1 ) {
        printf ( "1" ) ;
    }
    if ( n % 4 == 2 ) {
        printf ( "%lld" , n + 1 ) ;
    }
    if ( n % 4 == 3 ) {
        printf ( "0" ) ;
    }

    return 0 ;
}
