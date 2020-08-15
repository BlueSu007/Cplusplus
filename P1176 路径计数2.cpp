#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[1000 + 5][1000 + 5] , b[1000 + 5][1000 + 5] ;
int n , m , x , y ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        b[x][y] = 1 ;
    }

    a[1][1] = 1 ;

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            a[i][j] += a[i - 1][j] + a[i][j - 1] ;
            if ( b[i][j] == 1 ) {
                a[i][j] = 0 ;
            }
            a[i][j] %= 100003 ;
        }
    }

    printf ( "%d" , a[n][n] ) ;

    return 0 ;
}
