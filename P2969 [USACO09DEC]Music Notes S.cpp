#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <queue>
using namespace std;

int a[114514] , b[114514] , n , k , x ;

int main () {
	
	scanf ( "%d %d" , &n , &k ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
		b[i] = b[i - 1] + a[i] ;
	}
	
	while ( k-- ) {
		scanf ( "%d" , &x ) ;
		printf ( "%d\n" , upper_bound ( b + 1 , b + 1 + n , x ) - b ) ;
	}
	
	return 0 ;
}
