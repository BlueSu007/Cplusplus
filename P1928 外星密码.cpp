#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

inline string qwq () ;

int main () {

    cout << qwq () ;
    return 0 ;
}

inline string qwq () {
    int n ;
    char c ;
    string s = "" , ans = "" ;
    
    while ( cin >> c ) {
        if ( c == '[' ) {
            cin >> n ;
            s = qwq () ;
            while ( n-- ) {
                ans += s ;
            }
        }
        else {
            if ( c == ']' ) {
                return ans ;
            }
            else {
                ans += c ;
            }
        }
    }
}
