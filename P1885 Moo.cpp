#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std ;

long long n , dp[10000000] , cnt ;
string a ;
inline char moo ( int step ) ;

int main () {
	
	scanf ( "%lld" , &n ) ;
	dp[0] = 3 ;
	for ( ; dp[cnt - 1] < n ; cnt++ ) {
		dp[cnt] = dp[cnt - 1] * 2 + cnt + 3 ;
	}
	printf ( "%c" , moo ( cnt - 1 ) ) ;
	
	return 0 ;
}

inline char moo ( int step ) {
	if ( n == 1 || n == dp[step - 1] + 1 ) {
		return 'm' ;
	}
	else if ( n <= 3 || ( n > dp[step - 1] && n <= dp[step - 1] ) ) {
		return 'o' ;
	}
	else if ( n > dp[step - 1] + step + 3 ) {
		n -= dp[step - 1] + step + 3 ;
		moo ( step - 1 ) ;
	}
	else {
		moo ( step - 1 ) ;
	}
}
