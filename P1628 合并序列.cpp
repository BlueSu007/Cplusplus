#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

string k , a[100000 + 5] ;
int n ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        cin >> a[i] ;
    }
    cin >> k ;

    sort ( a + 1 , a + 1 + n ) ;

    for ( int i = 1 ; i <= n ; i++ ) {
        if ( a[i].find (k) == 0 ) {
            cout << a[i] << endl ;
        }
    }

    return 0 ;
}
