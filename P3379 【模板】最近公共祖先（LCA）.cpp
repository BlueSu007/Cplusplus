#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 500100
int n , q , u , v , root , depth[LEN] , f[LEN][20] ;
int head[LEN] , nextn[LEN * 2] , endn[LEN * 2] , cnt ;
inline void addEdge ( int u , int v ) ;
inline void dfs ( int cur ) ;
inline int LCA ( int u , int v ) ;

int main () {

    scanf ( "%d %d %d" , &n , &q , &root ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( u , v ) , addEdge ( v , u ) ;
    }

    dfs ( root ) ;

    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d %d" , &u , &v ) ;
        printf ( "%d\n" , LCA ( u , v ) ) ;
    }

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    ++ cnt , nextn[cnt] = head[u] ;
    head[u] = cnt , endn[cnt] = v ;
}

inline void dfs ( int cur ) {
    depth[cur] = depth[f[cur][0]] + 1 ;
    for ( int j = 1 ; j <= 19 ; ++ j ) {
        f[cur][j] = f[f[cur][j - 1]][j - 1] ;
    }

    for ( int j = head[cur] ; j > 0 ; j = nextn[j] ) {
        if ( endn[j] != f[cur][0] ) {
            f[endn[j]][0] = cur ;
            dfs ( endn[j] ) ;
        }
    }
}

inline int LCA ( int u , int v ) {
    if ( depth[u] != depth[v] ) {
        if ( depth[u] < depth[v] ) {
            swap ( u , v ) ;
        }

        for ( int j = 19 ; j >= 0 ; -- j ) {
            if ( depth[f[u][j]] >= depth[v] ) {
                u = f[u][j] ;
            }
        }
    }

    if ( u == v ) {
        return u ;
    }

    for ( int j = 19 ; j >= 0 ; -- j ) {
        if ( f[u][j] != f[v][j] ) {
            u = f[u][j] ;
            v = f[v][j] ;
        }
    }

    return f[u][0] ;
}
