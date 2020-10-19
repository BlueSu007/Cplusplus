#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

char s[10000] , c ;
int x , ans , f , j ;

int main () {

    while ( gets (s) ) {

        int len = strlen (s) , ans = 0 ;
        bool flag = false ;

        for ( int i = 0 ; i < len ; i++ ) {
            if ( isdigit ( s[i] ) ) {
                flag = true ;
            }

            x = 0 , j = i ;
            while ( isdigit ( s[i] ) ) {
                x = x * 10 + ( s[i++] - '0' ) ;
            }

            if ( j > 1 && isdigit ( s[j - 2] ) ) {
                ans += x ;
            }
            else {
                if ( j > 0 && s[j - 1] == '-' ) {
                    ans -= x ;
                }
                else {
                    ans += x ;
                }
            }
        }

        if ( flag == true ) {
            printf ( "%d\n" , ans ) ;
        }
    }

    return 0 ;
}
