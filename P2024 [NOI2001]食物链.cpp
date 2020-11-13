#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , ans , f[300000 + 5] , op , x , y ;
inline int find ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= 3 * n ; i++ ) {
        f[i] = i ;
    }

    while ( m-- ) {
        scanf ( "%d %d %d" , &op , &x , &y ) ;
        if ( x > n || y > n ) {
            ans++ ;
            continue ;
        }

        if ( op == 1 ) {
            if ( find ( x + n ) == find (y) || find (x) == find ( y + n ) ) {
                ans++ ;
            }
            else {
                f[find (x)] = find (y) ;
                f[find ( x + n )] = find ( y + n ) ;
                f[find ( x + n + n )] = find ( y + n + n ) ;
            }
        }
        
        if ( op == 2 ) {
            if ( find (x) == find (y) || find (x) == find ( y + n ) ) {
                ans++ ;
            }
            else {
                f[find ( x + n )] = find (y) ;
                f[find ( x + n + n )] = find ( y + n ) ;
                f[find (x)] = find ( y + n + n ) ;
            }
        }
    }

    printf ( "%d\n" , ans ) ;

    return 0 ;
}

inline int find ( int x ) {
    if ( f[x] != x ) {
        return f[x] = find ( f[x] ) ;
    }

    return x ;
}
