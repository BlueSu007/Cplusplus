#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int n , a[8 + 5][25 + 5] = { {} , { 0 , 2 , 3 , 5 , 7 } , 
{ 0 , 23 , 29 , 31 , 37 , 53 , 59 , 71 , 73 , 79 } , 
{ 0 , 233 , 239 , 293 , 311 , 313 , 317 , 373 , 379 , 593 , 599 , 719 , 733 , 739 , 797 } , 
{ 0 , 2333 , 2339 , 2393 , 2399 , 2939 , 3119 , 3137 , 3733 , 3739 , 3793 , 3797 , 5939 , 7193 , 7331 , 7333 , 7393 } , 
{ 0 , 23333 , 23339 , 23399 , 23993 , 29399 , 31193 , 31379 , 37337 , 37339 , 37397 , 59393 , 59399 , 71933 , 73331 , 73939 } , 
{ 0 , 233993 , 239933 , 293999 , 373379 , 373393 , 593933 , 593993 , 719333 , 739391 , 739393 , 739397 , 739399 } , 
{ 0 , 2339933 , 2399333 , 2939999 , 3733799 , 5939333 , 7393913 , 7393931 , 7393933 } , 
{ 0 , 23399339 , 29399999 , 37337999 , 59393339 , 73939133 } } ;
int num[8 + 5] = { 0 , 4 , 9 , 14 , 16 , 15 , 12 , 8 , 5 } ;

int main() {
	
	scanf ( "%d" , &n ) ;
	for ( int i = 1 ; i <= num[n] ; i++ ) {
		printf ( "%d\n" , a[n][i] ) ;
	}
	
	return 0 ;
}
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int now ;
const int a[6] = { 0 , 1 , 3 , 5 , 7 , 9 } ;
const int b[5] = { 0 , 2 , 3 , 5 , 7 } ;
inline bool isprime ( int x ) ;
inline bool change ( int x ) ;

int main() {
	
	for ( int i = 1 ; i <= 99999999 ; i++ ) {
		if ( change(i) ) {
			printf ( "%d , " , i ) ;
		}
	}
	
	return 0 ;
}

inline bool isprime ( int x ) {
	if ( x == 1 ) {
		return 0 ;
	}
	if ( x == 2 ) {
		return 1 ;
	}
	for ( int i = 2 ; i * i <= x ; i++ ) {
		if ( x % i == 0 ) {
			return 0 ;
		}
	}
	
	return 1 ;
}

inline bool change ( int x ) {
	while (x) {
		if ( !isprime(x) ) {
			return 0 ;
		}
		
		x /= 10 ;
	}
	
	return 1 ;
}
*/
