#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int n , x , ans ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &x ) ;
        ans ^= x ;
    }
    printf ( "%d" , ans ) ;

    return 0 ;
}
