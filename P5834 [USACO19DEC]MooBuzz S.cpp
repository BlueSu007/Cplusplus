#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[8] = { 14 , 1 , 2 , 4 , 7 , 8 , 11 , 13 } , n ;

int main () {
	
	scanf ( "%d" , &n ) ;
	int tmp = n / 8 ;
	int ans = tmp * 15 ;
	
	if ( n % 8 ) {
		ans += a[n % 8] ;
	}
	else {
		ans-- ;
	}
	
	printf ( "%d" , ans ) ;
	
	return 0 ;
}
