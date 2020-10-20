#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <map>
using namespace std;

map < string , int > pam , vis ;
map < string , int > :: iterator it ;
string s , a , b ;
char c ;
int n , ans , flag ;
inline void init () ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a ;
        transform ( a.begin () , a.end () , a.begin () , :: tolower ) , pam[a] = 1 ;
    }

    getline ( cin , a ) ;
    getline ( cin , b ) ;
    int len = b.size () ;
    
    for ( int i = 0 ; i < len ; i++ ) {
        if ( b[i] == '.' ) {
            if ( !vis[s] ) {
                // cout << s << endl ;
                ans += pam[s] ;
                vis[s] = 1 ;
            }

            s = "" , init () ;
        }
        else if ( b[i] == ',' || b[i] == ' ' ) {
            if ( !vis[s] ) {
                // cout << s << endl ;
                ans += pam[s] ;
                vis[s] = 1 ;
            }
            s = "" ;
        }
        else {
            s += tolower (b[i]) ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}

inline void init () {
    for ( it = vis.begin () ; it != vis.end () ; it++ ) {
        it -> second = 0 ;
    }
}
