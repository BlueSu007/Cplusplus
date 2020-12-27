#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , vis[20][20] , que[400][4] , head , tail , ans ;
const int dx[4] = { -2 , -1 , 1 , 2 } ;
const int dy[4] = { 1 , 2 , 2 , 1 } ;
inline void dfs ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    dfs ( 0 , 0 ) ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void dfs ( int x , int y ) {
    if ( x == n && y == m ) {
        ans++ ;
        return ;
    }

    for ( int i = 0 ; i < 4 ; i++ ) {
        int fx = dx[i] + x ;
        int fy = dy[i] + y ;

        if ( fx < 0 || fy < 0 || fx > n || fy > m || vis[fx][fy] ) {
            continue ;
        }

        vis[fx][fy] = true ;
        dfs ( fx , fy ) ;
        vis[fx][fy] = false ;
    }
}
