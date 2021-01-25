#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

inline int dfs () ;

int main () {
    printf ( "%d" , abs ( dfs () ) ) ;
    return 0 ;
}

inline int dfs () {
    string s ;
    int k , len = 0 , bracket ;
    char c ;

    while ( cin >> c ) {
        if ( c == ']' ) {
            break ;
        }

        cin >> s >> k ;
        if ( c == 'R' ) {
            bracket = getchar () ;
            len += k * dfs () ;
            bracket = getchar () ;
        }
        else if ( c == 'B' ) {
            bracket = getchar () , len -= k ;
        }
        else if ( c == 'F' ) {
            bracket = getchar () , len += k ;
        }
        
        if ( bracket == ']' ) {
            break ;
        }
    }

    return len ;
}
