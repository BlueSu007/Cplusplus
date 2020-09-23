#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , maxn , ans , step ;
int star[3000000 + 5] , solar[3000000 + 5] , a[1500 + 5][1500 + 5] ;
char c ;
const int dx[9] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 } ;
const int dy[9] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 } ;
inline void dfs ( int x , int y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            if ( c == '*' ) {
                a[i][j] = 1 ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( a[i][j] ) {
                ans++ ;
                dfs ( i , j ) ;
                star[ans] = step , step = 0 ;
            }
        }
    }

    sort ( star + 1 , star + 1 + ans ) ;
    int cnt = 1 , tmp = 0 ;
    for ( int i = 1 ; i < ans ; i++ ) {
        solar[cnt] += star[i] ;
        if ( star[i] != star[i + 1] ) {
            cnt++ ;
        }
    }
    solar[cnt] += star[ans] ;

    sort ( solar + 1 , solar + 1 + cnt ) ;

    printf ( "%d %d" , cnt , solar[cnt] ) ;

    return 0 ;
}

inline void dfs ( int x , int y ) {
    a[x][y] = 0 , step++ ;

    for ( int i = 0 ; i < 9 ; i++ ) {
        int fx = x + dx[i] ;
        int fy = y + dy[i] ;
        if ( fx < 1 || fy < 1 || fx > n || fy > m ) {
            continue ;
        }
        if ( a[fx][fy] ) {
            dfs ( fx , fy ) ;
        }
    }
}
