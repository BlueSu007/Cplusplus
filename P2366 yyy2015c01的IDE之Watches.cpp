#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
#include <string>
using namespace std;

map < string , int > pam ;
string s , a ;
int n , x ;
inline int changeInt ( string s ) ;

int main () {

    scanf ( "%d" , &n ) ;
    while ( n-- ) {
        cin >> s ;
        s.erase ( s.size () - 1 , 1 ) ;
        x = s.find ( '=' ) ;
        a = s.substr ( 0 , x ) ;
        s.erase ( 0 , x + 1 ) ;
        x = s.find ( '+' ) ;

        if ( x >= 0 && x < s.size () ) {
            if ( s[0] >= 'a' && s[0] <= 'z' ) {
                pam[a] = pam[s.substr ( 0 , x )] ;
            }
            else {
                pam[a] = changeInt ( s.substr ( 0 , x ) ) ;
            }

            s.erase ( 0 , x + 1 ) ;

            if ( s[x + 1] >= 'a' && s[x + 1] <= 'z' ) {
                pam[a] += pam[s] ;
            }
            else {
                pam[a] += changeInt (s) ;
            }
        }
        else {
            if ( s[0] >= 'a' && s[0] <= 'z' ) {
                pam[a] = pam[s] ;
            }
            else {
                pam[a] = changeInt (s) ;
            }
        }
    }

    map < string , int > :: iterator it ;
    for ( it = pam.begin () ; it != pam.end () ; it++ ) {
        cout << ( it -> first ) << " " << ( it -> second ) << endl ;
    }

    return 0 ;
}

inline int changeInt ( string s ) {
    int len = s.size () , tmp = 0 ;
    for ( int i = 0 ; i < len ; i++ ) {
        tmp = tmp * 10 + ( s[i] - '0' ) ;
    }
    return tmp ;
}
