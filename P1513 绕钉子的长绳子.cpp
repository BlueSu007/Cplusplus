#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

#define LEN 105
const double qwq = 3.1415926535897932384626433 ;
double a[LEN][3] , r , edge , circle ;
int n ;
inline double qaq ( double sx , double sy , double ex , double ey ) ;

int main () {

    scanf ( "%d %lf" , &n , &r ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lf %lf" , &a[i][1] , &a[i][2] ) ;
    }

    edge = 2 * r * qwq ;
    for ( int i = 2 ; i <= n ; i++ ) {
        edge += qaq ( a[i - 1][1] , a[i - 1][2] , a[i][1] , a[i][2] ) ;
    }
    circle = qaq ( a[1][1] , a[1][2] , a[n][1] , a[n][2] ) ;

    printf ( "%.2lf" , edge + circle ) ;

    return 0 ;
}

inline double qaq ( double sx , double sy , double ex , double ey ) {
    return sqrt ( pow ( abs ( sx - ex ) , 2 ) + pow ( abs ( sy - ey ) , 2 ) ) ;
}
