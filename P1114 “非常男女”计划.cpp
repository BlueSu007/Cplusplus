#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , t , ans , cnt1 , cnt2 ;
int leftn[200000 + 5] , rightn[200000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        cnt1 += ( x == 0 ) ;
        cnt2 += ( x == 1 ) ;

        t = cnt1 - cnt2 + n ;

        if ( leftn[t] == 0 && t != n ) {
            leftn[t] = i ;
        }
        else {
            rightn[t] = i ;
        }
    }

    for ( int i = 0 ; i <= 2 * n ; i++ ) {
        ans = max ( ans , rightn[i] - leftn[i] ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
