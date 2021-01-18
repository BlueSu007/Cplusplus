#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 1005
int n , m , dp[LEN][LEN] , cnt , father ;
int head[LEN] , endn[LEN] , nextn[LEN] ;
inline void addEdge ( int u , int v ) ;
inline void treeDP ( int x ) ;

int main () {
    
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &father , &dp[i][1] ) ;
        addEdge ( father , i ) ;
    }

    treeDP (0) ;
    printf ( "%d" , dp[0][m + 1] ) ;

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    nextn[++cnt] = head[u] ;
    endn[cnt] = v ;
    head[u] = cnt ;
}

inline void treeDP ( int x ) {
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        int tmp = endn[i] ;
        treeDP ( tmp ) ;
        
        for ( int j = m + 1 ; j >= 1 ; j-- ) {
            for ( int k = 0 ; k < j ; k++ ) {
                dp[x][j] = max ( dp[x][j] , dp[tmp][k] + dp[x][j - k] ) ;
            }
        }
    }
}
