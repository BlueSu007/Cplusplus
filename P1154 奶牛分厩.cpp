#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[5000 + 5] , ans , vis[1000000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i + 1 ; j <= n ; j++ ) {
            vis[abs ( a[i] - a[j] )] = true ;
        }
    }

    ans = n ;
    while ( vis[ans] ) {
        ans++ ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
