#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , score , a , day , m ;
const int tmp[6] = { 0 , 3 , 7 , 30 , 120 , 365 } ;

int main () {

	scanf ( "%d" , &n ) ;

	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a ) ;
		if ( a == 1 ) {
			if ( m > 0 ) {
				day -= pow ( 2 , m - 1 ) ;
			}

			if ( day < 0 ) {
				day = 0 ;
			}

			score++ , day++ , m = 0 ;
			for ( int i = 1 ; i <= 5 ; i++ ) {
				if ( day >= tmp[i] ) {
					score++ ;
				}
			}
		}
		else if ( a == 0 ) {
			m++ ;
		}
	}

	printf ( "%d" , score ) ;

	return 0 ;
}
