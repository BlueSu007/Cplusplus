#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 100005

int head[LEN] , endn[LEN * 2] , nextn[LEN * 2] , weight[LEN * 2] , cnt , vis[LEN] ;
int que[LEN * 1000] , queHead , queTail ;
long long h , x , y , z , k , f[LEN] , ans ;
inline void addEdge ( int u , int v , int w ) ;
inline void spfa () ;

int main () {

    scanf( "%lld %lld %lld %lld" , &h , &x , &y , &z ) ;
    if ( x == 1 || y == 1 || z == 1 ) {
        printf ( "%lld" , h ) ;
        exit ( false ) ;
    }

    for ( int i = 0 ; i < x ; i++ ) {
        addEdge ( i , ( i + y ) % x , y ) ;
        addEdge ( i , ( i + z ) % x , z ) ;
    }

    spfa () ;
    for ( int i = 0 ; i < x ; i++ ) {
        if ( f[i] <= h ) {
            ans += ( h - f[i] ) / x + 1 ;
        }
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline void addEdge ( int u , int v , int w ) {
    endn[++cnt] = v , weight[cnt] = w , nextn[cnt] = head[u] , head[u] = cnt ;
}

inline void spfa () {
    memset ( f , 0x3f , sizeof (f) ) ;
    queHead++ , que[queHead] = vis[1] = f[1] = 1 , queTail += 2 ;

    while ( queHead < queTail ) {
        vis[que[queHead]] = false ;
        for ( int i = head[que[queHead]] ; i ; i = nextn[i] ) {
            if ( f[endn[i]] > f[que[queHead]] + weight[i] ) {
                f[endn[i]] = f[que[queHead]] + weight[i] ;
                if ( ! vis[endn[i]] ) {
                    que[queTail++] = endn[i] , vis[endn[i]] = true ;
                }
            }
        }

        queHead++ ;
    }
}
