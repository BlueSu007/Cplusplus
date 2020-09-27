#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n , m , ans , a[200 + 5] , height = 1 ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = i ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        int tmp = ( i * i * i ) % 5 + 1 ;
        height += tmp ;
        if ( height > n - i + 1 ) {
            height = tmp + 1 ;
        }

        if ( i != m ) {
            for ( int j = height + 1 ; j <= n - i + 1 ; j++ ) {
                a[j - 1] = a[j] ;
            }    
        }
    }

    printf ( "%d" , a[height] ) ;

    return 0 ;
}
