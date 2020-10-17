#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , ans = 1 ;

int main () {

    scanf ( "%lld" , &n ) ;
    for ( register long long i = 1 ; i <= n ; i++ ) {
        ans *= i ;
        while ( ans % 10 == 0 ) {
            ans /= 10 ;
        }
        ans %= 100000000 ;
    }
    printf ( "%lld" , ans % 10 ) ;

    return 0 ;
}
