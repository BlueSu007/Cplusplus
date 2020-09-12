#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <set>
using namespace std ;

int n , k , m , x , y ;
int a[10000 + 5] ;
int maxn , cnt = 1 , ans = 1 ;
inline void init() ; 
inline int find ( int k ) ;

int main() {
	
	scanf ( "%d %d %d" , &n , &k , &m ) ;
	init () ;
	
	for ( int i = 1 ; i <= k ; i++ ) {
		scanf ( "%d %d" , &x , &y ) ;
		a[find(x)] = find (y) ;
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		a[i] = find (i) ;
	}
	
	for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        if  ( find(x) == find(y) ) {
            printf ( "Yes\n" ) ;
        }
        else {
            printf ( "No\n" ) ;
        }
    }
	
	return 0 ;
}

inline void init () {
	for ( int i = 1 ; i <= n ; i++ ) {
		a[i] = i ;
	}
}

inline int find ( int k ) {
	if ( a[k] == k ) {
		return k ;
	}
	return a[k] = find (a[k]) ;
}
