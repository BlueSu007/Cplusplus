#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , a[1000000 + 5] , b[5000 + 5] , minn = 1e9 , maxn ;
long long ans ;
long long mod = 1e9 + 7 ;

int main () {

    scanf ( "%lld" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
        minn = min ( minn , a[i] ) ;
        maxn = max ( maxn , a[i] ) ;
        b[a[i]]++ ;
    }

    for ( int i = minn + 1 ; i <= maxn ; i++ ) {
        if ( b[i] > 1 ) {
            for ( int j = minn ; j <= i / 2 ; j++ ) {
                if ( b[j] >= 1 && b[i - j] >= 1 ) {
                    if ( j * 2 != i ) {
                        ans = ( ans + ( b[i] * ( b[i] - 1 ) / 2 ) * b[j] * b[i - j] % mod ) % mod ;
                    }
                    else if ( b[j] > 1 ) {
                        ans = ( ans + ( ( b[i] * ( b[i] - 1 ) / 2 ) * ( b[j] * ( b[j] - 1 ) / 2 ) % mod ) % mod ) % mod ;
                    }
                }
            }
        }
    }

    printf ( "%lld" , ans % mod ) ;

    return 0 ;
}
