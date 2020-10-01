#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long ans , n , x , y , a[100000 + 5] ;

int main () {

    scanf ( "%lld %lld" , &n , &x ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
        if ( a[i] + a[i - 1] > x ) {
            y = a[i] + a[i - 1] - x ;
            a[i] -= y , ans += y ;
        }
    }
    printf ( "%lld" , ans ) ;

    return 0 ;
}
