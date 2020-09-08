#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

double a , b , c , leftn , rightn ;
inline bool func ( double x ) ;

int main () {

    scanf ( "%lf %lf %lf" , &a , &b , &c ) ;
    leftn = 0 , rightn = 10 ;
    while ( rightn - leftn >= 0.0001 ) {
        double mid = ( leftn + rightn ) / 2 ;
        if ( func(mid) ) {
            rightn = mid ;
        }
        else {
            leftn = mid ;
        }
    }
    printf ( "%.1lf" , leftn * 100 + 0.00001 ) ;

    return 0 ;
}

inline bool func ( double x ) {
    if ( pow ( 1.0 / ( 1.0 + x ) , c ) >= 1 - a / b * x ) {
        return true ;
    }
    return false ;
}
