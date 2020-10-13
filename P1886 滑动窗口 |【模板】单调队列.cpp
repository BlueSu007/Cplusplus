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

    int head = 1 , tail = 0 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        while ( head <= tail && que1[head] + m <= i ) {
            head++ ;
        }
        while ( head <= tail && a[i] < a[que1[tail]] ) {
            tail-- ;
        }

        que1[++tail] = i ;
        if ( i >= m ) {
            printf ( "%d " , a[que1[head]] ) ;
        }
    }
}

inline void maxDeque () {
    
    int head = 1 , tail = 0 ;
    printf ( "\n" ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        while ( head <= tail && que2[head] + m <= i ) {
            head++ ;
        }
        while ( head <= tail && a[i] > a[que2[tail]] ) {
            tail-- ;
        }

        que2[++tail] = i ;
        if ( i >= m ) {
            printf ( "%d " , a[que2[head]] ) ;
        }
    }
}
