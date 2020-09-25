#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

int n , s , c , y , lastC , lastY ;
long long ans ;

int main () {

    scanf ( "%d %d %d %d" , &n , &s , &lastC , &lastY ) ;
    n-- , ans += lastC * lastY ;

    while ( n-- ) {
        scanf ( "%d %d" , &c , &y ) ;
        lastC = min ( lastC + s , c ) ;
        ans += lastC * y ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
