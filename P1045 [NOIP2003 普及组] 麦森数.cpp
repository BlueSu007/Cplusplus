#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 500005
long long a[LEN] , qwq[LEN] , powTwo[LEN] , x , k ;
inline void pown ( int x ) ;
inline void multiplication ( long long a[] , long long b[] ) ;
inline void output () ;

int main () {

    scanf ( "%lld" , &x ) ;
    a[0] = a[1] = powTwo[0] = 1 , powTwo[1] = 2 ;
    k = 0.30103 * x + 1 ; // ( N * log2 ) + 1

    printf ( "%lld\n" , k ) ;
    pown (x) , output () ;

    return 0 ;
}

inline void pown ( int x ) {
    if ( x & 1 ) {
        multiplication ( a , powTwo ) ;
    }

    x >>= 1 ;
    while ( x > 0 ) {
        multiplication ( powTwo , powTwo ) ;
        if ( x & 1 ) {
            multiplication ( a , powTwo ) ;
        }
        x >>= 1 ;
    }
}

inline void multiplication ( long long a[] , long long b[] ) {
    memset ( qwq , 0 , sizeof ( qwq ) ) ;
    qwq[0] = a[0] + b[0] ;

    if ( qwq[0] > 500 ) {
        qwq[0] = 500 ;
    }

    for ( int i = 0 ; i < a[0] ; i++ ) {
        for ( int j = 0 ; j < b[0] ; j++ ) {
            qwq[i + j + 1] += a[i + 1] * b[j + 1] ;
            qwq[i + j + 2] += qwq[i + j + 1] / 10 ;
            qwq[i + j + 1] %= 10 ;
        }
    }

    for ( int i = 0 ; i <= qwq[0] ; i++ ) {
        a[i] = qwq[i] ;
        // cout << a[i] << " " ;
    }
    // cout << endl ;
}

inline void output () {
    int qaq = 500 ;
    a[1]-- ;
    for ( int i = 1 ; i <= 10 ; i++ ) {
        for ( int j = 1 ; j <= 50 ; j++ ) {
            printf ( "%d" , a[qaq--] ) ;
        }
        printf ( "\n" ) ;
    }
}
