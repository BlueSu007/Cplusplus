#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , dis , a[100000 + 5] , ans ;

int main () {

    scanf ( "%d %d" , &n , &dis ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = 2 ; i < n ; i++ ) {
        if ( a[i + 1] - a[i - 1] <= dis ) {
            a[i] = a[i - 1] ;
            ans++ ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
