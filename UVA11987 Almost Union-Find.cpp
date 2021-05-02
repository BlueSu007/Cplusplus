#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 200005
int father[LEN] , id[LEN] , size[LEN] , sum[LEN] ;
int cnt , n , m , op , x , y ;
inline void init ( int n ) ;
inline int find ( int x ) ;
inline void combine ( int x , int y ) ;
inline void move ( int x , int y ) ;

int main () {

    while ( scanf ( "%d %d" , &n , &m ) != EOF ) {
        init (n) ;
        while ( m-- ) {
            scanf ( "%d" , &op ) ;
            if ( op == 1 ) {
                scanf ( "%d %d" , &x , &y ) ;
                combine ( id[x] , id[y] ) ;
            }
            if ( op == 2 ) {
                scanf ( "%d %d" , &x , &y ) ;
                move ( x , y ) ;
            }
            if ( op == 3 ) {
                scanf ( "%d" , &x ) ;
                int p = find ( id[x] ) ;
                printf ( "%d %d\n" , size[p] , sum[p] ) ;
            }
        }
    }

    return 0 ;
}

inline void init ( int n ) {
    for ( int i = 1 ; i <= n ; i++ ) {
        father[i] = i , sum[i] = i , id[i] = i , size[i] = 1 ;
    }
    cnt = n ;
    return ;
}

inline int find ( int x ) {
    if ( x != father[x] ) {
        return father[x] = find ( father[x] ) ;
    }
    return x ;
}

inline void combine ( int x , int y ) {
    int p = find (x) , q = find (y) ;
    if ( p == q ) {
        return ;
    }

    father[p] = q , size[q] += size[p] , sum[q] += sum[p] ;
    return ;
}

inline void move ( int x , int y ) {
    int p = find ( id[x] ) , q = find ( id[y] ) ;
    if ( p == q ) {
        return ;
    }

    size[p]-- , sum[p] -= x , id[x] = ++cnt ;
    father[cnt] = cnt , size[cnt] = 1 , sum[cnt] = x ;
    combine ( id[x] , id[y] ) ;
    return ;
}
