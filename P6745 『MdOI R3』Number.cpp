#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long k , x ;
inline int getdigit ( long long x ) ;

int main () {

    scanf ( "%lld %lld" , &k , &x ) ;
    int len = getdigit (x) ;

    if ( k == 0 ) {
        printf ( "%lld" , x + 1 ) ;
        exit ( false ) ;
    }

    k++ ;
    if ( k > len ) {
        printf ( "1" ) ;
        for ( int i = 1 ; i < k - len ; i++ ) {
            printf ( "0" ) ;
        }
        printf ( "%lld" , x ) ;
    }
    else {
        x += ( long long ) pow ( 10 , k - 1 ) ;
        printf ( "%lld" , x ) ;
    }

    return 0 ;
}

inline int getdigit ( long long x ) {
    if ( x == 0 ) {
        return 1 ;
    }

    int ans = 0 ;
    while ( x ) {
        ans++ ;
        x /= 10 ;
    }
    return ans ;
}
