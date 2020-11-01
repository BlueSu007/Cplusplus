#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>
using namespace std ;

int n , m , x , y ;
char c[100][100] , a[100] , ch = ' ' ;

int main () {
	
	cin >> n >> m ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			cin >> c[i][j] ;
		}
	}
	cin >> x >> y ;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			c[i + n][j] = c[n - i + 1][j] ;
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			c[i + n][j + m] = c[n - i + 1][m - j + 1] ;
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			c[i][j + m] = c[i][m - j + 1] ;
		}
	}
	
	c[x][y] = c[x][y] == '#' ? '.' : '#' ;
	
	for ( int i = 1 ; i <= 2 * n ; i++ ) {
		for ( int j = 1 ; j <= 2 * m ; j++ ) {
			printf ( "%c" , c[i][j] ) ;
		}
		
		printf ( "\n" ) ;
	}
	
	return 0 ;
}
