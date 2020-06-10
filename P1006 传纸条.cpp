#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

inline int max( int a, int b, int c, int d );
inline int read();
int f[200 + 5][200 + 5];
int v[200 + 5][200 + 5];
int n, m;

int main() {
	
	ios::sync_with_stdio( false );
	n = read(), m = read();
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= m ; j++ ) {
			v[i][j] = read();
		}
	}
	
	for ( int i = 3 ; i <= n + m ; i++ ) {
		for ( int j = n ; j >= 1 ; j-- ) {
			for ( int k = n ; k > j ; k-- ) {
				f[j][k] = max( f[j][k], f[j - 1][k - 1], f[j - 1][k], f[j][k - 1] ) ;
				f[j][k] += v[j][i - j] + v[k][i - k];
			}
		}
	}
	
	cout << f[n - 1][n] << endl;
	
	return 0;
} 

inline int read() {
	
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

inline int max( int a, int b, int c, int d ) {
	a = a > b ? a : b;
	c = c > d ? c : d;
	return a > c ? a : c;
}
