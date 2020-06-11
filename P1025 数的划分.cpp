#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, ans;
bool vis[200 + 5];
inline void dfs( int step, int sum, int last_number );

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n >> m;
	dfs( 0, 0, 1 );
	cout << ans << endl;
	
	return 0;
}

inline void dfs( int step, int sum, int last_number ) {
	if ( step == m && sum == n ) {
		ans++;
//		cout << 0 << endl;
		return ;
	}
	
	if ( step == m - 1 && sum + 1 >= n ) {
//		cout << 1 << endl;
		return ;
	}
	
	for ( int i = last_number ; sum + i * ( m - step ) <= n ; i++ ) {
		if ( step == m - 1 && sum + i != n ) {
//			cout << 2 << endl;
			continue;
		}
		else {
//			cout << 3 << endl;
			dfs( step + 1, sum + i, i );
		}
	}
}
