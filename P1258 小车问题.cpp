#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

double a , b , s , x ;
	
int main () {
	
	scanf ( "%lf %lf %lf" , &s , &a , &b ) ;
	x = ( 2 * a * s ) / ( 3 * a + b ) ;
	printf ( "%.6lf" , x / a + ( s - x ) / b ) ;
	
	return 0 ;
}
