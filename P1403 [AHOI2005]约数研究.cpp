#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , ans ; // long long
// inline long long getNumber ( long long x ) ;

int main () {

    scanf ( "%lld" , &n ) ;
    for ( long long i = 1 ; i <= n ; i++ ) {
        ans += n / i ;
        // cout << getNumber (i) << endl ;
    }
    printf ( "%lld" , ans ) ;

    return 0 ;
}
