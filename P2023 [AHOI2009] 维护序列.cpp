#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , p , x , y , op , leftn[400000 + 5] , rightn[400000 + 5] ;
long long a[100000 + 5] , sum[400000 + 5] , multiLazy[400000 + 5] , addLazy[400000 + 5] , k ;
inline void build ( int k , int leftbound , int rightbound ) ;
inline void pushDown ( int k ) ;
inline void multiplication ( int k , int leftbound , int rightbound , long long x ) ;
inline void addition ( int k , int leftbound , int rightbound , long long x ) ;
inline long long query ( int k , int leftbound , int rightbound ) ;

int main () {

    scanf ( "%d %d" , &n , &p ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
    }

    build ( 1 , 1 , n ) ;

    scanf ( "%d" , &m ) ;
    while ( m-- ) {
        scanf ( "%d %d %d" , &op , &x , &y ) ;
        if ( op == 1 ) {
            scanf ( "%lld" , &k ) ;
            multiplication ( 1 , x , y , k ) ;
        }
        else if ( op == 2 ) {
            scanf ( "%lld" , &k ) ;
            addition ( 1 , x , y , k ) ;
        }
        else {
            printf ( "%lld\n" , query ( 1 , x , y ) ) ;
        }
    }

    return 0 ;
}

inline void build ( int k , int leftbound , int rightbound ) {
    multiLazy[k] = 1 ;
    leftn[k] = leftbound , rightn[k] = rightbound ;
    if ( leftbound == rightbound ) {
        sum[k] = a[leftn[k]] ;
        sum[k] %= p ;
        return ;
    }

    int mid = ( leftn[k] + rightn[k] ) >> 1 ;
    build ( k << 1 , leftn[k] , mid ) ;
    build ( k << 1 | 1 , mid + 1 , rightn[k] ) ;

    sum[k] = sum[k << 1] + sum[k << 1 | 1] ;
    sum[k] %= p ;
}

inline void pushDown ( int k ) {
    if ( leftn[k] == rightn[k] ) {
        return ;
    }

    int mid = ( leftn[k] + rightn[k] ) >> 1 , leftchild = k << 1 , rightchild = k << 1 | 1 ;
    sum[leftchild] = ( sum[leftchild] * multiLazy[k] + addLazy[k] * ( mid - leftn[k] + 1 ) ) % p ;
    multiLazy[leftchild] = ( multiLazy[leftchild] * multiLazy[k] ) % p ;
    addLazy[leftchild] = ( addLazy[leftchild] * multiLazy[k] + addLazy[k] ) % p ;

    sum[rightchild] = ( sum[rightchild] * multiLazy[k] + addLazy[k] * ( rightn[k] - mid ) ) % p ;
    multiLazy[rightchild] = ( multiLazy[rightchild] * multiLazy[k] ) % p ;
    addLazy[rightchild] = ( addLazy[rightchild] * multiLazy[k] + addLazy[k] ) % p ;

    multiLazy[k] = 1 , addLazy[k] = 0 ;
    return ;
}

inline void multiplication ( int k , int leftbound , int rightbound , long long x ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        sum[k] = ( sum[k] * x ) % p ;
        multiLazy[k] = ( multiLazy[k] * x ) % p ;
        addLazy[k] = ( addLazy[k] * x ) % p ;
        return ;
    }

    pushDown (k) ;
    int mid = ( leftn[k] + rightn[k] ) >> 1 ;

    if ( leftbound <= mid ) {
        multiplication ( k << 1 , leftbound , rightbound , x ) ;
    }
    if ( mid + 1 <= rightbound ) {
        multiplication ( k << 1 | 1 , leftbound , rightbound , x ) ;
    }

    sum[k] = ( sum[k << 1] + sum[k << 1 | 1] ) % p ;
    return ;
}

inline void addition ( int k , int leftbound , int rightbound , long long x ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        sum[k] = ( sum[k] + ( rightn[k] - leftn[k] + 1 ) * x ) % p ;
        addLazy[k] = ( addLazy[k] + x ) % p ;
        return ;
    }

    pushDown (k) ;
    int mid = ( leftn[k] + rightn[k] ) >> 1 ;

    if ( leftbound <= mid ) {
        addition ( k << 1 , leftbound , rightbound , x ) ;
    }
    if ( mid + 1 <= rightbound ) {
        addition ( k << 1 | 1 , leftbound , rightbound , x ) ;
    }

    sum[k] = ( sum[k << 1] + sum[k << 1 | 1] ) % p ;
    return ;
}

inline long long query ( int k , int leftbound , int rightbound ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        return sum[k] ;
    }

    pushDown (k) ;
    int mid = ( leftn[k] + rightn[k] ) >> 1 ;
    long long ans = 0 ;

    if ( leftbound <= mid ) {
        ans += query ( k << 1 , leftbound , rightbound ) ;
        ans %= p ;
    }
    if ( mid + 1 <= rightbound ) {
        ans += query ( k << 1 | 1 , leftbound , rightbound ) ;
        ans %= p ;
    }

    return ans ;
}
