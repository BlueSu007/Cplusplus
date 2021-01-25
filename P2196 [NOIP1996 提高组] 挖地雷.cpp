#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 35
int n , a , x , y ;
int dp[LEN] , weightn[LEN] , id[LEN] , nextn[LEN] , map[LEN][LEN] ;
inline int dfs ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &weightn[i] ) ;
        nextn[i] = -1 ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i + 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &a ) ;
            if ( a ) {
                map[i][j] = true ;
                id[j]++ ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( id[i] == 0 ) {
            dp[i] = dfs (i) ;
            if ( dp[i] > y ) {
                x = i , y = dp[i] ;
            }
        }
    }

    while ( x != -1 ) {
        printf ( "%d " , x ) ;
        x = nextn[x] ;
    }

    printf ( "\n" ) ;
    printf ( "%d" , y ) ;

    return 0 ;
}

inline int dfs ( int x ) {
    if ( dp[x] ) {
        return dp[x] ;
    }

    int tmp = 0 , k = -1 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( map[x][i] ) {
            if ( dp[i] == 0 ) {
                dp[i] = dfs (i) ;
            }
            if ( dp[i] > tmp ) {
                tmp = dp[i] , k = i ;
            }
        }
    }

    nextn[x] = k ;
    return tmp + weightn[x] ;
}
