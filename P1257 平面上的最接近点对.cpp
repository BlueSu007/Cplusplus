#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct node {
	long long x , y ;
} a[10000 + 5] ;

long long n , ans = 0x7fffffff ;
	
inline long long dis ( node a , node b ) {
	return ( ( a.x - b.x ) * ( a.x - b.x ) ) + ( ( a.y - b.y ) * ( a.y - b.y ) ) ;
}

int main () {
	
	scanf ( "%lld" , &n ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld %lld" , &a[i].x , &a[i].y ) ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = i + 1 ; j <= n ; j++ ) {
			ans = min ( ans , dis ( a[i] , a[j] ) ) ;
		}
	}
	
	printf ( "%0.4lf" , ( double ) sqrt ( ans ) ) ;
	
	return 0 ;
}
