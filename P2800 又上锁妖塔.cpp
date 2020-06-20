#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[1000000 + 5];
int dp[10000000 + 5];

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n;
	
	for ( int i = 1 ; i <= n ; i++ )
		cin >> a[i];
	
	for ( int i = 1 ; i <= n + 1 ; i++ ) {
		dp[i] = dp[i - 1] + a[i];
		
		if ( i - 2 >= 0 ) {
			dp[i] = min ( dp[i], dp[i - 2] + a[i]);
		}
		
		if ( i - 3 >= 0 ) {
			dp[i] = min ( dp[i], dp[i - 3] + a[i] );
		}
	}
	
	cout << dp[n + 1] << endl;
	
	return 0;
} 
