#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[10][60] , c[10] , b[10][60] ;
int nowid , ans , minn = INT_MAX ;

int main () {

    for ( int i = 1 ; i <= 5 ; i++ ) {
        c[i] = 1 ;
    }

    for ( int i = 1 ; i <= 5 ; i++ ) {
        for ( int j = 1 ; j <= 10 ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
            b[i][j] = a[i][j] - a[i][j - 1] ;
        }
    }

    for ( int i = 1 ; i <= 20 ; i++ ) {
        minn = INT_MAX ;
        for ( int j = 1 ; j <= 5 ; j++ ) {
            if ( b[j][c[j] + 1] < minn && c[j] + 1 <= 10 ) {
                nowid = j ;
                minn = b[j][c[j] + 1] ;
            }
        }

        c[nowid]++ ;
    }

    for ( int i = 1 ; i <= 5 ; i++ ) {
        ans += a[i][c[i]] ;
    }

    printf ( "%d\n" , ans ) ;
    for ( int i = 1 ; i <= 5 ; i++ ) {
        printf ( "%d " , c[i] ) ;
    }

    return 0 ;
}
