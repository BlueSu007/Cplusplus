#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int m , w[20 + 5] , f[100000 + 5] , n ;

int main () {

    scanf ( "%d" , &m ) ;

    n = ceil ( sqrt ( sqrt (m) ) + 1 ) ; 
    for ( int i = 1 ; i <= n ; i++ ) {
        w[i] = i * i * i * i ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        f[i] = INT_MAX ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = w[i] ; j <= m ; j++ ) {
            f[j] = min ( f[j] , f[j - w[i]] + 1 ) ;
        }
    }

    printf ( "%d" , f[m] ) ;

    return 0 ;
}
