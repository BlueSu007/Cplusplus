#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , a[113 + 5][77 + 5] , ans[2][100000 + 5] ;
int vis[113 + 5][77 + 5] , path[2][100000 + 5] ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void input () ;
inline void dfs ( int x , int y , int step ) ;
inline void output ( int x ) ;

int main () {
    
    input () ;
    // for ( int i = 1 ; i <= n ; i++ ) {
    //     for ( int j = 1 ; j <= m ; j++ ) {
    //         cout << a[i][j] ;
    //     }
    //     cout << endl ;
    // }
    // for ( int i = 1 ; i <= n ; i++ ) {
    //     for ( int j = 1 ; j <= m ; j++ ) {
    //         cout << vis[i][j] ;
    //     }
    //     cout << endl ;
    // }
    // cout << 0 << endl ;
    dfs ( 1 , 1 , 1 ) ;
    // output () ;

    return 0 ;
}

inline void input () {
    char c ;
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            if ( c == '*' ) {
                a[i][j] = 1 ;
            }
        }
    }
}

inline void dfs ( int x , int y , int step ) {
    // cout << 4 << endl ;
    if ( x < 1 || y < 1 || x > n || y > m || a[x][y] || vis[x][y] ) {
        // cout << 6 << endl ;
        return ;
    }
    // cout << 3 << endl ;
    vis[x][y] = 1 ;
    path[0][step] = x , path[1][step] = y ;

    // cout << 5 << endl ;
    if ( x == n && y == m ) {
        // cout << 1 << endl ;
        output ( step ) ;
        exit(0) ;
    }

    for ( int i = 0 ; i < 4 ; i++ ) {
        dfs ( x + dx[i] , y + dy[i] , step + 1 ) ;
    }
}

inline void output ( int x ) {
    // cout << 2 << endl ;
    for ( int i = 1 ; i <= x ; i++ ) {
        printf ( "%d %d\n" , path[0][i] , path[1][i] ) ;
    }
}
