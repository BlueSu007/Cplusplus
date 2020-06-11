#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, dp[15][15][15][15];
int x = 1, y, num;
int a[9 + 5][9 + 5];

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n;
	
	while ( x != 0 ) {
		a[x][y] = num;
		cin >> x >> y >> num;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			for ( int k = 1 ; k <= n ; k++ ) {
				for ( int l = 1 ; l <= n ; l++ ) {
					dp[i][j][k][l] = max ( max ( dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1])
								   , max ( dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1]))
								   + a[i][j] + a[k][l];
					if ( i == k && j == l ) {
						dp[i][j][k][l] -= a[i][j];
					}
				}
			}
		}
	}
	
	cout << dp[n][n][n][n] << endl;
	
	return 0;
}
