#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int n , m , k , flag ;
char tmp[100] ;

struct node {
    int x , y ;
} a[10000 + 5] ;

int main () {

    scanf ( "%d %d %d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= k ; i++ ) {
        scanf ( "%d %d" , &a[i].x , &a[i].y ) ;
        gets (tmp) ;
    }

    int flag1 = 0 , flag2 = 0 ;
    for ( int i = 1 ; i <= k ; i++ ) {
        flag1 = flag2 = 0 ;
        for ( int j = 1 ; j <= k ; j++ ) {
            if ( i == j ) {
                continue ;
            }
            if ( a[i].x == a[j].x && a[i].y < a[j].y ) {
                flag1 = 1 ;
            }
            if ( a[i].y == a[j].y && a[i].x > a[j].x ) {
                flag2 = 1 ;
            }
        }

        if ( flag1 && flag2 ) {
            break ;
        }
    }

    if ( ! ( flag1 && flag2 ) ) {
        printf ( "0" ) ;
        exit ( false ) ;
    }

    for ( int i = 1 ; i <= k ; i++ ) {
        for ( int j = 1 ; j <= k ; j++ ) {
            if ( i == j ) {
                continue ;
            }

            flag1 = flag2 = 0 ;
            for ( int l = 1 ; l <= k ; l++ ) {
                if ( l == i || l == j ) {
                    continue ;
                }

                if ( a[j].x == a[l].x && a[j].y < a[l].y ) {
                    flag1 = 1 ;
                }
                if ( a[j].y == a[l].y && a[j].x > a[l].x ) {
                    flag2 = 1 ;
                }
            }

            if ( flag1 && flag2 ) {
                break ;
            }
        }

        if ( ! ( flag1 && flag2 ) ) {
            printf ( "%d\n" , i ) ;
            flag = 1 ;
        }
    }

    if ( !flag ) {
        printf ( "-1" ) ;
    }

    return 0 ;
}
