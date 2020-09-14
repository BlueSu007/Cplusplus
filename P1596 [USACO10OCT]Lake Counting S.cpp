#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int n , m , map[100 + 5][100 + 5] ;
char c ;
const int dx[9] = { -1 , -1 , -1 , 0 , 0 , 0 , 1 , 1 , 1 } ;
const int dy[9] = { -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 , 1 } ;
inline void dfs ( int x , int y ) ;

int main() {
	
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
//			scanf ( "%c" , &c ) ;
			cin >> c ;
			if ( c == 'W' ) {
				map[i][j] = 1 ;
			}
		}
	}
	
//	for ( int i = 1 ; i <= n ; i++ ) {
//		for ( int j = 1 ; j <= m ; j++ ) {
//			printf ( "%d " , map[i][j] ) ;
//		}
//		printf ( "\n" ) ;
//	}
	
	long long cnt = 0 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			if ( map[i][j] ) {
				cnt++ ;
				dfs ( i , j ) ;
			}
		}
	}
	
//	for ( int i = 1 ; i <= n ; i++ ) {
//		for ( int j = 1 ; j <= m ; j++ ) {
//			printf ( "%d " , map[i][j] ) ;
//		}
//		printf ( "\n" ) ;
//	}
	
	printf ( "%lld" , cnt ) ;
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	map[x][y] = 0 ;
	if ( x < 1 || x > n || y < 1 || y > m ) {
		return ;
	}
	
	for ( int i = 0 ; i < 9 ; i++ ) {
		int fx = dx[i] + x ;
		int fy = dy[i] + y ;
		if ( map[fx][fy] ) {
			dfs ( fx , fy ) ;
		}
	}
}
