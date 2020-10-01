#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#define cal1 ( i - 1 ) / 3 * 3 + ( j - 1 ) / 3 + 1
#define cal2 ( x - 1 ) / 3 * 3 + ( y - 1 ) / 3 + 1
using namespace std;

int map[10][10] , row[10][10] , col[10][10] , district[10][10] ;
inline void init () ;
inline void input () ;
inline void print () ;
inline void dfs ( int x , int y ) ;

int main () {

    init () ;
    input () ;
    dfs ( 1 , 1 ) ;

    return 0 ;
}

inline void init () {
    memset ( row , true , sizeof (row) ) ;
    memset ( col , true , sizeof (col) ) ;
    memset ( district , true , sizeof (district) ) ;
}

inline void input () {
    for ( int i = 1 ; i <= 9 ; i++ ) {
        for ( int j = 1 ; j <= 9 ; j++ ) {
            scanf ( "%d" , &map[i][j] ) ;
            if ( map[i][j] > 0 ) {
                row[i][map[i][j]] = false ;
                col[j][map[i][j]] = false ;
                district[cal1][map[i][j]] = false ;
            }
        }
    }
}

inline void print () {
    for ( int i = 1 ; i <= 9 ; i++ ) {
        for ( int j = 1 ; j <= 9 ; j++ ) {
            printf ( "%d " , map[i][j] ) ;
        }

        printf ( "\n" ) ;
    }
    // cout << "arrived!(1)" ;
    exit(0) ;
}

inline void dfs ( int x , int y ) {
    if ( map[x][y] != 0 ) {
        // cout << 0 ;
        if ( x == 9 && y == 9 ) {
            // cout << "arrived!(2)" ;
            print () ;
        }
        if ( y == 9 ) {
            // cout << 1 ;
            dfs ( x + 1 , 1 ) ;
        }
        else {
            // cout << 2 ;
            dfs ( x , y + 1 ) ;
        }
    }

    if ( map[x][y] == 0 ) {
        for ( int i = 1 ; i <= 9 ; i++ ) {
            // cout << 3 ;
            if ( row[x][i] && col[y][i] && district[cal2][i] ) {
                // cout << 4 ;
                map[x][y] = i ;
                row[x][i] = false ;
                col[y][i] = false ;
                district[cal2][i] = false ;

                if ( x == 9 && y == 9 ) {
                    // cout << "arrived!(3)" ;
                    print () ;
                }
                if ( y == 9 ) {
                    // cout << 4 ;
                    dfs ( x + 1 , 1 ) ;
                }
                else {
                    // cout << 5 ;
                    dfs ( x , y + 1 ) ;
                }

                // cout << 6 ;
                map[x][y] = 0 ;
                row[x][i] = true ;
                col[y][i] = true ;
                district[cal2][i] = true ;
            }
        }
    }
}
