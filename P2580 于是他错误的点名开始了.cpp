#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;

map < string , int > pam ;
int n , m ;
string s ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> s ;
        pam[s]++ ;
    }
    scanf ( "%d" , &m ) ;
    for ( int j = 1 ; j <= m ; j++ ) {
        cin >> s ;
        pam[s]++ ;

        if ( pam[s] == 2 ) {
            printf ( "OK\n" ) ;
        }
        else if ( pam[s] > 2 ) {
            printf ( "REPEAT\n" ) ;
        }
        else if ( pam[s] == 1 ) {
            printf ( "WRONG\n" ) ;
        }
    }

    return 0 ;
}
