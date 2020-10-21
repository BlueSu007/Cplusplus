#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;

int box[100] ;
char c ;
string a , b ;
map < char , char > pam ;

int main () {

    getline ( cin , a ) ;
    getline ( cin , b ) ;
    int len = a.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( a[i] > 'Z' || a[i] < 'A' || b[i] > 'Z' || b[i] < 'A' ) {
            continue ;
        }
        if ( pam[a[i]] != 0 ) {
            if ( pam[a[i]] == b[i] ) {
                continue ;
            }
            // cout << 1 << endl ;
            printf ( "Failed" ) ;
            exit ( false ) ;
        }
        pam[a[i]] = b[i] ;
    }

    map < char , char > :: iterator it ;
    for ( it = pam.begin () ; it != pam.end () ; it++ ) {
        int x = ( it -> second ) - 'A' + 1 ;
        box[x] ++ ;
        if ( box[x] > 1 ) {
            // cout << 1 ;
            printf ( "Failed" ) ;
            exit ( false ) ;
        }
    }

    for ( int i = 1 ; i <= 26 ; i++ ) {
        if ( !box[i] ) {
            // cout << 2 ;
            printf ( "Failed" ) ;
            exit ( false ) ;
        }
    }

    getline ( cin , a ) ;
    len = a.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        printf ( "%c" , pam[a[i]] ) ;
    }

    return 0 ;
}
