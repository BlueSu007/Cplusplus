#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 33333
int n , m , mainWeight[LEN] , mainValue[LEN] , dp[LEN] ;
int v , p , q , subWeight[LEN][3] , subValue[LEN][3] ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d" , &v , &p , &q ) ;
        if ( ! q ) {
            mainWeight[i] = v , mainValue[i] = v * p ;
        }
        else {
            subWeight[q][0]++ , subWeight[q][subWeight[q][0]] = v ;
            subValue[q][subWeight[q][0]] = v * p ;
        }
    }

    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = n ; j >= mainWeight[i] ; j-- ) {
            dp[j] = max ( dp[j] , dp[j - mainWeight[i]] + mainValue[i] ) ;
            if ( j >= mainWeight[i] + subWeight[i][1] ) {
                dp[j] = max ( dp[j] , dp[j - mainWeight[i] - subWeight[i][1]] + mainValue[i] + subValue[i][1] ) ;
            }
            if ( j >= mainWeight[i] + subWeight[i][2] ) {
                dp[j] = max ( dp[j] , dp[j - mainWeight[i] - subWeight[i][2]] + mainValue[i] + subValue[i][2] ) ;
            }
            if ( j >= mainWeight[i] + subWeight[i][1] + subWeight[i][2] ) {
                dp[j] = max ( dp[j] , dp[j - mainWeight[i] - subWeight[i][1] - subWeight[i][2]] + mainValue[i] + subValue[i][1] + subValue[i][2] ) ;
            }
        }
    }

    printf ( "%d" , dp[n] ) ;

    return 0 ;
}
