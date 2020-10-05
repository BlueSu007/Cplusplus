#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , sum , a[300000 + 5] , cnt ;
double ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = n ; i >= 1 ; i-- ) {
        sum += a[i] , cnt++ ;
        ans = max ( ans , 1.0 * sum / cnt * sum ) ;
    }

    printf ( "%.8lf" , ans ) ;

    return 0 ;
}
