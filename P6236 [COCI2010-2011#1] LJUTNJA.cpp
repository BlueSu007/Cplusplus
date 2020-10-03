#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

unsigned long long a[100000 + 5] , ans , n , m , maxn , id ;

int main () {

    scanf ( "%llu %llu" , &m , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%llu" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n , greater < int > () ) ;
    maxn = a[1] ;

    while ( m ) {
        if ( a[id] != maxn ) {
            maxn = a[1] , id = 1 ;
            continue ;
        }
        a[id] -= 1 , m -= 1 , id++ ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        ans += a[i] * a[i] ;
    }

    printf ( "%llu" , ans ) ;

    return 0 ;
}
