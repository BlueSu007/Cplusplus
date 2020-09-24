#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[1000 + 5] , n , f[10000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n / 2 ; i++ ) {
        for ( int j = 2 ; i * j <= n ; j++ ) {
            a[i * j] += i ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i ; j <= n ; j++ ) {
            f[j] = max ( f[j] , f[j - i] + a[i] ) ;
        }
    }

    printf ( "%d" , f[n] ) ;

    return 0 ;
}
