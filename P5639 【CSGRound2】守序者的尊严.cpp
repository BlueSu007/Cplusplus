#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , ans , a[1000000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 2 ; i <= n ; i++ ) {
        if ( a[i] != a[i - 1] ) {
            ans++ ;
        }
    }

    printf ( "%d" , ans + 1 ) ;

    return 0 ;
}
