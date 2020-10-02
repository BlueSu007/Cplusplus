#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , m , sum , k , ans , q ;
long long a[10000 + 5][100 + 5] , b[10000 + 5][100 + 5] , c[10000 + 5] ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 0 ; j < m ; j++ ) {
            scanf ( "%lld %lld" , &a[i][j] , &b[i][j] ) ;
            c[i] += a[i][j] ;
        }
    }
    scanf ( "%lld" , &k ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        sum += b[i][k] , ans = 0 , q = k ;
        b[i][q] = ( b[i][q] - 1 ) % c[i] + 1 ;

        while ( ans < b[i][q] ) {
            ans += a[i][k] ;
            if ( ans == b[i][q] ) {
                break ;
            }

            k++ ;
            if ( k == m ) {
                k = 0 ;
            }
        }
    }

    printf ( "%lld\n" , sum % 20123 ) ;

    return 0 ;
}
