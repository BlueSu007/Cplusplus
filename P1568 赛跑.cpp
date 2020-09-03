#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define bigger 0
#define smaller 1
using namespace std;

int sh[1000000 + 5] , kc[1000000 + 5] , arrSh[1000000 + 5] , arrKc[1000000 + 5] ;
int n , m , a , b , sum , shnow , ans ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a , &b ) ;
        sum++ ;
        for ( int j = sum ; j <= sum + b ; j++ ) {
            sh[j] = a ;
        }
        sum += b , sum-- ;
    }

    sum = 0 ;

    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &a , &b ) ;
        sum++ ;
        for ( int j = sum ; j <= sum + b ; j++ ) {
            kc[j] = a ;
        }
        sum += b , sum-- ;
    }

    arrSh[1] = sh[1] ;
    for ( int i = 2 ; i <= sum ; i++ ) {
        arrSh[i] = arrSh[i - 1] + sh[i] ;
    }

    arrKc[1] = kc[1] ;
    for ( int i = 2 ; i <= sum ; i++ ) {
        arrKc[i] = arrKc[i - 1] + kc[i] ;
    }

    if ( arrKc[1] > arrSh[1] ) {
        shnow = smaller ;
    }
    else {
        shnow = bigger ;
    }

    for ( int i = 2 ; i <= sum ; i++ ) {
        if ( arrKc[i] > arrSh[i] && shnow == bigger ) {
            ans++ ;
            shnow = smaller ;
        }
        else if ( arrKc[i] < arrSh[i] && shnow == smaller ) {
            ans++ ;
            shnow = bigger ;
        }
    }

    printf ( "%d\n" , ans ) ;

    return 0 ;
}
