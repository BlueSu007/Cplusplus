#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u , v , w ;
    bool operator < ( Edge tmp ) const {
        return w < tmp.w ;
    }
} edge[10000 + 5] ;

int n , m , k , x , y , l , sum , ans ;
int a[1000 + 5] ;
inline int find ( int x ) ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = i ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &edge[i].u , &edge[i].v , &edge[i].w ) ;
    }

    sort ( edge + 1 , edge + m + 1 ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        int tmpx = find ( edge[i].u ) , tmpy = find ( edge[i].v ) ;
        if ( tmpx != tmpy ) {
            a[tmpx] = tmpy ;
            sum++ ;
            ans += edge[i].w ;
        }

        if ( sum == n - k ) {
            printf ( "%d" , ans ) ;
            exit(0) ;
        }
    }

    printf ( "No Answer" ) ;

    return 0 ;
}

inline int find ( int x ) {
    if ( a[x] != x ) {
        a[x] = find ( a[x] ) ;
    }

    return a[x] ;
}
