#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std ;

int n , m , a , b , k[250000 + 5] ;
int map[250000 + 5][4] ;

int main() {
	
	scanf ( "%d %d %d %d" , &n , &m , &a , &b ) ;
	for ( int i = 1 ; i <= a ; i++ ) {
		scanf ( "%d %d" , &map[i][0] , &map[i][1] ) ; 
	}
	
	for ( int i = 1 ; i <= b ; i++ ) {
		scanf ( "%d %d" , &map[i][2] , &map[i][3] ) ;
	}
	
	memset ( k , 127 , sizeof(k) ) ;
	for ( int i = 1 ; i <= b ; i++ ) {
		for ( int j = 1 ; j <= a ; j++ ) {
			k[i] = min ( k[i] , abs ( map[j][0] - map[i][2] ) + abs ( map[j][1] - map[i][3] ) ) ;
		} 
	} 
	
	for ( int i = 1 ; i <= b ; i++ ) {
		printf ( "%d\n" , k[i] ) ;
	}
	
	return 0 ;
}
