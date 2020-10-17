#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , ans , tmp ;
double f[700 + 5][700 + 5] , x[700 + 5] , y[700 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lf %lf" , &x[i] , &y[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            if ( i == j ) {
                continue ;
            }
            f[i][j] = ( y[i] - y[j] ) / ( x[i] - x[j] ) ;
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        sort ( f[i] + 1 , f[i] + 1 + n ) ;
        int sum1 = 0 , sum2 = 0 ;

        for ( int j = 3 ; j <= n ; j++ ) {
            if ( f[i][j] == f[i][j - 1] ) {
                sum1++ , sum2 = max ( sum1 , sum2 ) ;
            }
            else {
                sum1 = 0 ;
            }
        }

        sum1 = max ( sum1 , sum2 ) ;
        ans = max ( ans , sum1 ) ;
    }

    printf ( "%d" , ans + 2 ) ;

    return 0 ;
}
