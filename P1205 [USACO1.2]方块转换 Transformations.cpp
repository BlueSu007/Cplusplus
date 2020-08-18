#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n ;
char a[100 + 5][100 + 5] , after[100 + 5][100 + 5] , tmp[100 + 5][100 + 5] , goal[100 + 5][100 + 5] ;

inline bool cmp () ;
inline void copy () ;
inline bool change1 () ;
inline bool change2 () ;
inline bool change3 () ;
inline bool change4 () ;
inline bool change5 () ;
inline bool change6 () ;
inline int change () ;

int main () {
	
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			cin >> a[i][j] ;
			tmp[i][j] = a[i][j] ;
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			cin >> goal[i][j] ;
		}
	}
	
	cout << change() << endl ;
	
	return 0 ;
}

inline bool cmp () {
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( after[i][j] != goal[i][j] ) {
				return false ;
			}
		}
	}
	
	return true ;
}

inline void copy () {
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			tmp[i][j] = after[i][j] ;
		}
	}
}

inline bool change1 () {
    // turn right 90°
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			after[j][n - i + 1] = tmp[i][j] ;
		}
	}
	
	return cmp () ;
}

inline bool change2 () {
    // turn right 180°
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			after[n - i + 1][n - j + 1] = tmp[i][j] ;
		}
	}
	
	return cmp () ;
}

inline bool change3 () {
    // turn right 270°
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			after[n - j + 1][i] = tmp[i][j] ;
		}
	}
	
	return cmp () ;
}

inline bool change4 () {
    // mirror
	for ( int i = 1 ; i <= n ; i++ ) {
		for ( int j = 1 ; j <= n ; j++ ) {
			after[i][n - j + 1] = tmp[i][j] ;
		}
	}
	
	return cmp () ;
}

inline bool change5 () {
    // puzzle
	change4() ;
    copy () ;
	if ( change1 () )//
		return 1 ;
    copy () ;
	if ( change2 () )//
		return 1 ;
    copy () ;
	if ( change3 () )//
		return 1 ;
	
	return 0 ;
}

inline bool change6 () {
    // no change
	return cmp() ;
}

inline int change () {
	if ( change1 () )
		return 1 ;
	if ( change2 () )
		return 2 ;
	if ( change3 () )
		return 3 ;
	if ( change4 () )
		return 4 ;
	if ( change5 () )
		return 5 ;
	if ( change6 () )
		return 6 ;
	
    // no solution
	return 7 ; 
}
