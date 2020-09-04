#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int len , ans , flag = 1 ;
char a[1000 + 5] ;

int main () {

    scanf ( "%d %s" , &len , a ) ;

    for ( int i = 0 ; i < len - 1 ; i++ ) {
        if ( a[i] == 'V' && a[i + 1] == 'K' ) {
            ans++ , a[i] = 'a' , a[i + 1] = 'a' ;
        }
    }

    for ( int i = 0 ; i < len - 1 ; i++ ) {
        if ( a[i] == a[i + 1] && a[i] != 'a' ) {
            ans++ ;
            break ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
