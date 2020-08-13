#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a , b , ans1 , ans2 , l ;

int main () {

    scanf ( "%d %d %d" , &a , &b , &l ) ;
    ans1 = l , ans2 = 1 ;

    for ( int i = 1 ; i <= l ; i++ ) {
        for ( int j = 1 ; j <= l ; j++ ) {
            if ( __gcd ( i , j ) == 1 && i * b >= j * a && i * ans2 < j * ans1) {
                ans1 = i ;
                ans2 = j ;
            }
        }
    }

    printf ( "%d %d" , ans1 , ans2 ) ;

    return 0 ;
}
