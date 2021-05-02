#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 105
int n , m , ans , dis[LEN][LEN] , a[LEN * LEN] ;

int main () {

	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}

	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			scanf ( "%d" , &dis[i][j] ) ;
		}
	}

	for ( int k = 1 ; k <= n ; k++ ) {
		for ( int i = 1 ; i <= n ; i++ ) {
			for ( int j = 1 ; j <= n ; j++ ) {
				dis[i][j] = min ( dis[i][j] , dis[i][k] + dis[k][j] ) ;
			}
		}
	}

	for ( int i = 2 ; i <= m ; i++ ) {
		ans += dis[a[i - 1]][a[i]] ;
	}

	ans += dis[1][a[1]] ;
	ans += dis[a[m]][n] ;
	printf ( "%d" , ans ) ;

	return 0 ;
}
