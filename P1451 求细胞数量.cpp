#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int a[100 + 5][100 + 5] , n , m , ans ;
char c ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void dfs ( int x , int y ) ;

int main() {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			scanf ( "%1d" , &a[i][j] ) ;
		} 
	} 
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( a[i][j] ) {
				ans++ ;
				dfs ( i , j ) ;
			}
		}
	}
	
	printf ( "%d" , ans ) ;
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	if ( x > n || y > m || x < 1 || y < 1 ) {
		return ;
	}
	
	a[x][y] = 0 ;
	for ( int i = 0 ; i < 4 ; i++ ) {
		int fx = dx[i] + x ;
		int fy = dy[i] + y ;
		if ( a[fx][fy] ) {
			dfs ( fx , fy ) ;
		}
	}
}
