#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long x , y , ans ;

int main () {

    scanf ( "%lld %lld" , &x , &y ) ;
    while ( x && y ) {
        swap ( x , y ) ;
        ans += 4 * y * ( x / y ) ;
        x %= y ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
