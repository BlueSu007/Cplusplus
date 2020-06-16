#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
inline void func( int x );

int main() {
	ios::sync_with_stdio( false );
	cin >> n;
	func(n);
	return 0;
}

inline void func( int x ) {
	for ( int i = 14 ; i >= 0 ; i-- ) {
		if ( pow( 2, i ) <= x ) {
			if ( i == 1 ) {
				cout << "2";
			}
			else if ( i == 0 ) {
				cout << "2(0)";
			}
			else {
				cout << "2(";
				func(i);
				cout << ")";
			}
			
			x -= pow( 2, i );
			if ( x != 0 ) {
				cout << "+";
			}
		}
	}
}
