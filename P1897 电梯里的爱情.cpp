#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , a[100000 + 5] , kind , vis[20000000 + 5] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        if ( vis[a[i]] == false ) {
            kind++ ;
            vis[a[i]] = true ;
        }
    }

    sort ( a + 1 , a + 1 + n ) ;

    int sumTime = 0 ;
    sumTime += a[n] * 6 , sumTime += a[n] * 4 ;
    sumTime += n , sumTime += kind * 5 ;
    
    printf ( "%d" , sumTime ) ;

    return 0 ;
}
