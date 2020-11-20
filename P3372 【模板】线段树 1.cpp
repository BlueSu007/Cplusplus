#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , q , leftn[400000 + 5] , rightn[4000000 + 5] , op , x , y ;
long long a[100000 + 5] , sum[400000 + 5] , lazy[400000 + 5] , k ;
inline void build ( int k , int leftbound , int rightbound ) ;
inline void pushDown ( int k ) ;
inline void update ( int k , int leftbound , int rightbound , long long x ) ;
inline long long query ( int k , int leftbound , int rightbound ) ;

int main () {

    scanf ( "%d %d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
    }

    build ( 1 , 1 , n ) ;

    for ( int i = 1 ; i <= q ; i++ ) {
        scanf ( "%d" , &op ) ;
        if ( op == 1 ) {
            scanf ( "%d %d %lld" , &x , &y , &k ) ;
            update ( 1 , x , y , k ) ;
        }
        else {
            scanf ( "%d %d" , &x , &y ) ;
            printf ( "%lld\n" , query ( 1 , x , y ) ) ;
        }
    }

    return 0 ;
}

inline void pushDown ( int k ) {
    if ( leftn[k] == rightn[k] ) {
        return ;
    }

    int leftchild = k << 1 , rightchild = k << 1 | 1 ;
    lazy[leftchild] += lazy[k] ;
    sum[leftchild] += ( rightn[leftchild] - leftn[leftchild] + 1 ) * lazy[k] ;

    lazy[rightchild] += lazy[k] ;
    sum[rightchild] += ( rightn[rightchild] - leftn[rightchild] + 1 ) * lazy[k] ;

    lazy[k] = 0 ;
    return ;
}

inline void update ( int k , int leftbound , int rightbound , long long x ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        lazy[k] += x ;
        sum[k] += ( rightn[k] - leftn[k] + 1 ) * x ;
        return ;
    }

    pushDown (k) ;

    int mid = ( leftn[k] + rightn[k] ) >> 1 ;
    if ( leftbound <= mid ) {
        update ( k << 1 , leftbound , rightbound , x ) ;
    }
    if ( mid + 1 <= rightbound ) {
        update ( k << 1 | 1 , leftbound , rightbound , x ) ;
    }

    sum[k] = sum[k << 1] + sum[k << 1 | 1] ;
}

inline long long query ( int k , int leftbound , int rightbound ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        return sum[k] ;
    }

    pushDown (k) ;
    long long ans = 0 ;
    int mid = ( leftn[k] + rightn[k] ) >> 1 ;

    if ( leftbound <= mid ) {
        ans += query ( k << 1 , leftbound , rightbound ) ;
    }
    if ( mid + 1 <= rightbound ) {
        ans += query ( k << 1 | 1 , leftbound , rightbound ) ;
    }

    return ans ;
}

inline void build ( int k , int leftbound , int rightbound ) {
    leftn[k] = leftbound , rightn[k] = rightbound ;
    if ( leftbound == rightbound ) {
        sum[k] = a[leftn[k]] ;
        return ;
    }

    int mid = ( leftn[k] + rightn[k] ) >> 1 ;
    build ( k << 1 , leftn[k] , mid ) ;
    build ( k << 1 | 1 , mid + 1 , rightn[k] ) ;
    sum[k] = sum[k << 1] + sum[k << 1 | 1] ;
}
