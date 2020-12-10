#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , k , energy , kind , ate , ans ;
int upbound[10000] , lenth[10000] ;

struct node {
    int kind , value ;
    inline bool operator < ( const node x ) const {
        if ( value == x.value ) {
            return upbound[kind] > upbound[x.kind] ;
        }
        return value > x.value ;
    }
} xlsx[20000] ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d" , &upbound[i] ) ;
    } 
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &xlsx[i].value , &xlsx[i].kind ) ;
    }

    sort ( xlsx + 1 , xlsx + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( lenth[xlsx[i].kind] == upbound[xlsx[i].kind] ) {
            continue ;
        }
        if ( ate == m ) {
            break ;
        }

        lenth[xlsx[i].kind]++ , ate++ ;
        ans += xlsx[i].value ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
