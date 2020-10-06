#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[1000 + 5][1000 + 5] , que[10000000 + 5][4] ;
int k , x , y , ex , ey , head , tail ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void bfs () ;

int main () {

    scanf ( "%d %d %d" , &ex , &ey , &k ) ;
    ex += 501 , ey += 501 ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        x += 501 , y += 501 ;
        a[x][y] = 1 ;
    }
    
    bfs () ;
    printf ( "%d" , que[tail - 1][3] ) ;

    return 0 ;
}

inline void bfs () {
    que[1][1] = que[1][2] = 501 ;
    head = tail = 1 , a[501][501] = 1 , tail++ ;

    while ( head < tail ) {
        for ( int i = 0 ; i < 4 ; i++ ) {
            int fx = dx[i] + que[head][1] ;
            int fy = dy[i] + que[head][2] ;

            if ( fx < 1 || fy < 1 || fx > 1000 || fy > 1000 || a[fx][fy] ) {
                continue ;
            }

            a[fx][fy] = 1 ;
            que[tail][1] = fx , que[tail][2] = fy ;
            que[tail][3] = que[head][3] + 1 , tail++ ;

            if ( fx == ex && fy == ey ) {
                return ;
            }
        }

        head++ ;
    }
}
