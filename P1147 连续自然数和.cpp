#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int m , tmp1 , tmp2 , tmp3 , tmp4 ;

int main () {

    scanf ( "%d" , &m ) ;

    for ( int n = m ; n >= 2 ; n-- ) {
        tmp1 = m / n , tmp2 = n / 2 ;
        double now = m / ( double ) n ;

        if ( n % 2 == 1 && now == ( int ) now && now * n == m && tmp1 - tmp2 > 0 ) {
            // cout << "# tmp1: " << tmp1 << " tmp2: " << tmp2 << " n: " << n << " now: " << now << endl ;
            printf ( "%d %d\n" , tmp1 - tmp2 , tmp1 + tmp2 ) ;
        }

        now *= 2 ;
        //  && now * n == m
        if ( n % 2 == 0 && now == ( int ) now ) {
            // cout << "I AK IOI!" << endl ;
            int a = now / 2 , b = now / 2 + 1 ;
            a -= tmp2 , a++ ;
            b += tmp2 , b-- ;
            if ( a > 0 && b > 0 && ( a + b ) * n / 2 == m ) {
                printf ( "%d %d\n" , a , b ) ;
            }
        }
    }

    return 0 ;
}
