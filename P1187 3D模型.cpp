#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000 + 5][1000 + 5] , n , m , ans ;
char c ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            /*
            scanf ( "%c" , &c ) ;
            if ( isdigit(c) ) {
                a[i][j] = c - '0' ;
            }
            else {
                scanf ( "%c" , &c ) ;
                a[i][j] = c - '0' ;
            }
            */
           cin >> c ;
           a[i][j] = c - '0' ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            ans += ( bool ) a[i][j] ;
        }
    }
    ans *= 2 ;

    // cout << ans << " " ;

    for ( int i = 1 ; i <= n + 1 ; i++ ) {
        for ( int j = 1 ; j <= m + 1 ; j++ ) {
            ans += abs ( a[i - 1][j] - a[i][j] ) ;
        }
    }

    // cout << ans << " " ;

    for ( int i = 1 ; i <= n + 1 ; i++ ) {
        for ( int j = 1 ; j <= m + 1 ; j++ ) {
            ans += abs ( a[i][j - 1] - a[i][j] ) ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
