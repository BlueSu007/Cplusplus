#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

int n ;
stringstream s ;
string a ;

int main () {

    scanf ( "%d" , &n ) ;
    s.precision (0) ;

    s << fixed << pow ( 2.0L , n ) ;
    a = s.str () ;

    a[a.size () - 1]-- ;

    cout << a << endl ;

    return 0 ;
}
