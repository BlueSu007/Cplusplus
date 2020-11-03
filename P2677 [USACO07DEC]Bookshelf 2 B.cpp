#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[100] , ans = INT_MAX , vis[100] ;
inline void dfs ( int step , int sum ) ;

int main () {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}
	
	dfs ( 0 , 0 ) ;
	printf ( "%d" , ans ) ;
	
	return 0 ;
}

inline void dfs ( int step , int sum ) {
	
	if ( sum - m >= 0 ) {
		ans = min ( ans , sum - m ) ;
		return ;
	}
	if ( ans == 0 ) {
		printf ( "0" ) ;
		exit ( false ) ;
	}
	if ( step == n ) {
		return ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( !vis[i] ) {
			vis[i] = true ;
			dfs ( step + 1 , sum + a[i] ) ;
			vis[i] = false ;
		}
	}
}
