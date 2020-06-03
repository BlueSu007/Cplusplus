#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int a[2000000 + 5], tmp;
inline int readn();

int main() {
	
	ios::sync_with_stdio( false );
	n = readn();
	m = readn();
	
	for ( register int i = 1 ; i <= n ; i++ ) {
		a[i] = readn();
	}
	
	while ( m-- ) {
		tmp = readn();
		cout << a[tmp] << endl;
	}
	
	return 0;
}

inline int readn() {
	
	int f = 1, x = 0;
	char ch = getchar();
	
	while ( !isdigit(ch) ) {
		if ( ch == '-' ) {
			f = -1;
		}
		
		ch = getchar();
	}
	
	while ( isdigit(ch) ) {
		x = x * 10 + ( ch - '0' );
		ch = getchar();
	} 
	
	return f * x;
}
