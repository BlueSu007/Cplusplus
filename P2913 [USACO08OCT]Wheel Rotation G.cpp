#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , y , z , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; i++ ) {
        scanf ( "%d %d %d" , &x , &y , &z ) ;
        if ( z == 1 ) {
            ans++ ;
        }
    }
    printf ( "%d" , ans % 2 ) ;

    return 0 ;
}
