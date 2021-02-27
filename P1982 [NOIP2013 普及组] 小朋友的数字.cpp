#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 10000005
long long a[LEN] , dp[LEN] , qwq[LEN] , score[LEN] , ans ;
long long n , p , nowMax , sum , tmp ;

int main () {

    // freopen ( "P1982_9.in.txt" , "r" , stdin ) ;
    scanf ( "%lld %lld" , &n , &p ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%lld" , &a[i] ) ;
    }

    nowMax = dp[1] = qwq[1] = score[1] = a[1] ;
    sum = max ( a[1] , 0LL ) ;

    int flag = ( a[1] > 0 ) ;
    for ( int i = 2 ; i <= n ; i++ ) {
        dp[i] = max ( dp[i - 1] + a[i] , a[i] ) ;
        qwq[i] = max ( dp[i] , qwq[i - 1] ) , sum += a[i] ;

        nowMax = max ( nowMax , sum ) ;
        if ( i == 2 ) {
            score[i] = ( score[1] + qwq[1] ) % p ;
        }
        else {
            score[i] = score[i - 1] + max ( qwq[i - 1] , 0LL ) ;
            score[i] %= p ;

            if ( qwq[i - 1] > 0 ) {
                tmp += qwq[i - 1] ;
                if ( tmp + score[1] >= 0 ) {
                    flag = true ;
                }
            }
        }
    }

    if ( ! flag ) {
        printf ( "%lld" , score[1] % p ) ;
    }
    else {
        printf ( "%lld" , score[n] ) ;
    }

    return 0 ;
}
