#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n ;

int main () {

    scanf ( "%d" , &n ) ;
    if ( n < 3 ) {
        printf ( "0" ) ;
        exit(0) ;
    }
    printf ( "%d" , n - 2 ) ;

    return 0 ;
}
