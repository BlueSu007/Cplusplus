#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

ll a[2000 + 5] , b[2000 + 5] , n , m , ans ;

int main () {

    scanf ( "%lld %lld" , &n , &m ) ;
    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
    }
    for ( int j = 1 ; j < m ; j++ ) {
        scanf ( "%lld" , &b[j] ) ;
    }

    sort ( a + 1 , a + 1 + n , greater < int > () ) ;
    sort ( b + 1 , b + 1 + m , greater < int > () ) ;

    int tmpa = 1 , tmpb = 1 ;
    for ( int i = 2 ; i < n + m ; i++ ) {
        if ( a[tmpa] > b[tmpb] ) {
            ans += tmpb * a[tmpa++] ;
        }
        else {
            ans += tmpa * b[tmpb++] ;
        }
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
