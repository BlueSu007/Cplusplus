#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct star {
    int x ;
    int y ;
    int t ;
} a[50000 + 5] ;

int n , head , tail , lastTime ;
int que[100000 + 5][4] , vis[500 + 5][500 + 5] , map[500 + 5][500 + 5] ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void bfs () ;

int main () {

    memset ( map , 255 , sizeof (map) ) ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d %d" , &a[i].x , &a[i].y , &a[i].t ) ;

        // this point have got broken -> got minium time
        if ( map[a[i].x][a[i].y] != -1 ) {
            map[a[i].x][a[i].y] = min ( map[a[i].x][a[i].y] , a[i].t ) ;
        }
        else {
            map[a[i].x][a[i].y] = a[i].t ;
        }
        
        // label the point which is the nearest
        for ( int j = 0 ; j < 4 ; j++ ) {
            int fx = dx[j] + a[i].x ;
            int fy = dy[j] + a[i].y ;
            if ( fx >= 0 && fy >= 0 ) {
                if ( map[fx][fy] != -1 ) {
                    map[fx][fy] = min ( map[fx][fy] , a[i].t ) ;
                }
                else {
                    map[fx][fy] = a[i].t ;
                }
            }
        }
    }

    bfs () ;
    printf ( "-1" ) ;

    return 0 ;
}

inline void bfs () {

    que[1][1] = 0 , que[1][2] = 0 , vis[0][0] = 1 , tail++ ;

    while ( head < tail ) {
        head++ ;
        for ( int i = 0 ; i < 4 ; i++ ) {
            int fx = dx[i] + que[head][1] ;
            int fy = dy[i] + que[head][2] ;

            // if not go out && ( never got broken || haven't got broken yet ) && unvisited
            if ( fx >= 0 && fy >= 0 && ( map[fx][fy] == -1 || que[head][3] + 1 < map[fx][fy] ) && !vis[fx][fy] ) {
                // labeled visited , push in queue
                vis[fx][fy] = true , tail++ ;
                que[tail][1] = fx , que[tail][2] = fy ;
                que[tail][3] = que[head][3] + 1 ;

                // arrived && output
                if ( map[fx][fy] == -1 ) {
                    printf ( "%d" , que[tail][3] ) ;
                    exit ( false ) ;
                }
            }
        }
    }
}
