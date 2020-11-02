#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std ;

int n , m , cnt[1000 + 5] ;
string bessie[1000 + 5] , farmerjohn[100 + 5] ;
inline bool cow ( string kkk , string ltt ) ;

int main () {
	
	freopen ( "testcase.in" , "r" , stdin ) ;
	scanf ( "%d %d" , &n , &m ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		cin >> bessie[i] ;
		transform ( bessie[i].begin () , bessie[i].end () , bessie[i].begin () , :: tolower ) ;
	}
	
	for ( int i = 1 ; i <= m ; i++ ) {
		cin >> farmerjohn[i] ;
		transform ( farmerjohn[i].begin () , farmerjohn[i].end () , farmerjohn[i].begin () , :: tolower ) ;
		
		for ( int j = 1 ; j <= n ; j++ ) {
			if ( cow ( bessie[j] , farmerjohn[i] ) ) {
				cnt[j]++ ;
			}
		}
	}
	
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "%d\n" , cnt[i] ) ;
	}
	
	return 0 ;
}

inline bool cow ( string kkk , string ltt ) {
	int qwq = -1 , len = ltt.size () ;
	string :: size_type pos = 0 ;
	for ( int i = 0 ; i < len ; i++ ) {
		pos = kkk.find ( ltt[i] , qwq + 1 ) ;
		if ( pos == kkk.npos ) {
			return false ;
		}
		qwq = pos ;
	}
	
	return true ;
}
