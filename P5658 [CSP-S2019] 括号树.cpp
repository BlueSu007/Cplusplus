#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 500005
int n , head[LEN] , nextn[LEN] , endn[LEN] , cnt ;
int stackn[LEN] , top , x ;
long long father[LEN] , list[LEN] , sum[LEN] , ans ;\
char c[LEN] ;
inline void addEdge ( int u , int v ) ;
inline void dfs ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    scanf ( "%s" , c + 1 ) ;

    for ( int i = 2 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        addEdge ( x , i ) ;
        father[i] = x ;
    }

    dfs (1) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        ans ^= sum[i] * ( long long ) i ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline void addEdge ( int u , int v ) {
    nextn[++cnt] = head[u] ;
    head[u] = cnt ;
    endn[cnt] = v ;
}

inline void dfs ( int x ) {
    int tmp = 0 ;
    if ( c[x] == ')' ) {
        if ( top ) {
            tmp = stackn[top] ;
            list[x] = list[father[tmp]] + 1 ;
            top-- ;
        }
    }
    else if ( c[x] == '(' ) {
        stackn[++top] = x ;
    }

    sum[x] = sum[father[x]] + list[x] ;
    for ( int i = head[x] ; i ; i = nextn[i] ) {
        dfs ( endn[i] ) ;
    }

    if ( tmp != 0 ) {
        stackn[++top] = tmp ;
    }
    else if ( top ) {
        top-- ;
    }
}
