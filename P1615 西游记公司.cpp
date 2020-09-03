#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

long long sec1 , sec2 , n , cnt ; // ( sec2 - sec1 ) * n
long long power , tmp , now ; // tmp += pow ( 10 , power ) * now ;
char c ; // character cache
string s1 , s2 ;

int main () {

    cin >> s1 >> s2 >> n ;
    int len1 = s1.size () ;
    int len2 = s2.size () ;

    for ( int i = len1 - 1 ; i >= 0 ; i-- ) {
        c = s1[i] ;
        if ( c == ':' ) {
            cnt++ ;
            if ( cnt == 1 ) {
                sec1 += tmp ;
            }
            else {
                sec1 += ( tmp * 60 ) ;
            }
            tmp = 0 , now = 0 , power = 0 ;
            continue ;
        }
        now = c - '0' ;
        tmp += pow ( 10 , power ) * now ;
        power++ ;
    }

    sec1 += ( tmp * 3600 ) ;
    cnt = 0 , now = 0 , power = 0 , tmp = 0 ;

    for ( int i = len2 - 1 ; i >= 0 ; i-- ) {
        c = s2[i] ;
        if ( c == ':' ) {
            cnt++ ;
            if ( cnt == 1 ) {
                sec2 += tmp ;
            }
            else {
                sec2 += ( tmp * 60 ) ;
            }
            tmp = 0 , now = 0 , power = 0 ;
            continue ;
        }
        now = c - '0' ;
        tmp += pow ( 10 , power ) * now ;
        power++ ;
    }
    sec2 += ( tmp * 3600 ) ;

    printf ( "%lld" , ( sec2 - sec1 ) * n ) ;

    return 0 ;
}
