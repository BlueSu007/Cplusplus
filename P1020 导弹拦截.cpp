#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long a[100000 + 5], b[100000 + 5], c[100000 + 5];
long long n;

int main() {
	
	ios::sync_with_stdio( false );
	while ( cin >> a[++n] );
	
	n--;
	long long len1, len2;
	len1 = len2 = 1;
	
	b[1] = a[1];
	c[1] = a[1];
	
	for ( int i = 2 ; i <= n ; i++ ) {
		if ( b[len1] >= a[i] ) {
			b[++len1] = a[i];
		}
		else {
			long long tmp1 = upper_bound ( b + 1, b + 1 + len1, a[i], greater < int > () ) - b;
			b[tmp1] = a[i];
		}
		
		if ( c[len2] < a[i] ) {
			c[++len2] = a[i];
		}
		else {
			long long tmp2 = lower_bound ( c + 1, c + 1 + len2, a[i] ) - c;
			c[tmp2] = a[i];
		}
	}
	
	cout << len1 << endl << len2 << endl;
	
	return 0;
}
