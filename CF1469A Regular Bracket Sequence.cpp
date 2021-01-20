#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int k , flag , cnt , tmp ;
string s ;

int main () {

    scanf ( "%d" , &k ) ;
    while ( k-- ) {
        cin >> s ;
        int len = s.size () ;
        if ( s[0] != ')' && s[len - 1] != '(' && len % 2 == 0 ) {
            printf ( "Yes\n" ) ;
        }
        else {
            printf ( "No\n" ) ;
        }
    }

    return 0 ;
}
