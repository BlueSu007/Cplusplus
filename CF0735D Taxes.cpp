#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm> 
#include <climits>
#include <cstring>
#include <string>
using namespace std;

int n ;
inline bool isprime ( int x ) ;

int main () {

    scanf ( "%d" , &n ) ;
    if ( isprime (n) ) {
        printf ( "1" ) ;
    }
    else {
        if ( n % 2 == 0 || isprime ( n - 2 ) ) {
            printf ( "2" ) ;
        }
        else {
            printf ( "3" ) ;
        }
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
