#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

long long NumberOfZ , ans ;
char c ;

int main () {

    while ( scanf ( "%c" , &c ) != EOF ) {
        if ( c == 'z' ) {
            NumberOfZ++ ;
        }
        else if ( c == 'y' ) {
            ans += NumberOfZ * ( NumberOfZ - 1 ) / 2 ;
        }
    }

    printf ( "%lld" , ans ) ;

    return 0 ;
}
