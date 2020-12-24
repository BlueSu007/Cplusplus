#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

long long a ;

int main () {

	scanf ( "%lld" , &a ) ;
	printf ( "%lld" , 1 + 12 * ( a * ( a - 1 ) / 2 ) ) ;

	return 0 ;
}
