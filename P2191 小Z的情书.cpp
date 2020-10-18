#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[1000 + 5][1000 + 5] , cnt ;
char b[1000 + 5][1000 + 5] , c , tmp[10000] , ans[10000000 + 5] , k[1000 + 5][1000 + 5] ;
inline void turn () ;
inline void calculate () ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            cin >> c ;
            if ( c == 'O' ) {
                a[i][j] = 1 ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            cin >> b[i][j] ;
        }
    }

    for ( int i = 1 ; i <= 4 ; i++ ) {
        calculate () ;
        turn () ;
    }

    for ( int i = 0 ; i <= cnt ; i++ ) {
        printf ( "%c" , ans[i] ) ;
    }

    return 0 ;
}

inline void turn () {
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( a[i][j] ) {
                k[j][n - i + 1] = 1 ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            a[i][j] = k[i][j] , k[i][j] = 0 ;
        }
    }
}

inline void calculate () {
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( a[i][j] == 1 ) {
                ans[cnt++] = b[i][j] ;
            }
        }
    }
}
