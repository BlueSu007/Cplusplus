#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[1000000 + 5] , vis[1000000 + 5] , tree[1000000 + 5] , ans[1000000 + 5] , n , m ;

struct IAKIOI {
    int leftn , rightn ;
    int position ;

    inline bool operator < ( const IAKIOI x ) const {
        return rightn < x.rightn ;
    }
} b[1000000 + 5] ;

inline int lowbit ( int x ) ;
inline void update ( int x , int k ) ;
inline int sum ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }
    scanf ( "%d" , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &b[i].leftn , &b[i].rightn ) ;
        b[i].position = i ;
    }

    sort ( b + 1 , b + 1 + m ) ;

    int next = 1 ;
    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = next ; j <= b[i].rightn ; j++ ) {
            if ( vis[a[j]] ) {
                update ( vis[a[j]] , -1 ) ;
            }
            update ( j , 1 ) ;
            vis[a[j]] = j ;
        }

        next = b[i].rightn + 1 ;
        ans[b[i].position] = sum ( b[i].rightn ) - sum ( b[i].leftn - 1 ) ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        printf ( "%d\n" , ans[i] ) ;
    }

    return 0 ;
}

inline int lowbit ( int x ) {
    return x & -x ;
}

inline void update ( int x , int k ) {
    while ( x <= n ) {
        tree[x] += k ;
        x += lowbit (x) ;
    }
}

inline int sum ( int x ) {
    int ans = 0 ;
    while ( x > 0 ) {
        ans += tree[x] ;
        x -= lowbit (x) ;
    }
    return ans ;
}
