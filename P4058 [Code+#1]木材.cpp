// #include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define ull unsigned long long
using namespace std;

ull n , x , y ;
ull h[200000 + 5] , a[200000 + 5] ;
ull now , left , right ;
ull b[200000 + 5] ;
inline void input () ;
inline void work () ;
inline bool check () ;
inline void add () ;

int main () {

    input () ;
    work () ;
    printf ( "%llu" , right ) ;

    return 0 ;
}

inline void input () {
    scanf ( "%llu %llu %llu" , &n , &x , &y ) ;
    now = right = max ( x , y ) ;
    for ( ull i = 1 ; i <= n ; i++ ) {
        scanf ( "%llu" , &h[i] ) ;
    }
    for ( ull i = 1 ; i <= n ; i++ ) {
        scanf ( "%llu" , &a[i] ) ;
        right = min ( right , ( now - h[i] ) / a[i] + 1 ) ;
    }
}

inline void work () {
    ull tmp = 0 ;
    for ( ull i = 1 ; i <= n ; i++ ) {
        if ( h[i] >= y ) {
            tmp += h[i] ;
        }
    }

    if ( tmp >= x ) {
        printf ( "0" ) ;
        exit(0) ;
    }

    while ( right - left > 1 ) {
        ull mid = ( left + right ) / 2 ;
        for ( ull i = 1 ; i <= n ; i++ ) {
            b[i] = h[i] + mid * a[i] ;
        }

        ull tmp = 0 ;
        for ( ull i = 1 ; i <= n ; i++ ) {
            if ( b[i] >= y ) {
                tmp += b[i] ;
                if ( tmp >= x ) {
                    break ;
                }
            }
        }

        if ( tmp >= x ) {
            right = mid ;
        }
        else {
            left = mid ;
        }
    }
}
