#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std ;

int n , k , label[20] , a[20] ;
long long ans = INT_MIN , maxn[20][20] ;
inline long long calculate ( int x , int y , int flag ) ;
inline long long getDP () ;
inline void dfs ( int x , int multiPos , int addPos ) ;

int main () {

    scanf ( "%d %d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    dfs ( 1 , 0 , 0 ) ;
    printf ( "%lld" , ans ) ;

    return 0 ;
}

inline long long calculate ( int x , int y , int flag ) {
    if ( flag == 1 ) {
        return x + y ;
    }
    else {
        return x * y ;
    }
}

inline long long getDP () {
    for ( int i = 1 ; i <= n ; i++ ) {
        maxn[i][i] = a[i] ;
    }

    int rightn ;
    for ( int len = 1 ; len <= n ; len++ ) {
        for ( int leftn = 1 ; leftn + len - 1 <= n ; leftn++ ) {
            rightn = leftn + len - 1 ;
            for ( int i = leftn ; i < rightn ; i++ ) {
                maxn[leftn][rightn] = max ( maxn[leftn][rightn] , calculate ( maxn[leftn][i] , maxn[i + 1][rightn] , label[i] ) ) ;
            }
        }
    }

    return maxn[1][n] ;
}

inline void dfs ( int x , int multiPos , int addPos ) {
    if ( x == n ) {
        memset ( maxn , 0 , sizeof ( maxn ) ) ;
        ans = max ( ans , getDP () ) ;
        return ;
    }

    if ( multiPos < k ) {
        label[x] = 2 ;
        dfs ( x + 1 , multiPos + 1 , addPos ) ;
    }
    if ( addPos < n - k - 1 ) {
        label[x] = 1 ;
        dfs ( x + 1 , multiPos , addPos + 1 ) ;
    }
}
