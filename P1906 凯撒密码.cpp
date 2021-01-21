#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
using namespace std;

string beginn , s , endn ;
int e , maxn , box[100] , t , flag ;
inline void change ( string &s ) ;
inline int getPos ( string &s ) ;
inline void translate ( string &str , int t ) ;

int main () {

    while ( cin >> beginn ) {
        if ( beginn == "ENDOFINPUT" ) {
            break ;
        }

        getline ( cin , s ) , getline ( cin , s ) ;
        cin >> endn ;
        change (s) ;

        if ( flag == false ) {
            t = getPos (s) ;
            flag = true ;
        }

        translate ( s , t ) ;
        cout << s << endl ;
    }

    return 0 ;
}

inline void change ( string &s ) {
    int len = s.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( s[i] >= 'a' && s[i] <= 'z' ) {
            s[i] -= 32 ;
        }
    }
}

inline int getPos ( string &s ) {
    int len = s.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        box[( int ) s[i]]++ ;
    }

    for ( int i = 'A' ; i <= 'Z' ; i++ ) {
        if ( box[i] > maxn ) {
            maxn = box[i] , e = i ;
        }
    }

    // cout << moven << " " << e << endl ;
    int moven = 'E' - e ;
    return moven ;
}

inline void translate ( string &str , int t ) {
    int len = str.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( 'A' <= str[i] && str[i] <= 'Z' ) {
            str[i] += t ;
            if ( str[i] < 'A' ) {
                str[i] += 26 ;
            }
            if ( str[i] > 'Z' ) {
                str[i] -= 26 ;
            }
        }
    }
}
