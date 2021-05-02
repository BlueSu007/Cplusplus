#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 100005
int n , a[LEN] , x , minn , maxn ;

int main () {

	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &a[i] ) ;
	}

	sort ( a + 1 , a + 1 + n ) ;

	int pos = 1 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		while ( pos < n && a[pos + 1] - a[i] < n ) {
			pos++ ;
		}
		x = max ( x , pos - i + 1 ) ;
	}

	minn = n - x ;
	maxn = max ( a[n - 1] - a[1] , a[n] - a[2] ) - n + 2 ;

	if ( ( a[n - 1] - a[1] == n - 2 && a[n] - a[n - 1] > 2 )
	  || ( a[n] - a[2] == n - 2 && a[2] - a[1] > 2 ) ) {
		  minn = 2 ;
	}

	printf ( "%d\n%d" , minn , maxn ) ;

	return 0 ;
}
