#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
int n , m , x , y , url , a[LEN] , sum[LEN] ;
inline int lowbit ( int x ) ;
inline void update ( int x ) ;
inline int query ( int x ) ;

int main () {

	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d" , &url , &x ) ;
		if ( url == 1 ) {
			scanf ( "%d" , &y ) ;
			update (x) , update ( y + 1 ) ;
		}
		else {
			printf ( "%d\n" , query (x) ) ;
		}
	}

	return 0 ;
}

inline int lowbit ( int x ) {
	return x & -x ;
}

inline void update ( int x ) {
	while ( x <= n ) {
		sum[x] ^= 1 ;
		x += lowbit (x) ;
	}
}

inline int query ( int x ) {
	int ans = 0 ;
	while ( x > 0 ) {
		ans ^= sum[x] ;
		x -= lowbit (x) ;
	}
	return ans ;
}
