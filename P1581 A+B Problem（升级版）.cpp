#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

const int carry[10] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};
int a[10], b[10], c[10];
char ch;

inline void reversed( int a[] );

int main() {
	
	scanf( "%d%c", &a[++a[0]], &ch );
	
	while ( ch != '+' ) {
		scanf( "%d%c", &a[++a[0]], &ch );
	}
	while ( cin >> b[++b[0]] >> ch );
	
	reversed(a);
	reversed(b);
	
	for ( int i = 1 ; i <= 5 ; i++ ) {
		c[i] = a[i] + b[i];
	}
	
	for ( int i = 1 ; i <= 5 ; i++ ) {
		c[i + 1] += c[i] / carry[i];
		c[i] %= carry[i];
	}
	
	c[0] = max ( a[0], b[0] ) + ( c[max ( a[0], b[0] ) + 1] > 0 );
	printf( "%d", c[c[0]] );
	
	for ( int i = c[0] - 1 ; i >= 1 ; i-- ) {
		printf( ",%d", c[i] );
	}
	
	return 0;
}

inline void reversed( int a[] ) {
	memcpy ( c, a, sizeof(c) );
	for ( int i = 1 ; i <= a[0] ; i++ ) {
		a[i] = c[a[0] - i + 1];
	}
}
