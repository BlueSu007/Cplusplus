#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;

struct ticket{
	int price;
	int timen;
	int ifuse;
}q[100000 + 5];

int n, price, timen, url, cost;
int head = 1, tail = 1;
inline int read();
inline void write( int x );

int main() {
	
	n = read();
	
	for ( int i = 1 ; i <= n ; i++ ) {
		url = read(), price = read(), timen = read();
		
		if ( url == 0 ) {
			cost += price;
			q[tail].timen = timen + 45;
			q[tail++].price = price;
		}
		else {
			while ( head < tail && q[head].timen < timen ) {
				head++;
			}
			
			bool ifound = false;
			for ( int j = head ; j < tail ; j++ ) {
				if ( q[j].price >= price && !q[j].ifuse ) {
					ifound = true;
					q[j].ifuse = 1;
					break;
				}
			}
			
			if ( !ifound ) {
				cost += price; 
			}
		}
	} 
	
	write(cost);
	
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
