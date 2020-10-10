#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

long long a , b , f , n , tmp ;
string s ;

int main () {

    cin >> s >> b ;
    int len = s.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        a = s[i] - '0' ;
        n *= 10 , n += a ;
        f = n / b ;
        n %= b ;

        if ( tmp || f ) {
            tmp = 1 ;
            printf ( "%lld" , f ) ;
        }
    }

    return 0 ;
}
