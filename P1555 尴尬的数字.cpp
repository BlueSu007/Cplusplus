#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string bit , three ;
inline bool check ( string str ) ;
inline int twoToTen ( string two ) ;
inline string tenToThree ( int num ) ;

int main () {

    cin >> bit >> three ;
    int len = bit.size () ;

    for ( int i = 0 ; i < len ; i++ ) {
        if ( i == 0 && bit[i] == '0' || i != 0 ) {
            bit[i] = 48 + ! ( bit[i] - 48 ) ;
            int tmp = twoToTen ( bit ) ;
            string tmp2 = tenToThree ( tmp ) ;
            // cout << bit << " " << tmp << " " << tmp2 << endl ;

            if ( check ( tmp2 ) ) {
                printf ( "%d" , tmp ) ;
                exit ( false ) ;
            }
            bit[i] = 48 + ! ( bit[i] - 48 ) ;
        }
    }

    return 0 ;
}

inline int twoToTen ( string two ) {
    int ans = 0 , len = two.size () ;
    reverse ( two.begin () , two.end () ) ;

    for ( int i = 0 ; i < len ; i++ ) {
        ans += pow ( 2 , i ) * ( two[i] - '0' ) ;
    }
    return ans ;
}

inline string tenToThree ( int num ) {
    string s = "" ;
    while ( num ) {
        s += ( num % 3 ) + '0' ;
        num /= 3 ;
    }

    reverse ( s.begin () , s.end () ) ;
    return s ;
}

inline bool check ( string str ) {
    int cnt = 0 , len = str.size () ;
    for ( int i = 0 ; i < len ; i++ ) {
        if ( str[i] != three[i] ) {
            cnt++ ;
        }
        if ( cnt > 1 ) {
            return false ;
        }
    }
    
    return true ;
}
