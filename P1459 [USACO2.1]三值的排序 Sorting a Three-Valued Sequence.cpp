#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , a[1000 + 5] , goal[1000 + 5] , ans1 , ans2 , ans3 ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        goal[i] = a[i] ;
    }

    sort ( goal + 1 , goal + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( ( goal[i] == 1 || goal[i] == 2 ) && a[i] == 3 ) {
            ans3++ ;
        }
        if ( goal[i] == 1 && a[i] == 2 ) {
            ans2++ ;
        }
        if ( goal[i] == 2 && a[i] == 1 ) {
            ans1++ ;
        }
    }

    printf ( "%d" , ans3 + max ( ans2 , ans1 ) ) ;

    return 0 ;
}
