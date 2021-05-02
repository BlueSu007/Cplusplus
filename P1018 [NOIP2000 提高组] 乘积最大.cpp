#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
using namespace std;

#define LEN 100
int n , m , a[LEN] ;
string s ;

struct HighPrecision {
    int len , num[LEN] ;
} dp[LEN][LEN / 10] ;

inline HighPrecision calculate ( HighPrecision x , int leftn , int rightn ) ;
inline HighPrecision maxn ( HighPrecision x , HighPrecision y ) ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    cin >> s ;
    for ( int i = 1 ; i <= n ; i++ ) {
        a[i] = s[i - 1] - '0' ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = i ; j >= 1 ; j-- ) {
            dp[i][0].num[++dp[i][0].len] = a[j] ;
        }
    }

    for ( int i = 2 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= min ( m , i - 1 ) ; j++ ) {
            for ( int k = j ; k < i ; k++ ) {
                dp[i][j] = maxn ( dp[i][j] , calculate ( dp[k][j - 1] , k + 1 , i ) ) ;
            }
        }
    }

    for ( int i = dp[n][m].len ; i >= 1 ; i-- ) {
        printf ( "%d" , dp[n][m].num[i] ) ;
    }

    return 0 ;
}

inline HighPrecision calculate ( HighPrecision x , int leftn , int rightn ) {
    HighPrecision ans , y ;
    memset ( ans.num , 0 , sizeof ( ans.num ) ) ;
    memset ( y.num , 0 , sizeof ( y.num ) ) ;

    y.len = rightn - leftn + 1 ;
    for ( int i = rightn ; i >= leftn ; i-- ) {
        y.num[rightn - i + 1] = a[i] ;
    }

    int len1 = x.len , len2 = y.len , maxLen ;
    for ( int i = 1 ; i <= len1 ; i++ ) {
        for ( int j = 1 ; j <= len2 ; j++ ) {
            ans.num[i + j - 1] += x.num[i] * y.num[j] ;
        }
    }

    maxLen = len1 + len2 - 1 ;
    for ( int i = 1 ; i <= maxLen ; i++ ) {
        ans.num[i + 1] += ans.num[i] / 10 ;
        ans.num[i] %= 10 ;
    }

    if ( ans.num[maxLen + 1] ) {
        maxLen++ ;
    }

    ans.len = maxLen ;
    return ans ;
}

inline HighPrecision maxn ( HighPrecision x , HighPrecision y ) {
    int len1 = x.len , len2 = y.len ;
    if ( len1 < len2 ) {
        return y ;
    }
    if ( len1 > len2 ) {
        return x ;
    }

    for ( int i = len1 ; i >= 1 ; i-- ) {
        if ( x.num[i] > y.num[i] ) {
            return x ;
        }
        if ( x.num[i] < y.num[i] ) {
            return y ;
        }
    }

    return x ;
}
