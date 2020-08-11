#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char occupation[100000 + 5][10 + 5] ;
long long n , m , cur , a , s , direction[100000 + 5] ;

int main () {


    scanf ( "%lld %lld" , &n , &m ) ;
    // cin >> n >> m ;
    for ( int i = 0 ; i < n ; i++ ) {
        scanf ( "%lld %s" , &direction[i] , occupation[i] ) ;
        // cin >> direction[i] >> occupation[i] ;
    }

    // for ( int i = 1 ; i <= n ; i++ ) {
    //     cout << direction[i] << " " ;
    // }

    // for ( int i = 1 ; i <= n ; i++ ) {
    //     cout << occupation[i] << " " ;
    // }

    for ( int i = 0 ; i < m ; i++ ) {
        scanf ( "%lld %lld" , &a , &s ) ;
        // cin >> a >> s ;
        if ( direction[cur] == a ) {
            s *= -1 ;
        }

        cur = ( cur + n + s ) % n ;
    }

    printf ( "%s" , occupation[cur] ) ;
    // cout << occupation[cur] << endl ;

    return 0 ;
}
