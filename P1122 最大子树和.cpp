#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
int n , a[LEN] , head[LEN] , nextn[LEN] , endn[LEN] ;
int cnt , dp[LEN] , ans , u , v ;
inline void addEdge ( int u , int v ) ;
inline void treeDP ( int x , int father ) ;

int main () {
    
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( u , v ) ;
        addEdge ( v , u ) ;
    }

    treeDP ( 1 , 0 ) ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    nextn[++cnt] = head[u] ;
    endn[cnt] = v ;
    head[u] = cnt ;
}

inline void treeDP ( int x , int father ) {
    dp[x] = a[x] ;
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        int y = endn[i] ;
        if ( y != father ) {
            treeDP ( y , x ) ;
            dp[x] += max ( 0 , dp[y] ) ;
        }
    }

    ans = max ( ans , dp[x] ) ;
}
