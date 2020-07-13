#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , x , ans;
char m[100000];

int main() {
	
	scanf ( "%d %s" , &n , m );
	
	for ( int i = 0 ; m[i] ; i++ ) {
		ans = ( ans * 10 + m[i] - '0' ) % n;
	}
	
	printf ( "%d" , ans ? ans : n );
	
	return 0;
}
