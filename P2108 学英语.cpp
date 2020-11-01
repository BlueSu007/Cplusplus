#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
using namespace std;

string s ;
map < string , int > pam ;
long long x , ans ;
inline void init () ;

int main () {
	
	freopen ( "testcase.in" , "r" , stdin ) ;
	init () ;
	while ( cin >> s ) {
		if ( s == "negative" ) {
			printf ( "-" ) ;
			continue ;
		}
		if ( pam[s]	< 100 ) {
			x += pam[s] ;
		}
		if ( pam[s] == 100 ) {
			x *= 100 ;
		}
		if ( pam[s] > 100 ) {
			ans += x * pam[s] , x = 0 ;
		}
	}
	
	printf ( "%lld" , ans + x ) ;
	
	return 0 ;
}

inline void init () {
	pam["one"] = 1 , pam["two"] = 2 , pam["three"] = 3 ;
	pam["four"] = 4 , pam["five"] = 5 , pam["six"] = 6 ;
	pam["seven"] = 7 , pam["eight"] = 8 , pam["nine"] = 9 ;
	pam["ten"] = 10 , pam["eleven"] = 11 , pam["twelve"] = 12 ;
	pam["thirteen"] = 13 , pam["fourteen"] = 14 , pam["fifteen"] = 15 ;
	pam["sixteen"] = 16 , pam["seventeen"] = 17 , pam["eighteen"] = 18 ;
	pam["nineteen"] = 19 , pam["twenty"] = 20 , pam["thirty"] = 30 ;
	pam["forty"] = 40 , pam["fifty"] = 50 , pam["sixty"] = 60 ;
	pam["seventy"] = 70 , pam["eighty"] = 80 , pam["ninety"] = 90 ;
	pam["hundred"] = 100 , pam["thousand"] = 1000 , pam["million"] = 1000000 ;
}
