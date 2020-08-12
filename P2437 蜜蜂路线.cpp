#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , len = 1 , a[1000 + 5][1000 + 5] ;
inline void add ( int k ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    a[1][1] = 1 ;
    a[2][1] = 2 ;

    for ( int i = 3 ; i <= m - n ; i++ ) {
        add (i) ;
    }

    for ( int i = len ; i >= 1 ; i-- ) {
        printf ( "%d" , a[m - n][i] ) ;
    }
    
    return 0 ;
}

inline void add ( int k ) {
    for ( int i = 1 ; i <= len ; i++ ) {
        a[k][i] = a[k - 1][i] + a[k - 2][i] ;
    }

    for ( int i = 1 ; i <= len ; i++ ) {
        if ( a[k][i] >= 10 ) {
            a[k][i + 1] += a[k][i] / 10 ;
            a[k][i] = a[k][i] % 10 ;
            if ( a[k][len + 1] ) {
                len++ ;
            }
        }
    }
}
