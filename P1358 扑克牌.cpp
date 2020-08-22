#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define mod 10007
using namespace std;

int n , m , tmp ;
long long a[100 + 5] , f[10000 + 5][100 + 5] , ans = 1 ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 0 ; i <= n ; i++ ) {
        f[i][0] = 1 ;
    }
    for ( int i = 1 ; i <= min ( n , m ) ; i++ ) {
        f[i][i] = 1 ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= min ( n , 100 ) ; j++ ) {
            f[i][j] = ( f[i - 1][j - 1] + f[i - 1][j] ) % mod ;
        }
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d" , &tmp ) ;
        ans *= f[n][tmp] ;
        ans %= mod ;
        n -= tmp ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
