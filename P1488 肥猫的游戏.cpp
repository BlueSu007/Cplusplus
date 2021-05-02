#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

int n , a , b , c ;

int main () {

    scanf ( "%d %d %d %d" , &n , &a , &b , &c ) ;
    if ( ( abs ( a - b ) == 1 ) + ( abs ( b - c ) == 1 ) + ( abs ( a - c ) == 1 ) >= 2 ) {
        printf ( "JMcat Win" ) ;
    }
    else {
        if ( n % 2 ) {
            printf ( "PZ Win" ) ;
        }
        else {
            printf ( "JMcat Win" ) ;
        }
    }

    return 0 ;
}
