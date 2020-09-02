#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define mian main
using namespace std;

long long n , cnt , ans1 , ans2 , tmp , a[18000 + 5] ;//
inline long long addNumber () ;//
inline long long work ( long long x ) ;//

int main () {

    scanf ( "%lld" , &n ) ;
    
    for ( long long i = n ; i ; i++ ) {
        ans1 = work (i) - i ;
        /*
        sort ( a + 1 , a + 1 + cnt ) ;
        for ( int i = 1 ; i <= cnt ; i++ ) {
            printf ( "%lld " , a[i] ) ;
        }
        printf ( "\n" ) ;
        */
        cnt = 0 ;
        memset ( a , 0 , sizeof(a) ) ;

        // -------------------------------------------------------

        ans2 = work (ans1) - ans1 ;
        /*
        sort ( a + 1 , a + 1 + cnt ) ;
        for ( int i = 1 ; i <= cnt ; i++ ) {
            printf ( "%lld " , a[i] ) ;
        }
        printf ( "\n" ) ;
        */
        cnt = 0 ;
        memset ( a , 0 , sizeof(a) ) ;

        if ( i == ans2 && ans1 != ans2 ) {
            printf ( "%lld %lld" , i , ans1 ) ;
            break ;
        }
    }

    return 0 ;
}

inline long long addNumber () {
    long long tmp = 0 ;
    for ( long long i = 1 ; i <= cnt ; i++ ) {
        tmp += a[i] ;
    }
    return tmp ;
}

inline long long work ( long long x ) {
    for ( long long i = 1 ; i * i <= x ; i++ ) {
        if ( x % i == 0 ) {
            cnt++ , a[cnt] = i ;
            cnt++ , a[cnt] = x / i ;
            if ( i == x / i ) {
                a[cnt] = 0 , cnt-- ;
            }
        }
    }

    return addNumber () ;
}
