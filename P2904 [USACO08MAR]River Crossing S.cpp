#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n, m, a[10000 + 5];
int asum[10000 + 5], dp[10000 + 5];
inline int readn() {
	
	int f = 1, x = 0;
	char ch = getchar();
	
	while ( !isdigit(ch) ) {
		if ( ch == '-' ) {
			f = -1;
		}
		
		ch = getchar();
	}
	
	while ( isdigit(ch) ) {
		x = x * 10 + ( ch - '0' );
		ch = getchar();
	}
	
	return f * x;
}

int main() {
	
	ios::sync_with_stdio( false );
	n = readn();
	m = readn();
	
	for ( int i = 1 ; i <= n ; i++ ) {
		dp[i] = INT_MAX;
		a[i] = readn();
		asum[i] = asum[i - 1] + a[i];
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		asum[i] += 2 * m;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = i ; j <= n ; j++ ) {
			dp[j] = min( dp[j], dp[j - i] + asum[i] );
		}
	}
	
	cout << dp[n] - m << endl;
	
	return 0;
} 
