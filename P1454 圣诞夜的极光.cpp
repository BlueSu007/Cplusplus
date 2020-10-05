#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[1000 + 5][1000 + 5] , ans ;
char c ;
const int dx[12] = { 1 , -1 , 0 , 0 , 2 , -2 , 0 , 0 , 1 , -1 , 1 , -1 } ;
const int dy[12] = { 0 , 0 , 1 , -1 , 0 , 0 , 2 , -2 , -1 , 1 , 1 , -1 } ;
inline void dfs ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            if ( c == '#' ) {
                a[i][j] = 1 ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( a[i][j] ) {
                ans++ ;
                dfs ( i , j ) ;
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void dfs ( int x , int y ) {
    if ( x < 1 || y < 1 || x > n || y > m || a[x][y] != 1 ) {
        return ;
    }

    a[x][y] = 0 ;

    for ( int i = 0 ; i < 12 ; i++ ) {
        dfs ( x + dx[i] , y + dy[i] ) ;
    }
}
