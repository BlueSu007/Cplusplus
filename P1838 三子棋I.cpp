#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char c ;
int a , map[3 + 5][3 + 5] , cnt ;

int main () {

    while ( cin >> c ) {
        a = c - '0' ;
        cnt++ ;
        if ( a < 4 ) {
            map[1][a] = cnt % 2 + 1 ;
        }
        else if ( a < 7 ) {
            if ( a % 3 == 0 ) {
                map[2][3] = cnt % 2 + 1 ;
                continue ;
            }
            map[2][a % 3] = cnt % 2 + 1 ;
        }
        else if ( a < 10 ) {
            if ( a % 3 == 0 ) {
                map[3][3] = cnt % 2 + 1 ;
                continue ;
            }
            map[3][a % 3] = cnt % 2 + 1 ;
        }
    }

    /*
    for ( int i = 1 ; i <= 3 ; i++ ) {
        for ( int j = 1 ; j <= 3 ; j++ ) {
            cout << map[i][j] << " " ;
        }
        cout << endl ;
    }
    */

    for ( int i = 1 ; i <= 3 ; i++ ) {
        if ( map[i][2] == map[i][1] && map[i][2] == map[i][3] ) {
            if ( map[i][2] == 1 ) {
                printf ( "uim wins." ) ;
                exit(0) ;
            }
            else {
                printf ( "xiaoa wins." ) ;
                exit(0) ;
            }
        }

        if ( map[2][i] == map[1][i] && map[2][i] == map[3][i] ) {
            if ( map[2][i] == 1 ) {
                printf ( "uim wins." ) ;
                exit(0) ;
            }
            else {
                printf ( "xiaoa wins." ) ;
                exit(0) ;
            }
        }
    }

    if ( ( map[2][2] == map[1][1] && map[2][2] == map[3][3] ) || ( map[2][2] == map[1][3] && map[2][2] == map[3][1] ) ) {
        if ( map[2][2] == 1 ) {
            printf ( "uim wins." ) ;
            exit(0) ;
        }
        else {
            printf ( "xiaoa wins." ) ;
            exit(0) ;
        }
    }

    printf ( "drew." ) ;

    return 0 ;
}
