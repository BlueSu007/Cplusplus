#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <map>
using namespace std;

char c[1000] , cpy[1000] ;
string s ;
map < string , int > pam ;

int main () {

    scanf ( "%s" , &c ) ;
    int len = strlen (c) ;
    pam["000"] = 0 , pam["001"] = 1 , pam["010"] = 2 , pam["011"] = 3 ;
    pam["100"] = 4 , pam["101"] = 5 , pam["110"] = 6 , pam["111"] = 7 ;

    int tmp = 0 ;
    if ( len % 3 ) {
        tmp = ( 3 - ( len % 3 ) ) % 3 ;
    }

    for ( int i = 1 ; i <= tmp ; i++ ) {
        cpy[i] = '0' ;
    }
    for ( int i = tmp + 1 ; i <= tmp + len ; i++ ) {
        cpy[i] = c[i - tmp - 1] ;
    }

    for ( int i = 1 ; i <= tmp + len ; i += 3 ) {
        s = "" ;
        for ( int j = i ; j <= i + 2 ; j++ ) {
            s += cpy[j] ;
        }

        printf ( "%d" , pam[s] ) ;
    }

    return 0 ;
}
