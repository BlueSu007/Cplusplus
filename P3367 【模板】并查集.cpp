#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , s , ans , x , y , z;
int f[10000 + 5];
inline void init(); 
inline int find ( int k );

int main() {
	
	scanf ( "%d %d" , &n , &m );
	init();
	
	for ( int i = 1 ; i <= m ; i++ ) {
		scanf ( "%d %d %d" , &x , &y , &z );
		
		if ( x == 1 ) {
			f[find(y)] = find(z);
		}
		else {
			if ( find(y) == find(z) ) {
				printf ( "Y\n" );
			}
			else {
				printf ( "N\n" );
			}
		}
	}
	
	return 0;
}

inline void init() {
	for ( int i = 1 ; i <= n ; i++ ) {
		f[i] = i;
	}
}

inline int find ( int k ) {
	if ( f[k] == k ) {
		return k;
	}
	
	return f[k] = find(f[k]);
}

/*
luogu P3367
4 7
2 1 2
1 1 2
2 1 2
1 3 4
2 1 4
1 2 3
2 1 4

N
Y
N
Y
*/
