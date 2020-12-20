#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

char star[100] , team[100] ;

int main () {

    scanf ( "%s %s" , star , team ) ;
    int len1 = strlen (star) , len2 = strlen (team) ;

    int sum1 = 1 , sum2 = 1 ;
    for ( int i = 0 ; i < len1 ; i++ ) {
        if ( isupper (star[i]) ) {
            sum1 *= star[i] - 'A' + 1 ;
            sum1 %= 47 ;
        }
    }
    for ( int i = 0 ; i < len2 ; i++ ) {
        if ( isupper (team[i]) ) {
            sum2 *= team[i] - 'A' + 1 ;
            sum2 %= 47 ;
        }
    }

    if ( sum1 == sum2 ) {
        printf ( "GO" ) ;
    }
    else {
        printf ( "STAY" ) ;
    }

    return 0 ;
}
