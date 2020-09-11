#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct person {
    int w , d , c ; // like description
} a[20000 + 5] ;

int e[10 + 5] , n , k ;
inline bool cmp ( person x , person y ) {
    if ( x.w == y.w ) {
        return x.c < y.c ;
    }

    return x.w > y.w ;
}

int main () {

    scanf ( "%d %d" , &n , &k ) ;
    for ( int i = 1 ; i <= 10 ; i++ ) {
        scanf ( "%d" , &e[i] ) ;
    }
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i].w ) ;
        a[i].c = i ;
    }

    sort ( a + 1 , a + 1 + n , cmp ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        a[i].d = ( i - 1 ) % 10 + 1 ;
        a[i].w += e[a[i].d] ;
    }

    sort ( a + 1 , a + 1 + n , cmp ) ;

    for ( int i = 1 ; i <= k ; i++ ) {
        printf ( "%d " , a[i].c ) ;
    }

    return 0 ;
}
