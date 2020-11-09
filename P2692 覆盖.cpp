#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std ;

int n , m , b , g , x , y , a[5000 + 5] , c[5000 + 5] ;
int col , row , cnt ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &b , &g ) ;
    for ( int i = 1 ; i <= b ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        for ( int j = x ; j <= y ; j++ ) {
            if ( !a[j] ) {
                row++ , a[j] = true ;
                cnt += m ;
            }  
        }
    }
    for ( int i = 1 ; i <= g ; i++ ) {
        scanf ( "%d %d" , &x , &y ) ;
        for ( int j = x ; j <= y ; j++ ) {
            if ( !c[j] ) {
                col++ , c[j] = true ;
                cnt += n - row ;
            }
        }
    }

    printf ( "%d" , cnt ) ;

    return 0 ;
}
