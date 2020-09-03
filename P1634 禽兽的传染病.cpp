#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

long long n , x , ans = 1 ;

int main () {

    cin >> n >> x ;
    for ( int i = 1 ; i <= x ; i++ ) {
        ans += ans * n ;
    }
    cout << ans << endl ;

    return 0 ;
}
