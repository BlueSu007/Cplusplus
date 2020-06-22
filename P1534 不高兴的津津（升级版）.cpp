#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n, a, b, sum, minusn;

int main() {
	
	cin >> n;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> a >> b;
		minusn += a + b - 8;
		sum += minusn;
	}
	
	cout << sum << endl;
	
	return 0;
}
