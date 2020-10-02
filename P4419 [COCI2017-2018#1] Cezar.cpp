#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int m , k , x , n , hand ;
int a[100] , box[100] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        box[a[i]]++ , hand += a[i] ;
    }

    x = 21 - hand ;

    for ( int i = x + 1 ; i <= 11 ; i++ ) {
        if ( i == 10 ) {
            m += 10 - a[i] ;
        }
        else {
            m += 4 - a[i] ;
        }
    }

    for ( int i = 1 ; i <= x ; i++ ) {
        k += 4 - a[i] ;
    }

    if ( m >= k ) {
        printf ( "DOSTA" ) ;
    }
    else {
        printf ( "VUCI" ) ;
    }

    return 0 ;
}
