#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>
using namespace std ;

int n , m , a[100 + 5][100 + 5] ;
long long ans ;
const int dx[4] = { 0 , 0 , 1 , -1 } ;
const int dy[4] = { 1 , -1 , 0 , 0 } ;
inline void dfs ( int x , int y ) ;

int main () {

	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			scanf ( "%d" , &a[i][j] ) ;
		}
	}
	
	dfs ( 1 , 1 ) ;
	
	return 0 ;
}

inline void dfs ( int x , int y ) {
	
	ans += a[x][y] , a[x][y] = 0 ;
	if ( x == n && y == m ) {
		printf ( "%lld" , ans + a[1][1] ) ;
		exit ( false ) ;
	}
	
	int tmp = 0 , tmpx , tmpy ;
	for ( int i = 0 ; i < 4 ; i++ ) {
		int fx = dx[i] + x , fy = dy[i] + y ;
		if ( fx && fy && fx <= n && fy <= m ) {
			if ( tmp < a[fx][fy] ) {
				tmp = a[fx][fy] , tmpx = fx , tmpy = fy ;
			}
		}
	}
	
	dfs ( tmpx , tmpy ) ;
}
