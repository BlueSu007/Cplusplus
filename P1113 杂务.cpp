#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a , b , c , ans ;
int dp[100000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &i , &a ) ;
        int tmp = 0 ;
        while ( scanf ( "%d" , &c ) && c != 0 ) {
            tmp = max ( tmp , dp[c] ) ;
        }

        dp[i] = tmp + a ;
        ans = max ( dp[i] , ans ) ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
