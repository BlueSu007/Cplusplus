#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

#define LEN 500005

struct Edge {
    int nextn , endn , dis ;
} edge[LEN] ;

int t , n , m , s , u , v , w , cnt ;
int distancen[LEN] , vis[LEN] , head[LEN] , qwq[LEN] ;
// int que[LEN] , queHead , queTail ;
queue < int > que ;
inline void init () ;
inline void addEdge ( int u , int v , int w ) ;
inline bool spfa () ;

int main () {

    scanf ( "%d" , &t ) ;
    while ( t-- ) {
        init () ;
        scanf ( "%d %d" , &n , &m ) ;
        for ( int i = 1 ; i <= m ; i++ ) {
            scanf ( "%d %d %d" , &u , &v , &w ) ;
            addEdge ( u , v , w ) ;
            
            if ( w >= 0 ) {
                addEdge ( v , u , w ) ;
            }
        }

        bool qaq = spfa () ;
        if ( qaq ) {
            printf ( "YES\n" ) ;
        }
        else {
            printf ( "NO\n" ) ;
        }
    }

    return 0 ;
}

inline void init () {
    memset ( vis , 0 , sizeof ( vis ) ) ;
    memset ( qwq , 0 , sizeof ( qwq ) ) ;
    // memset ( que , 0 , sizeof ( que ) ) ;
    memset ( edge , 0 , sizeof ( edge ) ) ;
    memset ( head , 0 , sizeof ( head ) ) ;
    memset ( distancen , 0x3f , sizeof ( distancen ) ) ;
    cnt = 0 ;
}

inline void addEdge ( int u , int v , int w ) {
    edge[++cnt].nextn = head[u] ;
    edge[cnt].endn = v ;
    edge[cnt].dis = w ;
    head[u] = cnt ;
}

inline bool spfa () {
    // queHead = queTail = 1 ;
    que.push (1) , distancen[1] = 0 , vis[1] = 1 ;
    // queTail++ ;

    while ( ! que.empty () ) {
        int u = que.front () ;
        que.pop () , vis[u] = false ;

        for ( int i = head[u] ; i ; i = edge[i].nextn ) {
            int v = edge[i].endn ;
            if ( distancen[v] > distancen[u] + edge[i].dis ) {
                distancen[v] = distancen[u] + edge[i].dis ;

                if ( qwq[v] >= n ) {
                    return true ;
                }

                if ( ! vis[v] ) {
                    qwq[v]++ ;
                    vis[v] = true , que.push (v) ;
                }
            }
        }
    }

    return false ;
}
