#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

#define LEN 100100
int n , m , k , x ;
int head , tail , que[LEN] , vis[LEN] , dis[LEN] ;

int main () {

    scanf ( "%d" , &k ) ;
    while ( k-- ) {
        scanf ( "%d %d" , &n , &m ) ;
        memset ( que , 0 , sizeof ( que ) ) ;
        memset ( vis , 0 , sizeof ( vis ) ) ;
        memset ( dis , 0 , sizeof ( dis ) ) ;

        head = tail = 1 , que[++tail] = n , vis[n] = 1 ;
        while ( head <= tail ) {
            head++ ;
            for ( int i = 0 ; i < 3 ; i++ ) {
                x = que[head] ;
                if ( i == 0 ) {
                    x++ ;
                }
                if ( i == 1 ) {
                    x-- ;
                }
                if ( i == 2 ) {
                    x *= 2 ;
                }

                if ( x >= 0 && x <= 100000 ) {
                    if ( ! vis[x] ) {
                        que[++tail] = x ;
                        vis[x] = true ;
                        dis[x] = dis[que[head]] + 1 ;
                    }
                }
            }
        }

        printf ( "%d\n" , dis[m] ) ;
    }

    return 0 ;
}
