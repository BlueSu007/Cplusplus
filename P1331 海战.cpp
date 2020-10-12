#include <iostream>// ?? From Luogu
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , cnt ;
char map[1000 + 5][1000 + 5] ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void input () ;
inline void work () ;
inline void passout () ;
inline bool check ( int x , int y ) ;
inline void dfs ( int x , int y ) ;
inline void output () ;

int main () {

    input () ;
    work () ;
    output () ;

    return 0 ;
}

inline void input () {
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%s" , &map[i] ) ;
        for ( int j = m ; j > 0 ; j-- ) {
            map[i][j] = map[i][j - 1] ;
        }
    }
}

inline void work () {
    passout () ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( map[i][j] == '#' ) {
                cnt++ ;
                dfs ( i , j ) ;
            }
        }
    }
}

inline void passout () {
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( i < n && j < m && !check ( i , j ) ) {
                printf ( "Bad placement." ) ;
                exit (0) ;
            }
        }
    }
}

inline bool check ( int x , int y ) {
    int tmp = 0 ;
    if ( map[x + 1][y + 1] == '#' ) {
        tmp++ ;
    }
    if ( map[x + 1][y] == '#' ) {
        tmp++ ;
    }
    if ( map[x][y + 1] == '#' ) {
        tmp++ ;
    }
    if ( map[x][y] == '#' ) {
        tmp++ ;
    }
    if ( tmp == 3 ) {
        return false ;
    }
    return true ;
}

inline void dfs ( int x , int y ) {
    map[x][y] = '.' ;

    for ( int i = 0 ; i < 4 ; i++ ) {
        int fx = x + dx[i] ;
        int fy = y + dy[i] ;
        if ( fx < 1 || fy < 1 || fx > n || fy > m || map[fx][fy] == '.' ) {
            continue ;
        }
        dfs ( fx , fy ) ;
    }
}

inline void output () {
    printf ( "There are %d ships." , cnt ) ;
}
