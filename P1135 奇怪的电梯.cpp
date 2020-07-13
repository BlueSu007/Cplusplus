#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , a , b , ans = 0x7ffffff;
int m[200 + 5];
bool vis[200 + 5];
inline void dfs ( int now , int step );

int main() {
	
	scanf ( "%d %d %d" , &n , &a , &b );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d" , &m[i] );
	}
	
	vis[a] = 1;
	dfs ( a , 0 );
	
	if ( ans != 0x7ffffff ) {
		printf ( "%d" , ans );
	}
	else {
		printf ( "-1" );
	}
	
	return 0;
}

inline void dfs ( int now , int step ) {
	if ( now == b ) {
		ans = min ( ans , step );
	}
	
	if ( step > ans ) {
		return ;
	}
	
	vis[now] = 1;
	
	if ( now + m[now] <= n && !vis[now + m[now]] ) {
		dfs ( now + m[now] , step + 1 );
	}
	if ( now - m[now] >= 1 &&  !vis[now - m[now]] ) {
		dfs ( now - m[now] , step + 1 );
	} 
	
	vis[now] = 0;
}
