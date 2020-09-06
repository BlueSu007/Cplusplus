#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , x[50 + 5] , y[50 + 5] , z[50 + 5] , ans , sx , sy , ex , ey ;
inline double distance ( int x1 , int y1 , int x2 , int y2 ) {
    return sqrt ( pow ( ( x1 - x2 ) , 2 ) + pow ( ( y1 - y2 ) , 2 ) ) ;
}

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x[i] ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &y[i] ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &z[i] ) ;
    }
    scanf ( "%d %d %d %d" , &sx , &sy , &ex , &ey ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( distance ( sx , sy , x[i] , y[i] ) > z[i] ^ distance ( ex , ey , x[i] , y[i] ) > z[i] ) {
            ans++ ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
