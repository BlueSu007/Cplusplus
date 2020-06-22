#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, a[100 + 5], f[2][100 + 5], ans;

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a[i];
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 0 ; j < i ; j++ ) {
			if ( a[i] > a[j] ) {
				f[0][i] = max( f[0][i], f[0][j] + 1 );
			}
		}
	}
	
	a[n + 1] = 0;
	
	for ( int i = n ; i ; i-- ) {
		for ( int j = n + 1 ; j > i ; j--) {
			if ( a[i] > a[j] ) {
				f[1][i] = max( f[1][i], f[1][j] + 1 );
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		ans = max( f[0][i] + f[1][i] - 1, ans );
	}
	
	cout << n - ans << endl;
	
	return 0;
}
