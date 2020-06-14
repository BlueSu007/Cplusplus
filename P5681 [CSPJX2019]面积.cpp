#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
	
	long long a, b, c;
	cin >> a >> b >> c;
	
	long long sum1, sum2;
	sum1 = a * a;
	sum2 = b * c;
	
	if ( sum1 > sum2 ) {
		cout << "Alice" << endl;
	}
	else {
		cout << "Bob" << endl;
	}
	
	return 0;
}
