#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , y , a[50 + 5][50 + 5] , vis[50 + 5] , route[50 + 5] ;
inline void dfs ( int cur , int step ) ;

int main () {

    scanf ( "%d" , &n ) ;
    while ( scanf ( "%d %d" , &x , &y ) != EOF ) {
        a[x][y] = a[y][x] = 1 ;
    }

    vis[1] = 1 ;
    dfs ( 1 , 1 ) ;

    return 0 ;
}

inline void dfs ( int cur , int step ) {

    route[step] = cur ;

    if ( step == n ) {
        if ( a[cur][1] ) {
            for ( int i = 1 ; i <= n ; i++ ) {
                printf ( "%d " , route[i] ) ;
            }
            exit ( false ) ;            
        }
        else {
            return ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( !vis[i] && a[cur][i] ) {
            vis[i] = 1 ;
            dfs ( i , step + 1 ) ;
            vis[i] = 0 ;
        }
    }
}
