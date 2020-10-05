#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , love[50 + 5][50 + 5] , ans , x , y , vis[50 + 5] ;
inline void dfs ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        love[i][x] = love[i][y] = 1 ;
    }

    if ( n <= 1 ) {
        printf ( "%d" , 0 ) ;
        exit ( false ) ;
    }

    dfs (1) ;

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void dfs ( int x ) {
    if ( x == n + 1 ) {
        ans++ ;
        return ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( !vis[i] && love[x][i] ) {
            vis[i] = 1 ;
            dfs ( x + 1 ) ;
            vis[i] = 0 ;
        }
    }
}
