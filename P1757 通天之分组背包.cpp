#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , x , maxn , arrNum ;
int w[100000 + 5] , v[100000 + 5] ;
int dp[1000 + 5][1000 + 5] , kinds[1000000 + 5] , f[10000000 + 5] ;

int main () {

    scanf ( "%d %d" , &m , &n , &arrNum ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d %d" , &w[i] , &v[i] , &x ) ;
        maxn = max ( x , maxn ) ;
        kinds[x]++ ;
        dp[x][kinds[x]] = i ;
    }

    for ( int k = 1 ; k <= maxn ; k++ ) {
        for ( int j = m ; j >= 0 ; j-- ) {
            for ( int i = 1 ; i <= kinds[k] ; i++ ) {
                int tmp = dp[k][i] ;
                if ( j >= w[tmp] ) {
                    f[j] = max ( f[j - w[tmp]] + v[tmp] , f[j] ) ;
                }
            }
        }
    }

    printf ( "%d" , f[m] ) ;

    return 0 ;
}
