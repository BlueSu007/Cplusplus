#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

struct node {
	unsigned int x , y ;
}a[200000 + 5] ;

unsigned int n , m , d , len , cnt , t , x ;
char c , ch[200000 + 5] ;
unsigned int f[200000 + 5] , num[200000 + 5] ;
inline int find ( int k ) ;

int main() {
	
	scanf ( "%d %d" , &m , &d ) ;
	for ( int i = 1 ; i <= m ; i++ ) {
		getchar() ;
		scanf ( "%s %d" , ch , &x ) ;
		if ( ch[0] == 'A' ) {
			x += t , x %= d ;
			len++ , num[len] = x , f[len] = len ;
			while ( x > a[cnt].x && cnt ) {
				f[a[cnt].y] = len ;
				cnt-- ;
			}
			
			a[++cnt].x = x ;
			a[cnt].y = len ;
		} 
		else {
			x = len - x + 1 ;
			int tmp = find(x) ;
			t = num[tmp] ;
			printf ( "%d\n" , t ) ;
		}
	}
	
	return 0 ;
}

inline int find ( int k ) {
	if ( f[k] == k ) {
		return f[k] ;
	}
	
	return f[k] = find(f[k]) ;
}
