#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct node {
    int x ;
    int y ;
    int t ;
} route[100000 + 5] ;

inline bool cmp ( node x , node y ) {
    return x.t < y.t ;
}

int n , m , f[100000 + 5] ;
inline int find ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &route[i].x , &route[i].y , &route[i].t ) ;
    }

    sort ( route + 1 , route + 1 + m , cmp ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        f[i] = i ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        int fx = find ( route[i].x ) , fy = find ( route[i].y ) ;
        if ( fx != fy ) {
            f[fx] = fy , n-- ;
        }
        if ( n == 1 ) {
            printf ( "%d" , route[i].t ) ;
            exit ( false ) ;
        }
    }

    printf ( "-1" ) ;

    return 0 ;
}

inline int find ( int x ) {
    if ( f[x] != x ) {
        return f[x] = find ( f[x] ) ;
    }

    return x ;
}
