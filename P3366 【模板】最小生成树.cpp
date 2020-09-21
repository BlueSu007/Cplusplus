#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int start ;
    int end ;
    int weight ;

    bool operator < ( Edge tmp ) {
        return weight < tmp.weight ;
    }
} edge[500000 + 5] ;

int n , m , x , y , z , cnt , ans ;
int a[500000 + 5] ;
inline void input () ;
inline void init () ;
inline int find ( int x ) ;
inline void kruskal () ;

int main () {

    input () ;
    init () ;
    kruskal () ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void input () {
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &x , &y , &z ) ;
        edge[i].start = x , edge[i].end = y , edge[i].weight = z ;
    }
}

inline void init () {
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = i ;
    }
}

inline int find ( int x ) {
    if ( a[x] != x ) {
        a[x] = find ( a[x] ) ;
    }

    return a[x] ;
}

inline void kruskal () {

    sort ( edge + 1 , edge + 1 + m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        int estart = find ( edge[i].start ) ;
        int eend = find ( edge[i].end ) ;
        if ( estart == eend ) {
            continue ;
        }

        ans += edge[i].weight ;
        a[eend] = estart ;

        if ( ++cnt == n - 1 ) {
            break ;
        }
    }
}
