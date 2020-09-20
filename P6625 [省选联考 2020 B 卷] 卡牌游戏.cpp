#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

long long ans , n , x , sum ;

int main () {

    scanf ( "%lld" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &x ) ;
        sum += x ;
        if ( sum >= 1 && i != 1 ) {
            ans += sum ;
        }
    }
    printf ( "%lld" , ans ) ;

    return 0 ;
}
