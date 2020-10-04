#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , a[100] ;

int main () {

    scanf ( "%lld" , &n ) ;
    a[1] = 0 , a[2] = 1 , a[3] = 2 ;
    for ( int i = 4 ; i <= n ; i++ ) {
        a[i] = ( i - 1 ) * ( a[i - 1] + a[i - 2] ) ;
    }
    printf ( "%lld" , a[n] ) ;

    return 0 ;
}
