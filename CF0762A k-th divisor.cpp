#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
using namespace std;

long long n , k , a[10000000 + 5] ;

int main () {

    scanf ( "%lld %lld" , &n , &k ) ;
    long long cnt = 0 ;

    for ( long long i = 1 ; i * i <= n ; i++ ) {
        if ( n % i == 0 ) {
            cnt++ , a[cnt] = i ;
            if ( i != n / i ) {
                cnt++ , a[cnt] = n / i ;
            }
        }
    }

    sort ( a + 1 , a + 1 + cnt ) ;

    if ( cnt >= k ) {
        printf ( "%lld" , a[k] ) ;
    }
    else {
        printf ( "-1" ) ;
    }

    return 0 ;
}
