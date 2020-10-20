#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , a[100000 + 5] ;
int ans , leftn , rightn , mid ;
inline bool check ( int x ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        leftn = max ( leftn , a[i] ) ;
        rightn += a[i] ;
    }

    while ( leftn <= rightn ) {
        mid = ( leftn + rightn ) / 2 ;
        if ( check ( mid ) ) {
            leftn = mid + 1 ;
        }
        else {
            rightn = mid - 1 ;
        }
    }

    printf ( "%d" , leftn ) ;

    return 0 ;
}

inline bool check ( int x ) {
    int cnt = 0 , sum = 0 ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i] + sum <= x ) {
            sum += a[i] ;
        }
        else {
            sum = a[i] , cnt++ ;
        }
    }

    return cnt >= m ;
}
