#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 205
int n , a[LEN] , minn[LEN][LEN] , maxn[LEN][LEN] ;
int ansMax , ansMin = INT_MAX , sum[LEN] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        a[i + n] = a[i] ;
    }

    for ( int i = 1 ; i <= 2 * n ; i++ ) {
        sum[i] = sum[i - 1] + a[i] ;
    }

    for ( int len = 2 ; len <= n ; len++ ) {
        for ( int leftn = 1 ; leftn + len - 1 <= 2 * n ; leftn++ ) {
            int rightn = leftn + len - 1 ;
            minn[leftn][rightn] = INT_MAX ;
            for ( int k = leftn ; k < rightn ; k++ ) {
                maxn[leftn][rightn] = max ( maxn[leftn][rightn] , maxn[leftn][k] + maxn[k + 1][rightn] + sum[rightn] - sum[leftn - 1] ) ;
                minn[leftn][rightn] = min ( minn[leftn][rightn] , minn[leftn][k] + minn[k + 1][rightn] + sum[rightn] - sum[leftn - 1] ) ;
            }

            if ( len == n ) {
                ansMax = max ( ansMax , maxn[leftn][rightn] ) ;
                ansMin = min ( ansMin , minn[leftn][rightn] ) ;
            }
        }
    }

    printf ( "%d\n%d" , ansMin , ansMax ) ;

    return 0 ;
}
