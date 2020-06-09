#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <memory.h>
using namespace std;

int t, n, m;
//a[i][j]: day i object j 's price
int a[100 + 5][100 + 5];
//f[k]: left k RMB -> selled all tommorow's left RMB
//all of all, after tommorow's selling, how many left
int f[10000 + 5], ans;
inline int read();
inline void write( int x );

int main(){
	
	t = read(), n = read(), m = read();
	
	for ( int i = 1 ; i <= t ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			a[i][j] = read();
		}
	}
	
	//day one have m RMB
	ans = m;
	
	for ( int i = 1 ; i <= t ; i++ ) {
		
		memset( f, 0, sizeof(f) );
		//without buying, today is ans RMB, tommorow even is ans RMB
		f[ans] = ans;
		
		for ( int j = 1 ; j <= n ; j++ ) {
			//while we have k RMB, calculate money tommorow morning
			for ( int k = ans ; k >= a[i][j] ; k-- ) {
				//f[k - a[i][j]]: this is the money tommorow morning, so minus object's price
				//f[k] + a[i + 1][j] - a[i][j]: buy-minus; sell-add
				f[k - a[i][j]] = max( f[k - a[i][j]], f[k] + a[i + 1][j] - a[i][j] );
			}
		}
		
		//tommorow morning the biggest amount
		int maxn = 0;
		for ( int i = 0 ; i <= ans ; i++ )
			maxn = max( maxn, f[i] );
			
		ans = maxn;
	}
	
	write(ans);
	
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

inline void write( int x ) {
	if ( x >= 10 ) {
		write( x / 10 );
	}
	
	putchar( x % 10 + '0' );
}
