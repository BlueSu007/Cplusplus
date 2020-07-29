#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

int a[2000 + 5] , b[2000 + 5] , c[2000 + 5] ;
int sum[5000 + 5] , n ;
inline void high_defination_addition() ;
inline void high_defination_multiplecation ( int x ) ;

int main() {
	
	scanf ( "%d" , &n ) ;
	a[1] = 1 ;
	for ( int i = 1 ; i <= n ; i++ ) {
		high_defination_multiplecation(i) ;
		high_defination_addition() ;
	} 
	
	bool flag = false ;
	for ( int i = 2000 ; i >= 1 ; i-- ) {
		if ( c[i] != 0 ) {
			flag = true ;
		}
		if ( flag ) {
			printf ( "%d" , c[i] ) ;
		}
	}
	
	return 0 ;
}

inline void high_defination_addition() {
	int carry = 0 ;
	for ( int i = 1 ; i <= 2000 ; i++ ) {
		c[i] += a[i] + carry ;
		carry = c[i] / 10 ;
		c[i] %= 10 ;
	}
}

inline void high_defination_multiplecation ( int x ) {
	int carry = 0 ;
	for ( int i = 1 ; i <= 1000 ; i++ ) {
		a[i] = a[i] * x + carry ;
		carry = a[i] / 10 ;
		a[i] %= 10 ;
	}
}
