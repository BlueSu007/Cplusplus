#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , step , emptyPos ;
char c[1000] ;
inline void move ( int x ) ;
inline void work ( int n ) ;
inline void print () ;

int main () {

    scanf ( "%d" , &n ) ;
    emptyPos = 2 * n + 1 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        c[i] = 'o' ;
    }
    for ( int i = n + 1 ; i <= 2 * n ; i++ ) {
        c[i] = '*' ;
    }

    c[2 * n + 1] = '-' ;
    c[2 * n + 2] = '-' ;

    // printf ( "step 0:" ) ;
    for ( int i = 1 ; i <= 2 * n + 2 ; i++ ) {
        printf ( "%c" , c[i] ) ;
    }
    printf ( "\n" ) ;
    work (n) ;

    return 0 ;
}

inline void move ( int x ) {
    // cout << "BreakPoint1" << endl ;
    for ( int i = 0 ; i <= 1 ; i++ ) {
        c[emptyPos + i] = c[x + i] ;
        c[x + i] = '-' ;
    }
    emptyPos = x ;
    print () ;
}

inline void work ( int n ) {
    // cout << "BreakPoint2" << endl ;
    if ( n == 4 ) {
        move (4) , move (8) , move (2) , move (7) , move (1) ;
    }
    else {
        move (n) , move ( 2 * n - 1 ) , work ( n - 1 ) ;
    }
}

inline void print () {
    // printf ( "step %d:" , ++step ) ;
    for ( int i = 1 ; i <= 2 * n + 2 ; i++ ) {
        printf ( "%c" , c[i] ) ;
    }
    printf ( "\n" ) ;
}
