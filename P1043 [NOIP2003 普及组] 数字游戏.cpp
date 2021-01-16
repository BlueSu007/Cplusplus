#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[100 + 5] , minn = INT_MAX , maxn ;
const int pow9[10] = { 9 , 81 , 729 , 6561 , 59409 , 531441 , 4782969 , 43046721 , 387420489 } ;
inline int MOD ( int x ) ;
inline void dfs ( int cnt , int step , int value ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        a[n + i] = a[i] ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        dfs ( 1 , 1 , 1 ) ;
        for ( int j = 1 ; j <= 2 * n ; j++ ) {
            a[j] = a[j + 1] ;
        }
    }

    printf ( "%d\n%d" , minn , maxn ) ;
    
    return 0 ;
}

inline int MOD ( int x ) {
    return ( x % 10 + 10 ) % 10 ;
}

inline void dfs ( int cnt , int step , int value ) {
    if ( minn <= value && value * pow9[m - cnt] <= maxn ) {
        return ;
    }

    int sum = 0 ;
    if ( cnt == m ) {
        for ( int i = step ; i <= n ; i++ ) {
            sum += a[i] ;
        }

        value *= MOD ( sum ) ;
        minn = min ( minn , value ) , maxn = max ( maxn , value ) ;
        return ;
    }

    for ( int i = step ; i <= n - m + cnt ; i++ ) {
        sum += a[i] ;
        dfs ( cnt + 1 , i + 1 , value * MOD ( sum ) ) ;
    }
}
