#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 105
struct node {
	int pos , food , cost ;
	int performance ;

	inline bool operator < ( const node &x ) const {
		return performance < x.performance ;
	}
} a[LEN] ;
int k , len , n , ans , cnt ;

int main () {

	scanf ( "%d %d %d" , &k , &len , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d %d" , &a[i].pos , &a[i].food , &a[i].cost ) ;
		a[i].performance = len - a[i].pos + a[i].cost ;
	}

	sort ( a + 1 , a + 1 + n ) ;

	int num = k ;
	for ( int i = 1 ; i <= n && num > 0 ; i++ ) {
		ans += min ( num , a[i].food ) * a[i].performance ;
		num -= a[i].food ;
	}

	printf ( "%d" , ans ) ;

	return 0 ;
}
