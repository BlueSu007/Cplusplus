#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring> 
using namespace std;

int n , s , ans;
int res[100 + 5];
inline bool isreverse ( int n , int k );

int main () {
	
	scanf ( "%d %d" , &n , &s ); 
	
	for ( int i = s + 1 ; ans != n ; i++ ) {
		int cnt = 0;
		for ( int j = 2; j <= 10 && cnt < 2 ; j++ ) {
			if ( isreverse ( i , j ) ) {
				cnt++;
			}
		}
		
		if ( cnt >= 2 ) {
			printf ( "%d\n" , i );
			ans++;
		}
	}
	
	return 0;
}

inline bool isreverse ( int n , int k ) {
	memset ( res , 0 , sizeof(res) );
	int p = 0;
	
	while ( n ) {
		res[p++] = n % k;
		n /= k;
	}
	
	int i = 0 , j = p - 1;
	while ( i < j ) {
		if ( res[i++] != res[j--] ) {
			return 0;
		}
	}
	
	return 1;
}
