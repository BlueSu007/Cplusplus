#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n ;
inline bool isprime ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;

    for ( int i = 2 ; i <= n ; i += 2 ) {
        for ( int j = i ; i + j <= n ; j += 2 ) {
            if ( i == 4 ) {
                i-- ;
            }
            if ( j == 4 ) {
                j-- ;
            }

            if ( isprime (i) && isprime (j) && isprime ( n - i - j ) ) {
                printf ( "%d %d %d" , i , j , n - i - j ) ;
                exit(0) ;
            }
        }
    }

    return 0 ;
}

inline bool isprime ( int x ) {
    if ( x < 2 ) {
        return false ;
    }
    else if ( x == 2 ) {
        return true ;
    }

    for ( int i = 2 ; i * i <= x ; i++ ) {
        if ( x % i == 0 ) {
            return false ;
        }
    }

    return true ;
}
