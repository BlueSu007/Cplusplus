#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 3000
int x , y , a , b , map[LEN][LEN] ;
int sx = INT_MAX , sy = INT_MAX , ex , ey , ans ;

int main () {

	for ( int i = 0 ; i < 3 ; i++ ) {
		scanf ( "%d %d %d %d" , &x , &y , &a , &b ) ;
		x += 1001 , y += 1001 , a += 1001 , b += 1001 ;
		for ( int k = x ; k < a ; k++ ) {
			for ( int j = y ; j < b ; j++ ) {
				map[k][j] = ( i + 1 ) % 3 ;
			}
		}
		sx = min ( min ( x , a ) , sx ) , sy = min ( min ( y , b ) , sy ) ;
		ex = max ( max ( x , a ) , ex ) , ey = max ( max ( y , b ) , ey ) ;
	}

	for ( int i = sx ; i <= ex ; i++ ) {
		for ( int j = sy ; j <= ey ; j++ ) {
			if ( map[i][j] ) {
				ans++ ;
			}
			// cout << map[i][j] << " " ;
		}
		// cout << endl ;
	}

	printf ( "%d" , ans ) ;

	return 0 ;
}
