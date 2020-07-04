#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , m;

int main() {
	
	cin >> n;
	while ( n-- ) {
		cin >> m;
		cout << ( m + 1 ) / 2 << endl;
	}
	
	return 0;
}
