#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long n , m , len ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;
    len = n / m ;
    int tmp = n - ( len * m ) ;
    for ( int i = 1 ; i <= m - tmp ; i++ ) {
        printf ( "%d " , len ) ;
    }

    for ( int i = 1 ; i <= tmp ; i++ ) {
        printf ( "%d " , len + 1 ) ;
    }

    return 0 ;
}
