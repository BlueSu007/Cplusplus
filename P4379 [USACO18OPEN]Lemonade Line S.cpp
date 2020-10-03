#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[100000 + 5] , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;
    reverse ( a + 1 , a + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] < i - 1 ) {
            break ;
        }
        ans++ ;
        // cout << a[i] << " " ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
