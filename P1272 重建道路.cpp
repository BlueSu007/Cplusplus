#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

#define LEN 155
int n , p , x , y , root ;
int head[LEN] , vis[LEN] , dp[LEN][LEN] ;
vector < int > a[LEN] ;
inline int dfs ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &p ) ;
    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        a[x].push_back (y) , head[x]++ , vis[y] = true ;
    }

    memset ( dp , 0x3f , sizeof ( dp ) ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( ! vis[i] ) {
            root = i ;
        }
        dp[i][1] = head[i] ;
    }

    dfs ( root ) ;

    int ans = dp[root][p] ;
    for ( int i = 1 ; i <= n ; i++ ) {
        ans = min ( ans , dp[i][p] + 1 ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline int dfs ( int x ) {
    int len = 1 ;
    for ( int i = 0 ; i < a[x].size () ; i++ ) {
        int tmp = dfs ( a[x][i] ) ;
        len += tmp ;
        for ( int j = len ; j >= 1 ; j-- ) {
            for ( int k = 1 ; k < j ; k++ ) {
                dp[x][j] = min ( dp[x][j] , dp[x][j - k] + dp[a[x][i]][k] - 1 ) ;
            }
        }
    }

    return len ;
}
