#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 100
struct node {
	int x , y ;
	bool ifNotCanUse ;

	inline bool operator < ( const node & qwq ) const {
		return y < qwq.y ;
	}
} a[LEN] ;

int k , n , FarmerJohnX , FarmerJohnY ;

int main () {

	scanf ( "%d" , &k ) ;
	while ( k-- ) {
		memset ( a , 0 , sizeof (a) ) ;
		scanf ( "%d" , &n ) ;
		for ( int i = 1 ; i <= n ; i++ ) {
			scanf ( "%d %d" , &a[i].x , &a[i].y ) ;
		}

		sort ( a + 1 , a + 1 + n ) ;

		int flag = false ;
		for ( int i = 0 ; i < n ; i++ ) {
			if ( abs ( a[i].x - a[i + 1].x ) > abs ( a[i + 1].y - a[i].y ) ) {
				printf ( "Notabletocatch\n" ) ;
				flag = true ;
				break ;
			}
		}

		if ( ! flag ) {
			printf ( "Abletocatch\n" ) ;
		}
	}

	return 0 ;
}
