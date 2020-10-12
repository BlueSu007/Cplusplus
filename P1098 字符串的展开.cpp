#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string s , ans ;
int p1 , p2 , p3 ;

int main () {

    scanf ( "%d %d %d" , &p1 , &p2 , &p3 ) ;
    cin >> s ;
    int len = s.size () ;

    int tmp = 0 ;
    while ( s[tmp] == '-' ) {
        printf ( "%c" , s[tmp] ) ;
        tmp++ ;
    }
    for ( int i = tmp ; i < len ; i++ ) {
        if ( s[i] == '-' ) {
            if ( s[i - 1] >= s[i + 1] ) {
                printf ( "-" ) ;
                continue ;
            }
            else if ( s[i + 1] - s[i - 1] == 1 ) {
                continue ;
            }
            else if (
                ( s[i + 1] >= '0' && s[i - 1] >= '0' && s[i + 1] <= '9' && s[i - 1] <= '9' )
             || ( s[i + 1] >= 'A' && s[i - 1] >= 'A' && s[i + 1] <= 'Z' && s[i - 1] <= 'Z' ) 
             || ( s[i + 1] >= 'a' && s[i - 1] >= 'a' && s[i + 1] <= 'z' && s[i - 1] <= 'z' ) ) {

                char start = ' ' , end = ' ' ;
                int dir = 0 , form = 0 ;
                if ( p3 == 1 ) {
                    start = s[i - 1] + 1 , end = s[i + 1] , dir = 1 ;
                }
                else {
                    start = s[i + 1] - 1 , end = s[i - 1] , dir = -1 ;
                }

                if ( p1 == 1 ) {
                    form = 'a' ;
                }
                else if ( p1 == 2 ) {
                    form = 'A' ;
                }
                else {
                    for ( int j = 1 ; j < s[i + 1] - s[i - 1] ; j++ ) {
                        for ( int k = 1 ; k <= p2 ; k++ ) {
                            printf ( "*" ) ;
                        }
                    }
                    continue ;
                }

                if ( isdigit ( s[i + 1] ) ) {
                    form = '0' ;
                }

                for ( char j = start ; j != end ; j += dir ) {
                    for ( int k = 1 ; k <= p2 ; k++ ) {
                        if ( isdigit ( s[i + 1] ) ) {
                            printf ( "%c" , j - 48 + form ) ;
                            continue ;
                        }
                        printf ( "%c" , j - 97 + form ) ;
                    }
                }
            }
            else {
                printf ( "%c" , s[i] ) ;
            }
        }
        else {
            printf ( "%c" , s[i] ) ;
        }
    }

    return 0 ;
}
