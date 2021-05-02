#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

int n , m , k , x ;
long long ans = 1 ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        ans *= pow ( ( n - i + 1 ) , 2 ) ;
        // ans *= ( n - i + 1 ) * ( n - i + 1 ) ;
    }

    while ( k-- ) {
        scanf ( "%d" , &x ) ;
        for ( int i = 2 ; i <= x ; i++ ) {
            ans /= i ;
        }
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
