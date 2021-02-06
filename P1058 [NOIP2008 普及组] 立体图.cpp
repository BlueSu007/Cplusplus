#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1000
const char block[6][8] = { "..+---+" , "./   /|", "+---+ |", "|   | +", "|   |/.", "+---+.." } ;
int n , m , x , y , wide , length , a[LEN][LEN] ;
char map[LEN][LEN] ;
inline void paint ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    wide = 4 * m + 2 * n + 1 ;
    
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
            length = max ( length , a[i][j] * 3 + 2 * ( n - i + 1 ) + 1 ) ;
        }
    }

    for ( int i = 1 ; i <= length ; i++ ) {
        for ( int j = 1 ; j <= wide ; j++ ) {
            map[i][j] = '.' ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            x = length - 2 * ( n - i ) ;
            y = 2 * ( n - i ) + 4 * ( j - 1 ) + 1 ;

            while ( a[i][j]-- ) {
                paint ( x , y ) ;
                x -= 3 ;
            }
        }
    }

    for ( int i = 1 ; i <= length ; i++ ) {
        for ( int j = 1 ; j <= wide ; j++ ) {
            printf ( "%c" , map[i][j] ) ;
        }
        printf ( "\n" ) ;
    }

    return 0 ;
}

inline void paint ( int x , int y ) {
    for ( int i = 0 ; i < 6 ; i++ ) {
        for ( int j = 0 ; j < 7 ; j++ ) {
            if ( block[6 - i - 1][j] != '.' ) {
                map[x - i][y + j] = block[6 - i - 1][j] ;
            }
        }
    }
}
