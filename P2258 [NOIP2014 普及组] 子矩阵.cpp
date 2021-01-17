#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 25
int n , m , r , c , a[LEN][LEN] , ans = INT_MAX , rightBound , cnt = 1 ;
int route[LEN] , colSum[LEN] , rowSum[LEN][LEN] , dp[LEN][LEN] ;
inline void pretreatment () ;
inline void DP () ;
inline void dfs ( int step ) ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &r , &c ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
        }
    }

    dfs (1) ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void pretreatment () {
    for ( int i = 1 ; i <= m ; i++ ) {
        colSum[i] = 0 ;
        for ( int j = 1 ; j < r ; j++ ) {
            colSum[i] += abs ( a[route[j]][i] - a[route[j + 1]][i] ) ;
        }
    }

    for ( int i = 2 ; i <= m ; i++ ) {
        for ( int j = 1 ; j < i ; j++ ) {
            rowSum[i][j] = 0 ;
            for ( int k = 1 ; k <= r ; k++ ) {
                rowSum[i][j] += abs ( a[route[k]][i] - a[route[k]][j] ) ;
            }
        }
    }
}

inline void DP () {
    for ( int i = 1 ; i <= m ; i++ ) {
        rightBound = min ( i , c ) ;
        for ( int j = 1 ; j <= rightBound ; j++ ) {
            if ( j == 1 ) {
                dp[i][j] = colSum[i] ;
            }
            else {
                if ( i == j ) {
                    dp[i][j] = dp[i - 1][j - 1] + colSum[i] + rowSum[i][j - 1] ;
                }
                else {
                    dp[i][j] = 2e8 ;
                    for ( int k = j - 1 ; k < i ; k++ ) {
                        dp[i][j] = min ( dp[i][j] , dp[k][j - 1] + colSum[i] + rowSum[i][k] ) ;
                    }
                }
            }

            if ( j == c ) {
                ans = min ( ans , dp[i][c] ) ;
            }
        }
    }
}

inline void dfs ( int step ) {
    if ( step > n ) {
        pretreatment () , DP () ;
        return ;
    }

    if ( r - cnt + 1 == n - step + 1 ) {
        route[cnt++] = step ;
        dfs ( step + 1 ) ;
        route[cnt--] = 0 ;
        return ;
    }

    dfs ( step + 1 ) ;
    if ( cnt <= r ) {
        route[cnt++] = step ;
        dfs ( step + 1 ) ;
        route[cnt--] = 0 ;
    }
}
