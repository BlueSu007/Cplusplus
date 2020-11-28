#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

long long k ;
string ans ;

int main () {

    scanf ( "%lld" , &k ) ;
    while ( k > 0 ) {
        if ( k % 2 == 0 ) {
            ans += '7' ;
        }
        else {
            ans += '4' ;
        }
        k = ( k - 1 ) / 2 ;
    }

    reverse ( ans.begin () , ans.end () ) ;
    cout << ans ;

    return 0 ;
}
