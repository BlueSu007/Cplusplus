#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , d , l , ans ;
int s[50000 + 5] ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &d , &l ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &s[i] ) ;
    }

    sort ( s + 1 , s + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        int k = ans / m ;
        if ( s[i] - k * d >= l ) {
            ans++ ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
