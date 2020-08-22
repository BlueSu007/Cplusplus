#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , m = 1 , ans ;
char c , ch ;

int main () {

    while ( true ) {
        scanf ( "%lld" , &n ) ;
        if ( scanf ( "%c" , &c ) != 1 ) {
            ans += m ;
            ans %= 10000 ;
            break ;
        }

        if ( ch == '*' ) {
            m *= n ;
            m %= 10000 ;
        }
        else if ( ch == '+' ) {
            ans += m ;
            ans %= 10000 ;
            m = n ;
        }
        else {
            m = n ;
        }
        ch = c ;
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
