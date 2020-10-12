#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int ans , n , a[100] , b[100] ;
inline bool qaq ( int num , int flag ) ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a[i] ) ;
        b[a[i]] = 1 ;
    }

    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        for ( int j = 1 ; j <= n ; j++ ) {
            for ( int k = 1 ; k <= n ; k++ ) {
                for ( int l = 1 ; l <= n ; l++ ) {
                    int num1 = a[i] * 100 + a[j] * 10 + a[k] ;
                    if ( !qaq ( num1 * a[l] , 0 ) ) {
                        continue ;
                    }

                    for ( int m = 1 ; m <= n ; m++ ) {
                        if ( !qaq ( num1 * a[m] , 0 ) ) {
                            continue ;
                        }
                        int num2 = a[l] * 10 + a[m] ;
                        if ( !qaq ( num1 * num2 , 1 ) ) {
                            continue ;
                        }
                        ans++ ;
                    }
                }
            }
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline bool qaq ( int num , int flag ) {
    if ( flag && ( num < 1000 || num > 9999 ) ) {
        return false ;
    }
    else if ( !flag && ( num < 100 || num > 999 ) ) {
        return false ;
    }

    while ( num ) {
        if ( b[num % 10] ) {
            num /= 10 ;
        }
        else {
            return false ;
        }
    }

    return true ;
}
