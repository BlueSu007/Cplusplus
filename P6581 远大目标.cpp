#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
using namespace std ;

long long tmp ;
unsigned long long n ;

int main () {

    cin >> tmp ;
    if ( tmp <= 0 ) {
        cout << 0 << endl ;
        exit(0) ;
    }
    n = tmp ;
    cout << n * ( unsigned long long ) 2 - ( unsigned long long ) 1 << endl ;

    return 0 ;
}
