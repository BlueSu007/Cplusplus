#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n ;
unsigned long long k ;

int main () {

    // scanf ( "%d %lld" , &n , &k ) ;
    cin >> n >> k ;
    k ^= k >> 1 ;
    while ( ~--n ) {
        // printf ( "%lld" , ( k >> n & 1 ) ) ;
        cout << ( k >> n & 1 ) ;
    }

    return 0 ;
}
