#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>
using namespace std ;

string pre , mid ;
inline void last ( string mid , string pre ) ;

int main () {
	
	freopen ( "testcase.in" , "r" , stdin ) ;
	cin >> mid >> pre ;
	last ( mid , pre ) ;
	
	return 0 ;
}

inline void last ( string mid , string pre ) {
	if ( pre.size () > 0 ) {
		char c = pre[0] ;
		int k = mid.find (c) ;
		
		last ( mid.substr ( 0 , k ) , pre.substr ( 1 , k ) ) ;
		last ( mid.substr ( k + 1 ) , pre.substr ( k + 1 ) ) ;
		printf ( "%c" , c ) ;
	}
}
