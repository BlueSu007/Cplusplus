#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[200 + 5][200 + 5];
int dp[200 + 5], n;

int main() {
	
	cin >> n;
	
	for ( int i = 1 ; i < n ; i++ ) {
		for ( int j = i + 1 ; j <= n ; j++ ) {
			cin >> a[i][j];
		}
		
		dp[i] = 0x7fffff;
	}
	
	for ( int i = n - 1 ; i >= 1 ; i-- ) {
		for ( int j = i + 1 ; j <= n ; j++ ) {
			dp[i] = min( dp[i], a[i][j] + dp[j] );
		} 
	}
	
	cout << dp[1] << endl;
	
	return 0;
}
