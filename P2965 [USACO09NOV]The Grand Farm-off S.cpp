#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
using namespace std;

#define LEN 1500005
struct node {
	long long u , w ;
	inline bool operator < ( const node &x ) const {
		if ( u == x.u ) {
			return w < x.w ;
		}
		return u > x.u ;
	}
} qwq[LEN] ;

long long n , k , a , b , c , d , e , f , g , h , m ;
long long ans ;
inline long long pown ( long long n , long long k , long long p ) ;

int main () {

	// freopen ( "tmp.txt" , "w" , stdout ) ;
	scanf ( "%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld" , &k , &a , &b , &c , &d , &e , &f , &g , &h , &m ) ;
	long long n = k * 3 ;
	a %= d , b %= d , c %= d , e %= h , f %= h , g %= h ;
	for ( int i = 0 ; i < n ; i++ ) {
		int OwO = i % d , OvO = i % h ;
		qwq[i].w = ( ( a * pown ( OwO , 5 , d ) ) % d + ( b * pown ( OwO , 2 , d ) ) % d + c ) % d ;
		qwq[i].u = ( ( e * pown ( OvO , 5 , h ) ) % h + ( f * pown ( OvO , 3 , h ) ) % h + g ) % h ;
		// cout << endl ;
	}

	sort ( qwq , qwq + n ) ;
	
	for ( int i = 0 ; i < k ; i++ ) {
		// cout << qwq[i].w << " " << qwq[i].u << endl ;
		ans += ( qwq[i].w % m ) , ans %= m ;
	}
	printf ( "%lld" , ans ) ;
	
	return 0 ;
}

inline long long pown ( long long n , long long k , long long p ) {
	long long base = n , ans = 1 ;
	while ( k ) {
		base %= p ;
		if ( k & 1 ) {
			ans *= base , ans %= p ;
		}

		base *= base , base %= p ;
		k >>= 1 ;
		// cout << ans << " " ;
	}

	// cout << ans << " " ;
	return ans % p ;
}
