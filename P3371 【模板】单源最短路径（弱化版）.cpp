#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define LEN 500005

struct Edge {
    int nextn , endn , dis ;
} edge[LEN] ;

int n , m , s , u , v , w , cnt ;
int distancen[LEN] , vis[LEN] , head[LEN] ;
queue < int > que ;
inline void addEdge ( int u , int v , int w ) ;
inline void spfa () ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &s ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &u , &v , &w ) ;
        addEdge ( u , v , w ) ;
    }

    spfa () ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( s == i ) {
            printf ( "0 " ) ;
        }
        else {
            printf ( "%d " , distancen[i] ) ;
        }
    }

    return 0 ;
}

inline void addEdge ( int u , int v , int w ) {
    edge[++cnt].nextn = head[u] ;
    edge[cnt].endn = v ;
    edge[cnt].dis = w ;
    head[u] = cnt ;
}

inline void spfa () {
    for ( int i = 1 ; i <= n ; i++ ) {
        distancen[i] = INT_MAX ;
        vis[i] = 0 ;
    }

    que.push (s) , distancen[s] = 0 , vis[s] = 1 ;
    while ( ! que.empty () ) {
        int u = que.front () ;
        que.pop () , vis[u] = false ;

        for ( int i = head[u] ; i ; i = edge[i].nextn ) {
            int v = edge[i].endn ;
            if ( distancen[v] > distancen[u] + edge[i].dis ) {
                distancen[v] = distancen[u] + edge[i].dis ;
                if ( ! vis[v] ) {
                    vis[v] = true , que.push (v) ;
                }
            }
        }
    }
}
