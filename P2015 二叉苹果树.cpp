#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 105
int son[LEN][LEN] , dp[LEN][LEN] , x , y , z ;
int n , m , map[LEN][LEN] , cnt[LEN] , vis[LEN] ;
inline void treeDP ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d %d" , &x , &y , &z ) ;
        map[x][y] = map[y][x] = z ;
        son[x][++cnt[x]] = y ;
        son[y][++cnt[y]] = x ;
    }

    treeDP (1) ;
    printf ( "%d" , dp[1][m] ) ;

    return 0 ;
}

inline void treeDP ( int x ) {
    vis[x] = 1 ;
    for ( int i = 1 ; i <= cnt[x] ; i++ ) {
        int tmp = son[x][i] ;
        if ( vis[tmp] == 1 ) {
            continue ;
        }

        vis[tmp] = 1 ;
        treeDP ( tmp ) ;

        for ( int j = m ; j >= 1 ; j-- ) {
            for ( int k = j - 1 ; k >= 0 ; k-- ) {
                dp[x][j] = max ( dp[x][j] , dp[tmp][k] + dp[x][j - k - 1] + map[x][tmp] ) ;
            }
        }
    }
}
