#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

int dp[100000 + 5] , n , ans = INT_MIN ;
string s ;

int main () {

    cin >> s ;
    n = s.size () ;

    dp[1] = ( s[0] == '0' ? 1 : -1 ) ;
    for ( int i = 2 ; i <= n ; i++ ) {
        int f = ( s[i - 1] == '0' ? 1 : -1 ) ;
        dp[i] = max ( dp[i - 1] + f , f ) ;
    }

    for ( int i = 1 ; i <= n ; i++ ) {
        ans = max ( ans , dp[i] ) ;
    }

    cout << ans << endl ;

    return 0 ;
}
