#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 200005
int n , qwq , last , ans = INT_MAX ;
int father[LEN] , distancen[LEN] ;
inline void init () ;
inline int find ( int x ) ;
inline void combine ( int x , int y ) ;
inline void check ( int x , int y ) ;

int main () {

    scanf ( "%d" , &n ) ;
    init () ;

    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &qwq ) ;
        combine ( i , qwq ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void init () {
    for ( int i = 1 ; i <= n ; i++ ) {
        father[i] = i ;
    }
}

inline int find ( int x ) {
    if ( father[x] != x ) {
        int last = father[x] ;
        father[x] = find ( father[x] ) ;
        distancen[x] += distancen[last] ;
    }

    return father[x] ;
}

inline void combine ( int x , int y ) {
    int p = find (x) , q = find (y) ;
    if ( p != q ) {
        father[p] = q ;
        distancen[x] = distancen[y] + 1 ;
    }
    else {
        ans = min ( ans , distancen[x] + distancen[y] + 1 ) ;
    }
}
