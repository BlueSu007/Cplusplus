#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

int n , m , a[1000 + 5] , dp[1000 + 5][3][30 + 5] ;
inline int dfs ( int i , int j , int k ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    memset ( dp , -1 , sizeof (dp) ) ;
    printf ( "%d" , dfs ( 1 , 1 , 0 ) ) ;

    return 0 ;
}

inline int dfs ( int i , int j , int k ) { // i = time , j = tree , k = move count
    if ( i > n ) { // n times, boundary condition
        return 0 ;
    }

    if ( dp[i][j][k] != -1 ) {
        return dp[i][j][k] ;
    }

    int tmp1 = 0 , tmp2 = 0 ;
    if ( k < m && a[i] != j ) { // move 
        tmp1 = dfs ( i + 1 , j == 1 ? 2 : 1 , k + 1 ) + 1 ;
    }
    // don't move
    tmp2 = dfs ( i + 1 , j , k ) + ( j == a[i] ? 1 : 0 ) ;

    return dp[i][j][k] = max ( tmp1 , tmp2 ) ;
}
