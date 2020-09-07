#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , sumTime , sumPeanut , ans , cnt = 1 ;
int a[1000 + 5][1000 + 5] ;

struct peanut {
    int x ;
    int y ;
    int timen ;
    int number ;
} sorted[1000000 + 5] ;

inline bool cmp ( peanut x , peanut y ) {
    return x.number > y.number ;
}

int main () {

    scanf ( "%d %d %d" , &n , &m , &sumTime ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= m ; j++ ) {
            scanf ( "%d" , &a[i][j] ) ;
            if ( a[i][j] > 0 ) {
                sorted[cnt].number = a[i][j] ;
                sorted[cnt].x = i , sorted[cnt].y = j ;
                cnt++ ;
            }
        }
    }

    for ( int i = 1 ; i < cnt ; i++ ) {
        for ( int j = i + 1 ; j <= cnt ; j++ ) {
            if ( sorted[i].number < sorted[j].number ) {
                swap ( sorted[i] , sorted[j] ) ;
            }
        }
    }
    // sort ( sorted + 1 , sorted + 1 + cnt , cmp ) ;

    for ( int i = 1 ; i <= cnt ; i++ ) {
        int tmp = sorted[i].x ;
        if ( i == 1 ) {
            sorted[i].timen = sorted[i].x + 1 ;
        }
        else {
            sorted[i].timen = sorted[i - 1].timen + abs ( sorted[i].x - sorted[i - 1].x ) + abs ( sorted[i].y - sorted[i - 1].y ) + 1 ;
        }

        if ( sorted[i].timen + tmp <= sumTime ) {
            ans += sorted[i].number ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
