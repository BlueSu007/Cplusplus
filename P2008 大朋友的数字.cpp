#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n , a[10000 + 5] , b[10000 + 5] , c[10000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        b[i] = 1 ;
        for ( int j = 1 ; j <= i - 1 ; ++ j ) {
            if ( a[i] >= a[j] && b[i] < b[j] + 1 ) {
                b[i] = b[j] + 1 ;
                c[i] = c[j] ;
            }
        }
        c[i] += a[i] ;
    }

    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , c[i] ) ;
    }

    return 0 ;
}
