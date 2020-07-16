#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

long long a[100 + 5][100 + 5] , map[100 + 5][100 + 5] ;
int n , m;
inline void add_company ( int i , int j ) ;

int main() {
	
	int x , y , z ;
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d %d" , &x , &y , &z ) ;
		a[x][y] = z ;
		m = max ( max ( x , z ) , max ( y , z ) ) ;
	}
	
	for ( int i = 1 ; i <= 100 ; i++ ) {
		for ( int j = 1 ; j <= 100 ; j++ ) {
			if ( a[i][j] > 50 ) {
				add_company ( i , j ) ;
			}
		}
	}
	
	for ( int i = 1 ; i <= 100 ; i++ ) {
		for ( int j = 1 ; j <= 100 ; j++ ) {
			if ( map[i][j] && i != j ) {
				printf ( "%d %d\n" , i , j ) ;
			}
		}
	}
	
	return 0;
}

inline void add_company ( int i , int j ) {
	if ( map[i][j] ) {
		return ;
	}
	map[i][j] = true ;
	
	for ( int k = 1 ; k <= 100 ; k++ ) {
		a[i][k] += a[j][k] ;
		if ( a[i][k] > 50 ) {
			add_company ( i , k ) ;
		}
	}
}
