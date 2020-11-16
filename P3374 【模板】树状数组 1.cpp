#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[500000 + 5] , c[500000 + 5] , n , m , url , x , y ;
inline int sum ( int x ) ;
inline void update ( int x , int k ) ;
inline int lowbit ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        update ( i , a[i] ) ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &url , &x , &y ) ;
        if ( url == 1 ) {
            update ( x , y ) ;
        }
        else {
            printf ( "%d\n" , sum (y) - sum ( x - 1 ) ) ;
        }
    }

    return 0 ;
}

inline int sum ( int x ) {
    int ans = 0 ;
    while ( x != 0 ) {
        ans += c[x] ;
        x -= lowbit (x) ;
    }
    return ans ;
}

inline void update ( int x , int k ) {
    while ( x <= n ) {
        c[x] += k ;
        x += lowbit (x) ;
    }
}

inline int lowbit ( int x ) {
    return x & -x ;
}
