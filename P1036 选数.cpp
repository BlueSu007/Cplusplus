#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, cnt;
int a[20 + 5], vis[20 + 5];
inline int readn();
bool isprime( int x );
void dfs( int sum, int step, int array );

int main() {
	
	ios::sync_with_stdio( false );
	n = readn(), m = readn();
	
	for ( int i = 1 ; i <= n ; i++ ) {
		a[i] = readn();
	}
	
	sort( a + 1, a + 1 + n);
	
	dfs( 0, 0, 1 );
	cout << cnt << endl;
	
	return 0;
}

//fast read
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

//isprime function
bool isprime( int x ) {
	if ( x == 1 ) {
		return false;
	}
	
	for ( int i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			return false;
		}
	}
	
	return true;
}

void dfs( int sum, int step, int array ) {
	if ( step == m ) {
		if ( isprime(sum) ) {
			cnt++;
		}
		
		return ;
	}
	
	for ( int i = array ; i <= n ; i++ ) {
		if ( !vis[i] ) {
			//label this number
			vis[i] = 1;
			//dfs
			dfs( sum + a[i], step + 1, i );
			//dfs back
			vis[i] = 0;
		}
	}
}
//P1036
