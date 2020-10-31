#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n ;

struct node {
	double value ;
	int x , y ;
	
	inline bool operator < ( const node x ) const {
		return value < x.value ;
	}
	
	inline bool operator == ( const node x ) const {
		return value == x.value ;
	}
} ;

vector < node > v ;

inline int gcd ( int x , int y ) {
	if ( y == 0 ) {
		return x ;
	}
	
	return gcd ( y , x % y ) ;
}

int main () {
	
	scanf ( "%d" , &n ) ;
	
	for ( int i = 0 ; i <= n ; i++ ) {
		for ( int j = i + 1 ; j <= n ; j++ ) {
			int x = i , y = j , tmp = gcd ( i , j ) ;
			node tmpn ;
			tmpn.x = x / tmp , tmpn.y = y / tmp , tmpn.value = 1.0 * x / y ;
			
			if ( find ( v.begin () , v.end () , tmpn ) == v.end () && tmpn.value > 0 && tmpn.value < 1 ) {
				//cout << tmpn.x << " " << tmpn.y << " " << tmp << endl ;
				v.push_back (tmpn) ;
			}
		}
	}
	
	sort ( v.begin () , v.end () ) ;
	int len = v.size () ;
	
	printf ( "0/1\n" ) ;
	for ( int i = 0 ; i < len ; i++ ) {
		node tmp = *v.begin () ;
		printf ( "%d/%d\n" , tmp.x , tmp.y ) ;
		v.erase ( v.begin () ) ;
	}
	printf ( "1/1" ) ;
	
	return 0 ;
}
