#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;

string a ;
int len ;
inline bool check ( int x ) ;

int main () {

    cin >> len >> a ;

    for ( int i = 1 ; i <= len ; i++ ) {
        if ( check(i) ) {
            cout << i << endl ;
            break ;
        }
    }

    return 0 ;
}

inline bool check ( int x ) {
    for ( int i = 0 ; i <= len - x ; i++ ) {
        int num = 0 ;
        string s = a.substr ( i , x ) ;

        for ( int j = 0 ; j <= len - x ; j++ ) {
            if ( a.substr ( j , x ) == s ) {
                num++ ;
            }
        }

        if ( num > 1 ) {
            return false ;
        }
    }

    return true ;
}
