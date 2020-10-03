#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#define ull unsigned long long
using namespace std;

ull a , b , c , ans ;
inline ull gcd ( ull a , ull b ) ;
inline ull lcm ( ull a , ull b ) ;

int main () {

    scanf ( "%llu %llu %llu" , &a , &b , &c ) ;
    printf ( "%llu" , lcm ( lcm ( a , b ) , c ) ) ;

    return 0 ;
}

inline ull gcd ( ull a , ull b ) {
    if ( b == 0 ) {
        return a ;
    }

    return gcd ( b , a % b ) ;
}

inline ull lcm ( ull a , ull b ) {
    return a / gcd ( a , b ) * b ;
}
