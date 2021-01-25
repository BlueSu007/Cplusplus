#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

#define LEN 210
int p , n , m , len , dp[LEN][LEN] , sum[LEN][LEN] ;
string s = " " , a[LEN] ;
inline void init () ;
inline bool check ( int leftn , int rightn ) ;
inline void work () ;

int main () {

    init () ; 
    work () ;

    return 0 ;
}

inline void init () {
    string tmp ;
    scanf ( "%d %d" , &p , &m ) ;
    for ( int i = 1 ; i <= p ; i++ ) {
        cin >> tmp ;
        s += tmp ;
    }

    scanf ( "%d" , &n ) ;
    len = s.size () ;

    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i] ;
    }

    for ( int i = len - 1 ; i >= 1 ; i-- ) {
        for ( int j = i ; j >= 1 ; j-- ) {
            sum[j][i] = sum[j + 1][i] ;
            if ( check ( j , i ) ) {
                sum[j][i]++ ;
            }
        }
    }
}

inline bool check ( int leftn , int rightn ) {
    string tmp = s.substr ( leftn ,  rightn - leftn + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        if ( tmp.find ( a[i] ) == false ) {
            return true ;
        }
    }

    return false ;
}

inline void work () {
    for ( int i = 1 ; i <= m ; i++ ) {
        dp[i][i] = dp[i - 1][i - 1] + sum[i][i] ;
    }

    for ( int i = 1 ; i < len ; i++ ) {
        dp[i][1] = sum[1][i] ;
    }
    
    for ( int i = 1 ; i < len ; i++ ) {
        for ( int j = 1 ; j <= m && j < i ; j++ ) {
            for ( int k = j ; k < i ; k++ ) {
                dp[i][j] = max ( dp[i][j] , dp[k][j - 1] + sum[k + 1][i] ) ;
            }
        }
    }

    printf ( "%d" , dp[len - 1][m] ) ;
}
