#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int k , a , b , c ;

int main () {

    // freopen ( "cake.in" , "r" , stdin ) ;
    // freopen ( "cake.out" , "w" , stdout ) ;

    scanf ( "%d" , &k ) ;
    while ( k-- ) {
        scanf ( "%d %d %d" , &a , &b , &c ) ;
        int sum = a + b + c , ans = 0 ;
        if ( a == 0 && b == 0 || a == 0 && c == 0 || b == 0 && c == 0 ) {
            ans = 0 ;
        }
        else if ( a == 0 || b == 0 || c == 0 ) {
            if ( a == b || b == c || a == c ) {
                ans = 1 ;
            }
            else {
                ans = 2 ;
            }
        }
        else if ( ( double ) a == sum / 2.0 || ( double ) b == sum / 2.0 || ( double ) c == sum / 2.0 ) {
            ans = 2 ;
        }
        else if ( ! ( a == b && a == c && b == c ) && ( a == b || a == c || b == c ) ) { /* 3 3 2 | 4 4 1 */
            ans = 2 ;
        }
        else {
            ans = 3 ;
        }
        printf ( "%d\n" , ans ) ;
    }

    return 0 ;
}
