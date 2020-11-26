#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , url , x , y , a[1000000 + 5] ;
long long lazy[4000000 + 5] , sum[4000000 + 5] ;
inline void pushDown ( int k , int leftn , int rightn ) ;
inline void update ( int k , int leftbound , int rightbound , int leftn , int rightn ) ;
inline long long query ( int k , int leftbound , int rightbound , int leftn , int rightn ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &url , &x , &y ) ;
        if ( !url ) {
            update ( 1 , 1 , n , x , y ) ;
        }
        else {
            printf ( "%lld\n" , query ( 1 , 1 , n , x , y ) ) ;
        }
        // for ( int j = 1 ; j <= n * 4 ; j++ ) {
        //     cout << sum[j] << " " ;
        // }
        // cout << endl ;
    }

    return 0 ;
}

inline void pushDown ( int k , int leftn , int rightn ) {
    if ( lazy[k] ) {
        int leftchild = k << 1 , rightchild = k << 1 | 1 , len = rightn - leftn + 1 ;
        lazy[leftchild] ^= 1 , lazy[rightchild] ^= 1 ;

        sum[leftchild] = ( len - ( len >> 1 ) ) - sum[leftchild] ;
        sum[rightchild] = ( len >> 1 ) - sum[rightchild] ;
        lazy[k] = 0 ;
    }
}

inline void update ( int k , int leftbound , int rightbound , int leftn , int rightn ) {
    if ( leftn <= leftbound && rightbound <= rightn ) {
        lazy[k] ^= 1 ;
        sum[k] = ( rightbound - leftbound + 1 ) - sum[k] ;
        return ;
    }

    pushDown ( k , leftbound , rightbound ) ;
    int mid = ( leftbound + rightbound ) >> 1 ;

    if ( leftn <= mid ) {
        update ( k << 1 , leftbound , mid , leftn , rightn ) ;
    }
    if ( mid + 1 <= rightn ) {
        update ( k << 1 | 1 , mid + 1 , rightbound , leftn , rightn ) ;
    }

    sum[k] = sum[k << 1] + sum[k << 1 | 1] ;
    return ;
}

inline long long query ( int k , int leftbound , int rightbound , int leftn , int rightn ) {
    if ( leftn <= leftbound && rightbound <= rightn ) {
        return sum[k] ;
    }

    pushDown ( k , leftbound , rightbound ) ;
    int mid = ( leftbound + rightbound ) >> 1 ;
    long long ans = 0 ;

    if ( leftn <= mid ) {
        ans += query ( k << 1 , leftbound , mid , leftn , rightn ) ;
    }
    if ( mid + 1 <= rightn ) {
        ans += query ( k << 1 | 1 , mid + 1 , rightbound , leftn , rightn ) ;
    }

    return ans ;
}
