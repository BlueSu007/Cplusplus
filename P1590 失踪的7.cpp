#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long a ;//!
int n ;

int main () {

    scanf ( "%d" , &n ) ;
    while ( n-- ) {
        scanf ( "%lld" , &a ) ;
        int tmp = 1 , ans = 0 ;
        for ( ; a ; a /= 10 , tmp *= 9 ) {
            ans += tmp * ( a % 10 ) ;
            if ( a % 10 >= 7 ) {
                ans -= tmp ;
            }
        }
        printf ( "%d\n" , ans ) ;
    }

    return 0 ;
}
