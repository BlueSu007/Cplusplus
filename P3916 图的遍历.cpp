#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
int head[LEN] , nextn[LEN] , endn[LEN] , cnt ;
int n , m , u , v , ans[LEN] ;
inline void addEdge ( int u , int v ) ;
inline void dfs ( int cur , int start ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( v , u ) ;
    }

    for ( int i = n ; i >= 1 ; i-- ) {
        if ( ! ans[i] ) {
            dfs ( i , i ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , ans[i] ) ;
    }

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    endn[++cnt] = v , nextn[cnt] = head[u] , head[u] = cnt ;
}

inline void dfs ( int cur , int start ) {
    if ( ans[cur] ) {
        return ;
    }

    ans[cur] = start ;

    for ( int i = head[cur] ; i ; i = nextn[i] ) {
        dfs ( endn[i] , start ) ;
    }
}
