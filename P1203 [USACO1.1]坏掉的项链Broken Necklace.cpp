#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std ;

int n , flower , maxflower ;
char a[1000] ;

int main() {
	
	scanf ( "%d" , &n ) ;
	scanf ( "%s" , a ) ;
	
	for ( int i = n ; i < n * 2 ; i++ ) {
		a[i] = a[i - n] ;
	}
	
	for ( int i = 0 ; i < 2 * n ; i++ ) {
		int left = i , right = i + 1 ;
		char color1 = a[left] , color2 = a[right] ;
		
		while ( a[left] == 'w' && left != 0 ) {
			left-- ;
			color1 = a[left] ;
		} 
		
		while ( a[right] == 'w' && right != 2 * n - 1 ) {
			right++ ;
			color2 = a[right] ;
		}
		
		flower = 0 ;
		left = i ;
		
		while ( left >= 0 ) {
			if ( a[left] == color1 || a[left] == 'w' ) {
				flower++ ;
			}
			else {
				break ;
			}
			left-- ;
		} 
		
		right = i + 1 ;
		
		while ( right < 2 * n ) {
			if ( a[right] == color2 || a[right] == 'w' ) {
				flower++ ;
			}
			else {
				break ;
			}
			right++ ;
		}
		
		if ( maxflower < flower ) {
			maxflower = flower ;
		}
	}
	
	if ( maxflower > n ) {
		maxflower = n ;
	}
	printf ( "%d" , maxflower ) ;
	
	return 0 ;
}
