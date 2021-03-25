#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 100
int n , d , b , a[LEN] , cnt , maxn ;
inline int check ( int x , int y ) ;

int main () {

    scanf ( "%d %d %d" , &n , &b , &d ) ;
    maxn = 1 << b , cnt++ ;
    
    while ( cnt < n ) {
        for ( int i = a[cnt] + 1 ; i <= maxn ; i++ ) {
            if ( check ( a[cnt] , i ) >= d ) {
                int flag = true ;
                for ( int j = 1 ; j < cnt ; j++ ) {
                    if ( check ( a[j] , i ) < d ) {
                        flag = false ;
                        break ;
                    }
                }

                if ( flag ) {
                    a[++cnt] = i ;
                    break ;
                }
            }
        }
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        printf ( "%d " , a[i] ) ;
        if ( i % 10 == 0 ) {
            printf ( "\n" ) ;
        }
    }

    return 0 ;
}

inline int check ( int x , int y ) {
    int qwq = x ^ y , ans = 0 ;
    while ( qwq != 0 ) {
        if ( qwq % 2 ) {
            ans++ ;
        }
        qwq /= 2 ;
    }
    return ans ;
}
