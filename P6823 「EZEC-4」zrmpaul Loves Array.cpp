#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000000 + 5] , b[1000000 + 5] , x[1000000 + 5] , y[1000000 + 5] , n , m ;
inline bool cmp ( int x , int y ) ;
inline void reverse () ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = i ;
    }
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &b[i] ) ;
        if ( b[i] == 3 ) {
            scanf ( "%d %d" , &x[i] , &y[i] ) ;
        }
    }

    int last ;
    for ( last = m ; last ; last-- ) {
        if ( b[last] == 1 || b[last] == 2 ) {
            break ;
        }
    }

    int tmp ;
    if ( b[last] == 2 ) {
        tmp = 1 ;
    }
    else {
        tmp = 0 ;
    }

    for ( int i = last + 1 ; i <= m ; i++ ) {
        if ( b[i] == 3 ) {
            if ( !tmp ) {
                swap ( a[x[i]] , a[y[i]] ) ;
            }
            else {
                swap ( a[n - x[i] + 1] , a[n - y[i] + 1] ) ;
            }
        }
        else {
            tmp = 1 - tmp ;
        }
    }

    if ( tmp == 0 ) {
        for ( int i = 1 ; i <= n ; i++ ) {
            printf ( "%d " , a[i] ) ;
        }
    }
    else {
        for ( int i = n ; i ; i-- ) {
            printf ( "%d " , a[i] ) ;
        }
    }

    return 0 ;
}

inline bool cmp ( int x , int y ) {
    return x > y ;
}

inline void reverse () {
    for ( int i = 1 ; i <= n / 2 ; i++ ) {
        swap ( a[i] , a[n - i + 1] ) ;
    }
}
