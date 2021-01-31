#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 1000005
#define MOD 100003

int n , m , u , v ;
int head[LEN] , nextn[LEN] , endn[LEN] , cnt ;
int distancen[LEN] , ans[LEN] , que[LEN] , queHead , queTail ;
inline void addEdge ( int u , int v ) ;
inline void bfs ( int x ) ;

int main () {
    
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &u , &v ) ;
        addEdge ( u , v ) ;
        addEdge ( v , u ) ;
    }

    bfs (1) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d\n" , ans[i] ) ;
    }

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    endn[++cnt] = v , nextn[cnt] = head[u] , head[u] = cnt ;
}

inline void bfs ( int x ) {
    memset ( distancen , 0x3f , sizeof distancen ) ;
    que[++queHead] = x , distancen[x] = 0 , ans[x] = 1 ;
    queTail = 2 ;

    while ( queHead < queTail ) {
        int u = que[queHead] ;
        for ( int i = head[u] ; i ; i = nextn[i] ) {
            if ( distancen[endn[i]] > distancen[u] + 1 ) {
                distancen[endn[i]] = distancen[u] + 1 ;
                que[queTail++] = endn[i] ;
                ans[endn[i]] += ans[u] ;
                ans[endn[i]] %= MOD ;
            }
            else if ( distancen[endn[i]] == distancen[u] + 1 ) {
                ans[endn[i]] += ans[u] ;
                ans[endn[i]] %= MOD ;
            }
        }

        queHead++ ;
    }
}
