#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

char c[10000 + 5] , ch ;
int minn = INT_MAX , len , tmp , ans ;
inline int check () ;
inline void dfs ( int step ) ;

int main () {

    scanf ( "%s" , c ) ;
    len = strlen(c) ;

    for ( int i = 0 ; i < len - 1 ; i++ ) {
        if ( c[i] != c[i + 1] ) {
            tmp = 1 ;
            break ;
        }
    }

    if ( tmp == 0 ) {
        if ( c[1] == '0' ) {
            puts("1") ;
        }
        else {
            puts("0") ;
        }
        exit(0) ;
    }

    ch = c[len - 1] ;
    
    for ( int i = len - 2 ; i >= 0 ; i-- ) {
        if ( c[i] != ch ) {
            for ( int j = i ; j >= 0 ; j-- ) {
                if ( c[j] == '0' ) {
                    c[j] = '1' ;
                }
                else {
                    c[j] = '0' ;
                }
            }
            ans++ ;
        }
    }

    if ( ch == '0' ) {
        ans++ ;
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
