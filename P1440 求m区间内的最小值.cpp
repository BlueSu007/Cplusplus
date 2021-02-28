#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 2000005
int n , m , a[LEN] , sum[LEN * 4] , leftn[LEN * 4] , rightn[LEN * 4] ;
inline void build ( int k , int leftBound , int rightBound ) ;
inline int query ( int k , int leftBound , int rightBound ) ;

int main () {

	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}

	build ( 1 , 1 , n ) ;

	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "%d\n" , query ( 1 , max ( 0 , i - m ) , i - 1 ) ) ;
	}

	return 0 ;
}

inline void build ( int k , int leftBound , int rightBound ) {
	leftn[k] = leftBound , rightn[k] = rightBound ;
	if ( leftBound == rightBound ) {
		sum[k] = a[leftn[k]] ;
		return ;
	}

	int mid = ( leftn[k] + rightn[k] ) >> 1 ;
	build ( k << 1 , leftBound , mid ) ;
	build ( k << 1 | 1 , mid + 1 , rightBound ) ;

	sum[k] = min ( sum[k << 1] , sum[k << 1 | 1] ) ;
	return ;
}

inline int query ( int k , int leftBound , int rightBound ) {
	if ( leftBound <= leftn[k] && rightn[k] <= rightBound ) {
		return sum[k] ;
	}

	int ans = INT_MAX , mid = ( leftn[k] + rightn[k] ) >> 1 ;
	if ( leftBound <= mid ) {
		ans = min ( ans , query ( k << 1 , leftBound , rightBound ) ) ;
	}
	if ( mid + 1 <= rightBound ) {
		ans = min ( ans , query ( k << 1 | 1 , leftBound , rightBound ) ) ;
	}

	return ans ;
}
