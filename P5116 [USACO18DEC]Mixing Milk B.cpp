#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

int cup[4] , water[4] ;

int main () {

    for ( int i = 1 ; i <= 3 ; i++ ) {
        scanf ( "%d %d" , &cup[i] , &water[i] ) ;
    }

    int i = 1 , j = 2 ;

    for ( int k = 1 ; k <= 4 ; k++ ) {
        if ( i == 4 ) {
            i = 1 ;
        }
        if ( j == 4 ) {
            j = 1 ;
        }

        if ( water[j] + water[i] <= cup[j] ) {
            water[j] += water[i] , water[i] = 0 ;
        }
        else {
            water[i] += water[j] - cup[j] , water[j] = cup[j] ;
        }

        i++ , j++ ;
    }

    for ( int i = 1 ; i <= 3 ; i++ ) {
        printf ( "%d\n" , water[i] ) ;
    }

    return 0 ;
}
