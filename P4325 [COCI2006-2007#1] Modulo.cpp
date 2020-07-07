#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[42] , x , num;

int main() {
	
	for ( int i = 1 ; i <= 10 ; i++ ) {
		scanf ( "%d" , &x );
		a[x % 42] = 1;
	}
	
	for ( int i = 0 ; i < 42 ; i++ ) {
		num += a[i];
	}
	
	cout << num << endl;
	
	return 0;
}
