#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , sumValue ;
double life , value , leftLife = 10 ;

int main () {

    scanf ( "%d" , &n ) ;
    while ( n-- ) {
        scanf ( "%lf %lf" , &life , &value ) ;
        leftLife -= life ;
        if ( leftLife <= 0 ) {
            break ;
        }
        if ( leftLife > 10 ) {
            leftLife = 10 ;
        }
        sumValue += value ;
    }

    int grade = 0 ;
    while ( sumValue - pow ( 2 , grade ) >= 0 ) {
        sumValue -= pow ( 2 , grade ) ;
        grade++ ;
    }

    printf ( "%d %d" , grade , sumValue ) ;

    return 0 ;
}
