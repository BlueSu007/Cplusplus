#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int a[1000 + 5] , b[1000 + 5][1000 + 5] ;
int record[1000 + 5] , ans[1000 + 5] ;
int minn = INT_MAX , n , m ;
inline void inputArray () ;
inline void copyArray ( int x ) ;
inline bool judgeBigger ( int x ) ;
inline void dfs ( int sum , int calculator ) ;
inline void outputArray () ;

int main() {

    inputArray () ;
    // cout << 1 << endl ;
    dfs ( 1 , 0 ) ;
    // cout << 2 << endl ;
    outputArray () ;

    return 0 ;
}

inline void inputArray () {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
    }

    scanf ( "%d" , &m ) ;
    for ( int i = 1 ; i <= m ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &b[i][j] ) ;
        }
    }
}

inline void copyArray ( int x ) {
    for ( int i = 1 ; i <= x ; i++ ) {
        ans[i] = record[i] ;
    }
}

inline bool judgeBigger ( int x ) {
    for ( int i = 1 ; i <= n ; i++ ) {
        int cnt = 0 ;
        for ( int j = 1 ; j <= x ; j++ ) {
            cnt += b[record[j]][i] ;
        }

        if ( cnt < a[i] ) {
            return false ;
        }
    }

    return true ;
}

inline void dfs ( int sum , int calculator ) {
    if ( calculator > m ) {
        if ( judgeBigger ( sum ) && sum < minn ) {
            minn = sum ;
            copyArray ( minn ) ;
        }

        return ;
    }

    record[sum + 1] = calculator ;
    dfs ( sum + 1 , calculator + 1 ) ;
    record[sum + 1] = calculator ;
    dfs ( sum , calculator + 1 ) ;
}

inline void outputArray () {
    // printf ( "\n" ) ;
    printf ( "%d" , minn - 1 ) ;
    for ( int i = 2 ; i <= minn ; i++ ) {
        printf ( " %d" , ans[i] ) ;
    }
}
