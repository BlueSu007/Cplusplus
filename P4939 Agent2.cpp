#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10000000
int n , m , url , x , y , sum[LEN] ;
inline int lowbit ( int x ) ;
inline void update ( int x , int k ) ;
inline int query ( int x ) ;

int main () {

	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d" , &url , &x ) ;
		if ( url == 0 ) {
			scanf ( "%d" , &y ) ;
			update ( x , 1 ) , update ( y + 1 , -1 ) ;
		}
		else {
			printf ( "%d\n" , query (x) ) ;
		}
		
		/*
		for ( int i = 1 ; i <= n ; i++ ) {
			cout << sum[i] << " " ;
		}
		cout << endl ;
		*/
	}

	return 0 ;
}

inline int lowbit ( int x ) {
	return x & -x ;
}

inline void update ( int x , int k ) {
	while ( x <= n ) {
		sum[x] += k ;
		x += lowbit (x) ;
	}
}

inline int query ( int x ) {
	int ans = 0 ;
	while ( x > 0 ) {
		ans += sum[x] ;
		x -= lowbit (x) ;
	}
	return ans ;
}
