#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100005
#define MOD 998244353
int n , k , t ;
unsigned long long duliu[LEN] , shuchong[LEN] ;
inline void duliutimuxuyaodabiao () ;

int main () {

    scanf ( "%d" , &t ) ;
    duliutimuxuyaodabiao () ;

    while ( t-- ) {
        scanf ( "%d %d" , &n , &k ) ;
        if ( n == 1 ) {
            printf ( "9\n" ) ;
            continue ;
        }
        printf ( "%llu\n" , duliu[n] % MOD ) ;
    }

    return 0 ;
}

inline void duliutimuxuyaodabiao () {
    duliu[1] = 8 , shuchong[1] = 1 ;
    for ( int i = 2 ; i <= 100000 ; i++ ) {
        duliu[i] = duliu[i - 1] * 9 + shuchong[i - 1] ;
        shuchong[i] = shuchong[i - 1] * 9 + duliu[i - 1] ;
        duliu[i] %= MOD , shuchong[i] %= MOD ;
    }
}
