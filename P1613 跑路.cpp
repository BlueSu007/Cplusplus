#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 100
int dis[LEN][LEN] , graph[LEN][LEN][LEN] ;
int n , m , x , y ;
inline void init () ;
inline void floyd () ;

int main () {

    memset ( dis , 0x3f , sizeof ( dis ) ) ;
    scanf ( "%d %d" , &n , &m ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        dis[x][y] = graph[x][y][0] = true ;
    }

    init () , floyd () ;
    printf ( "%d" , dis[1][n] ) ;

    return 0 ;
}

inline void init () {
    for ( int distance = 1 ; distance <= 64 ; distance++ ) {
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int k = 1 ; k <= n ; k++ ) {
                for ( int j = 1 ; j <= n ; j++ ) {
                    if ( graph[i][k][distance - 1] && graph[k][j][distance - 1] ) {
                        graph[i][j][distance] = dis[i][j] = true ;
                    }
                }
            }
        }
    }
}

inline void floyd () {
    for ( int k = 1 ; k <= n ; k++ ) {
        for ( int i = 1 ; i <= n ; i++ ) {
            for ( int j = 1 ; j <= n ; j++ ) {
                dis[i][j] = min ( dis[i][j] , dis[i][k] + dis[k][j] ) ;
            }
        }
    }
}
