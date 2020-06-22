#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n;

int main() {
	cin >> n;
	for ( int i = 1 ; i * i <= n ; i++ ) {
		cout << i * i << " " ;
	}
	return 0;
} 
