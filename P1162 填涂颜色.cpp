#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int a[30 + 5][30 + 5] , vis[30 + 5][30 + 5] , n ;
const int dx[4] = { 1 , -1 , 0 , 0 } ;
const int dy[4] = { 0 , 0 , 1 , -1 } ;
inline void dfs ( int x , int y ) ;

int main() {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			scanf ( "%d" , &a[i][j] ) ;
			vis[i][j] = a[i][j] ;
		}
	}
	
	dfs ( 0 , 0 ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( !vis[i][j] ) {
				printf ( "2 " ) ;
			}
			else {
				printf ( "%d " , a[i][j] ) ;
			}
		}
		printf ( "\n" ) ;
	}
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	if ( x < 0 || y < 0 || x > n + 1 || y > n + 1 || vis[x][y] != 0 ) {
		return ;
	}
	
	vis[x][y] = 1 ;
	for ( int i = 0 ; i < 4 ; i++ ) {
		dfs ( x + dx[i] , y + dy[i] ) ;
	}
}
