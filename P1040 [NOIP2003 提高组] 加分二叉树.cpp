#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 50
int n , a[LEN] , root[LEN][LEN] ;
long long dp[LEN][LEN] ;
inline long long dfs ( int leftBound , int rightBound ) ;
inline void print ( int leftBound , int rightBound ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        dp[i][i] = a[i] ;
        root[i][i] = i ;
    }

    printf ( "%d\n" , dfs ( 1 , n ) ) ;
    print ( 1 , n ) ;

    return 0 ;
}

inline long long dfs ( int leftBound , int rightBound ) {
    if ( leftBound > rightBound ) {
        return 1 ;
    }

    if ( dp[leftBound][rightBound] ) {
        return dp[leftBound][rightBound] ;
    }

    for ( int i = leftBound ; i <= rightBound ; i++ ) {
        long long tmp = dfs ( leftBound , i - 1 ) * dfs ( i + 1 , rightBound ) + a[i] ;
        if ( dp[leftBound][rightBound] < tmp ) {
            dp[leftBound][rightBound] = tmp ;
            root[leftBound][rightBound] = i ;
        }
    }

    return dp[leftBound][rightBound] ;
}

inline void print ( int leftBound , int rightBound ) {
    if ( leftBound > rightBound ) {
        return ;
    }

    printf ( "%d " , root[leftBound][rightBound] ) ;
    print ( leftBound , root[leftBound][rightBound] - 1  ) ;
    print ( root[leftBound][rightBound] + 1 , rightBound ) ;
}
