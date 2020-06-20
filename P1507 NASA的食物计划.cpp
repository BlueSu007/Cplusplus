#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int v, m, n;
int a[500 + 5], b[500 + 5], c[500 + 5];
int dp[1000 + 5][1000 + 5];

int main() {
	
	ios::sync_with_stdio( false );
	cin >> v >> m >> n;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = v ; j >= a[i] ; j-- ) {
			for ( int k = m ; k >= b[i] ; k-- ) {
				dp[j][k] = max( dp[j][k], dp[j - a[i]][k - b[i]] + c[i] );
			}
		}
	}
	
	cout << dp[v][m] << endl;
	
	return 0;
}
