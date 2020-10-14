#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[500][500] , vis[500][500] , que[114514][4] ;
int n , m , sx , sy , ex , ey , tripx , tripy , head , tail ;
char c ;
const int dx[4] = { -1 , 1 , 0 , 0 } ;
const int dy[4] = { 0 , 0 , -1 , 1 } ;
inline void check ( int x , int y ) ;
inline void bfs () ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c ;
            if ( c == '.' ) {
                a[i][j] = 1 ;
            }
            else if ( c >= 'A' && c <= 'Z' ) {
                a[i][j] = c ;
            }
            else if ( c == '@' ) {
                sx = i , sy = j ;
                a[i][j] = 1 ;
            }
            else if ( c == '=' ) {
                ex = i , ey = j ;
                a[i][j] = 1 ;
            }
        }
    }

    bfs () ;

    return 0 ;
}

inline void check ( int x , int y ) {
    // cout << '$' ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            if ( ! ( i == x && j == y ) ) {
                if ( a[i][j] == a[x][y] ) {
                    tripx = i , tripy = j ;
                    return ;
                }
            }
        }
    }
}

inline void bfs () {

    vis[sx][sy] = 1 , que[1][1] = sx , que[1][2] = sy , tail++ ;

    do {
        head++ ;
        if ( a[que[head][1]][que[head][2]] >= 'A' && a[que[head][1]][que[head][2]] <= 'Z' ) {
            check ( que[head][1] , que[head][2] ) ;
            que[head][1] = tripx , que[head][2] = tripy ;
        }

        for ( int i = 0 ; i < 4 ; i++ ) {
            // cout << tail ;
            int fx = que[head][1] + dx[i] ;
            int fy = que[head][2] + dy[i] ;
            if ( a[fx][fy] != 0 && vis[fx][fy] == 0 ) {
                // cout << fx << " " << fy ;
                vis[fx][fy] = 1 , tail++ ;
                que[tail][1] = fx , que[tail][2] = fy ;
                que[tail][3] = que[head][3] + 1 ;
                if ( fx == ex && fy == ey ) {
                    printf ( "%d" , que[tail][3] ) ;
                    exit ( false ) ;
                }
            }
        }
    } while ( head < tail ) ;
}
