#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int n , m , x ;
vector < short > v ;

int main () {

    scanf ( "%d %d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        v.push_back (x) ;
    }

    sort ( v.begin () , v.end () ) ;

    for ( int i = 0 ; i < m ; i++ ) {
        printf ( "%d\n" , v[i] ) ;
    }

    return 0 ;
}
