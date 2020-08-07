#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

map < int , bool > pam ;
int a[100000 + 5] ;
int n , m , b ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    while ( m-- ) {
        scanf ( "%d" , &b ) ;
        pam[b] = true ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( pam[a[i]] ) {
            printf ( "%d " , a[i] ) ;
        }
    }

    return 0 ;
}
