#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define LL long long
using namespace std;

LL k , n , c , a , b , street[10000 + 5] , cnt1 , cnt2 ;
// 0 -> begining tree
// 1 -> air
// 2 -> small new tree

int main () {
    
    scanf ( "%lld %lld" , &n , &k ) ;

    while ( k-- ) { 
        scanf ( "%lld %lld %lld" , &c , &a , &b ) ;
        if ( c == 0 ) {
            for ( int i = a ; i <= b ; i++ ) {
                if ( street[i] == 2 ) {
                    cnt2++ ;
                }
                street[i] = 1 ;
            }
        }
        else {
            for ( int i = a ; i <= b ; i++ ) {
                if ( street[i] == 1 ) {
                    street[i] = 2 ;
                }
            }
        }
    }

    for ( int i = 0 ; i <= n ; i++ ) {
        if ( street[i] == 2 ) {
            cnt1++ ;
        }
        // cout << street[i] << " " ;
    }
    // cout << endl ;

    printf ( "%lld\n%lld" , cnt1 , cnt2 ) ;

    return 0 ;
}
