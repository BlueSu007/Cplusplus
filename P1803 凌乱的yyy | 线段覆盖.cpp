#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

struct contest {
    int start ;
    int end ;
} a[100000 + 5] ;

int n , f[100000 + 5] , maxn , tmp ;

inline bool cmp ( contest x , contest y ) {
    if ( x.end != y.end ) {
        return x.end < y.end ;
    }

    return x.start < y.start ;
}

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a[i].start , &a[i].end ) ;
    }

    sort ( a + 1 , a + 1 + n , cmp ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        while ( a[tmp + 1].end <= a[i].start ) {
            tmp++ ;
        }

        f[i] = max ( f[i - 1] , f[tmp] + 1 ) ;
    }

    printf ( "%d" , f[n] ) ;

    return 0 ;
}
