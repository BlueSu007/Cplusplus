#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int n , l , ans , x ;
struct bound {
    int left ;
    int right ;

    bool operator < ( bound x ) const {
        return left < x.left ;
    }
} a[10000 + 5] ;

int main () {

    scanf ( "%d %d" , &n , &l ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a[i].left , &a[i].right ) ;
    }
    
    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        x = max ( x , a[i].left ) ;
        while ( x < a[i].right ) {
            x += l ;
            ans++ ;
        }
    }

    printf ( "%d" , ans ) ;
    
    return 0 ;
}
