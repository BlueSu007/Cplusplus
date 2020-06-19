#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100 + 5];
int n, leftn, rightn, sum;

int main() {
	
	ios::sync_with_stdio( false );
	cin >> n;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a[i];
		sum += a[i];
	}
	
	int q = 0, p = 0;
	cin >> leftn >> rightn;
	
	for ( int i = 1 ; i <= n ; i++ ) {
		if ( a[i] > rightn ) {
			q += a[i] - rightn;
		}
		if ( a[i] < leftn ) {
			p += leftn - a[i];
		}
	}
	
	if ( sum > n * rightn ) {
		cout << -1 << endl;
	}
	else {
		cout << max( q, p ) << endl;
	}
	
	return 0;
}
