#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[1000000 + 5] , que1[1000000 + 5] , que2[1000000 + 5] ;
inline void minDeque () ;
inline void maxDeque () ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    minDeque () ;
    maxDeque () ;

    return 0 ;
}

inline void minDeque () {

    int cnt1 = 1 , cnt2 = 0 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        while ( cnt1 <= cnt2 && que1[cnt1] + m <= i ) {
            cnt1++ ;
        }
        while ( cnt1 <= cnt2 && a[i] < a[que1[cnt2]] ) {
            cnt2-- ;
        }

        que1[++cnt2] = i ;
        if ( i >= m ) {
            printf ( "%d " , a[que1[cnt1]] ) ;
        }
    }
}

inline void maxDeque () {
    
    int cnt1 = 1 , cnt2 = 0 ;
    printf ( "\n" ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        while ( cnt1 <= cnt2 && que2[cnt1] + m <= i ) {
            cnt1++ ;
        }
        while ( cnt1 <= cnt2 && a[i] > a[que2[cnt2]] ) {
            cnt2-- ;
        }

        que2[++cnt2] = i ;
        if ( i >= m ) {
            printf ( "%d " , a[que2[cnt1]] ) ;
        }
    }
}
