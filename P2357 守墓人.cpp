#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , m , a[200000 + 5] , url , k , x , y ;
long long sum1[400000 + 5] , sum2[400000 + 5] , qwq ;
inline long long lowbit ( long long x ) ;
inline void update ( long long x , long long k ) ;
inline long long query ( long long x ) ;

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
        else if ( url == 2 ) {
            scanf ( "%lld" , &k ) ;
            qwq += k ;
        }
        else if ( url == 3 ) {
            scanf ( "%lld" , &k ) ;
            qwq -= k ;
        }
        else if ( url == 4 ) {
            scanf ( "%lld %lld" , &x , &y ) ;
            long long tmp = query (y) - query ( x - 1 ) ;
            if ( x == 1 ) {
                tmp += qwq ;
            }
            printf ( "%lld\n" , tmp ) ;
        }
        else {
            printf ( "%lld\n" , query (1) + qwq ) ;
        }
    }

    return 0 ;
}

inline long long lowbit ( long long x ) {
    return x & -x ;
}

inline void update ( long long x , long long k ) {
    long long tmp = x ;
    while ( x <= n ) {
        sum1[x] += k , sum2[x] += tmp * k ;
        x += lowbit (x) ;
    }
}

inline long long query ( long long x ) {
    long long ans = 0 , tmp = x + 1 ;
    while ( x != 0 ) {
        ans += tmp * sum1[x] - sum2[x] ;
        x -= lowbit (x) ;
    }
    return ans ;
}
