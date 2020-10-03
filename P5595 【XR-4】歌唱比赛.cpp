#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

char c , lastChar = ' ' ;
int i , x[1000000 + 5] , y[1000000 + 5] ;

int main () {

    while ( scanf ( "%c" , &c ) != EOF ) {
        if ( c == '\n' || c == '\r' ) {
            break ;
        }
        if ( lastChar == 'Z' && c != 'Z' ) {
            printf ( "-1" ) ;
            exit(0) ;
        }

        if ( c == 'X' ) {
            i++ , x[i] = 3 , y[i] = 2 , lastChar = c ;
        }
        if ( c == 'Y' ) {
            i++ , x[i] = 2 , y[i] = 3 , lastChar = c ;
        }
        if ( c == 'Z' ) {
            i++ , x[i] = 3 , y[i] = 3 , lastChar = c ;
        }
        // cout << c << ' ' ;
    }

    // reverse ( x + 1 , x + 1 + i ) ;
    // reverse ( y + 1 , y + 1 + i ) ;

    for ( int j = 1 ; j <= i ; j++ ) {
        printf ( "%d" , x[j] ) ;
    }
    printf ( "\n" ) ;
    for ( int j = 1 ; j <= i ; j++ ) {
        printf ( "%d" , y[j] ) ;
    }

    return 0 ;
}
