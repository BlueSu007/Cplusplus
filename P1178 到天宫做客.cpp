#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , a , b , num[400] , ans ;
const int month[13] = { 0 , 0 , 31 , 60 , 91 , 121 , 152 , 182 , 213 , 244 , 274 , 305 , 335 } ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a , &b ) ;
        num[i] += month[a] ;
        num[i] += b ;
    }

    sort ( num + 1 , num + 1 + n ) ;
    num[n + 1] = 367 ;

    for ( int i = 1 ; i <= n + 1 ; i++ ) {
        ans = max ( num[i] - num[i - 1] - 1 , ans ) ;
    }

    double tmp = ( ans * 1.0 * 86400 / 366 ) + 0.5 ;
    ans = tmp ;
    printf ( "%d" , ans ) ;

    return 0 ;
}
