#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1000005
int n , m , x , y , a[LEN] , sum[LEN] ;
inline int read () ;
inline void write ( int x ) ;
inline int lowbit ( int x ) ;
inline void update ( int x , int k ) ;
inline int query ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( register int i = 1 ; i <= n ; i++ ) {
        // scanf ( "%d" , &a[i] ) ;
        a[i] = read () ;
        update ( i , a[i] ) ;
    }

    for ( register int i = 1 ; i <= m ; i++ ) {
        // scanf ( "%d %d" , &x , &y ) ;
        x = read () , y = read () ;
        // printf ( "%d\n" , query ( x , y ) ) ;
        write ( query ( x , y ) ) ;
        printf ( "\n" ) ;
    }

    return 0 ;
}

inline int read () {
    int f = 1 , x = 0 ;
    char c = getchar () ;
    while ( ! isdigit (c) ) {
        if ( c == '-' ) {
            f = -1 ;
        }
        c = getchar () ;
    }

    while ( isdigit (c) ) {
        x = ( x << 1 ) + ( x << 3 ) + ( c ^ 48 ) ;
        c = getchar () ;
    }

    return f * x ;
}

inline void write ( int x ) {
    if ( x < 0 ) {
        putchar ( '-' ) ;
        x = -x ;
    }
    if ( x > 9 ) {
        write ( x / 10 ) ;
    }

    putchar ( x % 10 + '0' ) ;
}

inline int lowbit ( int x ) {
    return x & -x ;
}

inline void update ( int x , int k ) {
    while ( x <= n ) {
        sum[x] = max ( sum[x] , k ) ;
        x += lowbit (x) ;
    }
}

inline int query ( int x , int y ) {
    if ( y > x ) {
        if ( y - lowbit (y) > x ) {
            return max ( sum[y] , query ( x , y - lowbit (y) ) ) ;
        }
        else {
            return max ( a[y] , query ( x , y - 1 ) ) ;
        }
    }

    return a[x] ;
}
