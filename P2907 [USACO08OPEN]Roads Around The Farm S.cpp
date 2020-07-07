#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , k , num;
inline long long dfs ( int left );

int main() {
	
	scanf ( "%lld %lld" , &n , &k );
	printf ( "%lld" , dfs(n) );
	
	return 0;
}

inline long long dfs ( int left ) {
	if ( left <= k ) {
		return 1;
	}
	
	if ( ( left - k ) % 2 == 0 ) {
		return ( dfs ( ( left - k ) / 2 ) + dfs ( ( left + k ) / 2 ) );
	}
	else {
		return 1;
	}
}
