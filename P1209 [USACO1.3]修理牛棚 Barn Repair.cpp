#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int m , s , c , ans ;
int a[200 + 5] , b[200 + 5] ;
inline void input () ;
inline void work () ;

inline bool cmp ( int x , int y ) {
    return x > y ;
}

int main () {

    input () ;
    work () ;
    printf ( "%d\n" , ans ) ;

    return 0 ;
}

inline void input () {
    scanf ( "%d %d %d" , &m , &s , &c ) ;
    for ( int i = 1 ; i <= c ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    if ( m > c ) {
        printf ( "%d\n" , c ) ;
        exit(0) ;
    }
}

inline void work () {
    sort ( a + 1 , a + c + 1 ) ;
    ans = a[c] - a[1] + 1 ;

    for ( int i = 2 ; i <= c ; i++ ) {
        b[i - 1] = a[i] - a[i - 1] ;
    }

    sort ( b + 1 , b + c + 1 , cmp ) ;

    for ( int i = 1 ; i <= m - 1 ; i++ ) {
        ans = ans - b[i] + 1 ;
    }
}
