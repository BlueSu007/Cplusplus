#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , ans ;
struct node {
    int value ;
    int id ;

    inline bool operator < ( const node x ) const {
        if ( value == x.value ) {
            return id < x.id ;
        }
        return value < x.value ;
    }
} a[100000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i].value ) ;
        a[i].id = i ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        ans = max ( ans , a[i].id - i ) ;
    }

    printf ( "%d" , ans + 1 ) ;

    return 0 ;
}
