#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define kkk 200000 + 5
using namespace std ;

int n , k , p , color , price ;
int last[kkk] , sum[kkk] , cnt[kkk] ;
int ans , now ;

int main() {
	
	scanf ( "%d %d %d" , &n , &k , &p ) ;
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%d %d" , &color , &price ) ;
		//can pay out
		if ( price <= p ) {
			//short stay here
			now = i ;
		}
		//same color amount before the café
		if ( now >= last[color] ) {
			sum[color] = cnt[color] ;
		}
		
		//change 
		last[color] = i ;
		ans += sum[color] ;
		cnt[color]++ ;
	}
	
	printf ( "%d" , ans ) ;
	
	return 0 ;
}
