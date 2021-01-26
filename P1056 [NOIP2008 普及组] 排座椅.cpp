#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 2005
int m , n , k , l , d , x , y , p , q , colCnt , rowCnt ;
int qwq[LEN] , qaq[LEN] , row[LEN] , col[LEN] ;
inline void searchRow () ;
inline void searchCol () ;

int main () {

    scanf ( "%d %d %d %d %d" , &m , &n , &k , &l , &d ) ;
    for ( int i = 1 ; i <= d ; i++ ) {
        scanf ( "%d %d %d %d" , &x , &y , &p , &q ) ;
        if ( x == p ) {
            qwq[min ( y , q )]++ ;
        }
        else {
            qaq[min ( x , p )]++ ;
        }
    }

    searchRow () ;
    searchCol () ;

    for ( int i = 0 ; i < LEN ; i++ ) {
        if ( row[i] ) {
            printf ( "%d " , i ) ;
        }
    }

    printf ( "\n" ) ;

    for ( int i = 0 ; i < LEN ; i++ ) {
        if ( col[i] ) {
            printf ( "%d " , i ) ;
        }
    }

    return 0 ;
}

inline void searchRow () {
    for ( int i = 1 ; i <= k ; i++ ) {
        int maxn = INT_MIN , OvO ;
        for ( int j = 1 ; j < m ; j++ ) {
            if ( qaq[j] > maxn ) {
                maxn = qaq[j] , OvO = j ;
            }
        }

        qaq[OvO] = 0 , row[OvO]++ ;
    }
}

inline void searchCol () {
    for ( int i = 1 ; i <= l ; i++ ) {
        int maxn = INT_MIN , OvO ;
        for ( int j = 1 ; j < n ; j++ ) {
            if ( qwq[j] > maxn ) {
                maxn = qwq[j] , OvO = j ;
            }
        }

        qwq[OvO] = 0 , col[OvO]++ ;
    }
}   
