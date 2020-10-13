#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct node {
    int h ;
    int w ;
} a[1000 + 5] ;

inline bool cmp ( node x , node y ) {
    return x.h < y.h ;
}

int n , k , m , ans = INT_MAX ;
int f[500 + 5][500 + 5] ;

int main () {

    scanf ( "%d %d" , &n , &k ) ;
    m = n - k ;

    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d %d" , &a[i].h , &a[i].w ) ;
    }

    sort ( a + 1 , a + 1 + n , cmp ) ;
    memset ( f , 20 , sizeof (f) ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        f[i][1] = 0 ;
    }

    for ( int i = 2 ; i <= n ; i++ ) {
        for ( int j = 1 ; j < i ; j++ ) {
            for ( int l = 2 ; l <= min ( n , m ) ; l++ ) {
                f[i][l] = min ( f[i][l] , f[j][l - 1] + abs ( a[i].w - a[j].w ) ) ;
            }
        }
    }

    for ( int i = m ; i <= n ; i++ ) {
        ans = min ( ans , f[i][m] ) ;
    }

    printf ( "%d\n" , ans ) ;

    return 0 ;
}
