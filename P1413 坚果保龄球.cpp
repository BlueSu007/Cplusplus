#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int maxn[10 + 5] , zombie[10][500000] ;
int n , t , p , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &p , &t ) ;
        maxn[p] = max ( maxn[p] , t ) ;
        zombie[p][t]++ ;
    }

    for ( int i = 1 ; i <= 6 ; i++ ) {
        for ( int j = 1 ; j <= maxn[i] ; ) {
            if ( zombie[i][j] ) {
                ans++ ;
                j += 60 ;
            }
            else {
                j++ ;
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
