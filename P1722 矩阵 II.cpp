#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , dp[200 + 5][100 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    dp[1][1] = 1 ;
    for ( int i = 2 ; i <= 2 * n ; i++ ) {
        for ( int j = ( i + 1 ) >> 1 ; j <= i ; j++ ) {
            dp[i][j] = ( dp[i - 1][j] + dp[i - 1][j - 1] ) % 100 ;
        } 
    }

    printf ( "%d" , dp[2 * n][n] ) ;

    return 0 ;
}
