#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 10005
int k , n , m , head[LEN] , endn[LEN] , nextn[LEN] , cnt ;
int u , v , x , ans , dp[LEN] , vis[LEN] ;
inline void addEdge ( int u , int v ) ;
inline void dfs ( int x ) ;

int main () {

    scanf ( "%d %d %d" , &k , &n , &m ) ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d" , &x ) ;
        dp[x] = 1 ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( v , u ) ;
    }

    int ans = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        bool flag = false ;
        memset ( vis , 0 , sizeof ( vis ) ) ;
        dfs (i) ;
        
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( vis[j] != 1 && dp[j] == 1 ) {
                flag = true ;
                break ;
            }
        }

        if ( ! flag ) {
            ans++ ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    endn[++cnt] = v ;
    nextn[cnt] = head[u] ; 
    head[u] = cnt ;
}

inline void dfs ( int x ) {
    vis[x] = true ;
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        if ( ! vis[endn[i]] ) {
            dfs ( endn[i] ) ;
        }
    }
}
