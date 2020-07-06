#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[10 + 5] , b[10 + 5] , n , ans = 0x7fffffff;
inline void dfs ( int step , int x , int y );

int main() {
	
	scanf ( "%d" , &n );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d%d" , &a[i] , &b[i] );
	}
	
	dfs ( 1 , 1 , 0 );
	printf ( "%d\n" , ans );
	
	return 0;
}

inline void dfs ( int step , int x , int y ) {
	if ( step > n ) {
		if ( x == 1 && y == 0 ) {
			return ;
		}
		
		ans = min ( abs ( x - y ) , ans );
		return ;
	}
	
	dfs ( step + 1 , x * a[step] , y + b[step] );
	dfs ( step + 1 , x , y );
}
