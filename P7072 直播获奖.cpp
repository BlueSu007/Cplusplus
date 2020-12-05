#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int box[600 + 5] , n , w , x ;

int main () {

    scanf ( "%d %d" , &n , &w ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        box[x] ++ ;
        int sum = 0 ;

        for ( int j = 600 ; j >= 0 ; -- j ) {
            sum += box[j] ;
            if ( sum >= max ( 1 , i * w / 100 ) ) {
                printf ( "%d " , j ) ;
                break ;
            }
        }
    }

    return 0 ;
}
