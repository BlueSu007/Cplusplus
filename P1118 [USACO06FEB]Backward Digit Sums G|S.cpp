#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , dp[100][100] , a[50000] , vis[50000] ;
inline void dfs ( int step , int sum ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    
    dp[1][1] = 1 ;
    for ( int i = 2 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= i ; j++ ) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] ;
        }
    }

    dfs ( 0 , 0 ) ;

    return 0 ;
}

inline void dfs ( int step , int sum ) {
    if ( sum > m ) {
        return ;
    }

    if ( step == n ) {
        if ( sum == m ) {
            for ( int i = 1 ; i <= n ; i++ ) {
                printf ( "%d " , a[i] ) ;
            }

            exit ( false ) ;
        }

        return ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( !vis[i] ) {
            vis[i] = true , a[step + 1] = i ;
            dfs ( step + 1 , sum + i * dp[n][step + 1] ) ;
            vis[i] = false ;
        }
    }
}
