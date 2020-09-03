#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int n , m , x , y , sx , sy , ex , ey ;
int a , b ;

struct boom {
    int count ; // how many boom
    int number ; // the last round boom's id
} map[100 + 5][100 + 5] ;

int main () {

    scanf ( "%d %d %d %d" , &n , &m , &x , &y ) ;
    for ( int i = 1 ; i <= x ; i++ ) {
        scanf ( "%d %d %d %d" , &sx , &sy , &ex , &ey ) ;
        for ( int j = sx ; j <= ex ; j++ ) {
            for ( int k = sy ; k <= ey ; k++ ) {
                map[j][k].count++ ;
                map[j][k].number = i ;
            }
        }
    }

    while ( y-- ) {
        scanf ( "%d %d" , &a , &b ) ;
        if ( map[a][b].count == 0 ) {
            printf ( "N\n" ) ;
            continue ;
        }
        printf ( "Y %d %d\n" , map[a][b].count , map[a][b].number ) ;
    }

    return 0 ;
}
