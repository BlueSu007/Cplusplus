#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , x , y , a[200000 + 5] , sum[800000 + 5] , leftn[800000 + 5] , rightn[800000 + 5] ;
char c ;
inline void build ( int k , int leftbound , int rightbound ) ;
inline void pushDown ( int k ) ;
inline void update ( int k , int position , int x ) ;
inline int query ( int k , int position , int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    build ( 1 , 1 , n ) ;

    for ( int i = 1 ; i <= m ; i++ ) {
        cin >> c >> x >> y ;
        if ( c == 'Q' ) {
            printf ( "%d\n" , query ( 1 , x , y ) ) ;
        }
        else {
            update ( 1 , x , y ) ;
            // for ( int i = 1 ; i <= 2 * n ; i++ ) {
                // cout << sum[i] << " " ;
            // }
            // cout << endl ;
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
    if ( leftbound <= mid ) {
        build ( k << 1 , leftbound , mid ) ;
    }
    if ( mid + 1 <= rightbound ) {
        build ( k << 1 | 1 , mid + 1 , rightbound ) ;
    }
    sum[k] = max ( sum[k << 1] , sum[k << 1 | 1] ) ;
}

inline void update ( int k , int position , int x ) {
    if ( leftn[k] == position && rightn[k] == position ) {
        sum[k] = max ( sum[k] , x ) ;
        return ;
    }

    if ( position > rightn[k << 1] ) {
        update ( k << 1 | 1 , position , x ) ;
    }
    else {
        update ( k << 1 , position , x ) ;
    }

    sum[k] = max ( sum[k << 1] , sum[k << 1 | 1] ) ;
}

inline int query ( int k , int leftbound , int rightbound ) {
    if ( leftbound <= leftn[k] && rightn[k] <= rightbound ) {
        return sum[k] ;
    }

    int mid = ( leftn[k] + rightn[k] ) >> 1 , ans = 0 ;
    if ( leftbound <= mid ) {
        ans = max ( ans , query ( k << 1 , leftbound , rightbound ) ) ;
    }
    if ( mid + 1 <= rightbound ) {
        ans = max ( ans , query ( k << 1 | 1 , leftbound , rightbound ) ) ;
    }

    return ans ;
}
