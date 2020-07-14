#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[500 + 5][500 + 5] , num , n;

int main() {
	
	scanf ( "%d" , &n );
	for ( int i = 1 ; i < n ; i++ ) {
		for ( int j = i + 1 ; j <= n ; j++ ) {
			scanf ("%d" , &a[i][j] );
			a[j][i] = a[i][j];
		}
	}
	
	int ans = 0;
	for ( int i = 1 ; i <= n ; i++ ) {
		sort ( a[i] + 1 , a[i] + 1 + n );
		if ( ans <= a[i][n - 1] ) {
			ans = a[i][n - 1];
		} 
	}
	
	printf ( "1\n%d\n" , ans );
	
	return 0;
}
