#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , head[20000 + 5] , army[20000 + 5] , ans ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &head[i] ) ;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &army[i] ) ;
    }

    sort ( head + 1 , head + 1 + n ) ;
    sort ( army + 1 , army + 1 + m ) ;

    int j = 1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        while ( j <= m && army[j] < head[i] ) {
            j++ ;
        }
        if ( j > m ) {
            printf ( "you died!" ) ;
            exit ( false ) ;
        }

        ans += army[j] , j++ ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
