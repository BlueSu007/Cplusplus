#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , ans ;
struct node {
	int x , y ;
	inline bool operator < ( const node tmp ) const {
		return y < tmp.y ;
	}
} a[100000 + 5] ;

int main () {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d" , &a[i].x , &a[i].y ) ;
	}
	
	sort ( a + 1 , a + 1 + n ) ;
	
	int i = 1 , j = n ;
	while ( i <= j ) {
		int tmp = min ( a[i].x , a[j].x ) ;
		ans = max ( ans , a[i].y + a[j].y ) ;
		a[i].x -= tmp , a[j].x -= tmp ;
		
		if ( a[i].x <= 0 ) {
			i++ ;
		}
		if ( a[j].x <= 0 ) {
			j-- ;
		}
	}
	
	printf ( "%d" , ans ) ;
	return 0 ;
}
