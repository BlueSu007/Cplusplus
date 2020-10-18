#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int n , MOD , x , ans ;
char c ;
string s , a ;
map < string , int > pam ;

int main () {

    scanf ( "%d %d" , &n , &MOD ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> s >> x ;
        pam[s] = x ;
    }

    scanf ( "\n" ) ;

    while ( scanf ( "%c" , &c ) != EOF ) {
        if ( c == ',' || c == '.' || c == '!' || c == '?' || c == ' ' ) {
            ans += pam[a] , ans %= MOD ;
            a = "" ;
        }
        else {
            a += c ;
        }
    }

    printf ( "%d" , ans ) ;

    return 0 ;
}
