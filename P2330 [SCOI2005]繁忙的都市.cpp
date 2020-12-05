#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 305
int n , m , a , b , c , maxn = -1 ;
int minn[LEN] , graph[LEN][LEN] ;
bool u[LEN] ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d %d %d" , &a , &b , &c ) ;
        graph[a][b] = c , graph[b][a] = c ;
    }

    memset ( minn , 0x7f , sizeof (minn) ) ;
    minn[1] = 0 ;
    memset ( u , 1 , sizeof (u) ) ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        int k = 0 ; 
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( u[j] && ( minn[j] < minn[k] ) ) {
                k = j ;
            }
        }

        u[k] = 0 ;
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( u[j] && graph[k][j] != 0 && graph[k][j] < minn[j] ) {
                minn[j] = graph[k][j] ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( minn[i] > maxn ) {
            maxn = minn[i] ;
        }
    }

    printf ( "%d %d" , n - 1 , maxn ) ;

    return 0 ;
}
