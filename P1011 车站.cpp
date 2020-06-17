#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int f[20 + 5], sum[20 + 5];
int k, n, m, x, ans;

int main() {
	
	ios::sync_with_stdio( false );
	cin >> k >> n >> m >> x;
	
	ans = k;
	if ( x >= 3 ) {
		ans += k;
	}
	
	if ( x >= 4 ) {
		
		f[1] = f[2] = 1;
		for ( int i = 3 ; i <= n - 4 ; i++ ) {
			f[i] = f[i - 1] + f[i - 2];
		}
		
		for ( int i = 1 ; i <= n - 4 ; i++ ) {
			sum[i] = sum[i - 1] + f[i];
		} 
		
		int tmp = ( m - sum[n - 5] * k - ans ) / sum[n - 4];
		ans += sum[x - 4] * k + sum[x - 3] * tmp;
	}
	
	cout << ans << endl;
	
	return 0;
}
