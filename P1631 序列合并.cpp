#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int n , a[100000 + 5] , b[100000 + 5] ;
priority_queue < int , vector < int > , greater < int > > que ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }
    for ( int j = 1 ; j <= n ; j++ ) {
        scanf ( "%d" , &b[j] ) ;
    }

    int len = sqrt (n) ;
    for ( int i = 1 ; i <= len ; i++ ) {
        // 1.
        for ( int j = i ; j <= n / i ; j++ ) {
            que.push ( a[j] + b[i] ) ;
        }
        // 2.
        for ( int j = i + 1 ; j <= n / i ; j++ ) {
            que.push ( a[i] + b[j] ) ;
        }
        /*
        -------------------------
        | 1 | 1 | 1 | 1 | 1 | 1 |
        -------------------------
        | 2 | 1 | 1 | 1 | 1 | 1 |
        -------------------------
        | 2 | 2 | 1 | 1 | 1 | 1 |
        -------------------------
        | 2 | 2 | 2 |   |   |   |
        ----------------.....----
        | 2 | 2 | 2 |   .....   |
        ----------------.....----
        | 2 | 2 | 2 |   |   |   |
        -------------------------
        */
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , que.top () ) ;
        que.pop () ;
    }

    return 0 ;
}
