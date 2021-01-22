#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

const unsigned long long x = 13331 ;
unsigned long long k , cnt1 , cnt2 ;
char c ;

int main () {

    while ( c = getchar () ) {
        if ( islower (c) ) {
            break ;
        }
    }

    cnt1 = c , cnt2 = c , k = x ;
    while ( c = getchar () ) {
        if ( ! islower (c) ) {
            break ;
        }

        cnt1 = cnt1 * x + c , cnt2 = c * k + cnt2 , k *= x ;
    }

    if ( cnt1 == cnt2 ) {
        printf ( "TAK" ) ;
    }
    else {
        printf ( "NIE" ) ;
    }

    return 0 ;
}
