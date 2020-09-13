#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int tmp[10] , n ;
inline void dfs ( int step , int sum , int lastNumber ) ;

int main () {

    scanf ( "%d" , &n );
    dfs ( 0 , 0 , 1 ) ;

    return 0 ;
}

inline void dfs ( int step , int sum , int lastNumber ) {
    if ( sum >= n ) {
        if ( sum == n && step > 1 ) {
            printf ( "%d" , tmp[1] ) ;
            for ( int i = 2 ; i <= step ; i++ ) {
                printf ( "+%d" , tmp[i] ) ;
            }
            printf ( "\n" ) ;           
        }

        return ;
    }

    for ( int i = lastNumber ; i <= n - sum ; i++ ) {
        // if ( i != lastNumber ) {
        tmp[step + 1] = i ;
        dfs ( step + 1 , sum + i , i ) ;
        // }
    }
}
