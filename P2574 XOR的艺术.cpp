#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , p , x , y , a[200000 + 5] , leftn[800000 + 5] , rightn[800000 + 5] ;
char s[200000 + 5] ;
long long lazy[800000 + 5] , sum[800000 + 5] ;
inline void build ( int k , int leftbound , int rightbound ) ;
inline void pushDown ( int k ) ;
inline void update ( int k , int leftbound , int rightbound ) ;
inline long long query ( int k , int leftbound , int rightbound ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> s[i] ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = s[i] - '0' ;
    }

    build ( 1 , 1 , n ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &p , &x , &y ) ;
        if ( !p ) {
            update ( 1 , x , y ) ;
        }
        else {
            printf ( "%lld\n" , query ( 1 , x , y ) ) ;
        }
    }

    return 0 ;
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

inline void pushDown ( int k ) {
    if ( lazy[k] ) {
        int leftchild = k << 1 , rightchild = k << 1 | 1 , len = rightn[k] - leftn[k] + 1 ;
        lazy[leftchild] ^= 1 ;
        sum[leftchild] = ( len - ( len >> 1 ) ) - sum[leftchild] ;

        lazy[rightchild] ^= 1 ;
        sum[rightchild] = ( len >> 1 ) - sum[rightchild] ;
        lazy[k] = 0 ;
    }
}

inline void update ( int k , int leftbound , int rightbound ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        lazy[k] ^= 1 ;
        sum[k] = ( rightn[k] - leftn[k] + 1 ) - sum[k] ;
        return ;
    }

    pushDown (k) ;
    int mid = ( leftn[k] + rightn[k] ) >> 1 ;
    if ( leftbound <= mid ) {
        update ( k << 1 , leftbound , rightbound ) ;
    }
    if ( mid + 1 <= rightbound ) {
        update ( k << 1 | 1 , leftbound , rightbound ) ;
    }

    sum[k] = sum[k << 1] + sum[k << 1 | 1] ;
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
    }
    if ( mid + 1 <= rightbound ) {
        ans += query ( k << 1 | 1 , leftbound , rightbound ) ;
    }

    return ans ;
}
