#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100 + 5] , b[100 + 5] , c[100 + 5] , d[100 + 5];
int num , n;
inline void dfs ( int column );
inline void print();

int main() {
	
	scanf ( "%d" , &n );
	dfs(1);
	printf ( "%d\n" , num );
	
	return 0;
}

inline void dfs ( int col ) {
	if ( col == n + 1 ) {
		num++;
		if ( num <= 3 ) {
			print();
		}
		return ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( !b[i] && !c[col + i] && !d[col - i + n] ) {
			a[col] = i;
			b[i] = 1 , c[col + i] = 1 , d[col - i + n] = 1;
			dfs( col + 1 );
			b[i] = 0 , c[col + i] = 0 , d[col - i + n] = 0;
		}
	}
}

inline void print() {
	for ( int k = 1 ; k <= n ; k++ ) {
		printf ( "%d " , a[k] );
	}
	
	printf ( "\n" );
}
