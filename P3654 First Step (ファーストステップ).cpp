#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int r , c , k , ans ;
char a[100 + 5][100 + 5] ;
const int dx[2] = { 0 , 1 } ;
const int dy[2] = { 1 , 0 } ;
inline void dfs ( int x , int y , int i , int step ) ;

int main () {

    scanf ( "%d %d %d" , &r , &c , &k ) ;
    for ( int i = 1 ; i <= r ; i++ ) {
        scanf ( "%s" , a[i] + 1 ) ;
    }

    for ( int i = 1 ; i <= r ; i++ ) {
        for ( int j = 1 ; j <= c ; j++ ) {
            if ( a[i][j] == '.' ) {
                for ( int k = 0 ; k < 2 ; k++ ) {
                    dfs ( i , j , k , 1 ) ;
                }
            }
        }
    }

    if ( k == 1 ) {
        ans /= 2 ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void dfs ( int x , int y , int i , int step ) {
    if ( step > k ) {
        ans++ ;
        return ;
    }

    if ( a[x][y] != '.' || x < 1 || y < 1 || x > r || y > c ) {
        return ;
    }

    dfs ( x + dx[i] , y + dy[i] , i , step + 1 ) ;
    return ;
}
