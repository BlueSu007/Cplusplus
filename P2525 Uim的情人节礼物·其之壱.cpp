#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[100] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    if ( prev_permutation ( a + 1 , a + 1 + n ) ) {
        for ( int i = 1 ; i <= n ; i++ ) {
            printf ( "%d " , a[i] ) ;
        }
    }
    else {
        printf ( "ERROR" ) ;
    }

    return 0 ;
}
