#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[50][50] , sx , sy , ans ;
int head , tail , que[2500][4] , vis[50][50] ;
char c ;
const int dx[4] = { 0 , 0 , -1 , 1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void bfs () ;

int main () {

    scanf ( "%d %d" , &m , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            while ( scanf ( "%c" , &c ) ) {
                if ( c == '.' || c == '#' || c == '@' ) {
                    break ;
                }
            }

            if ( c == '#' ) {
                a[i][j] = 1 ;
            }
            if ( c == '@' ) {
                sx = i , sy = j ;
            }
        }
    }

    bfs () ;
    printf ( "%d" , tail - 1 ) ;

    return 0 ;
}

inline void bfs () {
    que[1][3] = vis[sx][sy] = head = tail = 1 ;
    que[1][1] = sx , que[1][2] = sy , tail++ ;

    while ( head < tail ) {
        for ( int i = 0 ; i < 4 ; i++ ) {
            int fx = dx[i] + que[head][1] ;
            int fy = dy[i] + que[head][2] ;

            if ( fx < 1 || fy < 1 || fx > n || fy > m || vis[fx][fy] || a[fx][fy] ) {
                continue ;
            }

            que[tail][1] = fx , que[tail][2] = fy , vis[fx][fy] = true ;
            que[tail][3] = que[head][3] + 1 , tail++ ;
        }

        head++ ;
    }
}
