#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 12005
int n , k , l , root ;
int dp[5][12000] , nextn[LEN] , head[LEN] , endn[LEN] ;
inline void treeDP ( int x ) ;

int main () {
    
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &dp[1][i] ) ;
    }

    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d" , &l , &k ) ;
        endn[l]++ , nextn[l] = head[k] , head[k] = l ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( ! endn[i] ) {
            root = i ;
            break ;
        }
    }

    treeDP ( root ) ;   
    printf ( "%d" , max ( dp[0][root] , dp[1][root] ) ) ;

    return 0 ;
}

inline void treeDP ( int x ) {
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        // cout << 1 << endl ;
        treeDP (i) ;
        dp[1][x] = max ( max ( dp[1][x] , dp[0][i] + dp[1][x] ) , dp[0][i] ) ;
        dp[0][x] = max ( max ( dp[0][x] , dp[1][i] + dp[0][x] ) , max ( dp[0][i] , dp[1][i] ) ) ;
    }
}
