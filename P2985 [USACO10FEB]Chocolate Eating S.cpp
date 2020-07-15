#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long date[50000 + 5] , chocolate[50000 + 5];
long long n , d , ans , left , right;
inline bool check ( long long x , bool ifpity );

int main() {
	
	scanf ( "%lld %lld" , &n , &d );
	for ( int i = 1 ; i <= n ; i++ ) {
		scanf ( "%lld" , &chocolate[i] );
		right += chocolate[i];
	}
	
	while ( left <= right ) {
		long long mid = ( left + right ) / 2;
		if ( check ( mid , 0 ) ) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	} 
	
	printf ( "%lld" , ans );
	check ( ans , 1 );
	
	for ( int i = 1 ; i <= n ; i++ ) {
		printf ( "\n%lld" , date[i] );
	}
	
	return 0;
}

inline bool check ( long long x , bool ifpity ) {
	
	long long fatter = 0;
	long long happier = 0;
	
	for ( int i = 1 ; i <= d ; i++ ) {
		happier /= 2;
		while ( happier < x && fatter <= n ) {
			fatter++;
			if ( ifpity ) {
				date[fatter] = i;
			}
			
			happier += chocolate[fatter];
		}
		
		if ( happier < x ) {
			return false;
		}
	}
	
	if ( ifpity ) {
		for ( int i = fatter + 1 ; i <= n ; i++ ) {
			date[i] = d;
		}
	}
	
	return true;
}
