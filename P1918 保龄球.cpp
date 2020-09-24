#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

map < int , int > pam ;
int n , m , a ;

int main () {

    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; i++ ) {
        scanf ( "%d" , &a ) ;
        pam[a] = i ;
    }

    scanf ( "%d" , &m ) ;
    for ( int j = 1 ; j <= m ; j++ ) {
        scanf ( "%d" , &a ) ;
        printf ( "%d\n" , pam[a] ) ;
    }

    return 0 ;
}
