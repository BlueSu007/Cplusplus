#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , ans , minn = INT_MAX ;
char c[50 + 5][50 + 5] ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            cin >> c[i][j] ;
        }
    }

    for ( int i = 1 ; i <= n - 2 ; i++ ) {
        for ( int j = i + 1 ; j <= n - 1 ; j++ ) {
            ans = 0 ;
            for ( int k = 1 ; k <= i ; k++ ) {
                for ( int l = 1 ; l <= m ; l++ ) {
                    if ( c[k][l] != 'W' ) {
                        ans++ ;
                    }
                }
            }

            for ( int k = i + 1 ; k <= j ; k++ ) {
                for ( int l = 1 ; l <= m ; l++ ) {
                    if ( c[k][l] != 'B' ) {
                        ans++ ;
                    }
                }
            }

            for ( int k = j + 1 ; k <= n ; k++ ) {
                for ( int l = 1 ; l <= m ; l++ ) {
                    if ( c[k][l] != 'R' ) {
                        ans++ ;
                    }
                }
            }

            minn = min ( ans , minn ) ;
        }
    }

    printf ( "%d" , minn ) ;

    return 0 ;
}
