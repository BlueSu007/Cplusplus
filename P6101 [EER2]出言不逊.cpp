#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
#include <stack>
using namespace std ;

string s ;
unsigned long long len , maxn , ans ;
map < char , unsigned long long > pam ;

int main () {
	
	cin >> s ;
	scanf ( "%llu" , &len ) ;
	unsigned long long tmp = s.size () ;
	
	if ( tmp >= len ) {
		printf ( "0" ) ;
		exit ( false ) ;
	}
	
	for ( unsigned long long i = 0 ; i < tmp ; i++ ) {
		pam[s[i]]++ ;
		maxn = max ( maxn , pam[s[i]] ) ;
	}
	
	while ( true ) {
		if ( len - tmp <= maxn ) {
			ans++ ;
			break ;
		}
		
		tmp += maxn ;
		maxn *= 2 ;
		ans++ ;
	}
	
	printf ( "%llu" , ans ) ;
	
	return 0 ;
}
