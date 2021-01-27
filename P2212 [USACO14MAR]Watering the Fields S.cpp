// luogu-judge enabled -O2
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

#define LEN 19260817

struct node {
    int v ;
    long long w ;

    node ( int tmpv , long long tmpw ) : v (tmpv) , w (tmpw) {} 
    inline bool operator < ( node x ) const {
        return w > x.w ;
    }
} ;

int n , c , x[LEN] , y[LEN] , cnt , ans ;
int head[LEN] , endn[LEN] , weight[LEN] , nextn[LEN] , vis[LEN] ;
priority_queue < node > que ;

inline int read () ;
inline int distance ( int sx , int sy , int ex , int ey ) ;
inline void addEdge ( int u , int v , long long w ) ;
inline long long prim () ;

int main () {

    // scanf ( "%d %d" , &n , &c ) ;
    n = read () , c = read () ;
    for ( int i = 1 ; i <= n ; i++ ) {
        // scanf ( "%d %d" , &x[i] , &y[i] ) ;
        x[i] = read () , y[i] = read () ;
        for ( int j = 1 ; j < i ; j++ ) {
            int value = distance ( x[i] , y[i] , x[j] , y[j] ) ;
            if ( value >= c ) {
                addEdge ( i , j , value ) ;
                addEdge ( j , i , value ) ;
            }
        }
    }

    ans = prim () ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( ! vis[i] ) {
            printf ( "-1" ) ;
            exit ( false ) ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline int read () {
    char ch = getchar () ;
    int f = 1 , x = 0 ;

    while ( ! isdigit ( ch ) ) {
        if ( ch == '-' ) {
            f = -1 ;
        }

        ch = getchar () ;
    }

    while ( isdigit ( ch ) ) {
        x = x * 10 + ( ch - '0' ) ;
        ch = getchar () ;
    }

    return f * x ;
}

inline void addEdge ( int u , int v , long long w ) {
    cnt++ ;
    endn[cnt] = v , weight[cnt] = w ;
    nextn[cnt] = head[u] , head[u] = cnt ;
}

inline long long prim () {
    long long ans = 0 ;
    que.push ( node ( 1 , 0 ) ) ;

    while ( ! que.empty () ) {
        int u = que.top () .v ;
        long long w = que.top () .w ;
        que.pop () ;

        if ( vis[u] ) {
            continue ;
        }

        vis[u] = true , ans += w ;
        for ( int j = head[u] ; j > 0 ; j = nextn[j] ) {
            if ( ! vis[endn[j]] ) {
                que.push ( node ( endn[j] , weight[j] ) ) ;
            }
        }
    }

    return ans ;
}

inline int distance ( int sx , int sy , int ex , int ey ) {
    int tmp1 = ( sx - ex ) , tmp2 = ( sy - ey ) ;
    return tmp1 * tmp1 + tmp2 * tmp2 ;
}
