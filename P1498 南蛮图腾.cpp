#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10
int n , dp[LEN * 100] ;

int main () {

    scanf ( "%d" , &n ) ;
    int len = 1 << n ;
    dp[0] = 1 ;

    for ( int i = 0 ; i < len ; i++ ) {
        for ( int j = 1 ; j < len - i ; j++ ) {
                    // cout << 1 ;
            printf ( " " ) ;
        }

        for ( int j = i ; j >= 0 ; j-- ) {
                    // cout << 2 ;
            dp[j] ^= dp[j - 1] ;
        }

        if ( i % 2 == 0 ) {
            for ( int j = 0 ; j <= i ; j++ ) {
                if ( dp[j] == 0 ) {
                    // cout << 3 ;
                    printf ( "  " ) ;
                }
                else {
                    // cout << 4 ;
                    cout << "/\\" ;
                }
            }
        }
        else {
            for ( int j = 0 ; j <= i ; j += 2 ) {
                if ( dp[j] == 0 ) {
                    // cout << 5 ;
                    printf ( "    " ) ;
                }
                else {
                    // cout << 6 ;
                    cout << "/__\\" ;
                }
            }
        }

        printf ( "\n" ) ;
    }

    return 0 ;
}
