#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , m , sum1 , sum2 ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            sum1 += min ( i , j ) ;
            sum2 += i * j ;
        }
    }

    printf ( "%lld %lld" , sum1 , sum2 - sum1 ) ;

    return 0 ;
}
