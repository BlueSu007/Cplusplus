#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
using namespace std;

int n , label[1000000] ;
inline bool isprime ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    if ( n < 3 ) {
        printf ( "1\n" ) ;
    }
    else {
        printf ( "2\n" ) ;
    }

    label[0] = label[1] = true ;
    for ( int i = 2 ; i * i <= n + 1 ; i++ ) {
        if ( ! label[i] ) {
            for ( int j = i + i ; j <= n + 1 ; j += i ) {
                label[j] = true ;
            }
        }
    }

    for ( int i = 2 ; i <= n + 1 ; i++ ) {
        printf ( "%d " , label[i] + 1 ) ;
    }

    return 0 ;
}

inline bool isprime ( int x ) {
    for ( int i = 2 ; i * i <= x ; i++ ) {
        if ( x % i == 0 ) {
            return false ;
        }
    }

    return true ;
}
