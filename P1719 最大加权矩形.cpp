#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 150
int n , map[LEN][LEN] , sum[LEN][LEN] , prefix[LEN][LEN] ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            scanf ( "%d" , &map[i][j] ) ;
            prefix[i][j] = prefix[i][j - 1] + map[i][j] ;
            sum[i][j] = prefix[i][j] + sum[i - 1][j] ;
        }
    }

    int ans = INT_MIN ;
    for ( int sx = 1 ; sx <= n ; sx++ ) {
        for ( int sy = 1 ; sy <= n ; sy++ ) {
            for ( int ex = sx ; ex <= n ; ex++ ) {
                for ( int ey = sy ; ey <= n ; ey++ ) {
                    ans = max ( ans , sum[ex][ey] + sum[sx - 1][sy - 1] - sum[ex][sy - 1] - sum[sx - 1][ey] ) ;
                }
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
/*
4
0 -2 -7 0
 9 2 -6 2
-4 1 -4  1 
-1 8  0 -2
*/
