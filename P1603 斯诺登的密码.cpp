#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
using namespace std ;

int cnt , a[10] ;
string s ;
map < string , int > pam ;
inline void init () ;

int main () {

    init() ;
    for ( int i = 1 ; i <= 6 ; i++ ) {
        cin >> s ;
        // cout << s << " " << pam[s] << " " ;
        a[i] = pam[s] * pam[s] % 100 ;
    }

    sort ( a + 1 , a + 7 ) ;

    for ( int i = 1 ; i <= 6 ; i++ ) {
        if ( a[i] == 0 ) {
            if ( i == 6 ) {
                cout << 0 ;
            }
            continue ;
        }
        if ( a[i] < 10 && a[i - 1] ) {
            cout << '0' ;
        }
        cout << a[i] ;
    }

    return 0 ;
}

inline void init () {
    pam["one"] = 1 ;
    pam["two"] = 2 ;
    pam["three"] = 3 ;
    pam["four"] = 4 ;
    pam["five"] = 5 ;
    pam["six"] = 6 ;
    pam["seven"] = 7 ;
    pam["eight"] = 8 ;
    pam["nine"] = 9 ;
    pam["ten"] = 10 ;
    pam["eleven"] = 11 ;
    pam["twelve"] = 12 ;
    pam["thirteen"] = 13 ;
    pam["fourteen"] = 14 ;
    pam["fifteen"] = 15 ;
    pam["sixteen"] = 16 ;
    pam["seventeen"] = 17 ;
    pam["eighteen"] = 18 ;
    pam["nineteen"] = 19 ;
    pam["twenty"] = 20 ;

    pam["a"] = 1 ;
    pam["both"] = 2 ;
    pam["another"] = 1 ;
    pam["first"] = 1 ;
    pam["second"] = 2 ;
    pam["third"] = 3 ;
}
