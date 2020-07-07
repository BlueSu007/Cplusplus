#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int sqrtn[100 + 5] , k[5];
int n , f , ans;
bool isqrt[10000 + 5];
inline void dfs ( int p , int sum );

int main() {
	
	scanf ( "%d" , &n );
	f = sqrt(n);
	
	for ( int i = 0 ; i <= f ; i++ ) {
		sqrtn[i] = i * i;
		isqrt[i * i] = true;
	}
	
	dfs ( 0 , 0 );
	printf ( "%d" , ans );
	
	return 0;
}

inline void dfs ( int p , int sum ) {
	if ( sum > n ) {
		return ;
	}
	
	if ( p == 3 && !isqrt[n - sum] ) {
		return ;
	}
	
	if ( p == 4 && n == sum ) {
		ans++;
		return ;
	}
	
	if ( p > 4 ) {
		return ;
	}
	
	int x = sqrt ( n - sum );
	for ( int i = 0 ; i <= x ; i++ ) {
		dfs ( p + 1 , sum + sqrtn[i] );
	}
}
