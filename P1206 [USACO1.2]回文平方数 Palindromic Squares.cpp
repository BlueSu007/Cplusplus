#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

int n , p , a[10000] , b[10000] ;
int ansn[13] = { 0 , 1 , 2 , 3 , 11 , 22 , 26 , 101 , 111 , 121 , 202 , 212 , 264 } ;
int ansp[13] = {0 , 1 , 4 , 9 , 121 , 484 , 676 ,10201 , 12321 , 14641 , 40804 , 44944 , 69696 } ;
inline bool change ( int x , int m ) ;
inline void print () ;

int main () {
	
	cin >> n ;
	for ( int i = 1 ; i <= 300 ; i++ ) {
		if ( change ( i * i , n ) ) {
			change ( i , n ) ;
			print () ;
			cout << " " ;
			change ( i * i , n ) ;
			print () ;
			cout << endl ;
		}
	}
	// if ( n == 10 ) {
	// 	for ( int i = 1 ; i <= 12 ; i++ ) {
	// 		printf ( "%d %d\n" , ansn[i] , ansp[i] );
	// 	}
	// 	exit(0) ;
	// }
	// for ( int i = 1 ; i <= 12 ; i++ ) {
	// 	if ( change ( ansn[i] , n ) && change ( ansp[i] , n ) ) {
	// 		change ( ansn[i] , n ) ;
	// 		print () ;
	// 		cout << ' ' ;
	// 		change ( ansp[i] , n ) ;
	// 		print () ;
	// 		cout << endl ;
	// 	}
	// }
	
	return 0 ;
}

inline bool change ( int x , int m ) {
	p = 0 ;
	memset ( a , 0 , sizeof(a) ) ;
	do {
		a[p++] = x % m ;
		x /= m ;
	} while ( x != 0 ) ;

	int i = 0 , j = p - 1 ;
	while ( i <= j ) {
		if ( a[i++] != a[j--] ) {
			return 0 ;
		}
	}

	return 1 ;
}

inline void print () {
	for ( int i = p - 1 ; i >= 0 ; i-- ) {
		if ( a[i] >= 10 ) {
			printf ( "%c" , a[i] + 65 - 10 ) ;
			continue ;
		}
		
		cout << a[i] ;
	}
}
