#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

double d1 , d2 , c , P , d[15] , p[15] ;
double goalDis , maxDis , minPrice = 23333 , oil , ans ;
int pos , n ;

int main () {

    scanf ( "%lf %lf %lf %lf %d" , &d1 , &c , &d2 , &P , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lf %lf" , &d[i] , &p[i] ) ;
    }

    maxDis = c * d2 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( d[i] - d[i - 1] > maxDis ) {
            printf ( "No Solution" ) ;
            exit ( false ) ;
        }
    }

    while ( d1 - goalDis ) {
        for ( int i = pos + 1 ; d[i] - goalDis <= maxDis && i <= n ; i++ ) {
            if ( p[i] < minPrice ) {
                minPrice = p[i] , pos = i ;
            }
        }

        if ( minPrice <= P ) {
            ans += ( ( d[pos] - goalDis ) / d2 - oil ) * P ;
            oil = ( d[pos] - goalDis ) / d2 ;
        }
        else if ( d1 - goalDis > maxDis ) {
            ans += ( c - oil ) * P ;
            oil = c ;
        }
        else {
            ans += ( ( d1 - goalDis ) / d2 - oil ) * P ;
            break ;
        }

        oil = oil - ( d[pos] - goalDis ) / d2 ;
        goalDis = d[pos] ;
        P = minPrice , minPrice = 23333 ;
    }

    printf ( "%.2lf" , ans ) ;

    return 0 ;
}
