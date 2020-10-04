#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , x , sum , ans , l , flag ;

int main () {

    scanf ( "%d" , &n ) ;
    
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        sum += x , ans++ ;

        if ( ( sum >= 0 ) && flag ) {
            flag = 0 , ans += ( i - l ) * 2 ;
        }
        if ( ( sum < 0 ) && !flag ) {
            flag = 1 , l = i ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
