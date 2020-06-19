#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n, a[1000000 + 5];
long long m, p, s, k, sum, ans;

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a[i];
	}
	
	cin >> m >> p >> s >> k;	
	
	for ( int i = 1 ; i <= n ; i++ ) {
		sum += a[i] * ( m - i );
	}
	
	sum += s * ( m - p );
	int f = ( sum > 0 ? 1 : -1 );
	ans = m + int ( (double) sum / k + 0.5 * f );
	
	if ( ans > n ) {
		ans = n;
	}
	
	if ( ans < 1 ) {
		ans = 1;
	}
	
	cout << ans << endl;
	
	return 0;
}
