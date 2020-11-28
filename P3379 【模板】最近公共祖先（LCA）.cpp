#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 500005
int n , q , root , u , v , head[LEN] , nextn[LEN * 2] , endn[LEN * 2] , cnt ;
int depth[LEN] , father[LEN] ;
inline void addEdge ( int u , int v ) ;
inline void dfs ( int x ) ;
inline int LCA ( int u , int v ) ;

int main () {

    scanf ( "%d %d %d" , &n , &q , &root ) ;
    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( u , v ) , addEdge ( v , u ) ;
    }

    dfs ( root ) ;

    for ( int i = 1 ; i <= q ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        int tmp = LCA ( u , v ) ;
        printf ( "%d\n" , tmp ) ;
    }

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    cnt++ , nextn[cnt] = head[u] ;
    head[u] = cnt , endn[cnt] = v ;
}

inline void dfs ( int x ) {
    depth[x] = depth[father[x]] + 1 ;
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        if ( endn[i] != father[x] ) {
            father[endn[i]] = x ;
            dfs ( endn[i] ) ;
        }
    }
}

inline int LCA ( int u , int v ) {
    if ( depth[u] != depth[v] ) {
        if ( depth[u] < depth[v] ) {
            swap ( u , v ) ;
        }

        while ( depth[u] > depth[v] ) {
            u = father[u] ;
        }
    }

    while ( u != v ) {
        u = father[u] ;
        v = father[v] ;
    }

    return u ;
}
