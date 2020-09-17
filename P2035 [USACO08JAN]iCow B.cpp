#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

struct music {
    int value ;
    int id ;
} r[1000 + 5] ;

int n , t , maxn , maxid = 1000 + 5 ;
map < int , int > pam ;

int main () {

    scanf ( "%d %d" , &n , &t ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &r[i].value ) ;
        r[i].id = i ;
    }

    while ( t-- ) {
        // for ( int i = 1 ; i <= n ; i++ ) {
        //     printf ( " %d: %d\t" , r[i].id , r[i].value ) ;
        // }
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( r[i].value >= maxn ) {
                if ( r[i].value == maxn ) {
                    maxid = min ( maxid , r[i].id ) ;
                }
                else {
                    maxn = r[i].value ;
                    maxid = r[i].id ;                    
                }
            }
        }   

        printf ( "%d\n" , maxid ) ;
        int tmp = maxn / ( n - 1 ) ;
        maxn = 0 ;

        for ( int i = 1 ; i <= n ; i++ ) {
            if ( i == maxid ) {
                continue ;
            }
            r[i].value += tmp ;
            r[maxid].value -= tmp ;
        }

        for ( int i = 1 ; i <= n && r[maxid].value ; i++ ) {
            if ( i == maxid ) {
                continue ;
            }
            r[i].value++ ;
            r[maxid].value-- ;
        }
    }

    return 0 ;
}
