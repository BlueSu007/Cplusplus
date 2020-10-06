#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[1000 + 5][1000 + 5] ;
int sx , sy , ex , ey ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        scanf ( "%d %d %d %d" , &sx , &sy , &ex , &ey ) ;
        for ( int i = sx ; i <= ex ; i++ ) {
            for ( int j = sy ; j <= ey ; j++ ) {
                a[i][j]++ ;
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            printf ( "%d " , a[i][j] ) ;
        }

        puts ("") ;
    }

    return 0 ;
}
