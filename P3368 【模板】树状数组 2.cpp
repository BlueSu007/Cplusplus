#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , m , a[500000 + 5] , b[500000 + 5] , url , k , x , y ;
typedef long long ll ;
inline ll lowbit ( ll k ) ;
inline void update ( ll x , ll k ) ;
inline ll sum ( ll x ) ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
        update ( i , a[i] - a[i - 1] ) ;
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%lld" , &url ) ;
        if ( url == 1 ) {
            scanf ( "%lld %lld %lld" , &x , &y , &k ) ;
            update ( x , k ) ;
            update ( y + 1 , -k ) ;
        }
        else {
            scanf ( "%lld" , &k ) ;
            printf ( "%lld\n" , sum (k) ) ;
        }
    }

    return 0 ;
}

inline ll lowbit ( ll k ) {
    return k & -k ;
}

inline void update ( ll x , ll k ) {
    while ( x <= n ) {
        b[x] += k ;
        x += lowbit (x) ;
    }
}

inline ll sum ( ll x ) {
    ll ans = 0 ;
    while ( x != 0 ) {
        ans += b[x] ;
        x -= lowbit (x) ;
    }
    return ans ;
}
