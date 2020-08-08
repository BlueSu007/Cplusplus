#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int a[100000 + 5] , b[100000 + 5] ;
int n , m , ans ;
inline void input () ;
inline void work () ;

int main () {

    input () ;
    work () ;
    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void input () {
    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }
    for ( int j = 1 ; j <= m ; j++ ) {
        scanf ( "%d" , &b[j] ) ;
    }
}

inline void work () {
    sort ( a + 1 , a + 1 + n ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        int left = 0 , right = n + 1 ;
        while ( left < right ) {
            int mid = ( left + right ) / 2 ;
            if ( a[mid] <= b[i] ) {
                left = mid + 1 ;
            }
            else {
                right = mid ;
            }
        }

        if ( b[i] <= a[1] ) {
            ans += a[1] - b[i] ;
        }
        else {
            ans += min ( abs ( a[left - 1] - b[i] ) , abs ( a[left] - b[i] ) ) ;
        }
    }
}
