#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

#define LEN 3005
#define HASH 51971
#define MOD 2005091020050911

int n ;
char a[LEN] , b[LEN] ;
long long hashn[LEN * LEN] ;

int main () {

    scanf ( "%d %s %s" , &n , a + 1 , b + 1 ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        long long tmp = 0 , pos = 1 ;
        for ( int j = i ; j <= n ; j++ ) {
            while ( pos <= n && a[pos] != b[j] ) {
                pos++ ;
            }
            if ( pos > n ) {
                break ;
            }
            pos++ ;

            tmp = ( tmp * HASH + b[j] - 'a' + 1 ) % MOD ;
            hashn[++hashn[0]] = tmp ;
        }
    }

    sort ( hashn + 1 , hashn + 1 + hashn[0] ) ;
    printf ( "%d" , unique ( hashn + 1 , hashn + hashn[0] + 1 ) - hashn - 1 ) ;

    return 0 ;
}
