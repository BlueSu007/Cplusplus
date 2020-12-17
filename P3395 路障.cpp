#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

#define LEN 1005
// int k , n , a[LEN][LEN] , vis[LEN][LEN] , x[LEN * LEN] , y[LEN * LEN] ;
int k , n , x , y , vis[LEN][LEN] , map[LEN][LEN] ;
int que[LEN * LEN][4] , head , tail ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline string bfs () ;

int main () {

    scanf ( "%d" , &k ) ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d" , &n ) ;
        for ( int i = 1 ; i <= 2 * ( n - 1 ) ; i++ ) {
            scanf ( "%d %d" , &x , &y ) ;
            map[x][y] = i ;
        }
        if ( n == 1 ) {
            printf ( "Yes\n" ) ;
            continue ;
        }

        cout << bfs () << endl ;
        memset ( vis , 0 , sizeof (vis) ) ;
        memset ( map , 0 , sizeof (map) ) ;
        // for ( int i = 1 ; i < tail ; i++ ) {
        //     printf ( "%d %d\n" , que[i][1] , que[i][2] ) ;
        // }
    }

    return 0 ;
}

inline string bfs () {
    vis[1][1] = que[1][1] = que[1][2] = head = tail = 1 , tail++ ;
    while ( head < tail ) {
        for ( int i = 0 ; i < 4 ; i++ ) {
            int fx = dx[i] + que[head][1] ;
            int fy = dy[i] + que[head][2] ;

            if ( fx < 1 || fy < 1 || fx > n || fy > n || vis[fx][fy] ) {
                continue ;
            }

            if ( map[fx][fy] != 0 && map[fx][fy] < head ) {
                vis[fx][fy] = true ;
                continue ;
            }

            que[tail][1] = fx , que[tail][2] = fy , que[tail][3] = que[head][3] + 1 ;
            vis[fx][fy] = true , tail++ ;

            if ( fx == n && fy == n ) {
                return "Yes" ;
            }
        }

        head++ ;
    }

    return "No" ;
}
