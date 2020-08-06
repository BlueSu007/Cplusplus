#include <iostream>//P1506
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , a[500 + 5][500 + 5] , ans ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void input () ;
inline void helpSearch () ;
inline void dfs ( int x , int y ) ;
inline void findZero () ;

int main () {

    input () ;
    helpSearch () ;
    findZero () ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void input () {
    char c = ' ' ;
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            if ( c == '*' ) {
                a[i][j] = 1 ;
            }
            else {
                a[i][j] = 0 ;
            }
        }
    }
}

inline void dfs ( int x , int y ) {
    if ( x < 0 || y < 0 || x > n || y > m || a[x][y] == 1 ) {
        return ;
    }

    a[x][y] = 1 ;
    for ( int i = 0 ; i < 4 ; i++ ) {
        dfs ( x + dx[i] , y + dy[i] ) ;
    }
}

inline void findZero () {
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( !a[i][j] ) {
                ans++ ;
            }
        }
    }
}

inline void helpSearch () {
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i][1] == 0 ) {
            dfs ( i , 1 ) ;
        }
        if ( a[i][m] == 0 ) {
            dfs ( i , m ) ;
        }
    }

    for ( int j = 1 ; j <= m ; j++ ) {
        if ( a[1][j] == 0 ) {
            dfs ( 1 , j ) ;
        }
        if ( a[n][j] == 0 ) {
            dfs ( n , j ) ;
        }
    }
}

/*
4 5
00000
00*00
0*0*0
00*00
*/
/*
5 5
*****
*0*0*
**0**
*0*0*
*****
*/
