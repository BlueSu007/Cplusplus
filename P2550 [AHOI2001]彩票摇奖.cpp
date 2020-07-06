#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , a , b , c[30 + 5] , d[7 + 5];

int main() {
	
	scanf ( "%d" , &n );
	for ( int i = 1 ; i <= 7 ; i++ ) {
		scanf ( "%d" , &b );
		c[b] = 1;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		int sum = 0;
		
		for ( int j = 1 ; j <= 7 ; j++ ) {
			cin >> a;
			if ( c[a] == 1 ) {
				sum++;
			}
		}
		
		d[7 - sum + 1]++;
	}
	
	for ( int i = 1 ; i <= 7 ; i++ ) {
		cout << d[i] << " ";
	}
	
	return 0;
}
