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

int main () {
	
	cin >> s ;
	if ( next_permutation ( s.begin () , s.end () ) ) {
		cout << s ;
	}
	else {
		printf ( "0" ) ;
	}
	
	return 0 ;
}
