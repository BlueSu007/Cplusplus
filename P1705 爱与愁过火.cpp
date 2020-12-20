#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 3000
int m , r , n , a[LEN] , vis[LEN] , ans ;
inline void dfs ( int last , int step , int money) ;

int main () {

	scanf ( "%d %d %d" , &m , &r , &n ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}

	dfs ( 1 , 0 , 0 ) ;
	printf ( "%d" , ans ) ;

	return 0 ;
}

inline void dfs ( int last , int step , int money ) {
	if ( step == r ) {
		if ( money > n ) {
			ans++ ;
		}

		return ;
	}
	if ( m - last + 1 < r - step ) {
		return ;
	}
	if ( money > n ) {
		int tmp = 1 , qwq = m - last + 1 , len = r - step ;
		for ( int i = 1 ; i <= len ; i++ ) {
			tmp = tmp * ( qwq - i + 1 ) / i ;
		}

		ans += tmp ;
		return ;
	}

	for ( int i = last ; i <= m ; i++ ) {
		if ( ! vis[i] ) {
			vis[i] = true ;
			dfs ( i + 1 , step + 1 , money + a[i] ) ;
			vis[i] = false ;
		}
	}
}
