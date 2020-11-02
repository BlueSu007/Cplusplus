#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <deque>
using namespace std;

int a[2009] , b[2009] , maxn , n , x ;
inline void dfs ( int k , int step ) ;

int main () {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &x ) ;
		scanf ( "%d %d" , &a[x] , &b[x] ) ;
	}
	
	dfs ( 1 , 1 ) ;
	printf ( "%d" , maxn ) ;
	
	return 0 ;
}

inline void dfs ( int k , int step ) {
	if ( a[k] != 0 ) {
		dfs ( a[k] , step + 1 ) ;
	}
	if ( b[k] != 0 ) {
		dfs ( b[k] , step + 1 ) ;
	}
	
	maxn = max ( maxn , step ) ;
}
