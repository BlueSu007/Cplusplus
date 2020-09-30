#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , ans ;
int a[100 + 5][100 + 5] , rem[100 + 5][100 + 5] ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline int dfs ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            ans = max ( ans , dfs ( i , j ) ) ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline int dfs ( int x , int y ) {
    if ( rem[x][y] ) {
        return rem[x][y] ;
    }
    rem[x][y] = 1 ;

    for ( int i = 0 ; i < 4 ; i++ ) {
        int fx = dx[i] + x ;
        int fy = dy[i] + y ;
        if ( fx < 1 || fy < 1 || fx > n || fy > m || a[x][y] <= a[fx][fy] ) {
            continue ;
        }
        dfs ( fx , fy ) ;
        rem[x][y] = max ( rem[x][y] , rem[fx][fy] + 1 ) ;
    }

    return rem[x][y] ;
}
